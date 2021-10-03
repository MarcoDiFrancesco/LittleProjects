package com.marcodifrancesco.numpad;

import javafx.scene.control.Button;

public class MyButton extends Button {
    double buttonSize = 500 / 3;
    int row;
    int col;

    MyButton(int row, int col, String value) {
        super(value);
        this.row = row;
        this.col = col;
        setMinSize(buttonSize, buttonSize);
        setMaxSize(buttonSize, buttonSize);
        setStyle("-fx-font-size:40");
    }

    void updateValue(String value) {
        setText(value);
    }
}
