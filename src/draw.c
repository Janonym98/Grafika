#include "draw.h"
#include "model.h"
#include "callbacks.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

double corridorWidth = 300;
double corridorLength = 300;
double corridorHeight = 300;

GLfloat material_ambient_default[] = {0.9, 0.9, 0.9, 0.5};

void draw_teapot_for_light(){
    glPushMatrix();
        glTranslatef(120, 15, 120);
        glScalef(12, 12, 12);
        glutSolidTeapot(1.0);
    glPopMatrix();
}



void draw_content(World* world)
{
	Corridor roomToDraw = world -> corridor;
	glEnable(GL_TEXTURE_2D);

    glPushMatrix();
		draw_walls(roomToDraw);
		draw_window_wall(roomToDraw);
		draw_window_wall2(roomToDraw);
		draw_ground(roomToDraw);
		draw_ceiling(roomToDraw);
		draw_horizon(roomToDraw);
		draw_horizon2(roomToDraw);
	glPopMatrix();

	draw_door(0, +28, 0);

//balloon 1	

	glPushMatrix();
		glTranslatef(world->balloon[0].position.x, world->balloon[0].position.y, world->balloon[0].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->balloon[0].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->balloon[0].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->balloon[0].rotation, 0, 1, 0);

		draw_model(&world->balloon[0].model);
    glPopMatrix();

//balloon 2

	glPushMatrix();
		glTranslatef(world->balloon[1].position.x, world->balloon[1].position.y, world->balloon[1].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->balloon[1].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->balloon[1].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->balloon[1].rotation, 0, 1, 0);

		draw_model(&world->balloon[1].model);
    glPopMatrix();

//balloon 3

	glPushMatrix();
		glTranslatef(world->balloon[2].position.x, world->balloon[2].position.y, world->balloon[2].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->balloon[2].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->balloon[2].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->balloon[2].rotation, 0, 1, 0);

		draw_model(&world->balloon[2].model);
    glPopMatrix();

//balloon 4

	glPushMatrix();
		glTranslatef(world->balloon[3].position.x, world->balloon[3].position.y, world->balloon[3].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->balloon[3].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->balloon[3].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->balloon[3].rotation, 0, 1, 0);

		draw_model(&world->balloon[3].model);
    glPopMatrix();

//monster 1	

	glPushMatrix();
		glTranslatef(world->monster[0].position.x, world->monster[0].position.y, world->monster[0].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->monster[0].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->monster[0].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->monster[0].rotation, 0, 1, 0);

		glRotatef(world->rota, 0, -1, 0);

		draw_model(&world->monster[0].model);
    glPopMatrix();

//monster 2	

	glPushMatrix();
		glTranslatef(world->monster[1].position.x, world->monster[1].position.y, world->monster[1].position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->monster[1].material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->monster[1].texture);
		glScalef(10.0f, 10.0f, 10.0f);
		glRotatef(world->monster[1].rotation, 0, 1, 0);
		glRotatef(world->rota, 0, -1, 0);

		draw_model(&world->monster[1].model);
    glPopMatrix();

//campfire	

	glPushMatrix();
		glTranslatef(world->fire.position.x, world->fire.position.y, world->fire.position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->fire.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->fire.texture);
		
		glScalef(5.0f, 5.0f, 5.0f);

		draw_model(&world->fire.model);
    glPopMatrix();

//Schrank	

	glPushMatrix();
		glTranslatef(world->wardrobe.position.x, world->wardrobe.position.y, world->wardrobe.position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->wardrobe.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->wardrobe.texture);
		
		glScalef(5.0f, 5.0f, 5.0f);

		draw_model(&world->wardrobe.model);
    glPopMatrix();

//devil

	glPushMatrix();
		
		
		glTranslatef(world->devil.position.x, world->devil.position.y, world->devil.position.z);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->devil.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->devil.texture);
		glScalef(5.0f, 5.0f, 5.0f);
		
		glRotatef(world->rota, 1, 1, 1);

		draw_model(&world->devil.model);
    glPopMatrix();

	
//window

	glPushMatrix();
		glTranslatef(world->window.position.x, world->window.position.y, world->window.position.z);
		glRotatef(180, 0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->window.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->window.texture);
		glScalef(15.0f, 15.0f, 15.0f);

		draw_model(&world->window.model);
    glPopMatrix();

//window2
	glPushMatrix();
		glTranslatef(world->window2.position.x, world->window2.position.y, world->window2.position.z);
		glRotatef(0, 0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world->window2.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world->window.texture);
		glScalef(15.0f, 15.0f, 15.0f);

		draw_model(&world->window2.model);
    glPopMatrix();

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient_default);




	if (move_balloon_id != -1)
	{
		world->balloon[move_balloon_id].position.x = camera.position.x+20;
		world->balloon[move_balloon_id].position.z = camera.position.z+20;
	}

	if (move_monster_id != -1)
	{
		world->monster[move_monster_id].position.x = camera.position.x;
		world->monster[move_monster_id].position.z = camera.position.z;
	}
}



void draw_ground(Corridor corridor) {
	glBindTexture(GL_TEXTURE_2D, corridor.ground);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_QUADS);
	int x, z;
	for (x = -300; x < corridorLength; x += 50) {
		for (z = -300; z < corridorWidth; z += 50) {
			glTexCoord2f(0.0, 0.0);
			glNormal3f(0, -1, 0);
			glVertex3f(x, 0, z);
			glTexCoord2f(1.0, 0.0);
			glNormal3f(0, -1, 0);
			glVertex3f(x + 50, 0, z);
			glTexCoord2f(1.0, 1.0);
			glNormal3f(0, -1, 0);
			glVertex3f(x + 50, 0, z + 50);
			glTexCoord2f(0.0, 1.0);
			glNormal3f(0, -1, 0);
			glVertex3f(x, 0, z + 50);
		}
	}
	glEnd();
}

//ceiling
void draw_ceiling(Corridor corridor) {
	glBindTexture(GL_TEXTURE_2D, corridor.ceiling);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_QUADS);
	int x, z;
	for (x = -300; x < corridorLength; x += 50) {
		for (z = -300; z < corridorWidth; z += 50) {
			glTexCoord2f(0.0, 0.0);
			glNormal3f(0, 300, 0);
			glVertex3f(x, 300, z);
			glTexCoord2f(1.0, 0.0);
			glNormal3f(0, 300, 0);
			glVertex3f(x + 50, 300, z);
			glTexCoord2f(1.0, 1.0);
			glNormal3f(0, 300, 0);
			glVertex3f(x + 50, 300, z + 50);
			glTexCoord2f(0.0, 1.0);
			glNormal3f(0, 300, 0);
			glVertex3f(x, 300, z + 50);
		}
	}
	glEnd();
}

//window wall
void draw_window_wall(Corridor corridor) {
	//right
	glBindTexture(GL_TEXTURE_2D, corridor.back);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 0, 300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, 300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, 28);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength, 0, 28);
	glEnd();

	// left
	glBindTexture(GL_TEXTURE_2D, corridor.back);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 0, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, -34);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength, 0, -34);
	glEnd();

	// up
	glBindTexture(GL_TEXTURE_2D, corridor.back);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 157, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, 300);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength, 157, 300);
	glEnd();

	// down
	glBindTexture(GL_TEXTURE_2D, corridor.back);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 0, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, 49, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength, 49, 300);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength, 0, 300);
	glEnd();

	
}
//window wall
void draw_window_wall2(Corridor corridor) {
	//right
	glBindTexture(GL_TEXTURE_2D, corridor.front);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-corridorLength, 0, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, -28);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorLength, 0, -28);
	glEnd();

	// left
	glBindTexture(GL_TEXTURE_2D, corridor.front);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-corridorLength, 0, 300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, +300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, +34);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorLength, 0, +34);
	glEnd();

	// up
	glBindTexture(GL_TEXTURE_2D, corridor.front);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-corridorLength, +157, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorLength, corridorWidth, +300);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorLength, 157, +300);
	glEnd();

	// down
	glBindTexture(GL_TEXTURE_2D, corridor.front);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-corridorLength, 0, -300);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-corridorLength, 49, -300);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorLength, 49, 300);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorLength, 0, 300);
	glEnd();

	
}

//horizon
void draw_horizon(Corridor corridor) {
	glBindTexture(GL_TEXTURE_2D, corridor.horizon);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength+1000, -corridorWidth*5, corridorHeight*5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength+1000, corridorWidth*5, corridorHeight*5);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength+1000, corridorWidth*5, -corridorHeight*5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength+1000, -corridorWidth*5, -corridorHeight*5);
	glEnd();
}

//horizon2
void draw_horizon2(Corridor corridor) {
	glBindTexture(GL_TEXTURE_2D, corridor.horizon2);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength-1500, -corridorWidth*5, corridorHeight*5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength-1500, corridorWidth*5, corridorHeight*5);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(corridorLength-1500, corridorWidth*5, -corridorHeight*5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(corridorLength-1500, -corridorWidth*5, -corridorHeight*5);
	glEnd();
}

//door
void draw_door(int moveX, int moveZ,int degree) {
	glPushMatrix();
		glTranslatef(world.door.position.x+moveX, world.door.position.y, world.door.position.z+moveZ);
		glRotatef(degree, 0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, world.door.material_ambient);

		glBindTexture(GL_TEXTURE_2D, world.door.texture);
		glScalef(1.5f, 1.5f, 1.5f);

		draw_model(&world.door.model);
    glPopMatrix();
}

//walls
void draw_walls(Corridor corridor) {

	glBindTexture(GL_TEXTURE_2D, corridor.right);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorWidth, 0, -corridorWidth);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 0, -corridorWidth);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, -corridorWidth);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorWidth, corridorWidth, -corridorWidth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, corridor.left);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(corridorLength, 0, corridorWidth);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(corridorLength, corridorWidth, corridorWidth);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-corridorWidth, corridorWidth, corridorWidth);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-corridorWidth, 0, corridorWidth);
	glEnd();
}


//Help
void draw_help(int texture) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3f(WINDOW_WIDTH, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3f(WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	glTexCoord2f(0, 1);
	glVertex3f(0, WINDOW_HEIGHT, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}