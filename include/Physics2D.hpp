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
 * Physics2D.hpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef PHYSICS2D_HPP_
#define PHYSICS2D_HPP_

#include <vector>
#include <Box2D/Box2D.h>

union SDL_Event;

namespace Defcronyke
{

class GameObject;

class MyContactListener : public b2ContactListener
{
public:
	int num_foot_contacts;
	int jump_timeout;
	bool first_goal_drop;
	bool break_goal_on_landing;
	bool level_failed;
	bool level_completed;

	MyContactListener();
	~MyContactListener();

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

class Physics2DConfig
{
public:
	b2Vec2 gravity;
	bool do_sleep;
	float32 time_step;
	int32 velocity_iterations;
	int32 position_iterations;

	Physics2DConfig(float32 gravity_right = 0.0f, float32 gravity_down = -1.0f,
		bool do_sleep = true, float32 time_step = 1.0f / 60.0f,
		int32 velocity_iterations = 6, int32 position_iterations = 2);
	~Physics2DConfig();
};

class Physics2D
{
	enum EVENTS
	{
		NOTHING,
		QUIT,
		RELOAD,	// restart the current level
		MOVE_RIGHT,
		MOVE_LEFT,
		JUMP,
		NEXT_LEVEL,
		PREVIOUS_LEVEL
	};

	bool owns_physics2d_config_memory;
	int cheat_next_level_index;
	int cheat_timeout;
	int cheat_timer;

public:
	Physics2DConfig* physics2d_config;

	b2Vec2 gravity;
	bool do_sleep;
	float32 time_step;
	int32 velocity_iterations;
	int32 position_iterations;

	MyContactListener* contact_listener;

	SDL_Event* sdl_event;

	b2World world;
	std::vector<b2Body*> dynamic_bodies;

	Physics2D();
	Physics2D(Physics2DConfig*& physics2d_config);
	Physics2D(Physics2DConfig& physics2d_config);
	virtual ~Physics2D();

	Physics2D::EVENTS handle_events();	// called by step()
	bool init(std::vector<Defcronyke::GameObject*>& objects_on_screen);
	int step(std::vector<Defcronyke::GameObject*>& objects_on_screen);	// modifies x and y, return 0 to exit, 1 for running, and 2 on level complete
};

}
#endif
