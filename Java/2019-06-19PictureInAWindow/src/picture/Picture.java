package picture;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.StackPane;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.stage.Stage;

/**
 * This class makes a figure appear in the screen
 *
 * @author marco
 */
public class Picture extends Application {

  @Override
  public void start(Stage stage) {
    Group group = new Group();
    Scene scene = new Scene(group, 600, 600);

    Image image = new Image("https://avatars2.githubusercontent.com/u/7454137");
    ImageView imageview = new ImageView();
    imageview.setImage(image);
    imageview.setFitWidth(600);
    imageview.setPreserveRatio(true);
    imageview.setSmooth(true);
    imageview.setCache(true);

    group.getChildren().add(imageview);
    stage.setTitle("A picture");
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }

}
