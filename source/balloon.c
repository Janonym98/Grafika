#include "balloon.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_sceneb(Sceneb* sceneb)
{
    load_model(&(sceneb->balloon), "obj/balloon.obj");
    sceneb->balloon_texture_id = load_texture("tex/balloon.jpg"); 

    glBindTexture(GL_TEXTURE_2D, sceneb->balloon_texture_id);

    sceneb->materialb.ambient.red = 1.0;
    sceneb->materialb.ambient.green = 1.0;
    sceneb->materialb.ambient.blue = 0.0;

    sceneb->materialb.diffuse.red = 1.0;
    sceneb->materialb.diffuse.green = 0.5;
    sceneb->materialb.diffuse.blue = 1.0;

    sceneb->materialb.specular.red = 1.0;
    sceneb->materialb.specular.green = 0.5;
    sceneb->materialb.specular.blue = 1.0;

    sceneb->materialb.shininess = 1.0;
}

void set_lightingb()
{
    float ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float diffuse_light[] = { 0.9f, 0.9f, 0.9, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_materialb(const Material* materialb)
{
    float ambient_material_color[] = {
        materialb->ambient.red,
        materialb->ambient.green,
        materialb->ambient.blue
    };

    float diffuse_material_color[] = {
        materialb->diffuse.red,
        materialb->diffuse.green,
        materialb->diffuse.blue
    };

    float specular_material_color[] = {
        materialb->specular.red,
        materialb->specular.green,
        materialb->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(materialb->shininess));
}

void draw_sceneb(const Sceneb* sceneb)
{
    set_materialb(&(sceneb->materialb));
    set_lightingb();
    draw_model(&(sceneb->balloon));
    glBindTexture(GL_TEXTURE_2D, sceneb->balloon_texture_id);
}
