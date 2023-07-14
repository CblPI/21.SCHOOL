# 3DViewer v2.1

Implementation of 3DViewer

## Part 1. 3DViewer v2.1

Develop a program to visualize the 3D model.

- The program must be developed in C++ language of C++17 standard
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory could be arbitrary, except the building one
- The program should be developed according to the principles of object-oriented programming; the structured programming approach is not allowed
- Prepare full coverage of modules related to model loading and affine transformations with unit-tests
- There should be only one model on the screen at a time
- The program must provide the ability to:
    - Load a model from an obj file (vertices, surfaces and normal list support).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle in relation to its X, Y, Z axes.
    - Scale the model by a given value.
    - Toggle the type of object display: wireframe model, flat shading and smooth shading (by Gouraud or Phong methods)
    - Set the light source, its base intensity (via the three components: R, G, B) and position.
- GUI implementation, based on any GUI library with API for C++ (Qt, SFML, GTK+, Nanogui, Nngui, etc.)
  The graphical user interface must contain:
    - A button to select the model file and a field to output its name.
    - A visualization area for the model.
    - Button/buttons and input fields for translating the model.
    - Button/buttons and input fields for rotating the model.
    - Button/buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.
- The program must correctly processes and allows user to view models with details up to 100, 1000, 10,000, 100,000, 1,000,000  vertices without freezing (a freeze is an interface inactivity of more than 0.5 seconds)
- The program must be implemented using the MVC pattern, and also:
    - there should be no business code in the view code
    - there should be no interface code in the controller and the model
    - controllers must be thin
- There should be at least three different design patterns (e.g. facade, strategy and command)
- Classes must be implemented within the `s21` namespace
- To perform affine transformations, you can use the matrices from the library of the previous s21_matrix+ project

## Part 2. Bonus. Settings

- The program must allow customizing the type of projection (parallel and central)
- The program must allow setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program must allow choosing the background color
- The program must allow selecting the base color of the object
- Settings must be saved between program restarts

## Part 3. Bonus. Record

- The program must allow saving the captured (rendered) images as bmp and jpeg files.
- The program must allow recording small screencasts - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s) by a special button
- The program must allow saving a short preview of the model - gif-animation (640x480, 10fps, 5s) with rotation of the object around one axis by a special button.

## Part 4. Bonus. Texturing

- The program must allow applying a texture to an object (texture mapping) that has a UV-map
- When rendering, the polygons of the model must be shaded according to the UV-mapping
- When you load a model with UV-mapping, the "Apply Texture" button should appear, which allows you to select a texture file
- The resolution of a texture file cannot be more than 1024x1024 pixels
- The texture file has a BMP extension
- The texture can only be square, and the coordinates are always normalized to values between 0 and 1
- The texture must not be displayed in the wireframe mode
- After the texture is loaded, the "Unload texture" button should appear in the program interface, which makes the texture unloaded from the program memory and no longer displayed on the model
- Read the UV-map of the model from the obj-file
- The program must allow saving a UV-map of the model over the selected texture into a separate BMP-file; the texture must show the specified color of the model's map

