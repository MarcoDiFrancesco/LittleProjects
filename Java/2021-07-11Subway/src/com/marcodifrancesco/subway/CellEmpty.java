package com.marcodifrancesco.subway;

import javafx.geometry.Insets;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.paint.Color;

public class CellEmpty extends Cell {
    Color color;

    CellEmpty() {
        color = Color.WHITE;
        update();
    }

    void switchBackground() {
        if (color == Color.WHITE)
            color = Color.LIGHTGRAY;
        else if (color == Color.LIGHTGRAY)
            color = Color.WHITE;
        update();
    }

    @Override
    public String toString() {
        return "Vuoto";
    }


    @Override
    void setEventHandler() {
        addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> switchBackground());
    }

    private void update() {
        setBackground(new Background(new BackgroundFill(color, CornerRadii.EMPTY, Insets.EMPTY)));
    }

}
