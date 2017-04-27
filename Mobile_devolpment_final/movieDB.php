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
    <h2>Click <a href="indexDB.php">Here</a> If You Want to Add Content to the Database</h2>
    <h2>Click <a href="updateDB.php">Here</a> If You Want to Update Content on the Database</h2>
    <h3>Table Appears At The Bottom Of The Page</h3>

    <!-- #2. List the total number of oscars for by actor -->
  	<div class="DisplayBox">
  	<form method="POST"  action="movieDB.php">
  	<h3>Display the total number of Oscar's by actor</h3><p>Actor: <select name="ActorId2" /> 
  	</div>
	  <?php
	  
	   //Establish connection to DB
	  $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	  if ($mysqli->connect_errno) {
	      echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	   } 
	   if(!($stmt = $mysqli->prepare("SELECT actor_id, fname, lname FROM actors"))) {
	      echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
	  }

	  if(!$stmt->execute()){
	      echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
	  }
	  if(!$stmt->bind_result($ActorId2,$ActFname,$ActLname )){
	      echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
	  }
	  while($stmt->fetch()){
	      echo '<option value=" '. $ActorId2 . ' "> ' . $ActFname . ' '  . $ActLname . '</option>\n';
	  }
	  $stmt->close();

	  //Close connection to the databse
	  mysqli_close($mysqli);      
	  ?>
  	</select></p><button type="submit" name="DisActorSButton">Let's see the awards!</button> 
  	</form>

    <!-- List the films actor x has been in-->
    <div class="DisplayBox">
    <form method="POST"  action="movieDB.php">
  	<h3>Display movies that feature </h3><p>Actor <select name="ActorID" /> 
  	</div>
  	<?php
  	//Establish connection to DB
  	 $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
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
  	</select></p><button type="submit" name="DisFilmButton">Let's see the movies!</button> 
  	</form>

   	<!-- Display actors by movies -->
  	<div class="DisplayBox">
  	<form method="POST"  action="movieDB.php">
  	<h3>Display actors that appeared in </h3><p>Film Name: <select name="FilmId" /> 
  	</div>
	  <?php
	  
	   //Establish connection to DB
	  $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
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
  	</select></p><button type="submit" name="DisActorButton">Let's see the actors!</button> 
  	</form>

  	<!-- Display actor and movies by studios -->
  	<div class="DisplayBox">
  	<form method="POST"  action="movieDB.php">
  	<h3> List the first, last name of the actor and film titles where the character he/her played has one an oscar but no golden globe
  	and where the studio that released the film is </h3><p>Studio: <select name="StudioID"> 
  	</div>
  	 
    <?php
    //Establish connection to DB
    $mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
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

    </select></p><button type="submit" name="DisStudioButton">Let's see the actors and movies!</button> 
    </form>

    <!-- Display actors by characters  -->
    <div class="DisplayBox">
    <form method="POST"  action="movieDB.php">
  	<h3>Display the actor that portrayed </h3><p>Character <select name="CharSelectID" /> 
  	</div>
  	<?php
  	
  	//Establish connection to DB
  	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
  	if ($mysqli->connect_errno) {
  	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
  	} 
  	if(!($stmt = $mysqli->prepare("SELECT char_id, fname, lname FROM characters"))){
  	echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
  	}

  	if(!$stmt->execute()){
  	    echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
  	}
  	if(!$stmt->bind_result($charID, $charFName, $charLName)){
  	    echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
  	}
  	 while($stmt->fetch()){
        echo '<option value=" '. $charID . ' "> ' . $charFName . ' '  . $charLName. '</option>\n';
    }
  	$stmt->close();

  	//Close connection to the database
  	mysqli_close($mysqli);      
  	?>

  	</select></p><button type="submit" name="DisCActorButton">Let's see the actors!</button> 
  	</form>

  	<!-- list the characters that have won either an Oscar or Golden Globe -->
  	<div class="DisplayBox">
    <form method="POST"  action="movieDB.php">
  	<h3>Display the characters that have won an  </h3><p>Award <select name="AwardID"/>
  	<option value="1">Oscar</option>
  	<option value="2">Golden Globe</option>
  	</div>
  	</select></p><button type="submit" name="DisAwardButton">Let's see the characters!</button> 
  	</form>
 
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>

<?php


     if (isset($_POST['DisFilmButton']))
     {
     	DisplayFilms();
     	unset($_POST['DisFilmButton']);
     }
     
     else if (isset($_POST['DisActorSButton']))
     {
     	DisplayActorsAwards();
     	unset($_POST['DisActorSButton']);
     }
     else if (isset($_POST['DisActorButton']))
     {
     	DisplayActors();
     	unset($_POST['DisActorButton']);
     }
     else if (isset($_POST['DisStudioButton']))
     {
     	 DisplayStudioMovies();
     	 unset($_POST['DisStudioButton']);
     }
     else if (isset($_POST['DisCActorButton']))
     {
     	DisplayCharActor();
     	unset($_POST['DisCActorButton']); 
     }
     else if (isset($_POST['DisAwardButton']))
     {
     	DisplayAwards(); 
     	unset($_POST['DisAwardButton']); 
     }

// Display the total number of oscars by actor
function DisplayActorsAwards()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$ActorChoice = $_POST['ActorId2'];  //The ID of the Actor

	//Build the query to the database
	$result = $mysqli->query("SELECT act.fname, act.lname, SUM(chara.oscar_win) AS 'Oscars' FROM actors act
		INNER JOIN characters chara ON chara.actor_id = act.actor_id WHERE act.actor_id = '$ActorChoice'
		GROUP BY act.fname, act.lname ");

	//Build the table
	$rows = $result->num_rows;
	$title = array("First Name", "Last Name", "Total Oscars");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";

	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>";  //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 3; $j++) 
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>"; //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli); 
}

// Display the list of films by a given actor
function DisplayFilms()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$ActorSelect= $_POST['ActorID'];  //The ID of the Actor


	//Build the query to the database
	$result = $mysqli->query("SELECT f.title, f.released, f.genre, f.rating FROM films f
			INNER JOIN have h ON h.film_id = f.film_id
			INNER JOIN actors act ON act.actor_id = h.actor_id
			WHERE act.actor_id = '$ActorSelect' ORDER BY f.title ASC");

	//Build the table
	$rows = $result->num_rows;
	$title = array("Movie Title", "Release Date", "Genre", "Rating");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";

	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>";  //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 4; $j++) 
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>"; //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli); 
}


// Display the list of films by a given actor
function DisplayActors()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$MovieSelect = $_POST['FilmId'];  //The ID of the Films


	//Build the query to the database
	$result = $mysqli->query("SELECT a.fname, a.lname FROM actors a
			INNER JOIN have h ON h.actor_id= a.actor_id
			INNER JOIN films f ON f.film_id = h.film_id
			WHERE f.film_id = '$MovieSelect' ORDER BY a.actor_id ASC");

	//Build the table
	$rows = $result->num_rows;
	$title = array("First Name", "Last Name");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";

	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>"; //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 2; $j++)
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>"; //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli); 
}


 
// List the first, last name of the actor and film titles where the character he/her played has one an oscar but no golden globe
// and where the studio that released the film is
function DisplayStudioMovies()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$StudioSelect = $_POST['StudioID'];  //The ID of the Studio


	//Build the query to the database
	$result = $mysqli->query("SELECT act.fname, act.lname, f.title FROM actors act
		INNER JOIN characters chara ON chara.actor_id = act.actor_id
		INNER JOIN films f ON f.film_id = chara.film_id
		INNER JOIN studios stu ON stu.studio_id = f.studio_id
		WHERE chara.oscar_win = 1 AND chara.globe_win = 0 and stu.studio_id = '$StudioSelect'
		ORDER BY act.fname ASC");

	//Build the table
	$rows = $result->num_rows;
	$title = array("Actor-First Name ", "Actor-Last Name ", "Title ");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";

	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>"; //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 3; $j++)
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>";  //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli); 
}

//Display the actor who portrayed a certain character
function DisplayCharActor()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$CharSelect = $_POST['CharSelectID'];  //The ID of the Studio


	//Build the query to the database
	$result = $mysqli->query("SELECT a.fname, a.lname FROM actors a
	            INNER JOIN characters c ON c.actor_id=a.actor_id
	            WHERE c.char_id = '$CharSelect' ORDER BY a.actor_id ASC");

	//Build the table
	$rows = $result->num_rows;
	$title = array("First Name", "Last Name");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";

	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>"; //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 2; $j++)
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>";  //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli); 
}

//Display characters that won either an Oscar or Golden Globe
function DisplayAwards()
{
	//Establish connection to DB
	$mysqli = new mysqli("oniddb.cws.oregonstate.edu", "pikec-db", "F6YTD0RQ07ibl4Ns", "pikec-db");
	if ($mysqli->connect_errno) {
	    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	} 

	//Begin building the table
	echo "<table>";
	echo "<tbody>";

	$AwardSelect = $_POST['AwardID'];  //The ID of the Films

	if ($AwardSelect == 1)
	{
		//Build the query to the database
		$result = $mysqli->query("SELECT fname, lname FROM characters 
			WHERE oscar_win = 1");
	}
	else if ($AwardSelect == 2)
	{
		//Build the query to the database
		$result = $mysqli->query("SELECT fname, lname FROM characters 
			WHERE globe_win = 1");
	}

	//Build the table
	$rows = $result->num_rows;
	$title = array("First Name", "Last Name");  //Column headers
	//loop iterators
	$i = 0;
	$j = 0;
	echo "<br>";


	for ($i = 0; $i <= $rows; $i++) 
	{
		echo "<tr>"; //Make each row based on the number of rows pulled from the database
		if ($i != 0)
		{
			$table_results = $result->fetch_row(); //Get the information from that row
		}
		
		for ($j = 0; $j < 2; $j++)
		{
			if ($i === 0)
			{
				echo "<th>$title[$j]</th>";  //Display column titles
			}
			else 
			{
				$tableItem = $table_results[$j];
				echo "<td>$tableItem</td>";  //Display contents from the row
			}
		}
		echo "</tr>";
	}

	echo "<br>";
	echo "</tbody>";
	echo "<table>";

	//Close connection to the databse
	mysqli_close($mysqli);
}

?>


