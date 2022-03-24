<!-- Lists all the trips using the tripname vs country and asc vs desc user inputs in main webpage -->

<!DOCTYPE html>
<html>
 <head>
  <title>Navigation For Newbies</title>
   <link rel="stylesheet" type="text/css" href="bustrips.css">
   <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
 </head>
 <body>
  
  <form action="back.php">
    <input type="submit" value="back">
  </form>

<?php
  include "connecttodb.php";

 $ordered = $_POST["sortby"];
 $aord = $_POST["ascdesc"];
 $query = "SELECT * FROM bustrip ORDER BY $ordered $aord"; //organizes the data in bustrip accordingly
 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed.");
 }
 
 echo '<hr>';
 echo '<h2>' . "Trips In Our Catalog: " . '</h2>';

 echo '<form action="tripinfo.php" method="post">'; //the selected trip directs the user to tripinfo.php
  
while ($row = mysqli_fetch_assoc($result)) {
    echo '<input type="radio" name="selected" value="' . $row[tripid] . '">' . $row[tripname] . " in " . $row[country] . "<br>";
    echo "<br>";
  }
  echo "<input type=\"submit\" value=\"info\">";
 echo "</form>";

 mysqli_free_result($result);
?>
  
  </body>
  </html>

