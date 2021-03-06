#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "ECS.h"

class PositionComponent : public Component
{
private:
	int xpos, ypos;

public:

	int x() {return xpos; }
	int y() {return ypos; }

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
		
	}

	void init() override
	{
		xpos = 0;
		ypos = 0;
		
	}

	void update() override
	{
		xpos = x();
		ypos = y();
	}
	
};


#endif 
