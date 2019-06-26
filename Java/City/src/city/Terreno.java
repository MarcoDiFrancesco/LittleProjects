package city;

import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;

public abstract class Terreno extends StackPane {

  public Terreno() {
    addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {

      @Override
      public void handle(MouseEvent event) {
        mouseClicked();
      }
    });
  }

  public void mouseClicked() {
    boolean isAddCarClicked = false;

    try {
      isAddCarClicked = ((Strada) this).isAddCarClicked;
    } catch (Exception e) {
    }
    try {
      isAddCarClicked = ((Prato) this).isAddCarClicked;
    } catch (Exception e) {
    }
    try {
      isAddCarClicked = ((Macchina) this).isAddCarClicked;
    } catch (Exception e) {
    }
    
    if (this instanceof Strada | this instanceof Prato | isAddCarClicked == false) {
      exchange();
    } else if (isAddCarClicked == true) {
      addCar();
    }

  }

  /**
   * Change block from strada to prato and vice versa
   */
  public void exchange() {
    if (this instanceof Strada) {
      ((Strada) this).gridPane.add(new Prato(((Strada) this).isAddCarClicked, ((Strada) this).gridPane, ((Strada) this).posX, ((Strada) this).posY), ((Strada) this).posX, ((Strada) this).posY);
    } else if (this instanceof Prato) {
      ((Prato) this).gridPane.add(new Strada(((Prato) this).isAddCarClicked, ((Prato) this).gridPane, ((Prato) this).posX, ((Prato) this).posY), ((Prato) this).posX, ((Prato) this).posY);
    } else {
      System.err.println("Not prato or strada");
    }
  }

  private void addCar() {
    if (this instanceof Strada) {
      ((Strada) this).gridPane.add(new Macchina(((Strada) this).isAddCarClicked, ((Strada) this).gridPane, ((Strada) this).posX, ((Strada) this).posY), ((Strada) this).posX, ((Strada) this).posY);
    } else if (this instanceof Prato) {
      ((Prato) this).gridPane.add(new Macchina(((Prato) this).isAddCarClicked, ((Prato) this).gridPane, ((Prato) this).posX, ((Prato) this).posY), ((Prato) this).posX, ((Prato) this).posY);
    } else {
      System.err.println("Not prato or strada");
    }
  }
}
