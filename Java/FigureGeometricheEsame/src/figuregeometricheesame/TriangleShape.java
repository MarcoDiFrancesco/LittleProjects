package figuregeometricheesame;

import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

/**
 * Contains the shape of a triangle
 *
 * @author marco
 */
public class TriangleShape extends Shape {

  Polygon triangle;

  public TriangleShape() {
    triangle = new Polygon();
    triangle.getPoints().addAll(new Double[]{
      50.0, 0.0,
      0.0, 100.0,
      100.0, 100.0
    });
    triangle.setFill(Color.YELLOW);
    triangle.setStroke(Color.RED);
    triangle.setStrokeWidth(1);
    super.getChildren().add(triangle);
  }

}
