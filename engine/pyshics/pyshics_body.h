#ifndef PYSHICS_BODY_H
#define PYSHICS_BODY_H

#include <box2d/box2d.h>
#include "core/object/object.h"


#include <vector>
#include <map>
#include <string>
#include <array>



/**
 * 
 * @class PyshicsBody
 * @memberof Object
 * @namespace GG
 * @author Patsher Photo
 * @copyright 2023 / 2024 
 * @version 2.0.0
 * 
*/
/**
 * @brief `PhysicsBody2D`:
 * 
 `PhysicsBody2D` is a class that represents a 2D physics body in a game or simulation. It is commonly used in game development frameworks or physics engines to simulate realistic physics interactions between game objects.

 A `PhysicsBody2D` typically has the following properties and functionalities:

 1. **Shape**: It has a shape that defines its physical boundaries, such as a rectangle, circle, or polygon. The shape determines how the body interacts with other bodies and the environment.

 2. **Position and Orientation**: It has a position in the 2D space, represented by coordinates (x, y). The position determines the body's location within the game world. Additionally, the body may have an orientation or angle that specifies its rotation.

 3. **Motion**: It can have velocity and acceleration properties that control its linear motion. Velocity determines the body's speed and direction, while acceleration affects the change in velocity over time. By applying forces or impulses, the body's motion can be altered.

 4. **Collision Detection**: It performs collision detection with other bodies or colliders in the scene. This allows it to detect and respond to collisions, such as bouncing off walls, objects, or triggering events.

 5. **Mass and Forces**: It may have a mass value that affects its response to forces. By applying forces like gravity, friction, or user-defined forces, the body's motion can be influenced. Additionally, it may have properties like elasticity or damping that determine how it reacts to collisions or forces.

 6. **Constraints**: It can be subject to constraints or joints, which restrict its movement or connect it to other bodies. Constraints include hinges, springs, or fixed joints that allow for complex physics interactions, like creating pendulums or ragdoll structures.

 7. **Callbacks and Events**: It often provides callbacks or event triggers to no
 * tify the game or simulation about specific events, such as collisions, forces applied, or changes in motion. These events can be used to implement custom gameplay mechanics or trigger actions based on physics interactions.

The `PhysicsBody2D` 
class serves as a fundamental building block for implementing physics simulations in 2D games. It enables realistic movement, collision, and interaction between game objects, making the gameplay more engaging and immersive.
*/
class PyshicsBody : public b2Body {
    GGClass(PyshicsBody, b2Body)










};




#endif // PYSHICS_H