package com.marcodifrancesco.graybluegrid;

import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Popup extends Stage {

    Popup(String text) {
        StackPane root = new StackPane();
        root.getChildren().add(new Text(text));
        setScene(new Scene(root, 300, 100));
        show();
    }
}
