#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

enum PersistenceType {
	File,
	Queue
};

struct PersistenceAttribute {
	PersistenceType type;
	char value[30];
};

class DistrWorkPackage {
	public:
		DistrWorkPackage(char *type) {
			sprintf(_desc, "Distributed Work Package for: %s", type);
		}
		void setFile(char *f, char *v) {
			sprintf(_temp, "\n File(%s): %s", f, v);
			strcat(_desc, _temp);
		}
		
		void setQueue(char *q, char *v) {
			sprintf(_temp, "\n Queue(%s): %s", q, v);
			strcat(_desc, _temp);
		}
		const char *getState() {
			return _desc;
		}
	private:
		char _desc[200];
		char _temp[200];
};

class Builder {
	
	public:
		virtual void configureFile(char *) = 0;
		virtual void configureQueue(char *) = 0;
		DistrWorkPackage *getResult() {
			return _result;
		}
	protected:
		DistrWorkPackage *_result;

};


class UnixBuilder : public Builder {
	public:
		UnixBuilder() {
			_result = new DistrWorkPackage("Unix");
		}
		void configureFile(char *name) {
			_result->setFile("flatFile", name);
		}
		void configureQueue(char *queue) {
			_result->setQueue("FIFO", queue);
		}
};

class VmsBuilder : public Builder {
	public:
		VmsBuilder()
		{
			_result = new DistrWorkPackage("vms");
		}
		void configureFile(char *name) {
			_result->setFile("flatFile", name);
		}
		void configureQueue(char *queue) {
			_result->setQueue("FIFO", queue);
		}
};

class Reader {
	
	public:
		void setBuilder(Builder *b) {
			_builder = b;
		}
		
		void construct(PersistenceAttribute[], int);
	private:
		Builder *_builder;
};

void Reader::construct(PersistenceAttribute list[], int num) {

	for (int i = 0; i< num; ++i) {
		if (list[i].type == File) {
			_builder->configureFile(list[i].value);
		} else if (list[i].type == Queue) {
			_builder->configureQueue(list[i].value);
		}
	}
}

PersistenceAttribute input[] = 
{
	{File, "state.dat"},
	{File, "config.sys"},
	{Queue, "log"},
	{Queue, "compute"}
};

int main () {

	UnixBuilder unixBuilder;
	VmsBuilder vmsBuilder;
	Reader reader;

	reader.setBuilder(&unixBuilder);
	reader.construct(input, 4);
	cout << unixBuilder.getResult()->getState() << endl;

	reader.setBuilder(&vmsBuilder);
	reader.construct(input, 4);
	cout << vmsBuilder.getResult()->getState() << endl;

}




