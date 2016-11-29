<?php

    // configuration
    require("../includes/config.php"); 
    
    // All the history
    $rows = CS50::query("SELECT * FROM history ORDER BY id DESC");
    
    // If not empty 
    if(!empty($rows))
    {
        $positions = [];
        foreach ($rows as $row)
        {
            $positions[] = [
                "transaction"   => $row["transaction"],
                "date_time"     => $row["date_time"],
                "symbol"        => $row["symbol"],
                "shares"        => $row["shares"],
                "price"         => $row["price"]
            ];
        }
        
        // render history
        render("history.php", ["positions" => $positions, "title" => "History"]);
    }
    else
    {
        // render history
        render("history.php", ["title" => "History" ]);
    }
    
?>
