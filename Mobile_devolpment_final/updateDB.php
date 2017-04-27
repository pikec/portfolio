<?php
include 'storedInfo.php';
ini_set('display_errors', 'On');
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <title>Martin Scorsese Database</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <h1>Martin Scorsese's Film History</h1>
    <h2>Click <a href="indexDB.php">Here</a> If You Want to Add Content to the Database</h2>
    <h2>Click <a href="movieDB.php">Here</a> If You Want to View Scorses's Film History</h2>
    
    <!-- Update content in the database -->
    <div class="DisplayBox">
    <form method="POST"  action="updateDB.php">
    <h3>Update this movie's genre </h3><p>Film Name: <select name="FilmId" /> 
    </div>
    <?php
     //Establish connection to DB
    $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
        echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
     } 
     if(!($stmt = $mysqli->prepare("SELECT film_id, title FROM films"))){
        echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    }

    if(!$stmt->execute()){
        echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    if(!$stmt->bind_result($ActFilmID, $ActFilmTitle)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $ActFilmID . ' "> ' . $ActFilmTitle . '</option>\n';
    }
    $stmt->close();

    //Close connection to the database
    mysqli_close($mysqli);      
    ?>
    </select></p>
    Genre: <input type="text" name="genreSelect">
    <button type="submit" name="UpdateFilmButton">Update the genre!</button> 
    </form>

    <!-- Update content in the database -->
    <div class="DisplayBox">
    <form method="POST"  action="updateDB.php">
    <h3>Update this actor's homestate </h3><p>Actor Name: <select name="ActId" /> 
    </div>
    <?php
     //Establish connection to DB
    $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
        echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
     } 
     if(!($stmt = $mysqli->prepare("SELECT actor_id, fname, lname FROM actors"))){
        echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    }

    if(!$stmt->execute()){
        echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    if(!$stmt->bind_result($ActID, $ActFname, $ActLname)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $ActID . ' "> ' . $ActFname. ' '  . $ActLname . '</option>\n';
    }
    $stmt->close();

    //Close connection to the database
    mysqli_close($mysqli);      
    ?>
    </select></p>
    State: <input type="text" name="stateSelect">
    <button type="submit" name="UpdateStateButton">Update the state!</button> 
    </form>

    <!-- Delete actor from the database -->
    <div class="DisplayBox">
    <form method="POST"  action="updateDB.php">
    <h3>Delete this actor from the database </h3><p>Actor: <select name="ActorID" />     
    </div>
    <?php
    //Establish connection to DB
     $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
       echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
      } 
    if(!($stmt = $mysqli->prepare("SELECT actor_id, fname, lname FROM actors"))){
    echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    }

    if(!$stmt->execute()){
        echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    if(!$stmt->bind_result($filmActId, $filmActFname, $filmActLname)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $filmActId . ' "> ' . $filmActFname . ' '  . $filmActLname . '</option>\n';
    }
    $stmt->close();
    //Close connection to the database
     mysqli_close($mysqli);     
    ?>
    </select></p><button type="submit" name="DeleteActorButton">Delete the Actor</button> 
    </form>

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>

  <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>

<?php

  if (isset($_POST['UpdateFilmButton']))
  {
    UpdateFilms();
    unset($_POST['UpdateFilmButton']);
  }
  else if (isset($_POST['UpdateStateButton']))
  {
    UpdateState();
    unset($_POST['UpdateStateButton']);
  }
  else if (isset($_POST['DeleteActorButton']))
  {
    DeleteActor();
    unset($_POST['DeleteActorButton']);
  }

function UpdateFilms()
{
  //Establish connection to DB
  $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
  if ($mysqli->connect_errno) {
      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
  } 

  //Store movie inputs as a variable
  $GSelect= $_POST['genreSelect'];
  $FilmSelect = $_POST['FilmId'];

  //Check if the user provided the necessary values
  if (empty($GSelect))
  {
      $emptyG= "You must enter a genre";
      echo "<script type='text/javascript'>alert('$emptyG');</script>>";
      return;
  }

  //Update the film's genre
  if (!($stmt = $mysqli->prepare("UPDATE films Set genre = ? WHERE film_id = ?"))) 
  {
      echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
  }
  if (!$stmt->bind_param("ss",$GSelect,$FilmSelect)) 
  {
      echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
  }
  if (!$stmt->execute()) 
  {
      echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
  }

   //succesfully updated the genre
   $successGenre= "Movie genre succesfully updated.";
   echo "<script type='text/javascript'>alert('$successGenre');</script>>";
   
   /* explicit close recommended */
   $stmt->close();

  //Close connection to the databse
  mysqli_close($mysqli);

}

function UpdateState()
{
  //Establish connection to DB
  $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
  if ($mysqli->connect_errno) {
      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
  } 

  //Store actor inputs as a variable
  $sSelect= $_POST['stateSelect'];
  $aSelect = $_POST['ActId'];

  //Check if the user provided the necessary values
  if (empty($sSelect))
  {
      $emptyS= "You must enter a state";
      echo "<script type='text/javascript'>alert('$emptyS');</script>>";
      return;
  }

  //Update the actor's state
  if (!($stmt = $mysqli->prepare("UPDATE actors Set state = ? WHERE actor_id = ?"))) 
  {
      echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
  }
  if (!$stmt->bind_param("ss",$sSelect,$aSelect)) 
  {
      echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
  }
  if (!$stmt->execute()) 
  {
      echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
  }

   //succesfully updated the state
    $successState= "Actor state was succesfully updated.";
   echo "<script type='text/javascript'>alert('$successState');</script>>";
   
   /* explicit close recommended */
   $stmt->close();

  //Close connection to the databse
  mysqli_close($mysqli);
}

function DeleteActor()
{
  //Establish connection to DB
  $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
  if ($mysqli->connect_errno) {
      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
  } 

  //Store actor inputs as a variable
  $ASelect= $_POST['ActorID'];

  //Check if the user provided the necessary values
  if (empty($ASelect))
  {
      $emptyA= "You must enter select an actor";
      echo "<script type='text/javascript'>alert('$emptyA');</script>>";
      return;
  }

  //Delete the actor into the table
  if (!($stmt = $mysqli->prepare("DELETE FROM actors WHERE actor_id = ?"))) 
  {
      echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
  }
  if (!$stmt->bind_param("s",$ASelect)) 
  {
      echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
  }
  if (!$stmt->execute()) 
  {
      echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
  }

   //succesfully delete the actor
   $deleteGenre= "Actor succesfully deleted from the database.";
   echo "<script type='text/javascript'>alert('$deleteGenre');</script>>";
   
   /* explicit close recommended */
   $stmt->close();

  //Close connection to the databse
  mysqli_close($mysqli);

}

?>