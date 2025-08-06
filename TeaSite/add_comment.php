<?php
require_once('db.php');

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $article_id = $_POST['article_id'];
    $commenter_name = $_POST['commenter_name'];
    $comment_text = $_POST['comment_text'];

    // Вставка комментария в базу данных
    $insert_query = "INSERT INTO `comment` (`article_id`, `comment_text`, `commenter_name`) 
                    VALUES ('$article_id', '$comment_text', '$commenter_name')";
    $result = $conn->query($insert_query);

    if ($result) {
        // Комментарий успешно добавлен, перенаправляем обратно на страницу поста
        header("Location: article.php?id=$article_id");
    } else {
        echo "Ошибка: " . $conn->error;
    }
}
?>
