package poker;

public class Card {

  enum CardName {

    A,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    J,
    Q,
    K
  }

  enum Seed {

    Cuori,
    Fiori,
    Picche,
    Quadri
  }

  CardName cardName;
  Seed seed;

  Card(CardName cardName, Seed seed) {
    this.cardName = cardName;
    this.seed = seed;
  }

  @Override
  public String toString() {
    return "(" + cardName + "," + seed + ")";
  }
}
