<!-- http://localhost/bookstore/index.php -->
<?php
session_start();
include 'db.php';
include 'navigation.php';
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Spyros' BookStore</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <header>
        <h1>Welcome to Spyros' Bookstore</h1>
    </header>
    <main>
        <form method="get" class="search-form">
            <input type="text" name="search" placeholder="🔍 Search for books..." class="search-input">
            <button type="submit" class="search-button">Search</button>
        </form>
        <ul class="book-list">
            <?php 
            $books = $pdo->query("SELECT * FROM books")->fetchAll();
            if (isset($_GET['search']) && !empty($_GET['search'])) {
                $search = "%" . $_GET['search'] . "%";
                $stmt = $pdo->prepare("SELECT * FROM books WHERE title LIKE ? OR author LIKE ?");
                $stmt->execute([$search, $search]);
                $books = $stmt->fetchAll();
            }
            foreach ($books as $book): ?>
                <li class="book-item">
                    <img src="<?= $book['cover_image'] ?>" alt="<?= htmlspecialchars($book['title']) ?> Cover" class="book-cover">
                    <h2><u>Title: </u><?= htmlspecialchars($book['title']) ?></h2>
                    <h3><u>Author: </u><?= htmlspecialchars($book['author']) ?></h3>
                    <p><u>Description: </u><?= htmlspecialchars($book['description']) ?></p>
                    <p><b>Price: </b> €<?= number_format($book['price'], 2) ?></p>
                    <a href="?add_to_cart=<?= $book['id'] ?>">Add to Cart</a>
                    <?php if (isset($_SESSION['user']) && $_SESSION['user']['role'] == 'admin'): ?>
                        <a href="edit_book.php?id=<?= $book['id'] ?>">Edit</a>
                        <a href="delete_book.php?id=<?= $book['id'] ?>">Delete</a>
                    <?php endif; ?>
                </li>
            <?php endforeach; ?>
        </ul>
        
        <?php include 'cart.php'; ?>
        <div class="cart-actions">
            <a href="checkout.php" class="buy-now-button">Buy Now</a>
        </div>
    </main>
</body>
</html>