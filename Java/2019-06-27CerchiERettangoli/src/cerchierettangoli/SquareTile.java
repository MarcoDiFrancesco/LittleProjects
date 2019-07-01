package cerchierettangoli;

import java.util.Random;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;

public class SquareTile extends Tile {

  Rectangle rectangle;
  Text text = new Text();

  SquareTile(MainWindow mainWindow, int tileValue) {
    super(mainWindow, tileValue, new Random().nextInt(1000));
    rectangle = new Rectangle();
    rectangle.setWidth(50);
    rectangle.setHeight(50);
    rectangle.setFill(mainWindow.randomColor());
    getChildren().add(rectangle);

    text = new Text();
    text.setText(Integer.toString(tileValue));
    text.setFill(mainWindow.randomColor());
    getChildren().add(text);
  }

  @Override
  public void manageClick() {
    System.out.println("I'm a square and my value is " + this.tileValue);
    this.tileValue -= 1;
    if (this.tileValue < 0) {
      this.tileValue = 9;
    }
    text.setText(Integer.toString(tileValue));
    try {
      getChildren().add(text);
    } catch (Exception e) {

    }
    mainWindow.refreshTile();

    checkIfEqual();
  }

  @Override
  public boolean equals(Tile var) {
    boolean isEqual = false;
    if (var == null) {
      isEqual = false;
    } else if (var instanceof CircleTile) {
      isEqual = false;
    } else if (var instanceof SquareTile) {
      if (((SquareTile) var).tileValue == this.tileValue) {
        isEqual = true;
      }
    } else {
      System.err.println("Error in equal method" + var.getClass());
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
      mainWindow.tile.add(0,this);
    }
    mainWindow.refreshTile();
  }
}
