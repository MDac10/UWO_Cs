<!-- Shows all the trip bookings a selected passenger has -->

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

<h2>Passenger Bookings</h2>

<?php
 include "connecttodb.php";
 
 $pass = $_POST["passengerid"]; //user selected a passenger on the main webpage and the passengerid was passed on

//query finds all thenecessary information about bookings that a passenger has
 
 $query = 'SELECT passid, passbooks.tripid AS tid, price, tripname FROM (SELECT passenger.passengerid AS passid, tripid, price FROM passenger JOIN booking WHERE passenger.passengerid=booking.passengerid AND passenger.passengerid=' . $pass . ') AS passbooks JOIN bustrip WHERE passbooks.tripid=bustrip.tripid;';
 $result = mysqli_query($connection,$query);

 if (!$result) {
 die("databases query failed.");
 }

 echo '<ul>';
 while ($row = mysqli_fetch_assoc($result)) {
    echo '<li>' . "Trip " . $row[tid] . " - " . $row[tripname] . " with price $" . $row[price] . '</li>'; //shows the data in an unorganized list
  }
 echo '</ul>';

 mysqli_free_result($result);
?>

</body>
</html>
