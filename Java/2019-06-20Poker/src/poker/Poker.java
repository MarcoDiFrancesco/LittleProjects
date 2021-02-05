package poker;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.*;
import javafx.stage.Stage;

public class Poker extends Application {

  @Override
  public void start(Stage primaryStage) {
    Game game = new Game();
    List<Card> hand = game.newGame();
    int numberOfCards = hand.size();
    Stage stage = new Stage();
    BorderPane borderPane = new BorderPane();

    Scene scene = new Scene(borderPane, 800, 800);

    List<Rectangle> rectangleList = new ArrayList();
    List<Text> textList = new ArrayList();

    for (int i = 0; i < numberOfCards; i++) {
      int width = 100;
      int height = 200;
      int margin = 10;

      rectangleList.add(i, new Rectangle());
      rectangleList.get(i).setX(i * width + i * margin + margin);
      rectangleList.get(i).setY(margin);
      rectangleList.get(i).setWidth(width);
      rectangleList.get(i).setHeight(height);
      rectangleList.get(i).setFill(Color.LIGHTBLUE);
      borderPane.getChildren().add(rectangleList.get(i));

      textList.add(new Text());
      textList.get(i).setFont(new Font(20));
      textList.get(i).setX(width * i + margin * i + 10);
      textList.get(i).setY(margin + 35); // +35 because starts from bottom left of the text

      String handCardText = hand.get(i).toString();
      textList.get(i).setText(handCardText);
      borderPane.getChildren().add(textList.get(i));

    }

    stage.setScene(scene);
    stage.show();

  }

  public static void main(String[] args) {
    launch(args);
  }

}
