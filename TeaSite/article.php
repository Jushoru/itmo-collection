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
            <section>
                <?php
                require_once('db.php');
                $id = $_GET['id'];
                $query = $conn->query("SELECT * FROM `article` WHERE `article_id` = '$id'");
                if (mysqli_num_rows($query) == 0) echo "<span class='text-muted'>Не удалось найти пост.<span>";
                while ($res = mysqli_fetch_assoc($query)) :
                ?>
                    <h1 class="article-h"><?= $res['title']; ?></h1>
                    <article class="article_intro">
                        <p><?= $res['content']; ?></p><br>
                    </article>
                <?php
                endwhile;
                ?>
            </section>

            <section>
                <h1 class="comm_title">Комментарии</h1>
                <div class="comment_container">
                    <?php
                    $comment_query = $conn->query("SELECT * FROM `comment` WHERE `article_id` = '$id'");
                    while ($comment = mysqli_fetch_assoc($comment_query)) :
                    ?>
                        <div class="comment">
                            <p><strong class="commentator"><?= $comment['commenter_name']; ?>:</strong> <?= $comment['comment_text']; ?></p>
                        </div>
                    <?php endwhile; ?>
                </div>

                <h3 class="add_comm_title">Оставить комментарий</h3>
                <form action="add_comment.php" method="POST" class="add_comm">
                    <input type="hidden" name="article_id" value="<?= $id; ?>">
                    <div class="add_comm_elem">
                        <label for="commenter_name">Ваше имя:</label><br>
                    </div>
                    <input type="text" id="commenter_name" name="commenter_name" class="commenter_name" required><br>
                    <div class="add_comm_elem">
                        <label for="comment_text">Комментарий:</label><br>
                    </div>
                    <textarea id="comment_text" name="comment_text" class="comment_text" required></textarea><br>
                    <button type="submit" class="submit_comment">Отправить</button>
                </form>
            </section>

        </main>


        <footer>
            <div class="copyright">
                <p>Copyright © 2024. All rights reserved. Branding by Kirill Smirnov.</p>
            </div>
        </footer>
    </div>
</body>

</html>