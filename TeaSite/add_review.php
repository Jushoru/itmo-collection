<?php
// Подключение к базе данных
require_once('db.php');

// Проверка, была ли отправлена форма
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Получение данных из формы
    $commenter_name = $_POST['commenter_name'];
    $comment_text = $_POST['comment_text'];
    $tea_id = $_POST['tea_id'];

    // Подготовка SQL-запроса для вставки данных
    $sql = "INSERT INTO review (tea_id, review_text, reviewer_name) VALUES (?, ?, ?)";

    // Подготовка выражения для выполнения запроса
    $stmt = $conn->prepare($sql);

    // Привязка параметров
    $stmt->bind_param("iss", $tea_id, $comment_text, $commenter_name);

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
