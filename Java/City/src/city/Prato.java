package city;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Prato extends Terreno {

  Rectangle rectangle = new Rectangle(100.0, 100.0, Color.GREEN);

  public Prato() {
    rectangle.setStroke(Color.WHITE);
    rectangle.setStrokeWidth(5);
    getChildren().add(rectangle);
  }

}
