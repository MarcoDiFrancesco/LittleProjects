package cerchierettangoli;

import javafx.event.EventHandler;
import javafx.event.EventType;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

public abstract class Tile extends StackPane {

  MainWindow mainWindow;
  int tileValue;
  int id;
  Tile(MainWindow mainWindow, int tileValue, int id) {
    this.id = id;
    this.mainWindow = mainWindow;
    this.tileValue = tileValue;
    addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        manageClick();
        checkIfEqual();
      }

    });
  }

  public abstract void checkIfEqual();
  
  public abstract void manageClick();
  
  public abstract boolean equals(Tile tile);
}
