<?php
$file = "array.json";
$all_comments = json_decode(file_get_contents($file), true);

$count = count($all_comments);
echo "Всего сообщений: <b>{$count}</b><br><br>";

foreach ($all_comments as $key => $value) {
    // $arr[3] will be updated with each value from $arr...
    echo "<div class='comment'>
    <img src='images\avatar.png'>
    <p>{$value}</p></div>";
    // print_r($arr);
};
?>
