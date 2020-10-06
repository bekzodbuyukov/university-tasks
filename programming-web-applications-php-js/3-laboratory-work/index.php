<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Главная страница - Гостевая книга</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<div class="container">

    <nav>
        <ul>
            <li class="brand">
                ГостеваяКнига
            </li>
            <li class="item right">

            </li>
        </ul>
    </nav>

    <article>
        <br>
        Чтобы оставить сообщение, можно воспользоваться формой ниже.
        <br>
        <hr>
        <table>
            <tr>
                <td>
                    <?php
                    // include 'comments.php';
                    ?>
                </td>

                <td>
                    <div>Отправить сообщение:</div>
                    <br>
                    <form action="post_method_handler.php" method="post" name="commenting-form">
                        <label for="user_name">Имя</label><br>
                        <input autocomplete="off" id="user_name" name="name" type="text" placeholder="Ваше имя" value="" required>
                        <br>
                        <br>
                        <label for="comment">Сообщение</label><br>
                        <textarea autocomplete="off" id="comment" name="comment" cols="30" rows="10" type="text" placeholder="Ваше сообщение" value="" required></textarea>
                        <br>
                        <input name="submit" type="submit" value="Отправить">
                    </form>
                </td>
            </tr>
        </table>

    </article>


</div>
</body>
</html>
