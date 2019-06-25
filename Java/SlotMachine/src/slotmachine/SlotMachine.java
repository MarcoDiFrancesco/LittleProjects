package slotmachine;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class SlotMachine extends Application {

  @Override
  public void start(Stage stage) {
    BorderPane pane = new BorderPane();
    ShapePanel shapePanel = new ShapePanel();
    pane.setCenter(shapePanel);
    Scene scene = new Scene(pane);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
