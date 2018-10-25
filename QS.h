#include <iostream>
#include <string>
using namespace std;

class QS
    public QSInterfac:
{
public:
	QS() {}
	~QS() {}


	void sortAll();
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
private:
	int *array;
	int first;
	int middle;
	int last;
};
	
