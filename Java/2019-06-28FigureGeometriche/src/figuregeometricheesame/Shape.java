package figuregeometricheesame;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

/**
 * Is the abstract class used on all the shapes (also the empty one)
 * @author marco
 */
public abstract class Shape extends StackPane{
  
  Rectangle rectangle;
  
  Shape(){
     rectangle = new Rectangle();
     rectangle.setHeight(100);
     rectangle.setWidth(100);
     rectangle.setFill(Color.BLACK);
     rectangle.setStroke(Color.AQUAMARINE);
     rectangle.setStrokeWidth(1);
     getChildren().add(rectangle);
    setHeight(100);
    setWidth(100);
  }
}
