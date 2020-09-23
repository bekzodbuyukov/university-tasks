<?php
//$name = $_POST[name];
//$comment = $_POST[comment];

/*$comments = array(
    $name => $comment
);*/

// echo "<b>Array:</b><br><br>", $comments[$name], " : ";
// echo "<br><br>", var_dump($comments);

$file = "array.json";

$old_comments = json_decode(file_get_contents($file), true);

$old_comments += [$name => $comment];

//fwrite($file, json_encode($comments));
file_put_contents($file, json_encode($old_comments));

/*foreach ($comments as $key => $value) {
    // $arr[3] will be updated with each value from $arr...
    echo "<br><br><b>{$key}</b> пишет<br><i>{$value}</i> ";
    // print_r($arr);
};*/

// $file = fopen("array.json", "w+");

$all_comments = json_decode(file_get_contents($file), true);
foreach ($all_comments as $key => $value) {
    // $arr[3] will be updated with each value from $arr...
    echo "<br><br><b>{$key}</b> пишет<br><i>{$value}</i> ";
    // print_r($arr);
};

?>