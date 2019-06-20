package poker;

public class Card {

  String cardName;
  String seed;

  Card(String cardName, String seed) {
    this.cardName = cardName;
    this.seed = seed;
  }

  public String toString() {
    return "(" + cardName + "," + seed + ")";
  }

}
