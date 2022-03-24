<?php  //deletes a selected booking
  include "connecttodb.php";

 $deletion = explode(",", $_POST["delsel"]); // array holding delsel values
 $trip = $deletion[0]; //holds the tripid 
 $pass = $deletion[1]; //holds the passengerid

 $query = 'DELETE FROM booking WHERE tripid=' . $trip . ' AND passengerid=' . $pass . ';';
 
 $result = mysqli_query($connection,$query);
  
 if (!$result) {
   echo $query . '<br>';
   die ("Error while trying to delete this booking ". mysqli_error($connection));
 } else {
   header('Location: bustrips.php'); //goes back to the bustrips page
   exit;
 }

 mysqli_free_result($result);
?>
