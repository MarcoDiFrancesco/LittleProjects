package rectanglesinarow;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

/**
 * The objects inside the scene update automatically (for example a text inside
 * scene update alone) but the objects inside a StackPane (inside scene) need to
 * be removed and replaced
 *
 * @author marco
 */
public class RectanglesInARow extends Application {

  HBox hBox;
  List<Rectangle> rectangle;

  @Override
  public void start(Stage stage) {
    rectangle = new ArrayList();

    stage.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      Rectangle newRectangle = new Rectangle(100, 100, Color.BLACK);
      newRectangle.setStroke(Color.RED);
      newRectangle.setStrokeWidth(2);
      rectangle.add(newRectangle);
      System.out.println(rectangle);
      refresh();
    });

    hBox = new HBox();
    refresh();
    Scene scene = new Scene(hBox, 1000, 300);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

  private void refresh() {
    hBox.getChildren().clear();
    hBox.getChildren().addAll(rectangle);
  }
}
