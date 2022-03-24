<?php
  session_start(); //holds the tripid needed to perform the trip deletion
  
  include "connecttodb.php";

  $query = 'DELETE FROM bustrip WHERE tripid=' . $_SESSION["tid"] .';';
 
  $result = mysqli_query($connection,$query);
  
  if (!$result) {
    echo ' This trip still has bookings. Please select a trip with no bookings to delete.'; //if an error is thrown the webpage shows the error and prints this message
  } else {
   header('Location: bustrips.php'); //goes back to the bustrips page
   exit;
  }
?>
