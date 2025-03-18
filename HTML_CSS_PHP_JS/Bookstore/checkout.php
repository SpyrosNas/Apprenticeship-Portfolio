<?php
session_start();
include 'db.php';

if (!isset($_SESSION['cart']) || empty($_SESSION['cart'])) {
    die("Your cart is empty. <a href='index.php'>Go back</a>");
}

// Fetch book details for items in the cart
$cart_books = [];
$total_price = 0;

if (!empty($_SESSION['cart'])) {
    $placeholders = implode(',', array_fill(0, count($_SESSION['cart']), '?'));
    $stmt = $pdo->prepare("SELECT * FROM books WHERE id IN ($placeholders)");
    $stmt->execute(array_keys($_SESSION['cart']));
    $cart_books = $stmt->fetchAll();

    foreach ($cart_books as $book) {
        $total_price += $book['price'] * $_SESSION['cart'][$book['id']];
    }
}

// Handle order submission
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $address = $_POST['address'];
    $payment_method = $_POST['payment_method'];

    // Process the order (e.g., store in database, send email, etc.)
    $_SESSION['cart'] = []; // Clear cart after purchase
    echo "<div class='checkout-success'>Order placed successfully! Total: €" . number_format($total_price, 2) . "</div>";
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Checkout</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="checkout-container">
        <h1>Checkout</h1>
        <h2 class="total-price">Total Price: €<?= number_format($total_price, 2) ?></h2>

        <form method="post" class="checkout-form">
            <label>Full Name:</label>
            <input type="text" name="name" required>

            <label>Shipping Address:</label>
            <textarea name="address" required></textarea>

            <label>Payment Method:</label>
            <select name="payment_method">
                <option value="credit_card">Credit Card</option>
                <option value="paypal">PayPal</option>
                <option value="cash_on_delivery">Cash on Delivery</option>
            </select>

            <button type="submit" class="checkout-button">Confirm Purchase</button>
        </form>
        
        <a href="index.php" class="back-to-home-button">Back to Main Page</a>
    </div>
</body>
</html>