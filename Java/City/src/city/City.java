package city;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

/**
 * Create the gridPane 8x8 where to place all the block
 *
 * @author marco
 */
public class City extends Application {

  GridPane gridPane = null;
  public final static int N_ROWS = 8;
  public final static int N_COLS = 8;
  boolean isAddCarClicked = false; 
  
  @Override
  public void start(Stage stage) {
    gridPane = new GridPane();
    createCity();
    createControl();
    Scene scene = new Scene(gridPane);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

  public void createCity() {
    for (int row = 0; row < N_ROWS; row++) {
      for (int col = 0; col < N_COLS; col++) {
        if (row == 0 | row == N_ROWS - 1 | col == 0 | col == N_COLS - 1) {
          Strada strada = new Strada(isAddCarClicked, gridPane, row, col);
          gridPane.add(strada, row, col);
        } else {
          Prato prato = new Prato(isAddCarClicked, gridPane, row, col);
          gridPane.add(prato, row, col);
        }
      }
    }
  }
  
  public void createControl(){
    Control control = new Control();
    gridPane.add(control, 0, N_ROWS+1);
    control.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        mouseClicked();
      }
    });
  }
  
  void mouseClicked(){
    System.out.println("Button clicked");
    isAddCarClicked = true;
  }

  public void addCar() {
    
  }
 
}
