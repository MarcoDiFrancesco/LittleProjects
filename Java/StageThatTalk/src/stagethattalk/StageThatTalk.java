package stagethattalk;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class StageThatTalk extends Application {

  Text text = new Text();
  int counter = 0;
  StackPane stackPane1;
  StackPane stackPane2;
  @Override
  public void start(Stage stage1) {
    Stage stage2 = new Stage();
    stackPane1 = new StackPane();
    stackPane2 = new StackPane();
    Button button = new Button("Click me");
    button.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      mouseClicked();
    });
    stackPane1.getChildren().add(button);
    Scene scene1 = new Scene(stackPane1, 500, 500);
    stage1.setX(100);
    stage1.setY(100);
    stage1.setScene(scene1);
    stage1.show();
    stackPane2.getChildren().add(text);
    Scene scene2 = new Scene(stackPane2, 500, 500);
    stage2.setX(700);
    stage2.setY(100);
    stage2.setScene(scene2);
    stage2.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

  private void mouseClicked() {
    text.setText(Integer.toString(counter++));
  //  updateText();
  }

  private void updateText() {
    try {
      stackPane2.getChildren().add(text);
    } catch (IllegalArgumentException e) {
    }
    
  }
}
