<?php
 $country = $_POST["countrysel"]; //holds the country that user selected from dropdown menu

 $query = 'SELECT tripid, tripname, urlimage FROM bustrip WHERE country="' . $country . '";'; 
 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed."); //message if teh above query returns an error
 }

 echo '<h3>' . "Trips From This Country: " . '</h3>';

 while ($row = mysqli_fetch_assoc($result)) {
    echo '<hr>';
    echo  "Trip ID: " . $row[tripid] . " Trip Name: " .  $row[tripname] . " in " . $country . "<br>"; //in main webpage, the trips related to the selected country are displayed
    echo '<img src="' . $row["urlimage"] . '"height="250" width="250">';
    echo '<br>';
  }

 mysqli_free_result($result);
?>
