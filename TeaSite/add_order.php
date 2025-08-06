<?php
// Подключение к базе данных
require_once('db.php');

// Проверка, была ли отправлена форма
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Получение данных из формы
    $tea_id = $_POST['tea_id'];
    $cust_name = $_POST['cust_name'];
    $cust_surname = $_POST['cust_surname'];
    $cust_email = $_POST['cust_email'];
    $order_date = $_POST['order_date'];

    // Подготовка SQL-запроса для вставки данных
    $sql = "INSERT INTO `orders` (tea_id, customer_name, customer_surname, customer_email, order_date) VALUES (?, ?, ?, ?, ?)";

    // Подготовка выражения для выполнения запроса
    $stmt = $conn->prepare($sql);

    // Привязка параметров
    $stmt->bind_param("issss", $tea_id, $cust_name, $cust_surname, $cust_email, $order_date);

    // Выполнение запроса
    if ($stmt->execute()) {
        echo "Отзыв успешно добавлен.";
    } else {
        echo "Ошибка при добавлении отзыва: " . $conn->error;
    }

    // Закрытие запроса и соединения
    $stmt->close();
    $conn->close();
} else {
    // Если форма не была отправлена, выводим сообщение об ошибке
    echo "Ошибка: форма не была отправлена.";
}
header('Location: /');

?>
