<?php
session_start();

// Initialize cart if it doesn't exist
if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = [];
}

// Handle adding to cart
if (isset($_GET['add_to_cart'])) {
    $book_id = $_GET['add_to_cart'];
    if (!isset($_SESSION['cart'][$book_id])) {
        $_SESSION['cart'][$book_id] = 1;
    } else {
        $_SESSION['cart'][$book_id]++;
    }
    header("Location: index.php");
    exit();
}

// Handle removing from cart
if (isset($_GET['remove_from_cart'])) {
    $book_id = $_GET['remove_from_cart'];
    if (isset($_SESSION['cart'][$book_id])) {
        unset($_SESSION['cart'][$book_id]);
    }
    header("Location: index.php");
    exit();
}

// Fetch book details from the database
include 'db.php';
$cart_books = [];
if (!empty($_SESSION['cart'])) {
    $placeholders = implode(',', array_fill(0, count($_SESSION['cart']), '?'));
    $stmt = $pdo->prepare("SELECT * FROM books WHERE id IN ($placeholders)");
    $stmt->execute(array_keys($_SESSION['cart']));
    $cart_books = $stmt->fetchAll();
}
?>

<div class="cart">
    <h2>Your Cart</h2>
    <ul>
        <?php if (!empty($cart_books)): ?>
            <?php foreach ($cart_books as $book): ?>
                <li>
                    <h3><?= htmlspecialchars($book['title']) ?></h3>
                    <p>Quantity: <?= $_SESSION['cart'][$book['id']] ?></p>
                    <a href="?remove_from_cart=<?= $book['id'] ?>">Remove</a>
                </li>
            <?php endforeach; ?>
        <?php else: ?>
            <p>Your cart is empty.</p>
        <?php endif; ?>
    </ul>
</div>