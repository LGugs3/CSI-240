

#ifndef MUSHROOM
#define MUSHROOM



#include <fstream>
#include <string>
#include <sstream>

const int NUM_ATTRIBUTES = 22;

struct Mushroom
{
	private:
		bool mIsPoisonous;
		double mDistance;
		int mAttributes[NUM_ATTRIBUTES];

	public:
		Mushroom();
		Mushroom(bool isPoisonous, int attributes[]);
		void loadData();
		void setDistance(Mushroom compatator);


		friend std::ifstream& operator>>(std::ifstream& input, Mushroom& obj);
		Mushroom operator=(Mushroom rhs);


};


#endif // !MUSHROOM_H