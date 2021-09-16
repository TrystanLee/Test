#include "cVector3.h"    // cVector3 class
#include "cMatrix3x3.h"  // cMatrix3x3 class
#include <iostream>      // outputs
#include <cstdlib>       // for rand()
#include <time.h>        // for seeding

// Generate a random number between 0 and 1
float getRandom();

// Generate a random number between zero and a given high value
float getRandom(float high);

// Generate a random number in a given range
float getRandom(float low, float high);

// Returns a vector laying on the x-z plane, randomized in direction and magnitude.
// The output is designed to be linearly independent from the output of getRandomZVector()
cVector3 getRandomXVector();

// Returns a vector laying on the x-z plane, randomized in direction and magnitude.
// The output is designed to be linearly independent from the output of getRandomXVector()
cVector3 getRandomZVector();

// Determine from the parameters if the particle is currently above the ground.
bool particleIsAboveGround(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// Determine from the parameters if the particle is currently moving "up".
bool particleIsMovingUpward(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// Perform one single time-step implementing Euler Integration.
void doTimeStepEuler(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);
// Perform one single time-step implementing Midpoint Integration.
void doTimeStepMidpoint(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration);

// The main function
int main()
{
	// Step 1: Seed the random number generation.
	unsigned int uiTime = static_cast<unsigned int>(time(NULL));
	std::cout << "uiTime: " << uiTime << std::endl;
	srand(uiTime);

	// Step 2: Generate a random basis for the axes.
	//         If done correctly, the x and z axes will be randomized only in the x-z plane
	//         and the y axis will always be (0, 1, 0)
	cMatrix3x3 axes = orthonormalBasis(getRandomXVector(), getRandomZVector());

	// Step 3: Generate a random velocity for the particle.
	// Step 3.1: The position starts just above the ground.
	cVector3 position(0.0, 0.1f, 0.0);
	// Step 3.2: 
	// TODO: Create an initial velocity vector such that it has a magnitude of 10.0f
	//       and has a randomized direction that is mostly "up"
	//       mostly up: the y component is positive, and large relative to the others.
	cVector3 velocity;

	float xdir = 0;
	float ydir = 0;
	float zdir = 0;

	do {
		ydir = getRandom(0.0f, 10.0f);
		xdir = getRandom(0.0f, 10.0f);
		zdir = getRandom(0.0f, 10.0f);
		velocity = cVector3(xdir, ydir, zdir);
	} while (velocity.Length()!=10 || ydir<xdir || ydir<zdir);
	

	// Step 4: Define the acceleration due to gravity, and deltaTime.
	cVector3 acceleration(0.f, -9.8f, 0.f);
	float deltaTime = 0.03f;

	// Step 5: Enter the main loop.
	// Track the total elapsed simulation time.
	float timeElapsed = 0;
	// Continue the simulation so long as the particle is above the ground.
	while (particleIsAboveGround(axes, deltaTime, timeElapsed, position, velocity, acceleration))
	{
		if (particleIsMovingUpward(axes, deltaTime, timeElapsed, position, velocity, acceleration))
		{
			// Let the user know the particle is moving up.
			std::cout << "going up! \tx=" << position.x << "\ty=" << position.y << "\tz=" << position.z << std::endl;
		}
		else
		{
			// Let the user know the particle is moving down.
			std::cout << "going down! \tx=" << position.x << "\ty=" << position.y << "\tz=" << position.z << std::endl;
		}
		// Step the simulation forward
		//doTimeStepEuler(axes, deltaTime, timeElapsed, position, velocity, acceleration);
		doTimeStepMidpoint(axes, deltaTime, timeElapsed, position, velocity, acceleration);
	}
	std::cout << "Impacted after " << timeElapsed << " seconds with a velocity x=" << velocity.x << "\ty=" << velocity.y << "\tz=" << velocity.z << std::endl;

	return 0;
}

float getRandom()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

float getRandom(float high)
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / high);
}

float getRandom(float low, float high)
{
	return low + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (high - low));
}

// Use as-is.  Do not change.
cVector3 getRandomXVector()
{
	return cVector3(getRandom(0.1f, 1.f), 0.f, getRandom(0.1f, 1.f));
}

// Use as-is.  Do not change.
cVector3 getRandomZVector()
{
	return cVector3(-getRandom(0.1f, 1.f), 0.f, getRandom(0.1f, 1.f));
}

bool particleIsAboveGround(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	// TODO: Use the parameters to determine if the particle
	//       is currently above the ground.
	//       Return true if the particle is above the ground, false otherwise.
	if (position.y > 0.0f) {
		return true;
	}
	std::cout << "death line" << std::endl;
	return false;
}

bool particleIsMovingUpward(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	// TODO: Use the parameters to determine if the particle
	//       is currently moving upward.
	//       Return true if the particle is above the ground, false otherwise.
	if ((int)acceleration.y > 0) {
		return true;
	}
	std::cout << "kill line" << std::endl;
	return false;
}

void doTimeStepEuler(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	// TODO: Implement the Euler Integration algorithm to advance
	//       the simulation one step forward in time.

}

void doTimeStepMidpoint(cMatrix3x3& axes, float& deltaTime, float& timeElapsed, cVector3& position, cVector3& velocity, cVector3& acceleration)
{
	// TODO: Implement the Midpoint Integration algorithm to advance
	//       the simulation one step forward in time.
	//df = vt + 1/2 a*t^2
	timeElapsed += deltaTime;
	position.operator+=(velocity);
	position.operator+=(acceleration);
	position.operator/=(2);
	//std::cout << acceleration.y << std::endl;
	std::cout << " X: " << position.x << " Y: " << position.y << " Z: " << position.z << " Time: " << deltaTime << std::endl;
}