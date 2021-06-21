package com.marcodifrancesco.carsstreetgrass;

import javafx.scene.paint.Color;

public class Prato extends Terreno {

    Prato(int row, int col) {
        super(row, col);
        super.rectangle.setFill(Color.GREEN);
        update();
    }

    void update() {
        getChildren().removeAll();
        getChildren().add(rectangle);
    }
}
