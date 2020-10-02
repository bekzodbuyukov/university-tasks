<?php 
$name = $_POST[name];
$new_comment = $_POST[comment];

$comment = "<b>";
$comment .= $name;
$comment .= "</b>:<br><i>";
$comment .= $new_comment;
$comment .= "</i>";


// $comment = "<b>" + $name + "</b><br>" + $new_comment;

$file = "array.json";
$old_comments = json_decode(file_get_contents($file), true);
if ($old_comments == "") {
    $old_comments[0] = $comment;
} else {
    $old_key = array_key_last($old_comments);
    $key = $old_key + 1;
    $old_comments += [$key => $comment];
}

file_put_contents($file, json_encode($old_comments));


header("Location: index.php");
exit;
?>