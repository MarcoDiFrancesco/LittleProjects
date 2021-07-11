package com.marcodifrancesco.subway;

import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class CellCurve extends Cell {
    Line line;
    Color color;

    CellCurve() {
        color = Color.BLACK;
        line = new Line();
        getLine();
        getChildren().add(line);
    }

    public String toString() {
        return "Curva";
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
        line.setEndX(50);
        line.setEndY(30);
    }
}
