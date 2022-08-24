#include <iostream>
using namespace std;

class point{
public:
	
	int value;
	point * nextP = 0;
	
	point(int v){
		value = v;
	}
	
	~point(){
		delete nextP;
	}
	
	/*int* operator*(){
		int * newV = new int(this->value);
		return newV;
	}*/
	
	point* push_back(int v){
		if(nextP == 0) {
			nextP = new point(v);
			
			return nextP;
		} else {
			return nextP->push_back(v);
		}
	}

	void print(){
		cout << endl << value;
		if(nextP != 0) nextP->print();
	}

	/*point& operator++(){
		cout << "++ overload";
		return *nextP;
	}*/
	point& operator++(int){
		//cout << "++ overload 2";
	//	*this = *nextP;
		return *nextP;
	}
};

class forward_list{
public:

	point * begin = 0;
	point * end = 0;
	int size = 0;

	forward_list(){}
	~forward_list(){
		delete begin;
	}

	point* push_back(int v){
		if(size == 0) {
			begin = new point(v);
			end = begin;
		} else {
			end = begin->push_back(v);
		}
		
		size++;
		return end;
	}

	void pop_front(){
		begin = begin->nextP;
		size--;
	}

	void print(){
		if(begin != 0) begin->print();
	}
};

int main(){
	forward_list l = forward_list();
	
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	
	point *t = l.push_back(50);
//	cout << *t;
	l.push_back(40);
	l.push_back(400);
	l.push_back(4000);
	l.push_back(40998);
	l.pop_front();
	l.pop_front();
	l.pop_front();
	l.pop_front();
	l.print();
	cout << endl << l.size;

	return 0;
}
