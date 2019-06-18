package shape;

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

public class Shape extends Application {

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

    /*
     // input from text
     Scanner scanner = new Scanner(System.in);
     System.out.println("Tell me something");
     String inputString = scanner.nextLine();
     System.out.println(inputString);
     */ /*
     // alert
     Alert alert = new Alert(Alert.AlertType.INFORMATION);
     alert.setTitle("I'm your favorite alert");
     alert.setHeaderText("I'm your favourite Header");
     alert.setContentText("This is my favourite context bar");
     alert.showAndWait();
     */ /*
     // input from dialog
     TextInputDialog dialog = new TextInputDialog("Default input dialog");
     dialog.setTitle("I'm your favourite input dialog");
     dialog.setHeaderText("I'm your favourite header");
     dialog.setContentText("I'm your favourite context");
     dialog.showAndWait();
     String dialogString = dialog.getContentText();
     System.out.println(dialogString);
     */ /*
     //parsing with try catch
     String numberString = "10";
     int numberInt = Integer.parseInt(numberString);
     System.out.println(numberInt);

     String piString = "3.1415";
     float piFloat = Float.parseFloat(piString);
     System.out.println(piFloat);

     boolean correctNumber = false;
     String inputString = "";
     int inputInt = 0;
     Scanner scanner = new Scanner(System.in);
     do {
     System.out.println("Give me a number... ");
     inputString = scanner.next();
     try{
     inputInt = Integer.parseInt(inputString);
     correctNumber = true;
     } catch (NumberFormatException exception) {
     System.out.println("That's not a number");
     correctNumber = false;
     } finally {
     // do it in both
     }
     }while(correctNumber == false);
     System.out.println("The number is: " + inputInt);
     */



  }

  public static void main(String[] args) {
    launch(args);
  }

}
