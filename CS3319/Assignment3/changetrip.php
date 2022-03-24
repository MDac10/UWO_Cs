<?php
 session_start(); //opens a session/pipe so tripid can be passed to another function
?>

  <!-- Shows user the field they selected and gives then the option to change it -->
  
<!DOCTYPE>
<html>
<head>
<title>Trip Info Change</title>
</head>
<link rel="stylesheet" type="text/css" href="bustrips.css">
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
<body>
  
  <form action="back.php">
    <input type="submit" value="back">
  </form>

<h2>Change Trip Info</h2>

<?php
 $update = $_POST["changed"];
 $_SESSION["attr"] = $update; //sends the attribute to be changed into the pipe to be used in updatetrip.php
 echo '<form action="updatetrip.php" method="post">';
 echo '<br>'; 

 if ($update == "tripname"){ //Depending on what the user selected, their prompt will be different
   echo $id . " New Trip Name: " . '<input type="text" name="insert">' . '<br>';
 } else if($update == "startdate"){
   echo "New Start Date (YYYY-MM-DD): " . '<input type="date" name="insert">' . '<br>';
 } else if($update == "endate"){
   echo "New End Date (YYYY-MM-DD): " . '<input type="date" name="insert">' . '<br>';
 } else if($update == "urlimage"){
   echo "New Trip Image: " . '<input type="text" name="insert">' . '<br>';
 }

  echo'<input type="submit" value="Change info" onclick="updated()">'; //sends a message to user after the item has been updated
  echo '<script>';
    echo 'function updated() {confirm("Trip has been updated!");}';
  echo '</script>';
 echo '</form>';
?>

</body>
</html>
