package virus;

import java.awt.Color;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Background;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Paint;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class Virus extends Application {

  @Override
  public void start(Stage stage) {
    
    // stackpane number 1
    
    StackPane root = new StackPane();
    Scene scene = new Scene(root, 500, 500);
    
    Text text = new Text(100,100,"Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    text.setWrappingWidth(100);
    root.getChildren().add(text);

    stage.setTitle("Main pane");
    stage.setScene(scene);
    stage.show();
    
    Random random = new Random();
    
    // stackpane number 2
    while(true){
      try{ 
        StackPane root2 = new StackPane();
        Stage stage2 = new Stage();
        Scene scene2 = new Scene(root2,200,200);

        Text text2 = new Text();
        scene2.setFill(Paint.valueOf("YELLOW"));
        text2.setText("Hello eeeeverybody");

        root2.getChildren().add(text2);

        stage2.setX(random.nextInt(1920));
        stage2.setY(random.nextInt(1080));

        stage2.setScene(scene2);
        stage2.show();
        Thread.sleep(200);
        stage2.close();
      } catch(AbstractMethodError exception) {

      } catch (InterruptedException ex) {
        Logger.getLogger(Virus.class.getName()).log(Level.SEVERE, null, ex);
      }
    }
  }

  public static void main(String[] args) {
    launch(args);
  }

}
