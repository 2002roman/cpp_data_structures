/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class dot{
public:
    int value;
    dot * lAddress = 0;
    dot * rAddress = 0;
    dot(int v){
        value = v;
    }
    dot* operator* (){
        return this;
    }
    void setRightValue(int val){
        if(rAddress == 0){
            rAddress = new dot(val);
        } else if(val > rAddress->value){
            rAddress->setRightValue(val);
        } else if(val < rAddress->value){
            rAddress->setLeftValue(val);
        }
    }
    void setLeftValue(int val){
        if(lAddress == 0){
            lAddress = new dot(val);
        } else if(val > lAddress->value){
            lAddress->setRightValue(val);
        } else if(val < lAddress->value){
            lAddress->setLeftValue(val);
        }
    }
    void print(){
        cout << endl << value << endl;
        if(rAddress != 0) rAddress->print();
        if(lAddress != 0) lAddress->print();
    }
    ~dot(){
        delete lAddress;
        delete rAddress;
    }
};

class binaryThree{
public:
    dot * head = 0;
    binaryThree(){}
    binaryThree(int v){
        head = (new dot(v));
    }
    void insert(int val){
        if(head == 0){
            head = new dot(val);
        } else if(val > head->value){
            head->setRightValue(val);
        } else if(val < head->value){
            head->setLeftValue(val);
        }
    }
    void print (){
        head->print();
    }
    ~binaryThree(){
        delete head;
    }
};

int main()
{
    binaryThree a = binaryThree(78);
    a.insert(100);
    a.insert(98);
    a.insert(56);
    a.insert(878);
    a.print();
    return 0;
}


