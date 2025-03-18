<?php
include 'db.php';
include 'navigation.php';
if ($_SESSION['user']['role'] != 'admin') die("Access denied");

$stmt = $pdo->prepare("DELETE FROM books WHERE id=?");
$stmt->execute([$_GET['id']]);
header('Location: index.php');
?>