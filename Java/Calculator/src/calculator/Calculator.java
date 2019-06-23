package calculator;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Calculator extends Application {

  Text bottomText = null;
  @Override
  public void start(Stage stage) {
    BorderPane layout = new BorderPane();

    // Top
    Text topText = new Text("MiniCalculator");
    topText.setFont(Font.font("VERDANA", FontWeight.BOLD, 50));
    BorderPane.setAlignment(topText, Pos.CENTER);
    layout.setTop(topText);

    // Left
    Text leftText = new Text("left");
    leftText.setFont(Font.font("VERDANA", FontWeight.THIN, 20));
    BorderPane.setAlignment(leftText, Pos.CENTER_LEFT);
    layout.setLeft(leftText);

    // Bottom
    bottomText = new Text("");
    bottomText.setFont(Font.font("VERDANA",30));
    BorderPane.setAlignment(bottomText, Pos.CENTER);
    layout.setBottom(bottomText);

    // Center
    VBox verticalPane = new VBox();

    // Center input boxes
    TextField inputText1 = new TextField();
    TextField inputText2 = new TextField();
    verticalPane.getChildren().add(inputText1);
    verticalPane.getChildren().add(inputText2);

    // Center calcutator buttons
    HBox calculatorButtonsPane = new HBox();
    List<Button> calculatorButton = new ArrayList();
    calculatorButton.add(new Button("+"));
    calculatorButton.add(new Button("-"));
    calculatorButton.add(new Button("*"));
    calculatorButton.add(new Button("/"));
    calculatorButtonsPane.getChildren().addAll(calculatorButton);
    calculatorButtonsPane.setAlignment(Pos.CENTER);
    verticalPane.getChildren().add(calculatorButtonsPane);

    // Center output box
    TextField outputText = new TextField();
    verticalPane.getChildren().add(outputText);
    outputText.setEditable(false);
    
    calculatorButton.get(0).addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        try {
          String input1 = inputText1.getText();
          String input2 = inputText2.getText();
          int result = Integer.parseInt(input1) + Integer.parseInt(input2);
          outputText.setText(Integer.toString(result));
          bottomText.setText("");
        } catch (NumberFormatException error) {
          errorMessage();
        }
      }

    });

    calculatorButton.get(1).addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
      @Override
      public void handle(MouseEvent event) {
        String input1 = inputText1.getText();
        String input2 = inputText2.getText();
        int result = Integer.parseInt(input1) - Integer.parseInt(input2);
        outputText.setText(Integer.toString(result));
      }
    });

    calculatorButton.get(2).addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
      @Override
      public void handle(MouseEvent event) {
        String input1 = inputText1.getText();
        String input2 = inputText2.getText();
        int result = Integer.parseInt(input1) * Integer.parseInt(input2);
        outputText.setText(Integer.toString(result));
      }
    });

    calculatorButton.get(3).addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
      @Override
      public void handle(MouseEvent event) {
        String input1 = inputText1.getText();
        String input2 = inputText2.getText();
        int result = Integer.parseInt(input1) / Integer.parseInt(input2);
        outputText.setText(Integer.toString(result));
      }
    });

    // Right clear button
    Button clearButton = new Button("Clear");
    BorderPane.setAlignment(clearButton, Pos.CENTER);
    layout.setRight(clearButton);
    clearButton.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        inputText1.setText("");
        inputText2.setText("");
        outputText.setText("");
      }

    });

    // Center setup
    layout.setCenter(verticalPane);

    Scene scene = new Scene(layout, 700, 300);
    stage.setScene(scene);
    stage.show();
  }

  public void errorMessage() {
    bottomText.setText("Write only numbers");
  }

  public static void main(String[] args) {
    launch(args);
  }
}
