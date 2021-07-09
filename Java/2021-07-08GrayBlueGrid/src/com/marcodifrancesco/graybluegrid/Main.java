package com.marcodifrancesco.graybluegrid;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Game root = new Game();
        primaryStage.setTitle("Game");
        primaryStage.setScene(new Scene(root, 260, 300));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
