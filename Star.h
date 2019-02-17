#ifndef star_h
#define star_h
#include "Planet.h"
class Star{
	private:
		int current_planets;
		int next_id;
	public:
		Planet ** planets;
		Star();
		~Star();
		int addPlanet();
		Planet getFurthest();
		void orbit();
		void printStarInfo();
		Planet * getPlanet(int);
		int getCurrentNumPlanets(){return current_planets;};
		bool removePlanet(int);
        //you may add any additional methods you may need.
};

#endif
