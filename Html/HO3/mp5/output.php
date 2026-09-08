<?php
  $q1 = $_POST['q1'];
  $q2 = $_POST['q2'];
  $q3 = $_POST['q3'];
  $q4 = $_POST['q4'];
  $q5 = $_POST['q5'];
  $q6 = $_POST['q6'];

  $score = 0;

  if ($q1 == 'yes') { $score = $score + 5; }
  if ($q2 == 'yes') { $score = $score + 5; }
  if ($q2 == 'depends') { $score = $score + 10; }
  if ($q3 == 'ub') { $score = $score + 15; }
  if ($q4 == 'fail') { $score = $score + 20; }
  if ($q5 == 'stdint') { $score = $score + 25; }
  if ($q6 == 'radians') { $score = $score + 25; }
  
  echo '<p align="center">Your score is...</p>';
  echo '<h1 align="center" style="font-size:120px">'.$score.'</h1>';

  if ($score < 70) { echo '<h2 style="color:red" align="center">You failed!</h2>'; }
  elseif ($score < 100) { echo '<h2 align="center">You passed!</h2>'; }
  else { echo '<h2 style="color:green" align="center">PERFECT SCORE!</h2>'; }
?>
