package com.marcodifrancesco.dice;

import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;

public class Game extends BorderPane {

    PlayingField playingField;
    Button btnNewMatch, btnPrint;
    Text textTotal, textScore;

    Game() {
        // Buttons
        HBox hBox = new HBox();
        btnNewMatch = new Button("Nuova partita");
        btnNewMatch.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> reset());
        btnPrint = new Button("Stampa");
        btnPrint.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> print());
        textTotal = new Text(" TOTALE: 0");
        textScore = new Text(" PUNTEGGIO: 0");
        hBox.getChildren().addAll(btnPrint, btnNewMatch, textTotal, textScore);
        setBottom(hBox);
        // Center field
        playingField = new PlayingField();
        setCenter(playingField);
        // Event filter to get update before handler Dice consume
        addEventFilter(MouseEvent.MOUSE_CLICKED, mouseEvent -> updateText());
    }


    void reset() {
        playingField.reset();
        playingField.score = 0;
    }

    void updateText() {
        int total = playingField.getTotal();
        int score = playingField.getScore();
        textTotal.setText(String.format("TOTALE: %d", total));
        textScore.setText(String.format("PUNTEGGIO: %d", score));
    }

    void print() {
        System.out.println("Print everything from playing field");

    }
}
