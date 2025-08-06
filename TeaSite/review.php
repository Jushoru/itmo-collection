<!DOCTYPE html>
<html lang="ru">

<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <link href="style.css" rel="stylesheet" />
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
      <div class="review_container">
      <h3 class="add_comm_title">Оставить обратную связь</h3>
      <form action="add_review.php" method="POST" class="add_comm">
        <input type="hidden" name="tea_id" value="<?= $id; ?>">
        <div class="add_comm_elem">
          <label>Ваше имя:</label><br>
        </div>
        <input type="text" name="commenter_name" class="commenter_name" required><br>
        <div class="add_comm_elem">
          <label>Комментарий:</label><br>
        </div>
        <textarea name="comment_text" class="comment_text" required></textarea><br>
        <div class="add_comm_elem">
            <label>Чай:</label><br>
        </div>
        <select name="tea_id" class="tea_select" required>
            <option value="" required>Купленный чай</option>
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
        <button type="submit" class="submit_comment">Отправить</button>
      </form>
      </div>
  </main>


  <footer>
    <div class="copyright">
      <p>Copyright © 2024. All rights reserved. Branding by Kirill Smirnov.</p>
    </div>
  </footer>
  </div>
</body>

</html>