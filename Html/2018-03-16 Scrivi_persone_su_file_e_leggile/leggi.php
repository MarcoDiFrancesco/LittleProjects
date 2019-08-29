<?php
    $file = fopen('persone.txt','r'); // metti in read persone
    while($line = fgets($file)){
        echo($line);
        echo '<br>';
    }

    fclose($file);
    exit;
?>