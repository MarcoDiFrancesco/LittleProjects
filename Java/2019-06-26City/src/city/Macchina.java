package city;

import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Macchina extends Terreno {
  boolean isAddCarClicked;
  Circle circle = new Circle();
  GridPane gridPane;
  int posX;
  int posY;

  public Macchina(boolean isAddCarClicked, GridPane gridPane, int posX, int posY) {
    this.isAddCarClicked = isAddCarClicked;
    this.gridPane = gridPane;
    this.posX = posX;
    this.posY = posY;
    circle.setRadius(40);
    circle.setFill(Color.RED);
    getChildren().add(circle);
    setVisible(true);
  }
}
