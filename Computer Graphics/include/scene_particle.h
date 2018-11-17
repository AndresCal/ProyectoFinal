#pragma once
#include "scene.h"
#include "ParticleSystem.h"
#include "Particle.h"

class scene_particle : public scene
{
	public:
		 
		Particle p;
		ParticleSystem particleSystem;
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


