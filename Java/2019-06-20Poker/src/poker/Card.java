package poker;

public class Card {
    enum Value {
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

    Value value;
    Seed seed;

    Card(Value value, Seed seed) {
        this.value = value;
        this.seed = seed;
    }

    @Override
    public String toString() {
        return "(" + value + "," + seed + ")";
    }
}
