

class vector
{
	int sz;
	int* v;
public:
	vector(int);
	~vector();
	int& operator [] (int index);
};


vector::~vector()
{
	delete[] v;
}