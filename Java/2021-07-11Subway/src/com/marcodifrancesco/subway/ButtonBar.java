package com.marcodifrancesco.subway;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class ButtonBar extends HBox {
    private Button testButton, resetButton;

    ButtonBar(PlayingField playingField) {
        testButton = new Button("Test");
        testButton.addEventHandler(ActionEvent.ACTION, actionEvent -> playingField.random());
        resetButton = new Button("Reset");
        resetButton.addEventHandler(ActionEvent.ACTION, actionEvent -> playingField.reset());
        getChildren().addAll(testButton, resetButton);
    }
}
