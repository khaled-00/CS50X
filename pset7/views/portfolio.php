<table class="table table-striped">
    <thead>
        <tr>
            <th>symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>
    <tbody>
    <?php
        if(!empty($positions))
        {
            foreach ($positions as $position)
            {
                print("<tr>");
                print("<td>" .  $position["symbol"] . "</td>");
                print("<td>" .  $position["name"]   . "</td>");
                print("<td>" .  $position["shares"] . "</td>");
                print("<td>$" . $position["price"]  . "</td>");
                print("<td>$" . $position["total"]  . "</td>");
                print("</tr>");
            }
        }
        else
        { 
    ?>
        <tr>
            <td colspan="4">CASH</td>
            <td>$<?=$cash?></td>
        </tr>
  <?php 
        }
  ?>
    </tbody>
</table>