<?php
$upload_dir = 'images/';

if (!is_dir($upload_dir)) {
    echo "Error: 'images/' directory does not exist!";
} elseif (!is_writable($upload_dir)) {
    echo "Error: 'images/' directory is not writable!";
} else {
    echo "'images/' directory is ready!";
}
?>