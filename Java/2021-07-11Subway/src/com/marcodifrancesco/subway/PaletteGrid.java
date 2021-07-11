package com.marcodifrancesco.subway;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;

public class PaletteGrid extends GridPane {
    Cell[][] cells;
    private static final int CELLS_X = 2;
    private static final int CELLS_Y = 5;

    PaletteGrid() {
        cells = new Cell[CELLS_X][CELLS_Y];
        initCells();
        cells[0][0] = new CellEmpty();
        cells[1][0] = new CellHorizontal();
        cells[0][1] = new CellCurve();
        cells[1][1] = new CellExchange();
        setEventHandlers();
        update();
    }

    void setEventHandlers() {
        for (int i = 0; i < CELLS_X; i++)
            for (int j = 0; j < CELLS_Y; j++)
                cells[i][j].addEventFilter(MouseEvent.MOUSE_CLICKED, mouseEvent -> {
                    Cell cell = (Cell) mouseEvent.getSource();
                    changeGrayCells(cell);
                    // Print type
                    System.out.println(cell);
                    mouseEvent.consume();
                });
    }

    void changeGrayCells(Cell cellType) {
        // If clicked cell is empty do nothing
        if (cellType instanceof CellEmpty)
            return;
        // Else update all gray empty cells
        for (int i = 0; i < CELLS_X; i++) {
            for (int j = 0; j < CELLS_Y; j++) {
                // If cell is empty
                if (cells[i][j] instanceof CellEmpty) {
                    CellEmpty cell = (CellEmpty) cells[i][j];
                    if (cell.color == Color.LIGHTGRAY)
                        if (cellType instanceof CellCurve)
                            cells[i][j] = new CellCurve();
                        else if (cellType instanceof CellHorizontal)
                            cells[i][j] = new CellCurve();
                        else if (cellType instanceof CellExchange)
                            cells[i][j] = new CellExchange();
                }
            }
        }
        update();
    }


    void initCells() {
        for (int i = 0; i < CELLS_X; i++) {
            for (int j = 0; j < CELLS_Y; j++) {
                Cell cell = new CellEmpty();
                // Initialize empty to gray
                ((CellEmpty) cell).switchBackground();
                cells[i][j] = cell;
            }
        }
    }

    void update() {
        getChildren().clear();
        for (int i = 0; i < CELLS_X; i++)
            for (int j = 0; j < CELLS_Y; j++)
                add(cells[i][j], i, j);
    }
}
