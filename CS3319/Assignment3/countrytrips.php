<?php
 include "connecttodb.php";

 $query = "SELECT * FROM bustrip GROUP BY country";

 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed.");
 }

 while ($row = mysqli_fetch_assoc($result)) {
  echo '<option value="' . $row[country] . '">' . $row[country] . '</option>'; //list for countries
 } 

 mysqli_free_result($result); 
?>
