package figuregeometricheesame;

import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

/**
 * Contains the shape of a heaxagon
 *
 * @author marco
 */
public class HexagonShape extends Shape {

  Polygon hexagon;

  public HexagonShape() {
    hexagon = new Polygon();
    hexagon.getPoints().addAll(
      33.3, 0.0,
      66.6, 0.0,
      100.0, 50.0,
      66.6, 100.0,
      33.3, 100.0,
      0.0, 50.0);
    hexagon.setFill(Color.YELLOW);
    hexagon.setStroke(Color.RED);
    hexagon.setStrokeWidth(1);
    super.getChildren().add(hexagon);
  }
}
