# Rocket Animation with OpenGL

## Introduction

This repository contains a simple OpenGL program that simulates a rocket launch animation with interactive controls. The program creates a graphical representation of a rocket, complete with a body, nose, fins, engine, and flames, which can be manipulated through keyboard and menu options. The user can control the rocket's position and toggle the flames' visibility with key presses, and modify the rocket's color scheme using a right-click context menu.

## Features

- **Rocket Animation**: The rocket is displayed in a 2D view, with options to move it vertically and toggle flames at the engine.
- **Interactive Controls**: 
  - The rocket’s flames can be toggled on or off with the 'P' key.
  - The rocket’s vertical position can be adjusted using the arrow keys (up and down).
- **Color Customization**: A right-click menu allows users to change the rocket's body, nose, fins, and engine colors dynamically.
- **Basic Ground and Antenna Towers**: The scene includes a ground plane and antenna towers for added detail and realism.
  
## How It Works

The program utilizes OpenGL and GLUT (OpenGL Utility Toolkit) for rendering the graphics. The main components include:

1. **Rocket Drawing**: The rocket is drawn using basic geometric shapes like rectangles and triangles. Its body, nose, fins, and engine are colored based on predefined color constants.
2. **Flames**: The flames behind the rocket are drawn as a triangle shape and appear/disappear based on the `flamesVisible` flag, which is toggled by the user.
3. **Menu**: A custom context menu allows users to change the colors of different parts of the rocket.
4. **Keyboard and Mouse Input**: The program reacts to keyboard inputs for controlling the rocket's position and toggling the flame effect. The right-click context menu lets users change the rocket's colors dynamically.

## How to Run

1. Install OpenGL and GLUT. This may vary depending on your operating system, but for most systems, you can use package managers like `apt`, `brew`, or `pacman` to install these libraries.
2. Compile the code with a C++ compiler that supports OpenGL and GLUT, such as `g++`:
   ```bash
   g++ -o rocket_animation rocket_animation.cpp -lGL -lGLU -lglut
./rocket_animation

This `README.md` file includes an overview, features, how to run the code, and the available controls. You can copy and paste this into your GitHub repository.

