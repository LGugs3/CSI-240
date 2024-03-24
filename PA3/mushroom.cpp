
#include "mushroom.h"

Mushroom::Mushroom()
{
	mIsPoisonous = true;
	mDistance = 0;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = 0;
	}
}

Mushroom::Mushroom(bool isPoisonous, double distance, int attributes[])
{
	mIsPoisonous = isPoisonous;
	mDistance = distance;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = attributes[i];
	}

}

