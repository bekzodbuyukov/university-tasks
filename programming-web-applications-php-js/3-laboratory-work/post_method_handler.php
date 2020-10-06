<?php

$db = @mysqli_connect('lab-db', 'mysql', 'mysql', 'test') or die(mysql_error());
// $connection = new mysqli('lab_db', 'mysql', 'mysql', 'test');

$name = $_POST['name'];
$new_comment = $_POST['comment'];

// $query = "SELECT * FROM `user_data` WHERE `username` = '$name'"
$query = "INSERT INTO user_data (username, comment) VALUES ('$name', '$new_comment')";

mysqli_query($db, $query);

header("Location: index.php");
exit;

?>
