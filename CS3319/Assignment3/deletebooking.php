<?php
  session_start(); //opens a session/pipe so that certain data can be accessed from other functions that are not directly linked
?>
  
  <!-- Shows all the bookings that exist and gives the user the option to delete a selected one -->

<!DOCTYPE html>
<html>
<head>
<title>Navigation For Newbies</title>
<link rel="stylesheet" type="text/css" href="bustrips.css">
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
</head>
  
  <!-- Styling for the table -->
  
  <style>
   table, th, td {
   border: 1px solid DarkSlateGrey;
   }
  </style>
  
<body>
    
    <form action="back.php">
       <input type="submit" value="Back">
    </form>

  <h2>Select A Booking To Delete</h2>
  
  <?php
    include "connecttodb.php";
  
     //this query shows all necessary information from a JOIN of passenger, booking, and bustrip table from database
    $query = 'SELECT tid, passenger.passengerid AS passengerid, firstname, lastname, tripname, country, price FROM (SELECT booking.tripid AS tid, passengerid, tripname, country, price FROM booking JOIN bustrip WHERE booking.tripid=bustrip.tripid) AS binfo JOIN  passenger WHERE binfo.passengerid=passenger.passengerid;';
  
    $result = mysqli_query($connection,$query);
  
    if (!$result) {
     die("databases query failed.");
    }

    echo '<form action="delete.php" method="post">'; //the users selecetion is sent to the delete function
    echo '<table style="width:70%">';
     echo '<tr>';
      echo '<th>' . "   " . '</th>';
      echo '<th>' . "Trip ID" . '</th>';
      echo '<th>' . "Trip Name" . '</th>';
      echo '<th>' . "Passenger ID" . '</th>';
      echo '<th>' . "First Name" . '</th>';
      echo '<th>' . "Last Name" . '</th>';
      echo '<th>' . "Country" . '</th>';
      echo '<th>' . "Price" . '</th>';
    echo '</tr>';
    while ($row = mysqli_fetch_assoc($result)) {
      echo '<tr><td>' . '<input type="radio" name="delsel" value=' . $row[tid] . ',' . $row[passengerid] . '></td>';
      echo '<td>'. $row[tid] . '</td>' . '<td>' . $row[tripname] . '</td>' .  '<td>' . $row[passengerid] . '</td>' .  '<td>' . $row[firstname] . '</td>' .  '<td>' . $row[lastname] . '</td>' .  '<td>' . $row[country] . '</td>' . '<td>' . $row[price] . '</td></tr>';
    }
    echo '</table>';

    echo '<br>';
    echo '<input type="submit" value="Delete this booking" onclick="deletebooking()">'; //tells user when the deletion occurs
    echo '<script>';
      echo 'function deletebooking() {confirm("Deleting this booking");}';
   echo '</script>';
    echo '</form>';

   mysqli_free_result($result);
  ?>

</body>
</html>
