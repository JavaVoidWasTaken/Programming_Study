<?php
// Passenger information.
$name = $_POST['name'];
$dateofbirth = $_POST['dateofbirth'];
$address = $_POST['address'];
$gender = $_POST['gender'];
$email = $_POST['email'];

// Flight information.
$airlinebookingcode = $_POST['airlinebookingcode'];
$flightnumber = $_POST['flightnumber'];
$from = $_POST['from'];
$to = $_POST['to'];
$departuredate = $_POST['departuredate'];
$class = $_POST['class'];

echo "Welcome to BV air, your flight has been registered. Here is your ticketing information:<br>";
echo "Passenger Information:<br>";
echo "Name: $name<br>";
echo "Date of Birth: $dateofbirth<br>";
echo "Address: $address<br>";
echo "Gender: $gender<br>";
echo "E-mail: $email<br>";
echo "<br>";
echo "Airline Booking Code: $airlinebookingcode<br>";
echo "Flight Number: $flightnumber<br>";
echo "From: $from<br>";
echo "Tl: $to<br>";
echo "Departute Date: $departuredate<br>";
if ($class == "economy") {
  echo "Class: Economy";
} elseif ($class == "business") {
  echo "Class: Business";
} elseif ($class == "firstclass") {
  echo "Class: First Class";
} else {
  echo "Class: Unknown";
}
?>
