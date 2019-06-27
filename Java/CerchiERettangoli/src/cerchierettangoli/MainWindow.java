package cerchierettangoli;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextInputDialog;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

public class MainWindow extends BorderPane {

  public static final int MIN_NUMBER = 0;
  public static final int MAX_NUMBER = 9 + 1;
  public static final int MIN_TILE_NUMBER = 3;
  public static final int MAX_TILE_NUMBER = 11;

  List<Tile> tile = new ArrayList();
  List<Tile> tileBottom = new ArrayList();
  VBox vBox = new VBox();
  HBox hBox = new HBox();
  private int tileNumber;
  private Random random = new Random(System.currentTimeMillis());

  MainWindow() {
    askForTileNumber();
    addTiles();
    addButton();
    setCenter(vBox);
    setBottom(hBox);
    setAlignment(vBox, Pos.CENTER);
  }

  void askForTileNumber() {
    boolean gotRightNumber = false;
    TextInputDialog textInputDialog = new TextInputDialog();
    textInputDialog.setTitle("Number of tiles");
    textInputDialog.setContentText("Insert the number of tiles you want in the program");
    do {
      String outputDialog = textInputDialog.showAndWait().get();
      try {
        tileNumber = Integer.parseInt(outputDialog);
        if (tileNumber >= MIN_TILE_NUMBER & tileNumber <= MAX_TILE_NUMBER) {
          gotRightNumber = true;
        }
      } catch (NumberFormatException numberFormatException) {
        // number exeption is not used because the text is anyway changed later on
      }
      textInputDialog.setContentText("The quantity selected is not valid, it needs to be an integer between 3 and 11, insert again the number of tiles you want in the program");
    } while (gotRightNumber == false);
    
  }

  /**
   * add tiles to VBox when opening the program half of the tiles are
   */
  private void addTiles() {
    for (int i = 0; i < tileNumber; i++) {
      int randomValue = random.nextInt(MAX_NUMBER);
      if (i % 2 == 0) {
        tile.add(new CircleTile(this, randomValue));
      } else {
        tile.add(new SquareTile(this, randomValue));
      }
    }
    refreshTile();
  }

  public Color randomColor() {
    float r = random.nextFloat();
    float g = random.nextFloat();
    float b = random.nextFloat();
    Color color = new Color(r, g, b, 1);
    return color;
  }

  private void addButton() {
    Button button = new Button();
    button.setText("Riordina");
    button.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        riordina();
      }

    });
    this.setLeft(button);
  }

  public void riordina() {
    List<Tile> newTile = new ArrayList();
    for (int i = MIN_NUMBER; i < MAX_NUMBER; i++) {
      for (Tile tile1 : tile) {
        if (tile1.tileValue == i) {
          newTile.add(tile1);
        }
      }
    }
    tile = newTile;
    refreshTile(newTile);
  }

  /**
   * remove and refresh the tiles
   */
  public void refreshTile() {
    vBox.getChildren().clear();
    vBox.getChildren().addAll(tile);
    hBox.getChildren().clear();
    hBox.getChildren().addAll(tileBottom);
  }

  /**
   * replace all the tiles with the gave by the list
   *
   * @param newTile tiles to replace
   */
  public void refreshTile(List<Tile> newTile) {
    vBox.getChildren().clear();
    vBox.getChildren().addAll(newTile);
  }


}
