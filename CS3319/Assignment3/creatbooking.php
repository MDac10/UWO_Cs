<!-- Creates trip booking --> 
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="bustrips.css">
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
</head>

  <!-- styling for table -->
  
<style>
table, th, td {
  border: 1px solid DarkSlateGrey;
}
</style>

<body>
  
<form action="back.php">
 <input type="submit" value="Back">
</form>

<h2>Create A Booking</h2>
<h3>Select A Trip To Book</h3>
  
  <!-- Gets user to select an existing passenger, an existing trip, and input a price and sends those values to addbooking.php -->

<form action="addbooking.php" method="post">

 <?php
  include "connecttodb.php";

  $query = 'SELECT passnum, tid, tripname, licenseplate, capacity FROM (SELECT DISTINCT COUNT(passengerid) AS passnum, bustrip.tripid AS tid, tripname, assignedbus FROM bustrip LEFT JOIN booking ON bustrip.tripid=booking.tripid GROUP BY bustrip.tripid) AS pcount JOIN bus WHERE pcount.assignedbus=bus.licenseplate;';
  $result = mysqli_query($connection,$query);
  
  if (!$result) {
   die("databases query failed.");
  }

  echo '<table style="width:60%">'; //table design
   echo '<tr>';
    echo '<th>' . "  " . '</th>';
    echo '<th>' . "Trip ID" . '</th>';
    echo '<th>' . "Trip Name" . '</th>';
    echo '<th>' . "Current Number of Bookings" . '</th>';
    echo '<th>' . "Capacity" . '</th>';
   echo '</tr>';
   while ($row = mysqli_fetch_assoc($result)) {
    echo '<tr><td>' . '<input type="radio" name="tripid" value="' . $row[tid] . '">' . '</td>'; //makes one of the sections of each row of the table a radio button that links to tripid
    echo '<td>' . $row[tid] . '</td>';
    echo '<td>' . $row[tripname] . '</td>';
    echo '<td>' . $row[passnum] . '</td>';
    echo '<td>' . $row[capacity] . '</td></tr>';
   }
  echo '</table>';

  mysqli_free_result($result);
 ?>

 <h3>Select A Passenger For Your Booking:</h3>

 <?php
  include "connecttodb.php";

  $query = 'SELECT * FROM passenger;';
  $result = mysqli_query($connection,$query);
  
  if (!$result) {
   die("databases query failed.");
  }

  echo '<table style="width:32%">';
   echo '<tr>';
    echo '<th>' . "   " . '</th>';
    echo '<th>' . "Passenger ID" . '</th>';
    echo '<th>' . "First Name" . '</th>';
    echo '<th>' . "Last Name" . '</th>';
   echo '</tr>';
   while ($row = mysqli_fetch_assoc($result)) {
    echo '<tr><td>' . '<input type="radio" name="passengerid" value="' . $row[passengerid] . '">' . '</td>'; //makes one of the sections of each row of the table a radio button that links to passengerid
    echo '<td>' . $row[passengerid] . '</td>';
    echo '<td>' . $row[firstname] . '</td>';
    echo '<td>' . $row[lastname] . '</td></tr>';
   }
  echo '</table>';
 
  mysqli_free_result($result);
 ?>

 <h3>Set Price For Trip:</h3>

   <!-- user can input any numerical value greater than 0 as the price value -->
  Trip Price: $<input type="number" name="price" min="0">

  <br><br>

 <input type="submit" value="Book">
</form>

</body>
</html>

