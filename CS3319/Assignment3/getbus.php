<?php
 $query = "SELECT licenseplate FROM bus";
 $result = mysqli_query($connection,$query);
 if (!$result) {
 die("databases query failed.");
 }
 while ($row = mysqli_fetch_assoc($result)) {
  echo '<option value="' . $row[licenseplate] . '">' . $row[licenseplate] . '</option>'; //iterates through all existing busses and lists them in the dropdown menu
 }
 mysqli_free_result($result);
?>

