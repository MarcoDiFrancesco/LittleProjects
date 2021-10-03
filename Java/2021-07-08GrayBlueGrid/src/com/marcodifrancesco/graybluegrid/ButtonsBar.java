package com.marcodifrancesco.graybluegrid;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;

public class ButtonsBar extends HBox {
    // Value of the button
    int value;
    Button numberButton, rowButton, colButton;
    PlayingField playingField;

    ButtonsBar(PlayingField playingField) {
        value = 1;
        this.playingField = playingField;
        numberButton = new Button("1");
        numberButton.addEventHandler(ActionEvent.ACTION, actionEvent -> updateValue());
        rowButton = new Button("Cambia Riga");
        rowButton.addEventHandler(ActionEvent.ACTION, actionEvent -> updateRow());
        colButton = new Button("Cambia Colonna");
        colButton.addEventHandler(ActionEvent.ACTION, actionEvent -> updateCol());
        getChildren().addAll(numberButton, rowButton, colButton);
    }

    /**
     * Update button value
     */
    void updateValue() {
        if (value == 4) {
            value = 1;
        } else {
            value += 1;
        }
        numberButton.setText(Integer.toString(value));
    }

    /**
     * Update values of selected row
     */
    void updateRow() {
        for (int i = 0; i < playingField.FIELD_SIZE; i++) {
            // Array goes from 0 to 3, shown values from 1 to 4
            int rowToUpdate = value - 1;
            playingField.cells[i][rowToUpdate].updateValue();
        }
        playingField.update();
    }

    /**
     * Update values of selected col
     */
    void updateCol() {
        for (int i = 0; i < playingField.FIELD_SIZE; i++) {
            // Array goes from 0 to 3, shown values from 1 to 4
            int colToUpdate = value - 1;
            playingField.cells[colToUpdate][i].updateValue();
        }
        playingField.update();
    }
}
