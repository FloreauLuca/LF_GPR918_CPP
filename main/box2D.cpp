#include <Box2D/Box2D.h>
#include <iostream>

void WorldStep(b2World* world, b2Body* body)
{
	
	world->Step(0.02f, 10, 10);
	std::cout << "Body position : " << body->GetPosition().x << ", " << body->GetPosition().y << std::endl;
}


int main()
{
	b2World world(b2Vec2(0.0f, 0.0f));
	b2BodyDef bodyDef;

	bodyDef.fixedRotation = false;
	bodyDef.linearVelocity.Set(1.0f, 1.0f);
	bodyDef.type = b2_dynamicBody;
	auto * body = world.CreateBody(&bodyDef);

	for (int i = 0; i <4 ; i++)
	{
		WorldStep(&world, body);
	}

	return EXIT_SUCCESS;
}