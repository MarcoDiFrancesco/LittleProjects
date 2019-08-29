<?php

class Libro {

    private $nomeLibro = array();
    private $prezzo;
    private $numeroScaffale;
    private $numeroPagine;
    private $casaEditrice;

    function __construct($nomeLibro, $prezzo, $numeroScaffale, $numeroPagine, $casaEditrice) {
        $this->nomeLibro = $nomeLibro;
        $this->prezzo = $prezzo;
        $this->numeroScaffale = $numeroScaffale;
        $this->numeroPagine = $numeroPagine;
        $this->casaEditrice = $casaEditrice;
    }

    function mostra() {
        echo "Nome libro= ".$this->nomeLibro.
                "<br>Prezzo= $".$this->prezzo.
                "<br>Numero scaffale= ".$this->numeroScaffale.
                "<br>Numero pagine= ".$this->numeroPagine.
                "<br>Casa editrice= ".$this->casaEditrice."<br><br>";
    }

    function applicaSconto() {
        $this->prezzo = ($this->prezzo/10)*9;
    }

}
?>