package city;

import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;

public class Control extends Button {
  public Control(){
    setText("Add car");
  }
  
  public void mouseClicked(){
    System.out.println("Button clicked");
  }
}
