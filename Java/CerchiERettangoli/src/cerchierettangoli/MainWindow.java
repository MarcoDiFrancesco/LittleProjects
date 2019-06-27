package cerchierettangoli;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import javafx.geometry.Pos;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;

public class MainWindow extends BorderPane {

  List<Tile> tile = new ArrayList();
  VBox vBox = new VBox();
  private int tileNumber;
  private Random random = new Random(System.currentTimeMillis());

  MainWindow() {
    askForTileNumber();
    addTiles();
    setCenter(vBox);
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
        if (tileNumber >= 3 & tileNumber <= 11) {
          gotRightNumber = true;
        }
      } catch (NumberFormatException numberFormatException) {
        // number exeption is not used because the text is anyway changed later on
      }
      textInputDialog.setContentText("The quantity selected is not valid, it needs to be an integer between 3 and 11, insert again the number of tiles you want in the program");
    } while (gotRightNumber == false);
  }

  /**
   * add tiles to VBox when opening the program
   * half of the tiles are 
   */
  void addTiles() {

    for (int i = 0; i < tileNumber; i++) {
      int randomValue = random.nextInt(9);
      if(i%2 == 0){
        
      }
    }
  }

}
