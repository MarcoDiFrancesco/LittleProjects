package figuregeometricheesame;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;

public class EmptyShape extends Shape {

  Rectangle rectangle = new Rectangle();
  public EmptyShape() {
    rectangle.setWidth(100);
    rectangle.setFill(Color.BLACK);
    super.getChildren().add(rectangle);
  }
}
