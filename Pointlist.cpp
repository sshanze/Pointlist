 
#include <iostream>

using namespace std;

struct Point3D {
	float x, y, z;
};

class PointerList {
private:
	Point3D* points;
	int max_Size;
	int cur_Size;
	int cursor;

public:
	//Constructor Function
	PointerList(int max_Size) {
		this->max_Size = max_Size;
		this->cur_Size = 0;
		this->cursor = -1;

		points = new Point3D[max_Size];
	}

	//Destructor
	~PointerList() {
		delete[] points;
	}

	bool isEmpty() {
		return cur_Size == 0;
	}

	bool isFull() {
		return cur_Size == max_Size;
	}

	void insert(Point3D new_Point) {
		if (!isFull())
		{
			if (isEmpty())
			{
				cursor = 0;
			}
			points[cur_Size++] = new_Point;
		}
	}

	void showStructure() {
		if (isEmpty()) {
			cout<<"The list is empty..."<<endl;
				return;
		}

	    for (int i = 0; i < cur_Size; i++) {
			cout << "POSITION " << i << " " << "["<<points[i].x << "\t" << points[i].y << "\t" << points[i].z<<"]" << endl;
		}
	}

	Point3D getCursor() {
		Point3D error = { -1,-1,-1 };
		if (!isEmpty()) {
			return points[cursor];
		}
		else {
			cout << "The list is empty...." << endl;
			return error;
		}
	}

	void goToBeggining() {
		if (!isEmpty()) {
			cursor = 0;
		}
	}

	void goToEnd() {
		if (!isEmpty()) {
			cursor = cur_Size - 1;
		}
	}

	bool goToNext() {
		if (cursor < cur_Size - 1) {
			cursor++;
			return true;
		}
		return false;
	}

	bool goToPrior() {
		if (cursor > 0) {
			cursor--;
			return true;
		}
		return false;
	}

	void clear() {
		cursor = -1;
		cur_Size = 0;
	}

	bool replace(Point3D new_Point) {
		if (!isEmpty() && cursor >= 0 && cursor < cur_Size) {
			points[cursor] = new_Point;
			return true;
		}
		return false;
	}

	void remove() {
		if (!isEmpty() && cursor >= 0 && cursor < cur_Size) {
			for (int i = 0; i < cur_Size; i++) {
				points[i] = points[i + 1];
			}
			cur_Size--;

			if (cursor == cur_Size) {
				cursor = 0;
			}
		}
	}
};


int main() {
	PointerList pointerList(10);

	Point3D Point1 = { 10.0,20.0,30.0 };
	Point3D Point2 = { 40.0,50.0,60.0 };
	Point3D Point3 = { 70.0,80.0,90.0 };

	pointerList.insert(Point1);
	pointerList.insert(Point2);
	pointerList.insert(Point3);

	pointerList.showStructure();

	pointerList.goToBeggining();
	cout << "CURRENT POSITION: " << pointerList.getCursor().x << "\t" << pointerList.getCursor().y << "\t" << pointerList.getCursor().z << endl;

	pointerList.goToEnd();
	cout << "CURRENT POSITION: " << pointerList.getCursor().x << "\t" << pointerList.getCursor().y << "\t" << pointerList.getCursor().z << endl;

	if (pointerList.goToNext()) {
		cout << "CURRENT POSITION: " << pointerList.getCursor().x << "\t" << pointerList.getCursor().y << "\t" << pointerList.getCursor().z << endl;
	}
	else
	{
		cout << "CURSOR IS AT THE END..." << endl;
	}


	Point3D new_Point = { 100.0,200.0,300.0 };
	if (pointerList.replace(new_Point)) {
		cout << "REPLACED CURRENT POSITION..." << endl;
		pointerList.showStructure();
	}
	else 
	{
		cout << "NOT REPLACED CURRENT POSITION..." << endl;
	}

	pointerList.remove();

	cout << "AFTER REMOVAL..." << endl;
	pointerList.showStructure();

	return 0;
}