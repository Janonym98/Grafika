#ifndef INCLUDE_DRAW_H_
#define INCLUDE_DRAW_H_

#include "model.h"

#ifndef GL_EXT_texture_edge_clamp
#define GL_CLAMP_TO_EDGE                 0x812F
#endif

// Draw the content.
void draw_content(World* world);

// Draws the ground.
void draw_ground(Corridor corridor);

// Draws the ceiling.
void draw_ceiling(Corridor corridor);

// Draws the front horizon.
void draw_horizon(Corridor corridor);

// Draws the back horizon.
void draw_horizon2(Corridor corridor);

// Draws the front wall where the window is.
void draw_window_wall(Corridor corridor);

// Draws the back wall where the window is.
void draw_window_wall2(Corridor corridor);

// Draws the left and right walls.
void draw_walls(Corridor corridor);

// Draws the help menu
void draw_help(int texture);

// Draws the door
void draw_door(int moveX, int moveZ,int degree);

// Draws the balloons
void draw_balloon(int moveX, int moveZ,int degree);

// Draws the monsterss
void draw_monster(int moveX, int moveZ,int degree);


#endif /* INCLUDE_DRAW_H_ */
