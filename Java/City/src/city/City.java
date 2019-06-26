package city;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

/**
 * Create the city 8x8 where to place all the terreni
 *
 * @author marco
 */
public class City extends Application {

  GridPane city = null;
  public final static int N_ROWS = 8;
  public final static int N_COLS = 8;

  @Override
  public void start(Stage stage) {
//    createCity();
    city = new GridPane();
    city.add(new Prato(), 0, 0);
    Scene scene = new Scene(city);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

  public void createCity() {
    city = new GridPane();
    placeBlocks();
  }

  private void placeBlocks() {
    for (int row = 0; row < N_ROWS; row++) {
      for (int col = 0; col < N_COLS; col++) {
        if (row == 0 | row == N_ROWS - 1) {
          city.add(new Strada(), row, col);
        } else {
          city.add(new Prato(), row, col);
        }
      }
    }
  }
}
