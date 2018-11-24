#pragma once
#include "scene.h"
#include "ParticleSystem.h"
#include "Particle.h"

class scene_particle : public scene
{
	public:
		Particle p;
		ParticleSystem particleSystem;

		cgmath::vec3 camPosition;
		
		cgmath::vec3 minPosition, maxPosition;
		cgmath::vec3 minVelocidad, maxVelocidad;
		cgmath::vec3 a;
		float minTtl, maxTtl;
		float minAlpha, maxAlpha;

		void init();
		void awake();
		void sleep();
		void reset() { }
		void mainLoop();
		void resize(int width, int height);
		void normalKeysDown(unsigned char key) { }
		void normalKeysUp(unsigned char key) { }
		void specialKeys(int key) { }
		void passiveMotion(int x, int y) { }
	
	private:
		GLuint shaderID;
		GLuint texID;

		float aspect;
};


