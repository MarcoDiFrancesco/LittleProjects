package figuregeometricheesame;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

/**
 * Contains the shape of a circle
 * @author marco
 */
public class CircleShape extends Shape {

  Circle circle = new Circle();
  public CircleShape() {
    circle.setRadius(50);
    circle.setFill(Color.YELLOW);
    circle.setStroke(Color.RED);
    circle.setStrokeWidth(1);
    super.getChildren().add(circle);
  }
  
}
