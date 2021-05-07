#include "model.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include <obj/load.h>
#include <obj/draw.h>

void init_object(Object* object, int x, int z, int y)
{
	object->position.x = x;
	object->position.y = y;
	object->position.z = z;

	object->material_ambient[0] = 0.6;
	object->material_ambient[1] = 0.6;
	object->material_ambient[2] = 0.6;
	object->material_ambient[3] = 0.5;
}

// Loads the texture file with SOIL
GLuint load_texture(const char* filename) {
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	GLuint texture_name;
	Pixel* image;
	glGenTextures(1, &texture_name);

	int width;
	int height;

	image = (Pixel*)SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);

	glBindTexture(GL_TEXTURE_2D, texture_name);
	gluBuild2DMipmaps(GL_TEXTURE_2D,3,width,height,GL_RGBA,GL_UNSIGNED_BYTE,(Pixel*)image);
	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (Pixel*)image);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	// SOIL_free_image_data(image);

	return texture_name;
}



void init_entities(World* world) {
	move_balloon_id = -1;
	move_monster_id = -1;


	// Balloon
	load_model(&world->balloon[0].model, "obj/balloon.obj");
	world->balloon[0].texture = load_texture("tex/face2.png");
	init_object(&world->balloon[0], 260, -260, 100);
	world->balloon[0].rotation = 45.0f;

	// Balloon
	world->balloon[1].model = world->balloon[0].model;
	world->balloon[1].texture = world->balloon[0].texture;
	init_object(&world->balloon[1], 260, 260, 100);
	world->balloon[1].rotation = -45.f;

	// Balloon
	world->balloon[2].model = world->balloon[0].model;
	world->balloon[2].texture = world->balloon[0].texture;
	init_object(&world->balloon[2], -260, -260, 100);
	world->balloon[2].rotation = 135.0f;

	// Balloon
	world->balloon[3].model = world->balloon[0].model;
	world->balloon[3].texture = world->balloon[0].texture;
	init_object(&world->balloon[3], -260, 260, 100);
	world->balloon[3].rotation = -135.0f;


	// Monster
	load_model(&world->monster[0].model, "obj/balloon.obj");
	world->monster[0].texture = load_texture("tex/face3.png");
	init_object(&world->monster[0], 0, -250, 75);
	world->monster[0].rotation = 0.0f;

	// Monster
	load_model(&world->monster[1].model, "obj/balloon.obj");
	world->monster[1].texture = load_texture("tex/face3.png");
	init_object(&world->monster[1], -60, -250, 75);
	world->monster[1].rotation = 0.0f;

	// Fire

	load_model(&world->fire.model, "obj/fire.obj");
	world->fire.texture = load_texture("tex//fire2.jpg");
	init_object(&world->fire, 0, 0, 25);

	// Star

	load_model(&world->star.model, "obj/star.obj");
	world->star.texture = load_texture("tex//star.png");
	init_object(&world->star, 0, 0, 110);

	// Schrank
	load_model(&world->wardrobe.model, "obj/wardrobe.obj");
	world->wardrobe.texture = load_texture("tex//wardrobe.png");
	init_object(&world->wardrobe, 0, -240, 25);

	// devil
	glPushMatrix();
	load_model(&world->devil.model, "obj/devil.obj");
	world->devil.texture = load_texture("tex//devileye.jpg");
	init_object(&world->devil, 0, 0, 80);


	// Window
	load_model(&world->window.model, "obj/window.obj");
	world->window.texture =  load_texture("tex//devil.jpg");
	init_object(&world->window, 300, -3, 80);

	// Window2
	load_model(&world->window2.model, "obj/window.obj");
	world->window.texture =  load_texture("tex//devil.jpg");
	init_object(&world->window2, -300, 3, 80);

	// Door
	load_model(&world->door.model, "obj/door.obj");
	world->door.texture = load_texture("tex//door.png");
	init_object(&world->door, 0, 265, 0);

	// Corridor
	world->corridor.horizon = load_texture("tex//hell.png");
	world->corridor.horizon2 = load_texture("tex//hell2.png");
	world->corridor.ground = load_texture("tex//ground.png");
    world->corridor.ceiling = load_texture("tex//topfloor.jpg");
	world->corridor.back = load_texture("tex//wall.png");
	world->corridor.front = world->corridor.back;
	world->corridor.left = world->corridor.back;
	world->corridor.right = world->corridor.back;

	// Help
	world->helpTexture = load_texture("tex//help.png");
}
