package com.marcodifrancesco.graybluegrid;

import javafx.scene.layout.BorderPane;

public class Game extends BorderPane {
    PlayingField playingField;
    ButtonsBar buttonsBar;

    Game() {
        playingField = new PlayingField();
        setCenter(playingField);
        buttonsBar = new ButtonsBar(playingField);
        setBottom(buttonsBar);
    }
    
}
