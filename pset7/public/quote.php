<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Get Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Is not empty
        if (empty($_POST['symbol']))
        {
            apologize(" Must fill the input !!");
        }
        
        // Lookup the symbol
        if(lookup($_POST["symbol"]) != false)
        {
            // Get the symbol
            $stock          = lookup($_POST["symbol"]);
            // Make a price format
            $stock['price'] = number_format($stock['price'], 2, '.', '');
            
            // Show 
            render("quote.php", ["price" => $stock['price'], 'name' => $stock['name'], 'symbol' => $stock['symbol']] );
        }
        else
        {
            apologize(" Symbol not found !!");
        }
         
    }
    

?>
