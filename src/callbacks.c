#include <math.h>
#include "action.h"
#include "callbacks.h"
#include "init.h"
#include "draw.h"
#include "model.h"

int help = 0;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

struct Action action;

void display(void)
{
	double elapsed_time = calc_elapsed_time();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	update_camera_position(&camera, elapsed_time);
	update_entities(&world, elapsed_time);
	update_ghost(&world, elapsed_time);
	draw_content(&world);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT, 0.1, 20000.0);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	set_view_point(&camera);

	if (help)
	{
		GLfloat torchForHelp[] = {0.8, 0.8, 0.8, 0.8};
		glLightfv(GL_LIGHT1, GL_AMBIENT, torchForHelp);

		glLoadIdentity();
		gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

		draw_help(world.helpTexture);

		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}

	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;

	set_clear_camera_pose(&camera);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		action.move_forward = TRUE;
		break;
	case 's':
	case 'S':
		action.move_backward = TRUE;
		break;
	case 'a':
	case 'A':
		action.step_left = TRUE;
		break;
	case 'd':
	case 'D':
		action.step_right = TRUE;
		break;
	case 'c':
	case 'C':
		action.move_down = TRUE;
		break;
	case 32:
		action.move_up = TRUE;
		break;
	case '+':
		action.increase_light = TRUE;
		break;
	case '-':
		action.decrease_light = TRUE;
		break;
	case 27:
		exit(0);
	}
	glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		action.move_forward = FALSE;
		break;
	case 's':
	case 'S':
		action.move_backward = FALSE;
		break;
	case 'a':
	case 'A':
		action.step_left = FALSE;
		break;
	case 'd':
	case 'D':
		action.step_right = FALSE;
		break;
	case 'c':
	case 'C':
		action.move_down = FALSE;
		break;
	case 32:
		action.move_up = FALSE;
		break;
	case '+':
		action.increase_light = FALSE;
		break;
	case '-':
		action.decrease_light = FALSE;
		break;
	case 'h':
	case 'H':
		if (move_mask_id == -1)
		{
			grab_closest_mask(&world, camera.position);
		}
		else
		{
			move_mask_id = -1;
		}
		break;
	case 'f':
	case 'F':
		if (move_balloon_id == -1)
		{
			grab_closest_balloon(&world, camera.position);
		}
		else
		{
			move_balloon_id = -1;
		}
		break;
	case 'q':
	case 'Q':
		if (move_balloon_id != -1)
		{
			world.balloon[move_balloon_id].rotation += 15.0f;
		}
		break;
	case 'e':
	case 'E':
		if (move_balloon_id != -1)
		{
			world.balloon[move_balloon_id].rotation -= 15.0f;
		}
		break;
	}

	glutPostRedisplay();
}

void specialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F1:
		if (help == 1)
		{
			help = 0;
		}
		else
			help = 1;
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	mouse_x = x;
	mouse_y = y;
}

void motion(int x, int y)
{
	double horizontal, vertical;

	horizontal = mouse_x - x;
	vertical = mouse_y - y;

	rotate_camera(&camera, horizontal, vertical);

	mouse_x = x;
	mouse_y = y;

	glutPostRedisplay();
}

void idle()
{
	glutPostRedisplay();
}

double calc_elapsed_time()
{
	static int last_frame_time = 0;
	int current_time;
	double elapsed_time;

	current_time = glutGet(GLUT_ELAPSED_TIME);
	elapsed_time = (double)(current_time - last_frame_time) / 1000.0;
	last_frame_time = current_time;

	return elapsed_time;
}

void update_entities(World* world, double time){
	world->rota += 100 * time;
}

void update_ghost(World* world, double time){
		world->w += 5* time;
}

void update_camera_position(struct Camera *camera, double elapsed_time)
{
	float speed = 75;
	double distance;

	distance = elapsed_time * CAMERA_SPEED * speed;

	if (action.move_forward == TRUE)
	{
		move_camera_forward(camera, distance);
	}

	if (action.move_backward == TRUE)
	{
		move_camera_backward(camera, distance);
	}

	if (action.step_left == TRUE)
	{
		step_camera_left(camera, distance);
	}

	if (action.step_right == TRUE)
	{
		step_camera_right(camera, distance);
	}

	if (action.move_up == TRUE)
	{
		move_camera_up(camera, distance);
	}

	if (action.move_down == TRUE)
	{
		move_camera_down(camera, distance);
	}

	if (action.increase_light == TRUE)
	{
		if (light_ambient[0] < 1)
			light_ambient[0] = light_ambient[1] = light_ambient[2] += 0.01;
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}

	if (action.decrease_light == TRUE)
	{
		if (light_ambient[0] > -0.60)
			light_ambient[0] = light_ambient[1] = light_ambient[2] -= 0.01;
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}
}



void grab_closest_mask(World *world, Vertex camera_position)
{
	int mask_id;
	float min_distance = MAX_MOVING_DISTANCE;
	int i;

	for (i = 0; i < MASK_LENGTH; i++)
	{
		float distance = sqrt(pow((camera_position.x - world->mask[i].position.x), 2) + 
		pow((camera_position.z - world->mask[i].position.z), 2));

		if (min_distance > distance)
		{
			min_distance = distance;
			mask_id = i;
		}
	}

	if (min_distance < MAX_MOVING_DISTANCE)
	{
		move_mask_id = mask_id;
	}
}

void grab_closest_balloon(World *world, Vertex camera_position)
{
	int balloon_id;
	float min_distance = MAX_MOVING_DISTANCE;
	int i;

	for (i = 0; i < BALLOON_LENGTH; i++)
	{
		float distance = sqrt(pow((camera_position.x - world->balloon[i].position.x), 2) + 
		pow((camera_position.z - world->balloon[i].position.z), 2));

		if (min_distance > distance)
		{
			min_distance = distance;
			balloon_id = i;
		}
	}

	if (min_distance < MAX_MOVING_DISTANCE)
	{
		move_balloon_id = balloon_id;
	}
}
