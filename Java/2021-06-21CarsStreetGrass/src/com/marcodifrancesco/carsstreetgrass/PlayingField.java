package com.marcodifrancesco.carsstreetgrass;

import javafx.scene.layout.GridPane;

public class PlayingField extends GridPane {
    Terreno[][] terreni;
    int size = 8;

    PlayingField() {
        terreni = new Terreno[size][size];
        initTerreno();
        updateTerreno();
    }

    void initTerreno() {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                Terreno terreno;
                if (row == 0 || col == 0 || row == size - 1 || col == size - 1) {
                    terreno = new Strada(row, col);
                } else {
                    terreno = new Prato(row, col);
                }
                terreni[row][col] = terreno;
            }
        }
    }


    void updateTerreno() {
        getChildren().clear();
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                add(terreni[row][col], row, col);
            }
        }
    }
}
