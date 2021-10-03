package com.marcodifrancesco.graybluegrid;

import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;

public class PlayingField extends GridPane {
    Cell[][] cells;
    Cell[] rightCells, bottomCells;
    int FIELD_SIZE = 4;

    PlayingField() {
        cells = new Cell[FIELD_SIZE][FIELD_SIZE];
        rightCells = new Cell[FIELD_SIZE];
        bottomCells = new Cell[FIELD_SIZE];
        initCells();
        update();
    }

    void initCells() {
        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                cells[i][j] = new Cell();
                add(cells[i][j], i, j);
            }
        }
        for (int i = 0; i < FIELD_SIZE; i++) {
            rightCells[i] = new Cell(Color.GREEN);
            add(rightCells[i], FIELD_SIZE, i);
            bottomCells[i] = new Cell(Color.RED);
            add(bottomCells[i], i, FIELD_SIZE);
        }
    }

    void update() {
        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                cells[i][j].update();
            }
        }
        updateSumCells();
        checkWin();
    }

    private void updateSumCells() {
        resetSumCells();
        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                rightCells[j].value += cells[i][j].value;
                rightCells[j].update();
                bottomCells[i].value += cells[i][j].value;
                bottomCells[i].update();
            }
        }
    }

    private void resetSumCells() {
        for (int i = 0; i < FIELD_SIZE; i++) {
            rightCells[i].value = 0;
            bottomCells[i].value = 0;
        }
    }

    private void checkWin() {
        boolean hasWin = false;
        boolean hasLost = false;
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (rightCells[i].value == 10)
                hasWin = true;
            if (bottomCells[i].value == 10)
                hasLost = true;
        }
        
        if (hasWin && hasLost)
            new Popup("Pari!");
        else if (hasWin)
            new Popup("Hai vinto");
        else if (hasLost)
            new Popup("Hai perso");
    }
}
