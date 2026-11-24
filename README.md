_This project has been created as part of the 42 curriculum by omiskiny, sjolliet._

# cub3D - 42 Common Core

## Description

cub3D is a small 3D graphics project written in C with the MiniLibX library. It is inspired by the first-person shooters of the early 1990s, which gave a 2D maze the appearance of 3D using a technique called **raycasting**.

The goal is to display a maze from the player's point of view. The program reads a scene description file (`.cub`) containing the wall textures, the floor and ceiling colors and the map, checks that it is valid, then renders the scene in a window.

How it works:

- **Parsing:** the scene file is read and validated (file extension, texture paths, colors, map characters, a single player, a map enclosed by walls). If anything is wrong, the program prints `Error` followed by the reason and exits cleanly.
- **Raycasting:** one ray is cast for each column of the window. The DDA (Digital Differential Analysis) algorithm moves it through the grid square by square until it hits a wall.
- **Rendering:** the perpendicular distance to that wall gives the height of the column to draw, which avoids the fisheye effect. A 2D minimap with the player's position is drawn in the top left corner.

## Instructions

### Requirements

The project runs on Linux and needs `make`, a C compiler (`cc` and `gcc`) and the X11 development libraries. On Debian / Ubuntu:
```bash
sudo apt install build-essential libx11-dev libxext-dev libbsd-dev
```

### Compilation

Clone the repository and compile the project using `make`:
```bash
git clone <repository_url>
cd <project_name>
make
```

### Usage

Launch cub3D with a scene file as its only argument:
```bash
./cub3d maps/valid/minimalist.cub
```

Run it from the root of the repository, since the texture paths in the provided maps are relative to it.

Invalid scenes are available in `maps/invalid` to test error handling:
```bash
$> ./cub3d maps/invalid/too-many-players.cub
Error
Map grid: Number of players is incorrect
```

### Controls

| Input | Action |
|-------|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `Esc` | Quit the program |
| Window close button | Quit the program |

### Scene file format

A `.cub` file contains six parameters, in any order, followed by the map:
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
101101
10E001
111111
```

| Parameter | Meaning |
|-----------|---------|
| `NO`, `SO`, `WE`, `EA` | Path to the `.xpm` texture of the north, south, west and east walls |
| `F`, `C` | Floor and ceiling colors, as `R,G,B` values from 0 to 255 |

| Map character | Meaning |
|---------------|---------|
| `1` | Wall |
| `0` | Empty space |
| `N`, `S`, `E`, `W` | Player's starting position and the direction they face (exactly one) |
| space | Outside of the map |

The map must come last, be fully enclosed by walls and contain no empty lines.

## Resources

### References
- **The Linux Programming Interface**  
https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf
- **Linux Man Pages online**  
https://man7.org/linux/man-pages/
- **Lode's Computer Graphics Tutorial**  
https://lodev.org/cgtutor/raycasting.html

### AI Usage
AI tools were used as learning and productivity aids for :

- Getting help to create the Makefile and link the minilibx
- Improving the layout of the README file
- Understanding raycasting concepts
