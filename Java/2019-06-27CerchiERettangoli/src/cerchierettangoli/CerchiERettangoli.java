package cerchierettangoli;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class CerchiERettangoli extends Application {

  @Override
  public void start(Stage stage) {
    MainWindow mainWindow = new MainWindow();
    Scene scene = new Scene(mainWindow, 500, 500);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
      System.err.println("Before");
    launch(args);
  }
}
