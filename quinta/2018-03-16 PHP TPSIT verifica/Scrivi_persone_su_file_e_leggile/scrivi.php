<?php
    function addUtente($nome){
        $file = fopen("persone.txt", "a");
        fwrite($file, $nome . "\n");
    }
    addUtente($_POST["nome"]);
    header('Location: index.php');
    exit;
?>