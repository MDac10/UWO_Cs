<?php
 session_start(); //opens session/pipe for data
?>
  
  <?php
 include "connecttodb.php";

 if(isset($_POST["insert"])){
  $value = $_POST["insert"];
  $query = 'UPDATE bustrip SET ' . $_SESSION["attr"] . '="' . $value . '" WHERE tripid=' . $_SESSION["tid"] . ';'; //uses the data found to update the given trip
  $result = mysqli_query($connection,$query);

  if (!$result) {
    die ("Error while trying to change this trip\n". mysqli_error($connection));
  } else {
   header('Location: bustrips.php'); //goes back to the tripinfo page
   exit;
  }

 mysqli_free_result($result);
 }
?>
