<?php
 session_start(); //opens a session/pipe so that data can be retrieved from previous pages without a direct connection
?>

<!DOCTYPE>
<html>
<title>Trip Information</title>
<link rel="stylesheet" type="text/css" href="bustrips.css">
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@100&display=swap" rel="stylesheet">
<body>
  
  <form action="back.php">
    <input type="submit" value="back">
  </form>

<?php
 $tid = $_POST["selected"];
 $_SESSION["tid"] = $tid; //sends the tripid that was selected into the session
 include "connecttodb.php";

 $query = "SELECT * FROM bustrip WHERE tripid=$tid"; //query to get the information for a trip
 $result = mysqli_query($connection,$query);

 if (!$result) {
  die("databases query failed.");
 }

 $row = mysqli_fetch_assoc($result);

 echo '<h2 style=text-align:center;>' . "Current Information For this trip:" . '</h2>' . "<br>"; //prints all the necessary information about the selected trip on th enew page
 echo "<p style=text-align:center;>" . "Trip ID: " . $row[tripid] . "<br>" . "Trip Name: " . $row[tripname] . "<br>" . "Country: " . $row[country] . "<br>" . "Start Date: " . $row[startdate] . "<br>" . "End Date: " . $row[enddate] . "</p>" . "<br>";
 echo '<img src="' . $row["urlimage"] . '"height="350" width="350" class="center">';
 echo '<br>' . '<br>';

 echo '<hr>';

 echo '<h2 style=text-slign:center;>' . "Change A Detail About This Trip:" . '</h2>';

 echo '<form action="changetrip.php" method="post">'; //allows the user to select on of the allowable attributes to be changed 
  echo '<input type="radio" name="changed" value="tripname">' . "Trip Name" . '<br>';
  echo '<input type="radio" name="changed" value="startdate">' . "Start Date (yyyy-mm-dd): " . '<br>';
  echo '<input type="radio" name="changed" value="enddate">' . "End Date (yyyy-mm-dd): " . '<br>';
  if ($row[urlimage]=="https://www.meme-arsenal.com/memes/78e6ccda83d4af4c8b09c9ef916dca9d.jpg" || $row[urlimage]=="https://i.kym-cdn.com/entries/icons/facebook/000/019/588/No_idea.jpg" || $row[urlimage]==NULL){
   echo '<input type="radio" name="changed" value="urlimage">' . "Trip Image" . '<br>'; //if the image is null then this option for urlimage will be shown otherwise it will not
  }

 echo '<input type="submit" value="change this field">';
echo '</form>';
 
echo '<form action="deletetrip.php">'; //allows user to choose to delete this trip
 echo '<input type="submit" value="delete trip" onclick="confirmation()"/>';
    echo '<script>';
      echo 'function confirmation() {confirm("Are you sure you want to delete this trip?");}'; //confirms with the user if they are sure they want to attempt to delete the trip
   echo '</script>';
echo '</form>';

 mysqli_free_result($result);
?>

</body>
</html>
