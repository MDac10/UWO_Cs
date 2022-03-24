<?php  //I didn't actually use this file for anything but bitbucket wouldn't let me delete it
  $allowedExts = array("gif", "jpeg", "jpg", "png");
  $temp = explode(".", $_FILES["file"]["name"]);
  $extension = end($temp);  
  $extension = strtolower($extension);
  $uploadholder = dirname(__FILE__) . "/tripimages";
  if ((($_FILES["file"]["type"] == "image/gif")
      || ($_FILES["file"]["type"] == "image/jpeg")
      || ($_FILES["file"]["type"] == "image/jpg")
      || ($_FILES["file"]["type"] == "image/pjpeg")
      || ($_FILES["file"]["type"] == "image/x-png")
      || ($_FILES["file"]["type"] == "image/png")
      || ($_FILES["file"]["type"] == "NULL"))
      && ($_FILES["file"]["size"] < 500000)
      && in_array($extension, $allowedExts)) {
            if ($_FILES["file"]["error"] > 0) {
                        echo "Return Code: " . $_FILES["file"]["error"] . "<br>";
            } else {
                        if (file_exists("tripimages/" . $_FILES["file"]["name"])) {
                                    echo '<p><hr>';
                                    echo $_FILES["file"]["name"] . " already exists. ";
                                    echo '<p><hr>';
                                    $trippic = "NULL";
                        } else {
                                    move_uploaded_file($_FILES["file"]["tmp_name"],"tripimages/" . $_FILES["file"]["name"]);
                                    $trippic = "tripimages/" . $_FILES["file"]["name"];
                        }
            }
     } else {
            echo "Invalid file";
    }
?>
