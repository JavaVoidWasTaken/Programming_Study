<?php
$username = "Admin";
$password = "12345";

$inusername = $_POST['username'];
$inpassword = $_POST['password'];

if ($username == $inusername && $password == $inpassword) {
  header('Location: success.html');
} else {
  header('Location: fail.html');
}
?>
