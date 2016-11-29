<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    if(!empty($rows))
    {
        $positions = [];
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                    "name"   => $stock["name"],
                    "price"  => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"],
                    "total"  => $stock["price"] * $row["shares"] 
                ];
            }
        }
        
        // render portfolio
        render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);
    }
    else
    {
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        // render portfolio
        render("portfolio.php", ["title" => "Portfolio", "cash" => $cash[0]['cash'] ]);
    }
    
?>
