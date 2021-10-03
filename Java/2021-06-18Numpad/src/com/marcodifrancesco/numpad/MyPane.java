package com.marcodifrancesco.numpad;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.TilePane;

import java.util.ArrayList;

public class MyPane extends TilePane {
    ArrayList<ArrayList<MyButton>> buttons = new ArrayList<>();

    MyPane() {
        int count = 0;
        for (int row = 0; row < 3; row++) {
            ArrayList<MyButton> tmpList = new ArrayList<>();
            for (int col = 0; col < 3; col++) {
                String value = Integer.toString(count);
                count += 1;
                MyButton button = new MyButton(row, col, value);
                button.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> updateButton(button));
                tmpList.add(button);
            }
            buttons.add(tmpList);
        }
        buttons.get(2).get(2).updateValue("");
        updateButtons();
    }


    void updateButton(MyButton btn) {
        String up, down, right, left;
        int row = btn.row;
        int col = btn.col;
        up = getButtonValue(btn.row - 1, btn.col);
        down = getButtonValue(btn.row + 1, btn.col);
        right = getButtonValue(btn.row, btn.col - 1);
        left = getButtonValue(btn.row, btn.col + 1);

        if (up.equals("")) {
            swapValues(row, col, row - 1, col);
        } else if (down.equals("")) {
            swapValues(row, col, row + 1, col);
        } else if (right.equals("")) {
            swapValues(row, col, row, col - 1);
        } else if (left.equals("")) {
            swapValues(row, col, row, col + 1);
        }
    }

    String getButtonValue(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            return "-";
        }
        return buttons.get(row).get(col).getText();
    }

    void swapValues(int row1, int col1, int row2, int col2) {
        String val1 = buttons.get(row1).get(col1).getText();
        String val2 = buttons.get(row2).get(col2).getText();
        buttons.get(row1).get(col1).updateValue(val2);
        buttons.get(row2).get(col2).updateValue(val1);

    }

    void updateButtons() {
        getChildren().removeAll();
        for (ArrayList<MyButton> rows : buttons) {
            for (MyButton button : rows) {
                getChildren().addAll(button);
            }
        }
    }
}
