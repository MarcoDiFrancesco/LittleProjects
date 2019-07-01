package figuregeometricheesame;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

/**
 * Contains the main window of the program
 *
 * @author marco
 */
public class MainWindow extends BorderPane {

  public static final int MAX_VBOX_SHAPE = 5;
  List<Shape> shapeList = new ArrayList();
  StackPane mainShape = new StackPane();
  Rectangle rectangleMainShape = new Rectangle(100, 100);

  VBox vBox = new VBox();

  Button addButton = new Button("Add");
  Button removeBottomButton = new Button("Remove Bottom");
  Button removeTopButton = new Button("Remove Top");
  Button printStackButton = new Button("Print Stack");
  Button cicleShapeButton = new Button("Circle");
  Button triangleShapeButton = new Button("Triangle");
  Button hexagonShapeButton = new Button("Hexagon");

  FlowPane flowPaneCenter = new FlowPane();

  FlowPane flowPaneTop = new FlowPane();
  FlowPane flowPaneBottom = new FlowPane();

  MainWindow() {
    addLeftBoxes();
    setLeft(vBox);
    rectangleMainShape.setStroke(Color.AQUAMARINE);
    rectangleMainShape.setStrokeWidth(1);
    mainShape.getChildren().add(rectangleMainShape);
    addCenterBoxes();
    setCenter(flowPaneCenter);
    flowPaneBottom.setAlignment(Pos.CENTER);
    flowPaneCenter.setAlignment(Pos.CENTER);
    flowPaneTop.setAlignment(Pos.CENTER);
    
    setButtonEvent();
  }

  /**
   * Adds initially the boxes with empty shapes
   */
  private void addLeftBoxes() {
    shapeList.add(new EmptyShape());
    shapeList.add(new EmptyShape());
    shapeList.add(new EmptyShape());
    shapeList.add(new EmptyShape());
    shapeList.add(new EmptyShape());

    vBox.getChildren().addAll(shapeList);
  }

  /**
   * Add the buttons and the central shape (named mainShape)
   */
  private void addCenterBoxes() {
    addButton.setMinWidth(200.0);
    addButton.setMaxWidth(200.0);
    flowPaneTop.getChildren().add(addButton);
    removeBottomButton.setMinWidth(200.0);
    removeBottomButton.setMaxWidth(200.0);
    flowPaneTop.getChildren().add(removeBottomButton);
    removeTopButton.setMinWidth(200.0);
    removeTopButton.setMaxWidth(200.0);
    flowPaneTop.getChildren().add(removeTopButton);
    printStackButton.setMinWidth(200.0);
    printStackButton.setMaxWidth(200.0);
    flowPaneTop.getChildren().add(printStackButton);

    cicleShapeButton.setMinWidth(132.3);
    cicleShapeButton.setMaxWidth(132.3);
    flowPaneBottom.getChildren().add(cicleShapeButton);
    triangleShapeButton.setMinWidth(132.3);
    triangleShapeButton.setMaxWidth(132.3);
    flowPaneBottom.getChildren().add(triangleShapeButton);
    hexagonShapeButton.setMinWidth(132.3);
    hexagonShapeButton.setMaxWidth(132.3);
    flowPaneBottom.getChildren().add(hexagonShapeButton);

    flowPaneCenter.getChildren().addAll(flowPaneTop, mainShape, flowPaneBottom);
  }

  /**
   * Refresh all the figures of the program
   */
  public void refresh() {
    vBox.getChildren().clear();
    vBox.getChildren().addAll(shapeList);
    flowPaneCenter.getChildren().removeAll(flowPaneTop, mainShape, flowPaneBottom);
    flowPaneCenter.getChildren().addAll(flowPaneTop, mainShape, flowPaneBottom);
  }

  /**
   * Set all the events of the buttons
   */
  private void setButtonEvent() {

    /**
     * Set the button to make appear the circle in the central panel
     */
    cicleShapeButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      try {
        mainShape.getChildren().remove(1);
      } catch (Exception e) {
      }
      mainShape.getChildren().add(new CircleShape());
      cicleShapeButton.setDisable(true);
      triangleShapeButton.setDisable(false);
      hexagonShapeButton.setDisable(false);
      refresh();
    });
    
    /**
     * Set the button to make appear the triangle in the central panel
     */
    triangleShapeButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      try {
        mainShape.getChildren().remove(1);
      } catch (Exception e) {
      }
      mainShape.getChildren().add(new TriangleShape());
      cicleShapeButton.setDisable(false);
      triangleShapeButton.setDisable(true);
      hexagonShapeButton.setDisable(false);
      refresh();
    });

    /**
     * Set the button to make appear the hexagon in the central panel
     */
    hexagonShapeButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      try {
        mainShape.getChildren().remove(1);
      } catch (Exception e) {
      }
      mainShape.getChildren().add(new HexagonShape());
      cicleShapeButton.setDisable(false);
      triangleShapeButton.setDisable(false);
      hexagonShapeButton.setDisable(true);
      refresh();
    });

    /**
     * Set the button to move the figure from the center panel (mainPanel) to
     * the figures in the left
     */
    addButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      Shape checkShape = shapeList.get(0);
      if (checkShape instanceof EmptyShape) {
        try {
          shapeList.add((Shape) mainShape.getChildren().get(1));
          shapeList.remove(0);
        } catch (IndexOutOfBoundsException indexOutOfBoundsException) {
          Alert alert = new Alert(Alert.AlertType.INFORMATION);
          alert.setContentText("You didn't select any shape to add");
          alert.showAndWait();
        }
      } else {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText("Shape list is full");
        alert.showAndWait();
      }
      cicleShapeButton.setDisable(false);
      triangleShapeButton.setDisable(false);
      hexagonShapeButton.setDisable(false);
      refresh();
    });

    /**
     * Remove the figure from the bottom of the 5 figures, if there is no figure
     * to remove throws an error
     */
    removeBottomButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      Shape checkShape = shapeList.get(4);
      if (checkShape instanceof EmptyShape) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText("There is no block to remove");
        alert.showAndWait();
      } else {
        shapeList.remove(4);
        shapeList.add(0, new EmptyShape());
      }
      refresh();
    });

    /**
     * Remove the figure from the top of the 5 figures, if there is no figure to
     * remove throws an error
     */
    removeTopButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      Shape checkShape = shapeList.get(4);
      boolean isShapeEmpty = false;
      if (checkShape instanceof EmptyShape) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText("There is no block to remove");
        alert.showAndWait();
      } else {
        if (!(shapeList.get(0) instanceof EmptyShape)) {
          shapeList.remove(0);
          shapeList.add(0, new EmptyShape());
        } else if (!(shapeList.get(1) instanceof EmptyShape)) {
          shapeList.remove(1);
          shapeList.add(1, new EmptyShape());
        } else if (!(shapeList.get(2) instanceof EmptyShape)) {
          shapeList.remove(2);
          shapeList.add(2, new EmptyShape());
        } else if (!(shapeList.get(3) instanceof EmptyShape)) {
          shapeList.remove(3);
          shapeList.add(3, new EmptyShape());
        } else if (!(shapeList.get(4) instanceof EmptyShape)) {
          shapeList.remove(4);
          shapeList.add(4, new EmptyShape());
        }
      }
      refresh();
    });

    /**
     * Print the stack ordered by name. The order i chose is: Circle Hexagon
     * Triangle null (contains the empty figure)
     */
    printStackButton.addEventHandler(MouseEvent.MOUSE_CLICKED, (MouseEvent event) -> {
      List<String> stringList = new ArrayList();
      for (Shape shape1 : shapeList) {
        if (shape1 instanceof CircleShape) {
          stringList.add("Circle");
        } else if (shape1 instanceof HexagonShape) {
          stringList.add("Hexagon");
        } else if (shape1 instanceof TriangleShape) {
          stringList.add("Triangle");
        } else if (shape1 instanceof EmptyShape) {
          stringList.add("null");
        }
      }
      Collections.sort(stringList);
      System.out.println(stringList);
    });
  }

}
