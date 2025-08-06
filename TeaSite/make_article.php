<?php

require_once('db.php');

$title = $_POST['title'];
$intro = $_POST['intro'];
$content = $_POST['content'];
$tea_id = $_POST['tea_id'];

$sql = "INSERT INTO article (title, intro, content, tea_id) VALUES (?,?,?,?)";
$stmt = $conn->prepare($sql);
$stmt->bind_param("sssi", $title, $intro, $content, $tea_id);
$stmt->execute();

header('Location: /');
?>