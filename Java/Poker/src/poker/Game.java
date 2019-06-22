package poker;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javafx.scene.control.TextInputDialog;

public class Game extends Poker {

  public List<Card> newGame() {
    List<Card> deck = new ArrayList();
    addCards(deck);
    Collections.shuffle(deck);
    int numberOfCards = askForCardNumber();
    List<Card> hand = new ArrayList();
    hand = addCardsInHand(deck, numberOfCards);
    System.out.println(hand);
    boolean hasWin = checkWin(hand, numberOfCards);
    System.out.println(hasWin);
    return hand;
  }

  public void addCards(List<Card> deck) {
    Card.Seed seed = null;
    for (int i = 0; i < 4; i++) {
      if (i == 0) {
        seed = Card.Seed.Fiori;
      } else if (i == 1) {
        seed = Card.Seed.Picche;
      } else if (i == 2) {
        seed = Card.Seed.Quadri;
      } else if (i == 3) {
        seed = Card.Seed.Cuori;
      }

      deck.add(new Card(Card.CardName.A, seed));
      deck.add(new Card(Card.CardName._2, seed));
      deck.add(new Card(Card.CardName._3, seed));
      deck.add(new Card(Card.CardName._4, seed));
      deck.add(new Card(Card.CardName._5, seed));
      deck.add(new Card(Card.CardName._6, seed));
      deck.add(new Card(Card.CardName._7, seed));
      deck.add(new Card(Card.CardName._8, seed));
      deck.add(new Card(Card.CardName._9, seed));
      deck.add(new Card(Card.CardName._10, seed));
      deck.add(new Card(Card.CardName.J, seed));
      deck.add(new Card(Card.CardName.Q, seed));
      deck.add(new Card(Card.CardName.K, seed));
    }
  }

  public int askForCardNumber() {
    TextInputDialog textInputDialog = new TextInputDialog();
    textInputDialog.setContentText("Number of cards");
    textInputDialog.showAndWait();
    return Integer.parseInt(textInputDialog.getResult());
  }

  /**
   * get first 10 cards from the deck and put it in the hand
   *
   * @param deck contains all the cards of the deck
   * @param numberOfCards is the number of cards the users has requested to have
   * in his hand
   * @return returns the hand of cards the user
   */
  public List<Card> addCardsInHand(List<Card> deck, int numberOfCards) {
    List<Card> hand = new ArrayList();
    for (int i = 0; i < numberOfCards; i++) {
      hand.add(deck.get(i));
    }
    return hand;
  }
  
  public boolean checkWin(List<Card> hand, int numberOfCards) {
    boolean hasWin = false; // result if hand has win
    for (int i = 0; i < numberOfCards; i++) {
      for (int w = 0; w < numberOfCards; w++) {
        Card.CardName cardName1 = hand.get(i).cardName;
        Card.CardName cardName2 = hand.get(w).cardName;
        if (cardName1.equals(cardName2) && i != w) {
          hasWin = true;
        }
      }
    }
    return hasWin;
  }
  
  
}
