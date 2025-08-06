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
            <a href="add.php" class="add-button">Добавить статью</a>
        </header>


        <main>
            <h1 class="article-h">Все посты</h1>
            <section>
                <?php
                    require_once('db.php');
                    $query = $conn -> query("SELECT * FROM `article` ORDER BY `article_id` DESC");
                    if (mysqli_num_rows($query) == 0):
                ?>
                <span class="article_empty"> На данный момент нет постов</span>
                <?php
                    endif;
                    while ($res = mysqli_fetch_assoc($query)):
                ?>
                    <article class="article_intro">
                        <h2 class="title_intro"><?=$res['title'];?></h2>
                        <p class="intro_intro"><?=$res['intro'];?></p><br>
                        <div class="btn-container">
                            <a href="/article.php?id=<?=$res['article_id'];?>" class="follow_article_btn">Перейти</a>
                        </div>
                    </article>
                <?php
                    endwhile;
                ?>
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