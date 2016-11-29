<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell.php", ["title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Is not empty
        if (empty($_POST['sell_item']))
        {
            apologize(" Must fill the input !!");
        }
            
        // The user
        $user = CS50::query("SELECT shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        // Insert
        $item = CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ? ", $_SESSION["id"], $_POST['sell_item']);
        
        // Is it OK 
        if($item)
        {
            $stock = lookup($_POST['sell_item']);
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $stock['price'], $_SESSION["id"]);
            
            // Set a SELL transaction
            CS50::query("INSERT INTO history (transaction, date_time, symbol, shares, price) 
            VALUES(?, ?, ?, ?, ?)",
            'SELL', date("Y-m-d H:i:s"), $stock['symbol'], $user[0]['shares'], $stock['price']);
            
            redirect("/");
        }
        else
        {
            // No items
            apologize(" You have nothing to sell  !!");
        }
         
    }
    
        

?>

