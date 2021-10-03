package com.marcodifrancesco.subway;

import javafx.geometry.Insets;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public abstract class Cell extends Pane {
    Cell() {
        setPrefSize(100, 30);
        setBackground(new Background(new BackgroundFill(Color.LIGHTGRAY, CornerRadii.EMPTY, Insets.EMPTY)));
        setBorder(new Border(new BorderStroke(Color.BLUE, BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT)));
        setEventHandler();
    }

    Color switchColor(Color color) {
        if (color == Color.RED)
            color = Color.BLACK;
        else if (color == Color.BLACK)
            color = Color.RED;
        return color;
    }

    abstract void setEventHandler();
    public abstract String toString();
}
