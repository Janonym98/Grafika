#ifndef SCENEB_H
#define SCENEB_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Sceneb
{
    Model balloon;
    Material materialb;
    GLuint texture_idb;
} Sceneb;

/**
 * Initialize the scene by loading models.
 */
void init_sceneb(Sceneb* sceneb);

/**
 * Set the lighting of the scene.
 */
void set_lightingb();

/**
 * Set the current material.
 */
void set_materialb(const Material* materialb);

/**
 * Draw the scene objects.
 */
void draw_sceneb(const Sceneb* sceneb);


#endif /* SCENEB_H */
