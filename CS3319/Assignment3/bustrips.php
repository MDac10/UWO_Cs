<!-- Main webpage titles Naviagtion for Newbies -->

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
?>
  
<h1 style="text-align:center;">Navigation For Newbies</h1>
  
<img src="https://c.tenor.com/h8C3UimgNwoAAAAC/the-hobbit-adventure.gif"
width="500" height="295" class="center">
  <hr>
  
<!-- Two radio buttons to be selected to organize trips in list -->
  
<h2> Trips We Offer:</h2>
 Sort By:
<br>
  
  <!-- The input is sent to getbustrips.php to organize the trip list -->
  
<form action="getbustrips.php" method="post">
  <input type="radio" id="tripname" name="sortby" value="tripname">
  <label for="tripname">Trip Name</label>
  <input type="radio" id="country" name="sortby" value="country">
  <label for="country">Country</label>

  <br><br>

In (order):
<br>
  <input type="radio" id="asc" name="ascdesc" value="asc">
  <label for="asc">Ascending</label>
  <input type="radio" id="desc" name="ascdesc" value="desc">
  <label for="desc">Descending</label>  
  
  <br><br>
  
  <input type="submit" value="See Trips">
</form>
  
  <br>
<hr>

    <!-- Drop down menu to select a country to see trip information on -->
    
<h2>See Bus Trips Per Country</h2>
 See Bus Trips:
  <form action="" method="post">
   <select name="countrysel">
    <option value="1"> Select A Country </option><br>
    <?php
     include "countrytrips.php";
    ?>
   </select>
   <input type="submit" value="See trips">
  </form>

<br>

 <?php
  if(isset($_POST["countrysel"])){
   include "connecttodb.php";
   include "countryinfo.php";
  }
 ?>

<hr>

   <!-- Directs user to creatbooking.php page if they want to make a booking -->
   
<h2>Create A Booking</h2>
<form action="creatbooking.php">
  <input type="submit" value="Make a booking!">
</form>

<hr>
     
     <!-- Shows passenger information which is selectable -->

<h2>Passenger Information</h2>
<?php
 include "passengers.php";
?>
<br>

<hr>
  
  <!-- User selects the button to choose a booking to delete -->

<h2> Delete A Booking</h2>
  <form action="deletebooking.php">
    <input type="submit" value="Delete a booking">
  </form>
    
<br>

<hr>

  <!-- Lists all trips with no bookings -->
  
<h2>Bus Trips With No Bookings</h2>
<?php
 include "nobookings.php";
?>

<hr>

<h2> Add A Trip To Our Catalog:</h2>

  <!-- Allows user to enter all information necessary to input a new trip to the database -->
  
<form action="addtrip.php" method="post">
  Trip ID: <input type="number" name="tripid"/><br>
  Trip Name: <input type="text" name="tripname"/><br>
  Start Date (YYYY-MM-DD): <input type="date" name="startdate"/><br>
  End Date (YYYY-MM-DD): <input type="date" name="enddate"/><br>
  Country: <input type="text" name="country"/><br>
  Bus:
   <form action="" method="post">
    <select name="pickabus">
     <option value="1">Select Bus</option><br>
     <?php
      include "getbus.php";
     ?>
    </select>
   </form>
  Trip Image (URL): <input type="text" name="urlimage" value="https://i.kym-cdn.com/entries/icons/facebook/000/019/588/No_idea.jpg"/><br> 
  <input type="submit" value="Click here to add a new trip!"/>
</form>
      
  <br>

<hr>

<?php
 mysqli_close($connection);
?>
 </body>
</html>
