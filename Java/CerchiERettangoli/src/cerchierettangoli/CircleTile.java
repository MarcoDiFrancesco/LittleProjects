package cerchierettangoli;

import java.util.Random;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

public class CircleTile extends Tile {

  Circle circle;
  Text text = new Text();

  CircleTile(MainWindow mainWindow, int tileValue) {
    super(mainWindow, tileValue, new Random().nextInt(1000));
    circle = new Circle();
    circle.setRadius(25);
    circle.setFill(mainWindow.randomColor());
    super.getChildren().add(circle);

    Text text = new Text();
    text.setText(Integer.toString(tileValue));
    text.setFill(mainWindow.randomColor());
    getChildren().add(text);
  }

  public void manageClick() {
    System.out.println("I'm a circle and my value is " + this.tileValue);
    this.tileValue += 1;
    if (this.tileValue > 9) {
      this.tileValue = 0;
    }
    text.setText(Integer.toString(tileValue));
    try {
      getChildren().add(text);
    } catch (Exception e) {

    }
    mainWindow.refreshTile();
  }

  @Override
  public boolean equals(Tile var) {
    boolean isEqual = false;
    if (var == null) {
      isEqual = false;
    } else if (var instanceof SquareTile) {
      isEqual = false;
    } else if (var instanceof CircleTile) {
      if (((CircleTile) var).tileValue == this.tileValue) {
        isEqual = true;
      }
    } else {
      System.err.println("Error in equal method");
    }
    return isEqual;
  }

  public void checkIfEqual() {
    int i = 0;
    boolean hasRemoved = false;
    for (Tile tile1 : mainWindow.tile) {
      if (tile1.equals(this) & this != tile1) {
        System.out.println(Integer.toString(tile1.tileValue) + " is equal to " + Integer.toString(this.tileValue) + " - " + Integer.toString(i));
        mainWindow.tileBottom.add(tile1);
        mainWindow.tileBottom.add(this);        
        mainWindow.tile.remove(tile1);
        mainWindow.tile.remove(this);
        hasRemoved = true;
      }
    }
    if(hasRemoved == false){
      mainWindow.tile.remove(this);
      mainWindow.tile.add(this);
    }
    mainWindow.refreshTile();
  }
}
