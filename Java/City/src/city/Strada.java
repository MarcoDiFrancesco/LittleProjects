package city;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;

public class Strada extends Terreno {

  Rectangle rectangle = new Rectangle();
  boolean isAddCarClicked;
  GridPane gridPane;
  int posX;
  int posY;

  public Strada(boolean isAddCarClicked, GridPane gridPane, int posX, int posY) {
    this.isAddCarClicked = isAddCarClicked;
    this.gridPane = gridPane;
    this.posX = posX;
    this.posY = posY;
    rectangle.setWidth(100);
    rectangle.setHeight(100);
    rectangle.setFill(Color.GRAY);
    rectangle.setStroke(Color.WHITE);
    rectangle.setStrokeWidth(5);
    getChildren().add(rectangle);
  }

}
