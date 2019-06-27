package cerchierettangoli;

import javafx.event.EventHandler;
import javafx.event.EventType;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;

public abstract class Tile extends StackPane {

  MainWindow mainWindow;
  int tileValue;
  
  Tile(MainWindow mainWindow, int tileValue) {
    this.mainWindow = mainWindow;
    this.tileValue = tileValue;
    addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>(){

      @Override
      public void handle(MouseEvent event) {
        System.out.println(tileValue);
      }
      
    });
  }
  
  public abstract void manageClick();
}
