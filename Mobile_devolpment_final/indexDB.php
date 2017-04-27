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

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>


    <h1>Martin Scorsese's Film History</h1>

    <h2>Click <a href="movieDB.php">Here</a> If You Want to View Scorses's Film History</h2>
    <h2>Click <a href="updateDB.php">Here</a> If You Want to Update Content on the Database</h2>
    
    <!-- Add information to the database -->

    <!-- Add an Actor Form -->
    <div class="formBox">
    <h3>Add an Actor </h3>
    <form method="POST"  action="indexDB.php">
    <p>First Name: <input type="text" name="FirstName" /></p>
    <p>Last Name: <input type="text" name="LastName" /></p>
    <p>Date of Birth: <input type="date" name="DOB" /></p>
    <p>Date of Death: <input type="date" name="DOD" /></p>
    <p>From the city: <input type="text" name="City" /></p>
    <p>From the state: <input type="text" name="State" /></p>
    <button type="submit" name="actorButton">Add Actor</button>
    </form>
    </div>

    <!-- Add a Studio Form -->
    <div class="formBox">
    <h3>Add a Studio</h3>
    <form method="POST"  action="indexDB.php">
    <p>Name: <input type="text" name="StudioName" /></p>
    <p>HQ Location: <input type="text" name="HQ" /></p>
    <p>Founded: <input type="date" name="Founded" /></p>
    <button type="submit" name="studioButton">Add Studio</button>
    </form>
    </div>

    <br>

    <!-- Add a Movie Form -->
    <div class="formBox">
    <h3>Add a movie </h3>
    <form method="POST"  action="indexDB.php">
    <p>Title <input type="text" name="MovieTitle" /></p>
    <p>Budget: <input type="number" name="Budget" /></p>
    <p>Release Date: <input type="date" name="RelDate" /></p>
    <p>Genre: <input type="text" name="Genre" /></p>
    <p>Rating: <input type="text" name="Rating" /></p>
    <p>Number of Golden Globes Won: <input type="number" name="GG" /></p>
    <p>Number of Oscars Won: <input type="number" name="Oscar" /></p>
    <p>Studio: <select name="MovieStudio"> 
   
    <?php
    //Establish connection to DB
    $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
        echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
    } 
    if(!($stmt = $mysqli->prepare("SELECT studio_id, name FROM studios"))){
    echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
    }

    if(!$stmt->execute()){
        echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    if(!$stmt->bind_result($studioID, $studioName)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $studioID . ' "> ' . $studioName . '</option>\n';
    }
    $stmt->close();

    //Close connection to the databse
    mysqli_close($mysqli);      
    ?>
    </select> </p>
    <button type="submit" name="movieButton">Add Movie</button>
    </form>
    </div>

    <!-- Add a Character Form -->
    <div class="formBox">
    <h3>Add a Character </h3>
    <form method="POST"  action="indexDB.php">
    <p>First Name: <input type="text" name="CharFirstName" /></p>
    <p>Last Name: <input type="text" name="CharLastName" /></p>
    <p>Select Actor that portrayed the character: <select name="CharActorID">

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
    if(!$stmt->bind_result($actId, $actFname, $actLname)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $actId . ' "> ' . $actFname . ' '  . $actLname . '</option>\n';
    }
    $stmt->close();

    //Close connection to the databse
    mysqli_close($mysqli);     
    ?>

     </select></p>
        <p>Movie title they appeared in: <select name="CharFilmID" />

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
    if(!$stmt->bind_result($filmID, $filmTitle)){
        echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
    }
    while($stmt->fetch()){
        echo '<option value=" '. $filmID . ' "> ' . $filmTitle . '</option>\n';
    }
    $stmt->close();

    //Close connection to the databse
    mysqli_close($mysqli);      
    ?>
    </select></p>
    <p>Did they win an Oscar?: </p><input type="radio" name="OscarWin" value="1"/> Yes
    <input type="radio" name="OscarWin" value="0"/> No</p>
    <p>Did they win a Golden Globe?: </p><input type="radio" name="GlobeWin" value="1"/> Yes
    <input type="radio" name="GlobeWin" value="0"/> No</p>
    <button type="submit" name="charButton">Add Character</button>
    </form>
    </div>
    
    <!-- Add a Relationships between Movies and Actors Form -->
    <div class="formBox">
    <h3>Add Actor with Movie </h3>
    <form method="POST"  action="indexDB.php">
    <p>Actor Name: <select name="ActorFilmID">

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
    //Close connection to the databse
     mysqli_close($mysqli);     
     ?>

     </select></p>
        <p>Film Name: <select name="FilmActorId" />

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

    //Close connection to the databse
    mysqli_close($mysqli);      
    ?>
    </select></p>
    <button type="submit" name="actFilmButton">Add Actor with Film</button> 
    </form>
    </div>

    <br>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>

<?php

    //Check if any of the form buttons were clicked
    if (isset($_POST['actorButton']))
    {
        addActor();
        unset($_POST['actorButton']);
    }
    else if (isset($_POST['studioButton']))
    {
        addStudio();
        unset($_POST['studioButtonn']);
    }
    else if (isset($_POST['movieButton']))
    {
        addMovie();
        unset($_POST['movieButton']);
    }
    else if (isset($_POST['charButton']))
    {
        addChar();
        unset($_POST['charButton']);
    }
    
     else if (isset($_POST['actFilmButton']))
    {
        addActFilm();
        unset($_POST['actFilmButton']);
    }

//This function will connect to the database and add an actor
function addActor()
{
    //Establish connection to DB
    $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
        echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
    } 

    //Store movie inputs as a variable
    $FName= $_POST['FirstName'];
    $LName = $_POST['LastName'];
    $DOB = $_POST['DOB'];
    $DOD = $_POST['DOD'];
    $City= $_POST['City'];
    $State = $_POST['State'];

    //Check if the user provided the necessary values
    if (empty($FName) or empty($FName))
    {
        $emptyActor= "You must enter the first and last name of an actor";
        echo "<script type='text/javascript'>alert('$emptyActor');</script>>";
        return;
    }

    //if date of death is left blank set to null
    if (empty($DOD)){
        $DOD = NULL;
    }
    
    //Insert the actor into the table
    if (!($stmt = $mysqli->prepare("INSERT INTO actors(fname,lname,dob,dod,state,city) VALUES (?,?,?,?,?,?)"))) 
    {
        echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
    }
    if (!$stmt->bind_param("ssssss",$FName,$LName,$DOB,$DOD,$State,$City)) 
    {
        echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
    }
    if (!$stmt->execute()) 
    {
        echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
    }

    //succesfully entered actor
    $successActor= "Actor succesfully added.";
    echo "<script type='text/javascript'>alert('$successActor');</script>>";
    
    /* explicit close recommended */
    $stmt->close();

   //Close connection to the databse
   mysqli_close($mysqli);

}

//This function will connect to the database and add a studio
function addStudio()
{
    //Establish connection to DB
    $mysqli =  new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
       echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
    } 

    //Store movie inputs as a variable
    $SName= $_POST['StudioName'];
    $HQ = $_POST['HQ'];
    $Found = $_POST['Founded'];

     //Check if the user provided the necessary values
    if (empty($SName))
    {
        $emptyStudio= "You must enter a name for the studio";
        echo "<script type='text/javascript'>alert('$emptyStudio');</script>>";
        return;
    }
    
    //if hq or founded are blank set to NULL
    if (empty($HQ))
    {
        $HQ = NULL;
    }

    if (empty($Found))
    {
        $Found = NULL;
    }
    
    //Insert the studio into the table
    if (!($stmt = $mysqli->prepare("INSERT INTO studios(name,hq,founded) VALUES (?,?,?)"))) 
    {
        echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
    }
    if (!$stmt->bind_param("sss",$SName,$HQ,$Found)) 
    {
        echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
    }
    if (!$stmt->execute()) 
    {
        echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
    }
       
    //succesfully entered studio
    $successStudio= "Studio succesfully added.";
    echo "<script type='text/javascript'>alert('$successStudio');</script>>";

    /* explicit close recommended */
    $stmt->close();

    //Close connection to the databse
    mysqli_close($mysqli);
}

//This function will connect to the database and add a movie
function addMovie()
{
    //Establish connection to DB
    $mysqli =  new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
    if ($mysqli->connect_errno) {
      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
    } 

    //Store movie inputs as a variable
    $MTitle = $_POST['MovieTitle'];
    $Budget = $_POST['Budget'];
    $Release = $_POST['RelDate'];
    $Genre = $_POST['Genre'];
    $Rating = $_POST['Rating'];
    $GG = $_POST['GG'];
    $Oscar = $_POST['Oscar'];
    $MStudio = $_POST['MovieStudio'];
 
    //Insert the movie into the table
    if (!($stmt = $mysqli->prepare("INSERT INTO films(title,released,budget,genre,rating,globe,oscar,studio_id) VALUES (?, ?, ?, ?,?,?,?,?)"))) 
    {
        echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
    }
    if (!$stmt->bind_param("ssissiii", $MTitle, $Release,$Budget,$Genre,$Rating,$GG,$Oscar,$MStudio)) 
    {
        echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
    }
    if (!$stmt->execute()) 
    {
        echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
    }
    
    //succesfully entered movie
    $successMovie= "Movie succesfully added.";
    echo "<script type='text/javascript'>alert('$successMovie');</script>>";

    /* explicit close recommended */
    $stmt->close();

    //Close connection to the databse
    mysqli_close($mysqli);

}

//This function will connect to the database and add a character
function addChar()
{
    //Establish connection to DB
        $mysqli =  new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
        if ($mysqli->connect_errno) {
            echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
        } 

        //Store character inputs as a variable
        $CFName = $_POST['CharFirstName'];
        $CLName = $_POST['CharLastName'];
        $CActID = $_POST['CharActorID'];
        $CFilmID = $_POST['CharFilmID'];
        $COscar = $_POST['OscarWin'];
        $CGlobe = $_POST['GlobeWin'];
        
        //Check if the user provided the necessary values
        if (empty($CFName))
        {
            $emptyCActor= "You must enter the first name of the character";
            echo "<script type='text/javascript'>alert('$emptyCActor ');</script>>";
            return;
        }

        //Insert the character into the table
        if (!($stmt = $mysqli->prepare("INSERT INTO characters (fname, lname, globe_win, oscar_win, actor_id, film_id) VALUES (?, ?, ?, ?,?,?)"))) 
        {
            echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
        }
        if (!$stmt->bind_param("ssiiii", $CFName, $CLName,$CGlobe,$COscar,$CActID,$CFilmID)) 
        {
            echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
        }
        if (!$stmt->execute()) 
        {
            echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
        }

        //succesfully entered movie
        $successCharacter = "Character succesfully added.";
        echo "<script type='text/javascript'>alert('$successCharacter');</script>>";
        
        //explicit close recommended 
        $stmt->close();

        //Close connection to the databse
        mysqli_close($mysqli);
}

//This function will connect to the database and add a relationship between a film and actor
function addActFilm(){
    //Establish connection to DB
        $mysqli =  new mysqli("oniddb.cws.oregonstate.edu", "araujoj-db", "GswKHgOfjbTdm6sB", "araujoj-db");
        if ($mysqli->connect_errno) {
            echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
        } 
    
    //store actor and film variables
    $AFActID = $_POST['ActorFilmID'];
    $AFFilmID = $_POST['FilmActorId']; 
    
    //Insert the character into the table
        if (!($stmt = $mysqli->prepare("INSERT INTO have (actor_id, film_id) VALUES (?, ?)"))) 
        {
            echo "Prepare failed: (" . $mysqli->errno . ") " . $mysqli->error;
        }
        if (!$stmt->bind_param("ii",$AFActID, $AFFilmID )) 
        {
            echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
        }
        if (!$stmt->execute()) 
        {
            echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
        }

        //succesfully entered movie
        $successHave = "Actor with Film succesfully added.";
        echo "<script type='text/javascript'>alert('$successHave');</script>>";
        
        //explicit close recommended 
        $stmt->close();

        //Close connection to the databse
        mysqli_close($mysqli);
}
?>
