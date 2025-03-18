<?php
session_start();
include 'db.php';
include 'navigation.php';
if ($_SESSION['user']['role'] != 'admin') die("Access denied");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $id = $_POST['id'];
    $title = $_POST['title'];
    $author = $_POST['author'];
    $description = $_POST['description'];
    $price = $_POST['price'];
    
    // Check if a new cover image is uploaded
    if (!empty($_FILES['cover_image']['name'])) {
        $upload_dir = 'images/';
        if (!is_dir($upload_dir)) {
            mkdir($upload_dir, 0777, true);
        }

        $target_file = $upload_dir . basename($_FILES["cover_image"]["name"]);
        move_uploaded_file($_FILES["cover_image"]["tmp_name"], $target_file);

        // Update book with new cover image
        $stmt = $pdo->prepare("UPDATE books SET title=?, author=?, description=?, price=?, cover_image=? WHERE id=?");
        $stmt->execute([$title, $author, $description, $price, $target_file, $id]);

    } else {
        // Update book without changing cover image
        $stmt = $pdo->prepare("UPDATE books SET title=?, author=?, description=?, price=? WHERE id=?");
        $stmt->execute([$title, $author, $description, $price, $id]);

    }
    header('Location: index.php');
}

$book = $pdo->prepare("SELECT * FROM books WHERE id=?");
$book->execute([$_GET['id']]);
$book = $book->fetch();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Book</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="edit-book-container">
        <h1>Edit Book</h1>
        <form method="post" enctype="multipart/form-data" class="edit-book-form">
            <input type="hidden" name="id" value="<?= $book['id'] ?>">

            <label>Title:</label>
            <input type="text" name="title" value="<?= $book['title'] ?>" required>

            <label>Author:</label>
            <input type="text" name="author" value="<?= $book['author'] ?>" required>

            <label>Description:</label>
            <textarea name="description" required><?= $book['description'] ?></textarea>

            <label>Price:</label>
            <input type="number" name="price" step="0.01" value="<?= $book['price'] ?>" required>

            <label>Current Cover:</label>
            <img src="<?= $book['cover_image'] ?>" alt="Book Cover" class="current-cover">

            <label>Change Cover Image:</label>
            <input type="file" name="cover_image">

            <button type="submit" class="update-book-button">Update Book</button>
        </form>
    </div>
</body>
</html>