#include <iostream>
#include <cstring>

using namespace std;

class Document
{
	public:
		Document(char *fn)
		{
			strcpy(name, fn);
		}
		
		virtual void Open() = 0;
		virtual void Close() = 0;
		
		char *GetName()
		{
			return name;
		}
	private:
		char name[20];
};

class MyDocument : public Document
{
	public:
		MyDocument(char *fn) : Document(fn) {}
		
		void Open()
		{
			cout << " MyDocument: Open()" << endl;
		}
		
		void Close()
		{
			cout<< " MyDocument: Close()" << endl;
		}
};

class Application
{
	public:
		Application(): _index(0)
		{
			cout << "Application: ctor" << endl;
		}

		void NewDocument(char *name)
		{
			cout << "Application: NewDocument()" << endl;
			_docs[_index] = CreateDocument(name);
			_docs[_index++]->Open();
		}
		
		void OpenDocument() {}
		void ReportDocs();
		
		virtual Document *CreateDocument(char *) = 0;
	private:
		int _index;
		Document *_docs[10];
};


void Application::ReportDocs()
{
	cout << "Application: ReportDocs()" << endl;
	for (int i = 0; i < _index; ++i) {
		cout << " " << _docs[i]->GetName() << endl;
	}
}

class MyApplication : public Application
{
	public:
		MyApplication()
		{
			cout << "My Application: ctor" << endl;
		}

		Document *CreateDocument(char *fn)
		{
			cout << " MyApplication: CreateDocument()" << endl;
			return new MyDocument(fn);
		}
};

int main()
{
	MyApplication myApp;
	
	myApp.NewDocument("foo");
	myApp.NewDocument("bar");
	myApp.ReportDocs();
}

