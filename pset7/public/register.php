<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Is not empty
        if (empty($_POST['password']) || empty($_POST['conf_password']) || empty($_POST['username']))
        {
            apologize(" Must fill all inputs !!");
        }
        // Password is not matching
        else if ($_POST['password'] != $_POST['conf_password'])
        {
            apologize(" Password is not matching !!");
        }
            
        // Insert
        $var = CS50::query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"],
        password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        // Is it OK 
        if($var)
        {
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"] = $id;
            
            redirect("/");
        }
        else
        {
            apologize(" The username has already taken !!");
        }
         
    }
    

?>
