import tkinter as tk
from tkinter import ttk
from database import DB


# Переменные необходимые для сортировки от минимальной к максимальной сумме
last_sort_col = None
last_sort_reverse = False


class Main(tk.Frame):
    def __init__(self, root):
        # Метод super отыскивает базовый класс у класса main и возвращает его,
        # дальше идёт обращение к методу init этого найденного класса.
        # Таким образом при изменении родительского класса не придётся изменять содержимое метода
        super().__init__(root)
        self.init_main()
        self.db = db
        self.view_records()

    # Функция в которой хранятся и инициализируются все объекты графического интерфейса
    def init_main(self):
        toolbar = tk.Frame(bg='#f0f788', bd=2)
        toolbar.pack(side=tk.TOP, fill=tk.X)

        # Создание кнопки добавления доходов и расходов
        self.add_img = tk.PhotoImage(file='pictures/add.gif')
        btn_open_dialog = tk.Button(toolbar, text='Добавить позицию', command=self.open_dialog, bg='#f0f788', bd=0,
                                    compound=tk.TOP, image=self.add_img)
        btn_open_dialog.pack(side=tk.LEFT)
        # Кнопка удаления
        self.delete_img = tk.PhotoImage(file='pictures/delete.gif')
        btn_delete = tk.Button(toolbar, text='Удалить позицию', command=self.delete_records, bg='#f0f788', bd=0,
                               compound=tk.TOP, image=self.delete_img)
        btn_delete.pack(side=tk.LEFT)

        self.refresh_img = tk.PhotoImage(file='pictures/refresh.gif')
        btn_refresh = tk.Button(toolbar, text='Обновить', command=self.view_records, bg='#f0f788', bd=0,
                                compound=tk.TOP, image=self.refresh_img)
        btn_refresh.pack(side=tk.LEFT)

        self.tree = ttk.Treeview(self, columns=('ID', 'description', 'costs', 'date', 'total'), height=15, show='headings')

        self.tree.column('ID', width=30, anchor=tk.CENTER)
        self.tree.column('description', width=215, anchor=tk.CENTER)
        self.tree.column('costs', width=150, anchor=tk.CENTER)
        self.tree.column('date', width=150, anchor=tk.CENTER)
        self.tree.column('total', width=100, anchor=tk.CENTER)

        self.tree.heading('ID', text='ID')
        self.tree.heading('description', text='Наименование')
        self.tree.heading('costs', text='Категория')
        self.tree.heading('date', text='Дата')
        self.tree.heading('total', text='Сумма', command=lambda: self.treeview_sort_column(self.tree, 'total',
                                                                                           reverse=True))

        self.tree.pack()

    def records(self, description, costs, date, total):
        self.db.insert_data(description, costs, date, total)
        self.view_records()

    # Позволяет отобразить информацию из базы данных в виджете treeview главного окна программы
    def view_records(self):
        self.db.c.execute('''SELECT * FROM finance''')
        # Очистка содержимого виджета после каждого добавления нового поля
        [self.tree.delete(i) for i in self.tree.get_children()]
        # Отображение содержимого бд
        [self.tree.insert('', 'end', values=row) for row in self.db.c.fetchall()]

    def delete_records(self):
        # Реализуем цикл т.к. метод selection возвращает список уникальных идентификаторов виджета treeview,
        # при использовании цикла можно будет обращаться к каждому элементу по отдельности
        for selection_item in self.tree.selection():
            self.db.c.execute('''DELETE FROM finance WHERE  id=?''', (self.tree.set(selection_item, '#1'),))
        self.db.conn.commit()
        self.view_records()

    def treeview_sort_column(self, tv, col, reverse):
        global last_sort_col
        global last_sort_reverse
        # Определяем порядок сортировки
        if last_sort_col == col:
            reverse = not last_sort_reverse
        last_sort_reverse = reverse
        last_sort_col = col
        # Сортируем столбец
        l = [(tv.set(k, col), k) for k in tv.get_children()]
        l.sort(key=lambda x: float(x[0]), reverse=reverse)
        for index, (val, k) in enumerate(l):
            tv.move(k, '', index)
        # Обновляем заголовок сортируемого столбца
        heading = tv.heading(col)
        heading['text'] = heading['text'] + (' ▼' if reverse else ' ▲')

    # Вызов дочернего окна
    def open_dialog(self):
        Child()


# Дочернее окно
class Child(tk.Toplevel):
    def __init__(self):
        super().__init__(root)
        self.init_child()
        self.view = app

    def init_child(self):
        self.title('Добавить доходы\расходы')
        self.geometry('400x220+400+300')
        self.resizable(False, False)

        # Наименование полей ввода
        label_description = tk.Label(self, text='Наименование')
        label_description.place(x=50, y=50)
        label_category = tk.Label(self, text='Категория')
        label_category.place(x=50, y=70)
        label_date = tk.Label(self, text='Дата')
        label_date.place(x=50, y=90)
        label_sum = tk.Label(self, text='Сумма')
        label_sum.place(x=50, y=110)

        # Поле ввода описания доходов или затрат
        self.entry_description = ttk.Entry(self)
        self.entry_description.place(x=200, y=50)
        # Поле ввода даты
        self.entry_date = ttk.Entry(self)
        self.entry_date.place(x=200, y=90)
        # Поле ввода суммы денег
        self.entry_money = ttk.Entry(self)
        self.entry_money.place(x=200, y=110)

        # Выпадающий список с необходимой функцией, Доход или Расход
        self.combobox = ttk.Combobox(self, values=[u'Доход', u'Расход'])
        # Значение по умолчанию
        self.combobox.current(0)
        self.combobox.place(x=200, y=70)

        btn_cancel = ttk.Button(self, text='Закрыть', command=self.destroy)
        btn_cancel.place(x=300, y=170)

        btn_ok = ttk.Button(self, text='Добавить')
        btn_ok.place(x=220, y=170)
        btn_ok.bind('<Button-1>', lambda event: self.view.records(self.entry_description.get(), self.combobox.get(),
                                                                  self.entry_date.get(), self.entry_money.get()))

        # grab_set перехватывает все события происходящие в приложении
        self.grab_set()
        # focus_set захватывает и удерживает фокус
        self.focus_set()


# Если скрипт запущен как основная программа, то её содержимое выполнится
# Если скрипт импортируется, то её содержимое не пойдет на выполнение
if __name__ == "__main__":
    root = tk.Tk()
    db = DB()
    app = Main(root)
    app.pack()
    root.title("Контроль финансов")
    root.geometry("650x450+300+200")
    root.resizable(False, False)
    root.mainloop()
