<!DOCTYPE html>
<html>
<head>
    <title>Multiplication Table</title>
</head>
<body>
    <h1>Multiplication Table</h1>
    <hr>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["size"])) {
        $size = intval($_POST["size"]);

        echo "<h2>Multiplication Table for 1 to $size</h2>";
        echo "<table border='1'>";
        
        // Header row with column indexes
        echo "<tr>";
        echo "<th>&times;</th>";
        for ($i = 1; $i <= $size; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";

        // Generate and display the multiplication table
        for ($row = 1; $row <= $size; $row++) {
            echo "<tr>";
            echo "<th>$row</th>";
            for ($col = 1; $col <= $size; $col++) {
                $result = $row * $col;
                echo "<td>$result</td>";
            }
            echo "</tr>";
        }

        echo "</table>";
    } else {
        echo "Please enter a valid size for the multiplication table.";
    }
    ?>
    
    <a href="practice4.html">Go back</a>
</body>
</html>
