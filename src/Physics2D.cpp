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
 * Physics2D.cpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../include/Physics2D.hpp"
#include <Box2D/Box2D.h>
#include <vector>
#include "../include/GameObject.hpp"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <inttypes.h>

namespace Defcronyke
{

MyContactListener::MyContactListener()
	: num_foot_contacts(0),
	  jump_timeout(0),
	  first_goal_drop(true),
	  break_goal_on_landing(false),
	  level_failed(false),
	  level_completed(false)
{

}

MyContactListener::~MyContactListener()
{

}

void MyContactListener::BeginContact(b2Contact* contact)
{
	// if up against a surface
	if (reinterpret_cast<intptr_t>(contact->GetFixtureA()->GetUserData()) == 1)
	{
		this->num_foot_contacts++;
	}
	if (reinterpret_cast<intptr_t>(contact->GetFixtureB()->GetUserData()) == 1)
	{
		this->num_foot_contacts++;
	}

	// if we reached the goal
	if (reinterpret_cast<intptr_t>(contact->GetFixtureA()->GetUserData()) == 3 &&
		reinterpret_cast<intptr_t>(contact->GetFixtureB()->GetUserData()) == 1)
	{
		this->level_completed = true;
		return;
	}
	if (reinterpret_cast<intptr_t>(contact->GetFixtureA()->GetUserData()) == 1 &&
		reinterpret_cast<intptr_t>(contact->GetFixtureB()->GetUserData()) == 3)
	{
		this->level_completed = true;
		return;
	}

	if (this->break_goal_on_landing)
	{
		if (reinterpret_cast<intptr_t>(contact->GetFixtureA()->GetUserData()) == 3)
		{
			if (!this->first_goal_drop)
			{
				this->level_failed = true;
				return;
			}
			else
			{
				this->first_goal_drop = false;
				this->break_goal_on_landing = false;
			}
		}
		if (reinterpret_cast<intptr_t>(contact->GetFixtureB()->GetUserData()) == 3)
		{
			if (!this->first_goal_drop)
			{
				this->level_failed = true;
				return;
			}
			else
			{
				this->first_goal_drop = false;
				this->break_goal_on_landing = false;
			}
		}
	}

	return;
}

void MyContactListener::EndContact(b2Contact* contact)
{
	if (reinterpret_cast<intptr_t>(contact->GetFixtureA()->GetUserData()) == 1)
	{
		this->num_foot_contacts--;
	}

	if (reinterpret_cast<intptr_t>(contact->GetFixtureB()->GetUserData()) == 1)
	{
		this->num_foot_contacts--;
	}

	return;
}

// helper functions
float rad_to_deg(float rad)
{
	float deg = rad * (180.0f / 3.141592653589793f);
	return deg;
}

float deg_to_rad(float deg)
{
	float rad = deg * (3.141592653589793f / 180.0f);
	return rad;
}

Physics2DConfig::Physics2DConfig(float32 gravity_right, float32 gravity_down,
		bool do_sleep, float32 time_step,
		int32 velocity_iterations, int32 position_iterations)
	: do_sleep(do_sleep),
	  time_step(time_step),
	  velocity_iterations(velocity_iterations),
	  position_iterations(position_iterations)
{
	this->gravity.x = gravity_right;
	this->gravity.y = gravity_down;
}

Physics2DConfig::~Physics2DConfig()
{

}


Physics2D::Physics2D()
	: owns_physics2d_config_memory(true),
	  cheat_next_level_index(0),
	  cheat_timeout(100),
	  cheat_timer(cheat_timeout),
	  physics2d_config(new Physics2DConfig),
	  gravity(physics2d_config->gravity.x, physics2d_config->gravity.y),
	  do_sleep(physics2d_config->do_sleep),
	  time_step(physics2d_config->time_step),
	  velocity_iterations(physics2d_config->velocity_iterations),
	  position_iterations(physics2d_config->position_iterations),
	  contact_listener(0),
	  sdl_event(0),
	  world(gravity, do_sleep)
{

}

Physics2D::Physics2D(Physics2DConfig*& physics2d_config)
	: owns_physics2d_config_memory(false),
	  cheat_next_level_index(0),
	  cheat_timeout(100),
	  cheat_timer(cheat_timeout),
	  physics2d_config(physics2d_config),
	  gravity(physics2d_config->gravity.x, physics2d_config->gravity.y),
	  do_sleep(physics2d_config->do_sleep),
	  time_step(physics2d_config->time_step),
	  velocity_iterations(physics2d_config->velocity_iterations),
	  position_iterations(physics2d_config->position_iterations),
	  contact_listener(0),
	  sdl_event(0),
	  world(gravity, do_sleep)
{

}

Physics2D::Physics2D(Physics2DConfig& physics2d_config)
	: owns_physics2d_config_memory(false),
	  cheat_next_level_index(0),
	  cheat_timeout(100),
	  cheat_timer(cheat_timeout),
	  physics2d_config(&physics2d_config),
	  gravity(physics2d_config.gravity.x, physics2d_config.gravity.y),
	  do_sleep(physics2d_config.do_sleep),
	  time_step(physics2d_config.time_step),
	  velocity_iterations(physics2d_config.velocity_iterations),
	  position_iterations(physics2d_config.position_iterations),
	  contact_listener(0),
	  sdl_event(0),
	  world(gravity, do_sleep)
{

}

Physics2D::~Physics2D()
{
	if (owns_physics2d_config_memory)
		if (physics2d_config)
			delete physics2d_config;

	if (this->contact_listener)
		delete this->contact_listener;

	if (this->sdl_event)
		delete sdl_event;
}

Physics2D::EVENTS Physics2D::handle_events()
{
	Physics2D::EVENTS event = NOTHING;

	std::string cheat_next_level = "plus";
	std::string cheat_previous_level = "minus";

	if (!this->sdl_event)
	{
		std::cerr << "\nError: You have to call Window::open() before Window::handle_events()\n";
	}

	while (SDL_PollEvent(this->sdl_event))
	{
		if (this->sdl_event->type == SDL_QUIT)
		{
			event = QUIT;
		}

		else if (this->sdl_event->type == SDL_KEYDOWN)
		{
			if (this->sdl_event->key.keysym.sym == SDLK_RIGHT)
			{
				event = MOVE_RIGHT;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_LEFT)
			{
				event = MOVE_LEFT;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_LCTRL)
			{
				event = JUMP;
			}

			// cheat: skip to the next level
			else if (this->sdl_event->key.keysym.sym == SDLK_p)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_l &&
					 this->cheat_next_level_index == 1)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_u &&
					 this->cheat_next_level_index == 2)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_s &&
					 this->cheat_next_level_index == 3)
			{
				this->cheat_timer = this->cheat_timeout;
				event = NEXT_LEVEL;
			}

			// cheat: skip to the previous level
			else if (this->sdl_event->key.keysym.sym == SDLK_m)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_i &&
					 this->cheat_next_level_index == 1)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_n &&
					 this->cheat_next_level_index == 2)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_u &&
					 this->cheat_next_level_index == 3)
			{
				this->cheat_next_level_index++;
				this->cheat_timer = this->cheat_timeout;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_s &&
					 this->cheat_next_level_index == 4)
			{
				this->cheat_timer = this->cheat_timeout;
				event = PREVIOUS_LEVEL;
			}

			else
			{
				this->cheat_next_level_index = 0;
			}
		}

		else if (this->sdl_event->type == SDL_KEYUP)
		{
			if (this->sdl_event->key.keysym.sym == SDLK_ESCAPE)
			{
				event = QUIT;
			}

			else if (this->sdl_event->key.keysym.sym == SDLK_F1)
			{
				event = RELOAD;
			}
		}
	}

	if (this->cheat_timer <= 0)
	{
		this->cheat_next_level_index = 0;
		this->cheat_timer = this->cheat_timeout;
	}
	else
	{
		this->cheat_timer--;
	}

	return event;
}

bool Physics2D::init(std::vector<Defcronyke::GameObject*>& objects_on_screen)
{
	b2BodyDef ground_body_def;
	ground_body_def.position.Set(0.0f, 0.0f);

	b2Body* ground_body = this->world.CreateBody(&ground_body_def);

	b2PolygonShape ground_body_shape;

	ground_body_shape.SetAsBox(50.0f, 0.0f);

	b2FixtureDef ground_body_fixture_def;
	ground_body_fixture_def.shape = &ground_body_shape;
	ground_body_fixture_def.friction = 1.0f;

	ground_body->CreateFixture(&ground_body_fixture_def);

	for (unsigned int i = 0; i < objects_on_screen.size(); i++)
	{
		b2BodyDef dynamic_body_def;	// a dynamic body
		dynamic_body_def.type = b2_dynamicBody;

		dynamic_body_def.position.Set(objects_on_screen[i]->get_x(), objects_on_screen[i]->get_y());

		dynamic_body_def.angle = deg_to_rad(objects_on_screen[i]->rot);

		b2Body* dynamic_body = this->world.CreateBody(&dynamic_body_def);
		this->dynamic_bodies.push_back(dynamic_body);

		if (!objects_on_screen[i]->is_concave) // if object is convex
		{
			b2PolygonShape dynamic_body_shape;

			int32 vertex_count = objects_on_screen[i]->coords_physics.size();
			b2Vec2 vertices[vertex_count];
			for (int j = 0; j < vertex_count; j++)
			{
				vertices[j] = {
					objects_on_screen[i]->coords_physics[j].x,
					objects_on_screen[i]->coords_physics[j].y };
			}
			dynamic_body_shape.Set(vertices, vertex_count);

			b2FixtureDef dynamic_body_fixture_def;
			dynamic_body_fixture_def.shape = &dynamic_body_shape;
			dynamic_body_fixture_def.density = objects_on_screen[i]->density;
			dynamic_body_fixture_def.friction = objects_on_screen[i]->friction;
			dynamic_body_fixture_def.restitution = objects_on_screen[i]->restitution;

			if (objects_on_screen[i]->is_player)
			{
				dynamic_body_fixture_def.userData = (void*)1;
			}
			else if (objects_on_screen[i]->is_goal)
			{
				dynamic_body_fixture_def.userData = (void*)3;
			}
			else
			{
				dynamic_body_fixture_def.userData = (void*)2;
			}

			dynamic_body->CreateFixture(&dynamic_body_fixture_def);
		}
		else	// if object is concave
		{
			for (unsigned int j = 0; j < objects_on_screen[i]->convex_objects.size(); j++)
			{
				b2PolygonShape dynamic_body_shape;
				int32 vertex_count = objects_on_screen[i]->convex_objects[j]->coords_physics.size();
				b2Vec2 vertices[vertex_count];
				for (int k = 0; k < vertex_count; k++)
				{
					vertices[k] = {
						objects_on_screen[i]->convex_objects[j]->coords_physics[k].x,
						objects_on_screen[i]->convex_objects[j]->coords_physics[k].y };
				}
				dynamic_body_shape.Set(vertices, vertex_count);

				b2FixtureDef dynamic_body_fixture_def;
				dynamic_body_fixture_def.shape = &dynamic_body_shape;
				dynamic_body_fixture_def.density = objects_on_screen[i]->density;
				dynamic_body_fixture_def.friction = objects_on_screen[i]->friction;
				dynamic_body_fixture_def.restitution = objects_on_screen[i]->restitution;

				if (objects_on_screen[i]->is_player)
				{
					dynamic_body_fixture_def.userData = (void*)1;
				}
				else if (objects_on_screen[i]->is_goal)
				{
					dynamic_body_fixture_def.userData = (void*)3;
				}
				else
				{
					dynamic_body_fixture_def.userData = (void*)2;
				}

				dynamic_body->CreateFixture(&dynamic_body_fixture_def);
			}
		}
	}

	this->contact_listener = new MyContactListener;
	this->world.SetContactListener(this->contact_listener);

	this->sdl_event = new SDL_Event;

	return true;
}

int Physics2D::step(std::vector<Defcronyke::GameObject*>& objects_on_screen)
{
	Physics2D::EVENTS event = NOTHING;
	int return_val = 1;

	event = this->handle_events();

	if (event == QUIT)
		return_val = 0;	// return 0 to quit

	this->world.Step(this->time_step, this->velocity_iterations, this->position_iterations);
	this->world.ClearForces();

	unsigned int i = 0;
	std::vector<Defcronyke::GameObject*>::iterator it;
	for (it = objects_on_screen.begin(); it != objects_on_screen.end(); ++it, i++)
	{
		b2Vec2 dynamic_body_position = this->dynamic_bodies[i]->GetPosition();
		float32 dynamic_body_angle = rad_to_deg(this->dynamic_bodies[i]->GetAngle());

		objects_on_screen[i]->set_x(dynamic_body_position.x);
		objects_on_screen[i]->set_y(dynamic_body_position.y);
		objects_on_screen[i]->set_rot(dynamic_body_angle);

		this->contact_listener->jump_timeout--;

		if (objects_on_screen[i]->is_player)
		{
			if (event == MOVE_RIGHT)
			{
				b2Vec2 linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();

				if (linear_velocity.x <= 0.f)
				{
					linear_velocity.x = 1.0f; // half speed
					this->dynamic_bodies[i]->SetLinearVelocity(linear_velocity);
				}

				linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();
				if (linear_velocity.x < 2.0f)
					this->dynamic_bodies[i]->ApplyForce(b2Vec2(1.0f, 0.0f), this->dynamic_bodies[i]->GetWorldCenter());
			}

			else if (event == MOVE_LEFT)
			{
				b2Vec2 linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();

				if (linear_velocity.x >= 0.f)
				{
					linear_velocity.x = -1.0f; // half speed
					this->dynamic_bodies[i]->SetLinearVelocity(linear_velocity);
				}

				linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();
				if (linear_velocity.x > -2.0f)
					this->dynamic_bodies[i]->ApplyForce(b2Vec2(-1.0f, 0.0f), this->dynamic_bodies[i]->GetWorldCenter());
			}

			else if (event == JUMP)
			{
				if (this->contact_listener->num_foot_contacts >= 1)
				{
					if (this->contact_listener->jump_timeout <= 0)
					{
						b2Vec2 linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();
						if (linear_velocity.y < 0.5f)
						{
							this->dynamic_bodies[i]->ApplyForce(b2Vec2(0.0f, 30.0f), this->dynamic_bodies[i]->GetWorldCenter());
							this->contact_listener->jump_timeout = 15;
						}
					}
				}
			}

			else if (event == RELOAD)
			{
				return 4;
			}
		}

		else if (objects_on_screen[i]->is_goal)
		{
//			std::cout << "Goal box y velocity: " << this->dynamic_bodies[i]->GetLinearVelocity().y << std::endl;

			b2Vec2 linear_velocity = this->dynamic_bodies[i]->GetLinearVelocity();

			if (linear_velocity.y < -0.5f)
			{
				this->contact_listener->break_goal_on_landing = true;
			}

			if (this->contact_listener->level_failed)
			{
				std::cout << "Level Failed!" << std::endl;
				return 3;	// quit
			}

			if (this->contact_listener->level_completed || event == NEXT_LEVEL)
			{
				std::cout << "Level Completed!" << std::endl;
				return 2;	// quit
			}

			if (event == PREVIOUS_LEVEL)
			{
				return 5;
			}
		}
	}

	return return_val;
}

}
