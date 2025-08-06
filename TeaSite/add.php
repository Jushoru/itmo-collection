<!DOCTYPE html>
<html lang="ru">
<head>
  <meta charset="UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <link href="style.css" rel="stylesheet"/>
  <title>TreeTeaSip</title>
</head>
<body>
  <div class="layout">
    <header>
      <div class="logo">
        <img src="img\icon.png" alt="logo" class="icon">
        <p class="site_name">TreeTeaSip</p>
      </div>
      <ul>
        <li> <a href="index.php">Статьи</a> </li>
        <li> <a href="order.php">Заказать</a> </li>
        <li> <a href="review.php">Обратная связь</a> </li>
      </ul>
    </header>


    <main>
      <form action="make_article.php" method="post" class="add">
        <textarea placeholder="Введите заголовок" name="title" class="form-control-1" required></textarea>
        <textarea placeholder="Введите интро" name="intro" class="form-control-1" required></textarea>
        <textarea placeholder="Введите текст статьи" name="content" class="form-control-2" required></textarea>
        <select id="tea_id" name="tea_id" class="tea_select" required>
                <option value="" required>Выберите чай</option>
                <?php
                    require_once('db.php');

                    $sql = "SELECT * FROM `tea`";
                    $result = $conn->query($sql);

                    if ($result->num_rows > 0) {
                    while ($row = $result->fetch_assoc()) {
                        echo "<option value='" . $row["tea_id"] . "'>" . $row["name"] . "</option>";
                    }
                    }
                ?>
            </select><br>
        <button class="send-button">Опубликовать</button>
      </form>
    </main>


    <footer>
      <div class="copyright">
        <p>Copyright © 2024. All rights reserved. Branding by Kirill Smirnov.</p>
      </div>
    </footer>
  </div>
</body>
</html>