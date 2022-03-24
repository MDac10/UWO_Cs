<?php
 include "connecttodb.php";

 $passid = $_POST["passengerid"]; //holds passengerid
 $trip = $_POST["tripid"]; //holds triid
 $cost = $_POST["price"]; //holds price

 $query = 'INSERT INTO booking VALUES(' . $passid . ',' . $trip . ',' . $cost . ');';
 
 $result = mysqli_query($connection, $query);

 if (!$result) {
  die ("Error while trying to add this trip ". mysqli_error($connection)); //if the query returns an error kill the query connection
 } else {
  header('Location: creatbooking.php'); //stays on the createbooking page
  exit;
 }

 mysqli_free_result($result);
?>
