<?php
session_start();
include 'db.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $title = $_POST['title'];
    $author = $_POST['author'];
    $description = $_POST['description'];
    $price = $_POST['price']; // Capture price input

    // Ensure the uploads directory exists
    $upload_dir = 'images/';

    if (!is_dir($upload_dir)) {
        mkdir($upload_dir, 0777, true);
    }

    // File upload handling
    $target_file = $upload_dir . basename($_FILES["cover_image"]["name"]);
    $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));

    // Validate file type (allow only JPG, JPEG, PNG)
    $allowed_types = ['jpg', 'jpeg', 'png'];
    if (!in_array($imageFileType, $allowed_types)) {
        die("Error: Only JPG, JPEG, and PNG files are allowed.");
    }

    // Move uploaded file
    if (move_uploaded_file($_FILES["cover_image"]["tmp_name"], $target_file)) {
        // Insert book into database, including price
        $stmt = $pdo->prepare("INSERT INTO books (title, author, description, price, cover_image) VALUES (?, ?, ?, ?, ?)");
        $stmt->execute([$title, $author, $description, $price, $target_file]);

        header('Location: index.php');
        exit;
    } else {
        echo "Error uploading file.";
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Book</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="add-book-container">
        <h1>Add a New Book</h1>
        <form method="post" enctype="multipart/form-data" class="add-book-form">
            <label>Title:</label>
            <input type="text" name="title" required>

            <label>Author:</label>
            <input type="text" name="author" required>

            <label>Description:</label>
            <textarea name="description"></textarea>

            <label>Price:</label>
            <input type="number" name="price" step="0.01" required>

            <label>Cover Image:</label>
            <input type="file" name="cover_image" required>

            <button type="submit" class="add-book-button">Add Book</button>
        </form>
    </div>
</body>
</html>