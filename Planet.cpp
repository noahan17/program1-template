#include "Planet.h"
#include <stdlib.h>
#include <iostream>

Planet::Planet(int id){
	this->id = &this;
	this->distance = rand()% 3001;
    	this->pos = rand()%360;
	char arrayType[3] = {'h', 'r', 'g'};
	this->type = arrayType[rand()%3];
}
int Planet::orbit(){
	if(this->pos < 359){
		this->pos++;
	}
	else{
		this->pos = 0;
	}
	return this->pos;
}

