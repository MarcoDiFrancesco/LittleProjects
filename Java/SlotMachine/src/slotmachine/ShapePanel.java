package slotmachine;

import java.util.ArrayList;
import java.util.List;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Rectangle;

public class ShapePanel extends HBox{
  ShapePanel(){
    List<MyCircle> circle = new ArrayList();
    circle.add(new MyCircle(Color.BLUE));
    circle.add(new MyCircle(Color.RED));
    circle.add(new MyCircle(Color.GREEN));
    List<MyTriangle> triangle = new ArrayList();
    triangle.add(new MyTriangle(Color.BLUE));
    triangle.add(new MyTriangle(Color.RED));
    triangle.add(new MyTriangle(Color.GREEN));
    List<MyRectangle> rectangle = new ArrayList();
    rectangle.add(new MyRectangle(Color.BLUE));
    rectangle.add(new MyRectangle(Color.RED));
    rectangle.add(new MyRectangle(Color.GREEN));
    
    for(int i = 0; i<3; i++){
      StackPane stackPane = new StackPane();
      stackPane.getChildren().addAll(circle);
      stackPane.getChildren().addAll(triangle);
      stackPane.getChildren().addAll(rectangle);
      getChildren().add(stackPane);
    }
  }  
}

class MyCircle extends Circle {
  MyCircle(Color color) {
    setRadius(50);
    setFill(color);
  }
}

class MyRectangle extends Rectangle {
  MyRectangle(Color color){
    setWidth(50);
    setHeight(50);
    setFill(color);
  }
}

class MyTriangle extends Polygon {
  MyTriangle(Color color){
    setFill(color);
    getPoints().setAll(new Double[]{
      25.0,0.0,
      0.0,50.0,
      50.0,50.0
    });
  }
}