#ifndef INCLUDE_MODEL_H
#define INCLUDE_MODEL_H

#include <stdio.h>
#include <GL/glut.h>
#include "SOIL/SOIL.h"

#include <obj/model.h>

#define TRUE 1
#define FALSE 0

#define BALLOON_LENGTH 4
#define MONSTER_LENGTH 2
#define WINDOW_LENGTH 2

typedef GLubyte Pixel[3];

typedef struct {
    Model model;
    float material_ambient[4];
    int texture;
    struct Vertex position;
    float rotation;
}Object;

typedef struct {
    int front, back, left, right, ground, ceiling, horizon, horizon2;
}Corridor;

typedef struct {
	Corridor corridor;
	int helpTexture;
    Object door;
    Object fire;
    Object wardrobe;
    Object devil;
    Object star;
    Object fan;
    Object window[WINDOW_LENGTH];
    Object balloon[BALLOON_LENGTH];
    Object monster[MONSTER_LENGTH];
    float rota;
}World;

World world;

void init_object(Object* object, int x, int z, int y);

// Loads the texture file with SOIL
GLuint load_texture(const char* filename);

// Initialize my entities
void init_entities(World* world);

// Update my assigned entities
void update_entities(World* world, double time);

#endif // MODEL_H
