*This project has been created as part of the 42 curriculum by mjoao-fr and brmaria-.*

# Cub3D

## Description:   
Cub3D is a graphics project that renders a 2D map using a raycasting algorithm to create and simulate a 3D perspective.
Its goal is to help the student improve skills in C, to mantain rigor, to understand and apply algorithms and mathematic expressions and to explore the graphical part (window management, colors and shapes).

## Instructions:
How to use:   
1) Type `make` to compile the project;
2) Type `./cub3D` followed by the map you want to run, for example: `maps/lava_map.cub`;
3) Move your player using **w**, **a**, **s**, **d** and move the camera using **left arrow** and **right arrow**.
4) Have fun exploring the different maps!

## Resources:

**Raycasting Process:**

1) First we need to figure out where the player is looking and what the player can see. The direction where the player is currently facing is represented by a vector dir_x and dir_y. We need to use a vector because it gives precise direction (allows the in-between angles when the player rotates).
2) What the player sees defines the *FOV* and it is a vector perpendicular to the player's direction vector. It determinates the left and right edge of what the player sees. Points left/right across the screen. Everything inside the *FOV* is what the player sees, and everything inside it will be rendered.
3) How to render the 3D world: we send one ray for each vertical stripe of pixels on the screen - the ray sweeps across the FOV and uses DDA Algorithm to figure out the distance to a wall and that's how it gets rendered column by column.

**DDA Algorithm**
(Digital Differential Analysis):  
This algorithm helps to figure out which square (tile) on the 2D map does the ray hit first.
1) Traces a step-by-step through a grid (the map);
2) Checks at each step whether you've hit a wall;
3) Stops when a wall is hit and records the distance (calculates the distance from the player to the point where a ray intersects a wall).   
   



**Some links with great explanations:**
1) https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13
2) https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a

Some of the textures in the *textures* directory are images from the internet and some were created by us.
