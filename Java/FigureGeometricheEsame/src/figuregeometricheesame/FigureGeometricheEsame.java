package figuregeometricheesame;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * Main class that calls the main window.
 * This class creates the scene and set it into the stage.
 * @author marco
 */
public class FigureGeometricheEsame extends Application {

  @Override
  public void start(Stage stage) {
    MainWindow mainWindow = new MainWindow();
    Scene scene = new Scene(mainWindow,500,500);
    stage.setScene(scene);
    stage.setTitle("Figure geometriche");
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
