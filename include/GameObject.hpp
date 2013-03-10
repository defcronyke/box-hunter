/* Ⓒ Copyright 2013 Jeremy Carter
 *
 * This file is part of Box Hunter.
 *
 * Box Hunter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Box Hunter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Box Hunter.  If not, see <http://www.gnu.org/licenses/>.
 *
 * GameObject.hpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Defcronyke
{

class GameObject
{
public:
	bool is_player;
	bool is_deadly;
	bool is_goal;
	bool is_concave; // special handling needed for concave objects

	std::vector<Defcronyke::GameObject*> convex_objects; // empty unless object is concave

	float x;
	float y;
	float rot;	// rotation in degrees
	float width;
	float height;

	std::vector<glm::vec2> coords_opengl;
	std::vector<glm::vec2> coords_physics;
	std::vector<glm::vec4> colors;

	glm::mat4 T;	// translation matrix
	glm::mat4 R;	// rotation matrix

	GameObject();
	virtual ~GameObject();

	float get_x();
	void set_x(float x);

	float get_y();
	void set_y(float y);

	float get_rot();
	void set_rot(float rot);
};

}
#endif
