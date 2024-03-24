

const int NUM_ATTRIBUTES = 22;

struct Mushroom
{
	private:
		bool mIsPoisonous;
		double mDistance;
		int mAttributes[NUM_ATTRIBUTES];

	public:
		Mushroom();
		Mushroom(bool isPoisonous, double distance, int attributes[]);


};