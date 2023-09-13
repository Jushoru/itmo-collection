import sqlite3


class DB:
    def __init__(self):
        # Соединение с файлом бд finance.db
        self.conn = sqlite3.connect('finance.db')
        # Курсор помогает взаимодействовать с базой данных, удалять добавлять или редактировать данные
        self.c = self.conn.cursor()
        # Создание таблицы в базе данных, посредством обращения к finance.db
        self.c.execute(
            '''CREATE TABLE IF NOT EXISTS finance
            (id integer primary key, description text, costs text, date text, total real)'''
        )
        # Сохранение всех изменений
        self.conn.commit()

    # Функция при помощи которой в поля бд добавляются значения description, costs, date, total
    def insert_data(self, description, costs, date, total):
        self.c.execute('''INSERT INTO finance (description, costs, date, total) VALUES (?, ?, ?, ?)''',
                       (description, costs, date, total))
        self.conn.commit()


