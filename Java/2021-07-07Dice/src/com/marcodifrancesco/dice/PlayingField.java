package com.marcodifrancesco.dice;

import javafx.geometry.Insets;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;

import java.util.ArrayList;

public class PlayingField extends FlowPane {
    ArrayList<Dice> dice;
    int score;
    // Number of time field was clicked
    int clicks = 0;

    PlayingField() {
        dice = new ArrayList<>();
        setBackground(new Background(new BackgroundFill(Color.LIGHTGREEN, CornerRadii.EMPTY, Insets.EMPTY)));
        addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> addDice());
        // Reset score
        score = 0;
    }

    int getTotal() {
        int total = 0;
        for (Dice d : dice) {
            total += d.value;
        }
        return total;
    }

    int getScore() {
        int score = 30 - 3 * clicks;
        for (Dice d : dice) {
            score -= d.clicks;
        }
        return score;
    }

    void update() {
        getChildren().clear();
        getChildren().addAll(dice);
    }

    void reset() {
        dice.clear();
        score = 0;
        update();
    }

    void addDice() {
        clicks += 1;
        if (dice.size() < 5) {
            score -= 3;
            dice.add(new Dice());
            update();
        }
    }
}
