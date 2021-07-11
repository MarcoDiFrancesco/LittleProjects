package com.marcodifrancesco.subway;

import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;

public class Game extends BorderPane {
    PlayingField playingField;
    ButtonBar buttonBar;

    Game() {
        playingField = new PlayingField();
        setCenter(playingField);
        buttonBar = new ButtonBar(playingField);
        setBottom(buttonBar);
        addHandlers();
    }

    void addHandlers() {
        addEventHandler(KeyEvent.KEY_TYPED, keyEvent -> {
            if (keyEvent.getCharacter().equals("r"))
                playingField.random();
        });

    }
}
