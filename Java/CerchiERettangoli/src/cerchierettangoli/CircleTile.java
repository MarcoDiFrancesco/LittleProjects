package cerchierettangoli;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class CircleTile extends Tile {
  Circle circle = new Circle();
  
  CircleTile(MainWindow mainWindow, int tileValue){
    super(mainWindow, tileValue);
    circle.setRadius(30);
    circle.setFill(Color.BROWN);
    getChildren().add(circle);
  }
  
  public void manageClick(){
    
  }
}
