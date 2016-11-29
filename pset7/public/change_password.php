<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_password.php", ["title" => "Change the password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Is not empty
        if (empty($_POST['new_password']) || empty($_POST['conf_password']) || empty($_POST['old_password']))
        {
            apologize(" Must fill all inputs !!");
        }
        // Password is not matching
        else if ($_POST['new_password'] != $_POST['conf_password'])
        {
            apologize(" Password is not matching !!");
        }
        
        $old_pass = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        if (!password_verify($_POST['old_password'], $old_pass[0]['hash']) )
        {
            apologize(" old password is wrong !!");
        }
        
        $update = CS50::query("UPDATE users SET hash = ? WHERE id = ?",
        password_hash($_POST['new_password'], PASSWORD_DEFAULT) , $_SESSION["id"]);
        
        // Is it OK 
        if($update)
        {
            redirect("/");
        }
        else
        {
            apologize(" Something wrong !!");
        }
         
    }
    

?>
