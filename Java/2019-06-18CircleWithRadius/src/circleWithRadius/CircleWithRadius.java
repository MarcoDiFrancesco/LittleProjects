package circleWithRadius;

import java.util.Scanner;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class CircleWithRadius extends Application {

  @Override
  public void start(Stage stage) {
    // a circle
    BorderPane root = new BorderPane();
    Circle circle = new Circle(200, 200, 200);
    root.getChildren().add(circle);

    Scene scene = new Scene(root, 400, 400);
    stage.setTitle("My first Java FX app");
    stage.setScene(scene);
    stage.show();

    TextInputDialog dialogRadius = new TextInputDialog();
    dialogRadius.setTitle("Radius change");
    dialogRadius.setHeaderText("Radius change");
    dialogRadius.setContentText("Set the new radius for the circle...");
    
    boolean exceptionInt = false;
    do {
      String newRadius = dialogRadius.showAndWait().get();
      System.out.println(newRadius);

      try {
        int newRadiusInt = Integer.parseInt(newRadius);
        circle.setRadius(newRadiusInt);
        exceptionInt = true;
      } catch (NumberFormatException exception) {
        exceptionInt = false;
        dialogRadius.setContentText("The radius was not a number, set a number...");
      }
    } while (exceptionInt == false);
  }

  public static void main(String[] args) {
    launch(args);
  }
}
