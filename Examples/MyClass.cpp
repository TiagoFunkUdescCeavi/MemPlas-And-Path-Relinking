#include "MyClass.h"

MyClass::MyClass(int size){
	this->size = size;
	this->vector = new int[ size ];
}

MyClass::~MyClass(){
	delete vector;
}
