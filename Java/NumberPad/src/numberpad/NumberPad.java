package numberpad;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class NumberPad extends Application {

  @Override
  public void start(Stage stage) {
    GridPane gridPane = new GridPane();
    List<PersonalizedButton> listButton = new ArrayList();

    for (int i = 0; i < 9; i++) {
      listButton.add(new PersonalizedButton(this, Integer.toString(i), Integer.toString(i)));
    }

    gridPane.add(listButton.get(0), 0, 0);
    gridPane.add(listButton.get(1), 1, 0);
    gridPane.add(listButton.get(2), 2, 0);
    gridPane.add(listButton.get(3), 0, 1);
    gridPane.add(listButton.get(4), 1, 1);
    gridPane.add(listButton.get(5), 2, 1);
    gridPane.add(listButton.get(6), 0, 2);
    gridPane.add(listButton.get(7), 1, 2);
    gridPane.add(listButton.get(8), 2, 2);

    gridPane.addEventFilter(KeyEvent.KEY_TYPED, new EventHandler<KeyEvent>() {

      @Override
      public void handle(KeyEvent keyEvent) {
        String keyTyped = keyEvent.getCharacter();
        if ("012345678".contains(keyTyped)) {
          if(listButton.get(Integer.parseInt(keyTyped)).isVisible() == true){
            listButton.get(Integer.parseInt(keyTyped)).setVisible(false);
          } else {
            listButton.get(Integer.parseInt(keyTyped)).setVisible(true);
          }
          System.out.println(keyTyped);
        }
      }

    });
    Scene scene = new Scene(gridPane);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
