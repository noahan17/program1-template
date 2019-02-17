#ifndef planet_mp
#define planet_mp

class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
        int orbit();
	inline int getID(){return id;};
        int getDistance(){return distance;};
        int getPos(){return pos;};
	char getType(){return type;};
		//you may add any additional methods you may need.
};

#endif
