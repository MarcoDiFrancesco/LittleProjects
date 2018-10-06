<?php
    class calcola{
        
        private $primoNumero;
        private $secondoNumero;
        
        
        function __construct($primoNumero,$secondoNumero) {
            $this->primoNumero = $primoNumero;
            $this->secondoNumero = $secondoNumero;
        }

        function min(){
            if($this->primoNumero < $this->secondoNumero){
                echo 'Il primo numero è il più piccolo';
            } else {
                echo 'Il secondo numero è il più piccolo';
            }   
        }

        function max(){
            if($this->primoNumero > $this->secondoNumero){
                echo 'Il primo numero è il più grande';
            } else {
                echo 'Il secondo numero è il più grande';
            }   
        }
        
    }
    $primoNumero = $_POST['primoNumero'];
    $secondoNumero = $_POST['secondoNumero'];
    
    $massimiTest = new calcola($primoNumero,$secondoNumero);
    echo $massimiTest->min().'<br>';
    echo $massimiTest->max();
    
     
?>
