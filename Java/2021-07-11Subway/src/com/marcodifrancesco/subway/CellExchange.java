package com.marcodifrancesco.subway;

import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;


public class CellExchange extends Cell {
    private Line horizontalLine, obliqueLine;
    private Color horizontalColor, obliqueColor;


    CellExchange() {
        horizontalLine = new Line();
        horizontalColor = Color.BLACK;
        obliqueLine = new Line();
        obliqueColor = Color.BLACK;
        getLines();
        getChildren().addAll(horizontalLine, obliqueLine);
    }

    @Override
    void setEventHandler() {
        addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> {
            if (mouseEvent.getY() >= 15)
                switchHorizontalColor();
            else
                switchObliqueColor();
        });
    }

    @Override
    public String toString() {
        return "Scambio";
    }


    private void switchHorizontalColor() {
        horizontalColor = switchColor(horizontalColor);
        horizontalLine.setStroke(switchColor(horizontalColor));
    }

    private void switchObliqueColor() {
        obliqueColor = switchColor(obliqueColor);
        obliqueLine.setStroke(switchColor(obliqueColor));
    }

    void getLines() {
        horizontalLine.setStartX(0);
        horizontalLine.setStartY(15);
        horizontalLine.setEndX(100);
        horizontalLine.setEndY(15);

        obliqueLine.setStartX(50);
        obliqueLine.setStartY(0);
        obliqueLine.setEndX(100);
        obliqueLine.setEndY(15);
    }

}
