package calculator;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Calculator extends Application {

  String bufferText1 = "";
  String bufferText2 = "";
  int result;
  String operator = "";
  boolean deleteOnClick = false;
  TextField textField = null;

  @Override
  public void start(Stage stage) {
    BorderPane borderPane = new BorderPane();
    Scene scene = new Scene(borderPane);

    // BorderPane top
    textField = new TextField();
    textField.setEditable(false);
    borderPane.setTop(textField);

    // BorderPane center
    GridPane gridPane = new GridPane();
    List<Button> button = new ArrayList();

    for (int i = 0; i < 10; i++) { // set buttons from 0 to 9
      String numberButtonString = Integer.toString(i);
      button.add(i, new Button(numberButtonString));
    }

    button.add(10, new Button("+"));
    button.add(11, new Button("-"));
    button.add(12, new Button("*"));
    button.add(13, new Button("/"));
    button.add(14, new Button("Del"));
    button.add(15, new Button("="));

    gridPane.add(button.get(1), 0, 2);
    gridPane.add(button.get(2), 1, 2);
    gridPane.add(button.get(3), 2, 2);
    gridPane.add(button.get(4), 0, 1);
    gridPane.add(button.get(5), 1, 1);
    gridPane.add(button.get(6), 2, 1);
    gridPane.add(button.get(7), 0, 0);
    gridPane.add(button.get(8), 1, 0);
    gridPane.add(button.get(9), 2, 0);

    gridPane.add(button.get(10), 3, 0);
    gridPane.add(button.get(11), 3, 1);
    gridPane.add(button.get(12), 3, 2);
    gridPane.add(button.get(13), 3, 3);

    gridPane.add(button.get(0), 0, 3);
    gridPane.add(button.get(14), 1, 3);
    gridPane.add(button.get(15), 2, 3);

    
    stage.setMinWidth(500);
    stage.setMinHeight(500);

    for (Button button1 : button) {
      button1.setMinWidth(500 / 4);
      button1.setMaxWidth(500 / 4);
      button1.setMinHeight(500 / 4 - 15);
      button1.setMaxHeight(500 / 4 - 10);
    }

    // Listener with proprety
    stage.widthProperty().addListener(new ChangeListener<Number>() {

      @Override
      public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
        double widthButtonSize = newValue.doubleValue();
        for (Button button1 : button) {
          button1.setMinWidth(widthButtonSize / 4);
          button1.setMaxWidth(widthButtonSize / 4);
        }
      }

    });

    stage.heightProperty().addListener(new ChangeListener<Number>() {

      @Override
      public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
        double heightButtonSize = newValue.doubleValue();
        for (Button button1 : button) {
          button1.setMinHeight(heightButtonSize / 4 - 15);
          button1.setMaxHeight(heightButtonSize / 4 - 10);
        }
      }

    });

    for (Button button1 : button) {
      button1.setOnAction(new EventHandler<ActionEvent>() {

        @Override
        public void handle(ActionEvent event) {
          if ("0123456789".contains(button1.getText())) { // set number
            if (deleteOnClick == true) {
              textField.setText("");
              deleteOnClick = false;
              bufferText1 = Integer.toString(result);
              bufferText2 = "";
            }
            if (textField.getText().isEmpty()) {
              textField.setText(button1.getText());
            } else {
              String textFieldOutput = textField.getText();
              textFieldOutput += button1.getText();
              textField.setText(textFieldOutput);
            }
          } else if ("+-*/".contains(button1.getText())) {
            operator = button1.getText();
            if (bufferText1.equals("")) {
              bufferText1 = textField.getText();
              textField.setText("");
            } else {
              calculateResult();
            }
          } else if ("=".equals(button1.getText())) {
            if (bufferText1.equals("")) {
              textField.setText("0");
            } else if (operator.equals("")) {
              textField.setText(bufferText1);
            } else {
              calculateResult();
            }
          } else if ("Del".equals(button1.getText())) {
            bufferText1 = "";
            bufferText1 = "";
            operator = "";
            textField.setText("");
          }
          System.out.println(bufferText1 + " " + operator + " " + bufferText2 + " = " + result);

        }
      });
    }

    borderPane.setCenter(gridPane);
    stage.setScene(scene);
    stage.show();
  }

  public void calculateResult() {
    deleteOnClick = true;
    bufferText2 = textField.getText();

    switch (operator) {
      case "+":
        result = Integer.parseInt(bufferText1) + Integer.parseInt(bufferText2);
        break;
      case "-":
        result = Integer.parseInt(bufferText1) - Integer.parseInt(bufferText2);
        break;
      case "*":
        result = Integer.parseInt(bufferText1) * Integer.parseInt(bufferText2);
        break;
      case "/":
        result = Integer.parseInt(bufferText1) / Integer.parseInt(bufferText2);
        break;
    }
    textField.setText(Integer.toString(result));
  }

  public static void main(String[] args) {
    launch(args);
  }
}
