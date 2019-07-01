package city;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;

public class Prato extends Terreno {

  Rectangle rectangle = new Rectangle(100.0, 100.0, Color.GREEN);
  boolean isAddCarClicked;
  GridPane gridPane;
  int posX;
  int posY;
  
  public Prato(boolean isAddCarClicked, GridPane gridPane, int posX, int posY) {
    this.isAddCarClicked = isAddCarClicked;
    this.gridPane = gridPane;
    this.posX = posX;
    this.posY = posY;
    rectangle.setStroke(Color.WHITE);
    rectangle.setStrokeWidth(5);
    getChildren().add(rectangle);
  }

}
