#include "Star.h"
#include "Planet.cpp"
#include <stdlib.h>
#include <iostream>

Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;
}
Star::~Star(){
	for(int i = 0; i < this->current_planets; i++){
		delete this->planets[i];
	}
	delete[] planets;
}
int Star::addPlanet(){
	Planet ** planet_ptrs = new Planet*[current_planets+1];
	for(int i = 0; i < current_planets; i++){
		planet_ptrs[i] = planets[i];
	}
	Planet * a_planet = new Planet(current_planets+1);
	planet_ptrs[current_planets] = a_planet;
	current_planets++;
	delete[] planets;
	planets = planet_ptrs;
	return current_planets;
}
bool Star::removePlanet(int id){
	if(this->getPlanet(id) == NULL){
		return false;
	}
	Planet ** plnt = new Planet*[current_planets-1];
	int k = 0;
	for(int i = 0; i < current_planets; i++){
		if(planets[i]->getID() == id){
			delete planets[i];
		}
		else{
			plnt[k] = planets[i];
			k++;
		}
	}
	current_planets--;
	delete[] planets;
	planets = plnt;
	return true;
}
Planet* Star::getPlanet(int id){
	for(int i = 0; i < current_planets; i++){
		if(id == planets[i]->getID()){
			return planets[i];
		}
	}
	return NULL;
}
Planet Star::getFurthest(){
	Planet farthest = *planets[0];
	for(int i = 1; i < current_planets; i++){
		if(farthest.getDistance() < planets[i]->getDistance()){
			farthest = *planets[i];
		}
	}
	return farthest;
}
void Star::orbit(){
	for(int i = 0; i < current_planets; i++){
		planets[i]->orbit();
	}
}
void Star::printStarInfo(){
	printf("The star currently has %d planets\n",current_planets);
	printf("Planets:\n");
	for(int i = 0; i < current_planets; i++){
		printf("\tPlanet %d is %d million miles away at position %d around the star.\n", planets[i]->getID(), planets[i]->getDistance(), planets[i]->getPos());
	}
}
