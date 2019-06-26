package city;

import javafx.scene.layout.StackPane;

public abstract class Terreno extends StackPane {
  Prato prato = new Prato();
  Strada strada = new Strada();
  
  Terreno(){
    
  }
}
