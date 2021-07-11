package com.marcodifrancesco.subway;

import javafx.scene.Scene;
import javafx.stage.Stage;

public class Palette extends Stage {

    Palette() {
        PaletteGrid paletteGrid = new PaletteGrid();
        setScene(new Scene(paletteGrid, 200, 150));
        show();
    }
}
