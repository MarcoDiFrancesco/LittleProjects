package poker;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.*;
import javafx.stage.Stage;

public class Poker extends Application {

  @Override
  public void start(Stage primaryStage) {
    List<Card> deck = new ArrayList();
    Collections.shuffle(deck);

    addCards(deck);
    Collections.shuffle(deck);

    TextInputDialog textInputDialog = new TextInputDialog();
    textInputDialog.setContentText("Number of cards");
    textInputDialog.showAndWait();
    int numberOfCards = Integer.parseInt(textInputDialog.getResult());

    List<Card> hand = new ArrayList();
    // get first 10 cards from the deck and put it in the hand
    for (int i = 0; i < numberOfCards; i++) {
      hand.add(deck.get(i));
    }
    System.out.println(hand);
    boolean hasWin = CheckWin(hand, numberOfCards);
    System.out.println(hasWin);

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
      textList.get(i).setX(width*i + margin*i + 10);
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

  public void addCards(List<Card> deck) {
    String seed = "";
    for (int i = 0; i < 4; i++) {
      if (i == 0) {
        seed = "C";
      } else if (i == 1) {
        seed = "Q";
      } else if (i == 2) {
        seed = "F";
      } else if (i == 3) {
        seed = "P";
      }

      deck.add(new Card("1", seed));
      deck.add(new Card("2", seed));
      deck.add(new Card("3", seed));
      deck.add(new Card("4", seed));
      deck.add(new Card("5", seed));
      deck.add(new Card("6", seed));
      deck.add(new Card("7", seed));
      deck.add(new Card("8", seed));
      deck.add(new Card("9", seed));
      deck.add(new Card("10", seed));
      deck.add(new Card("J", seed));
      deck.add(new Card("Q", seed));
      deck.add(new Card("K", seed));
    }
  }

  public boolean CheckWin(List<Card> hand, int numberOfCards) {
    boolean hasWin = false; // result if hand has win
    for (int i = 0; i < numberOfCards; i++) {
      for (int w = 0; w < numberOfCards; w++) {
        String cardNumber1 = hand.get(i).cardName;
        String cardNumber2 = hand.get(w).cardName;
        if (cardNumber1.equals(cardNumber2) && i != w) {
          hasWin = true;
        }
      }
    }
    return hasWin;
  }
}
