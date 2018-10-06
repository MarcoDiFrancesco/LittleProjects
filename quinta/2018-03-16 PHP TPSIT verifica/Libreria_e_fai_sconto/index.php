<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Libreria</title>
    </head>
    <body>
        <?php
            include_once './libro.php';
            $primoLibro = new Libro('Enrico Fermi', 10, 1, 305, 'Scuolabook');
            $secondoLibro = new Libro('La scuola', 50, 3, 720, 'Zanichelli');
            
            $primoLibro->mostra();
            $primoLibro->applicaSconto();
            $primoLibro->mostra();
            
            $secondoLibro->mostra();
        ?>
    </body>
</html>
