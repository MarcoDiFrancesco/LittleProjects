package com.marcodifrancesco.subway;

import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class CellHorizontal extends Cell {
    Line line;
    Color color;

    CellHorizontal() {
        color = Color.BLACK;
        line = new Line();
        getLine();
        getChildren().add(line);
    }

    @Override
    public String toString() {
        return "Dritto";
    }

    @Override
    void setEventHandler() {
        addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> {
            color = switchColor(color);
            line.setStroke(color);
        });
    }

    void getLine() {
        line.setStartX(0);
        line.setStartY(15);
        line.setEndX(100);
        line.setEndY(15);
    }
}
