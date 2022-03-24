<!-- Creates a selectable table in the main webpage that shows all information about db passengers in order of tehir last names -->

<!DOCTYPE html>
<html>
<head>
<title>Navigation For Newbies</title>
<link rel="stylesheet" type="text/css" href="bustrips.css">
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
</head>
<style>
table, th, td {
  border: 1px solid DarkSlateGrey;
}
</style>
<body>

<h3>Select A Passenger To See Their Bookings:</h3>

<?php
 include "connecttodb.php";

 $query = 'SELECT passenger.passengerid AS passid, firstname, lastname, passportnum FROM passenger JOIN passport WHERE passenger.passengerid=passport.passengerid ORDER BY lastname;';
 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed.");
 }

echo '<form action="passbookings.php" method="post">';
echo '<table style="width:60%">';
 echo '<tr>';
  echo '<th>' . "   " . '</th>';
  echo '<th>' . "Passenger ID" . '</th>';
  echo '<th>' . "First Name" . '</th>';
  echo '<th>' . "Last Name" . '</th>';
  echo '<th>' . "Passport Number" . '</th>';
 echo '</tr>';
 while ($row = mysqli_fetch_assoc($result)) {
    echo '<tr><td>' . '<input type="radio" name="passengerid" value="' . $row[passid] . '"></td>'; //makes the table selectable and the selection holds the passengerid
    echo '<td>'. $row[passid] . '</td>' . '<td>' . $row[firstname] . '</td>' .  '<td>' . $row[lastname] . '</td>' .  '<td>' . $row[passportnum] . '</td></tr>';
  }
echo '</table>';
echo '<br>';
echo '<input type="submit" value="Passenger bookings">';
echo '</form>';

 mysqli_free_result($result);
?>

</body>
</html>
