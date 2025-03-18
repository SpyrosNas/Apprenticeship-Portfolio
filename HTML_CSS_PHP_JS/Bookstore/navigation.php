<?php
session_start();
?>
<nav>
    <a href="index.php">Home</a> |
    <?php if (isset($_SESSION['user'])): ?>
        <a href="logout.php">Logout (<?= $_SESSION['user']['username'] ?>)</a>
    <?php else: ?>
        <a href="login.php">Login</a> | <a href="register.php">Register</a>
    <?php endif; ?>
</nav>