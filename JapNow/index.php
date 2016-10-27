<?php 
require "connect.php";
    
$task = isset($_GET["task"]) ? $_GET["task"] : "form";
    
if ($task == "submit") {
    $userName = isset($_POST["txtUsername"]) ? $_POST["txtUsername"] : "";
    $content = isset($_POST["txtContent"]) ? $_POST["txtContent"] : "";
}
?>

<!DOCTYPE html>
<!--Authors: James Mok(Monday PM) Faizen Syed-->
<html>
    <head>
        <title>JapNow.com</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width">
        <link href="css/japnow.css" rel="stylesheet" type="text/css" />
        <script type="text/javascript" src="scripts/general.js"></script>
    </head>
    <body>
        <!-- Banner -->
        <header>
            <a href="index.html"> 
                <image alt="Banner" src="images/banner.jpg"/>
            </a>
        </header>
        <!-- Main Navigation -->
        <nav>
            <a href="content/language.html">Phrases</a>
            <a href="content/food.html">Food</a>
            <a href="content/anime.html">Anime</a>
            <a href="content/attractions.html">Attractions</a>
        </nav>
        <!-- Main Navigation close-->
        <!-- title -->
        <h2>
            Main Page
        </h2>
        <!-- main page header description area -->
    <u>
        Hello! This is James' and Faizen's Japanese Fan page. Here, you can find some
        information about topics like Anime, Food, Travel, and etc.  
    </u> <!-- main page header description area close-->
    <!-- Content area -->
    <article>
        <h4>Latest Updates</h4>
        <h3>April 2, 2014</h3>
        Ramen was added to Foods Page! <a href='content/food.html'>Click here to go to food!</a>
        <h3>November, 14, 2013</h3>
        Whats cute?! kawaii is cute! <a href='content/language.html'>Click here to go to phrases!</a>
        <h3>October 24, 2012</h3>
        Theres a Disney Land in Japan?!! <a href='content/attractions.html'>Click here to go to Attractionss!</a>
        

        <form method='post' action='index.php?task=submit'>
            <p>UserName: <input type='text' size='25' name='txtUsername'>
                <br>
                Content: <input type='text' size='25' name='txtContent'>
                </p>
            <p><input type='submit' value='Save'>
                <input type='reset' value='Clear'></p>
        </form>

    </article>
    <!-- content close -->
    <footer>
        Copyright ©2014 James Mok and Faizan Syed
    </footer>
        <?php
        if ($task == "submit") {
            $dblink = new mysqli("localhost", $user, $pass, $dbname);
            
            if ($dblink->connect_errno) {
                echo "<p>Failed to connect to $dbname: $dblink->connect_error</p>";
                } else {
                    
                    $sql = "INSERT INTO maincomments (userName, content) VALUES ('" .
                            $dblink->real_escape_string($userName) . "', '" .
                            $dblink->real_escape_string($content) . "');";
                    
                    $result = $dblink->query($sql);
                    
                    if ($result === TRUE) {
                        echo "<p><b>Record added successfully.</b></p>";
                        } else {
                            echo "<p><b>Error executing query ($sql): $dblink->error</b></p>\n";
                            }
                            $dblink->close();
                            }
                            }
       ?>
</body>
</html>