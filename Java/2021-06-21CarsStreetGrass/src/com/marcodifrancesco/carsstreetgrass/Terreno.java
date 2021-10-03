package com.marcodifrancesco.carsstreetgrass;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public abstract class Terreno extends StackPane {
    int size = 100;
    Rectangle rectangle;
    int row, col;

    Terreno(int row, int col) {
        this.row = row;
        this.col = col;
        rectangle = new Rectangle(size, size);
    }

    abstract void update();
}
