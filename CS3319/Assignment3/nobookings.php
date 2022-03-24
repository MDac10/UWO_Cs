<?php //lists all the trips that have no bookings
 include "connecttodb.php";

 $query = 'SELECT DISTINCT bustrip.tripid, tripname FROM bustrip LEFT JOIN booking ON bustrip.tripid=booking.tripid WHERE booking.tripid IS NULL;'; //JOINS eveyrthing between burstrip and booking (LEFT JOIN) and returns all those that have a booking.tripis as NULL which indicates no bookings
 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed.");
 }

echo '<ul>';
 while ($row = mysqli_fetch_assoc($result)) {
    echo '<li>' . "Trip " . $row[tripid] . " - " . $row[tripname] . '</li>'; //Shows the data in an unorganized list
  }
echo '</ul>';

 mysqli_free_result($result);
?>
