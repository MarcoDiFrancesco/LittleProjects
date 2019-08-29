<?php
$t1 = $_POST["t1"]; 
$t2 = $_POST["t2"]; 
$t3 = $_POST["t3"]; 
$t4 = $_POST["t4"]; 
$t5 = $_POST["t5"]; 
$t6 = $_POST["t6"]; 
$t7 = $_POST["t7"]; 
$t8 = $_POST["t8"]; 
$t9 = $_POST["t9"]; 
$t10 = $_POST["t10"];
$t11 = $_POST["t11"]; 
$t12 = $_POST["t12"]; 
$t13 = $_POST["t13"]; 
$t14 = $_POST["t14"]; 
$t15 = $_POST["t15"]; 
$t16 = $_POST["t16"]; 
$t17 = $_POST["t17"]; 
$t18 = $_POST["t18"]; 
$t19 = $_POST["t19"]; 
$t20 = $_POST["t20"]; 

$array = array($t1,$t2,$t3,$t4,$t5,$t6,$t7,$t8,$t9,$t10,$t11,$t12,$t13,$t14,$t15,$t16,$t17,$t18,$t19,$t20);

echo "<br>Temperature: ";
$count = 0;
foreach ($array as $x){ 
    echo $x. " ";
    $count = $count + $array[$x];
}
echo '<br>Temperature ordinate:';
sort($array);
foreach ($array as $x){ 
    echo $x . " ";
    $count = $count + $array[$x];
}
echo "<br>Media: ".$count/20;
echo '<br> Più piccoli: ';
for($w=0;$w<5;$w++){
    echo $array[$w]. " ";
}
echo '<br> Più grandi: ';
for($w=15;$w<20;$w++){
    echo $array[$w]. " ";
}

?>