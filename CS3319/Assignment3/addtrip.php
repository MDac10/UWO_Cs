<!-- This was supposed to add the values input in the main file bustrip.php into the database (doesnt work for some reason) -->
<!DOCTYPE html>
<html>
 <head>
  <title>Navigation For Newbies</title>
   <link rel="stylesheet" type="text/css" href="bustrips.css">
   <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
 </head>
 <body>

<?php
 include "connecttodb.php";

  $id=$_POST["tripid"]; //these values were all input by the user in the main webpage (bustrips.php)
  $name=$_POST["tripname"];
  $start=$_POST["startdate"];
  $endd=$_POST["enddate"];
  $country=$_POST["country"];
  $bus=$_POST["pickabus"];
  $image=$_POST["urlimage"];

  $query = 'INSERT INTO bustrip VALUES(' . $id . ',"' . $name . '","' . $start . '","' . $endd . '","' . $country . '","' . $bus . '","' . $image . '");';
 echo $query;

  $test = 'SELECT * FROM bustrip WHERE tripid=' . $id . ';'; //query used to check if the trip already exists
  $result = mysqli_query($connection, $test);

  if($result){
    echo '<br>';
   echo "This trip already exists, please try another one."; //if the tripid is already being used, asks user to try again
   echo '<br>';
    mysqli_free_result($result);
  } else {
    mysqli_free_result($result);
    $result = mysqli_query($connection, $query);
    if (!$result) {
      die ("Error while trying to add this trip ". mysqli_error($connection));
    } else {
      echo "Your trip has been added!";
      exit;
    }
  }

 mysqli_free_result($result);

?>
  
  </body>
  </html>
