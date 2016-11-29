<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Is not empty
        if (empty($_POST['symbol']) || empty($_POST['shares']))
        {
            apologize(" Must fill all inputs !!");
        }
        
        // Is a right values
        if(!is_numeric($_POST['shares']))
        {
            apologize(" Shares must be number !!");
        }    
        
        // Is user afford the stock
        $the_cash  = CS50::query("SELECT cash FROM users WHERE id= ? ", $_SESSION["id"]);
        $stock     = lookup($_POST["symbol"]);
        $the_price = $stock['price'] * $_POST['shares'];
        
        // Wrong symbol
        if(empty($stock))
        {
            apologize(" There is no such symbol!!");
        }
        
        // Is it OK 
        if($the_price < $the_cash[0]['cash'])
        {
            // By it
            CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ? , ?)
            ON DUPLICATE KEY UPDATE shares = shares + ? ",
            $_SESSION["id"], $stock['symbol'], $_POST['shares'], $_POST['shares']);
            
            // Update the cash
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $the_price, $_SESSION["id"]);
            
            // Set a bUY transaction
            CS50::query("INSERT INTO history (transaction, date_time, symbol, shares, price) 
            VALUES(?, ?, ?, ?, ?)",
            'BUY', date("Y-m-d H:i:s"), $stock['symbol'], $_POST['shares'], $stock['price']);
            
            redirect("/");
        }
        else
        {
            // No items
            apologize(" You can't afford the stock !!");
        }
         
    }
    
        

?>

