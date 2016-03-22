#include <iostream>
#include <string.h>

class TimeImp {
	public:
		TimeImp() {
		}
		TimeImp(int hr, int min) {
			_hr = hr;
			_min = min;
		}
		virtual void tell() {
			std::cout << "time is " << _hr << " " << _min << std::endl;
		}
	protected:
		int _hr, _min;
};

class CivilianTimeImp:public TimeImp {
	public:
		CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
			if (pm) {
				strcpy(_pm, "PM");
			} else {
				strcpy(_pm, "AM");
			}
		}

		void tell() {
			std::cout << "time is " << _hr << ":" << _min << _pm << std::endl;
		}
	
	protected:
		char _pm[4];
};

class ZuluTimeImp:public TimeImp {
	public:
		ZuluTimeImp(int hr, int min, int zone) : TimeImp(hr, min) {
			if (zone == 5) {
				strcpy(_zone, "Eastern");
			} else {
				strcpy(_zone, "West");
			}
		}

		void tell() {
			std::cout << "time is " << _hr << ":" << _min << _zone << std::endl;
		}
	protected:
		char _zone[30];
	
};

class Time {
	public:
		Time() {}
		Time (int hr, int min) {
			_imp = new TimeImp(hr, min);
		}
		virtual void tell() {
			_imp->tell();
		}
	protected:
		TimeImp *_imp;

};


class CivillianTime:public Time {
	public:
		CivillianTime(int hr, int min, int pm) {
			_imp = new CivilianTimeImp(hr, min, pm);
		}
};

class ZuluTime:public Time {
	public:
		ZuluTime(int hr, int min, int zone) {
			_imp =  new ZuluTimeImp(hr, min, zone);
		}
};


int main() {
	Time *times[3];
	times[0] = new Time(14, 30);
	times[1] = new CivillianTime(2, 30, 1);
	times[2] = new ZuluTime(14, 30, 6);
	for (int i = 0; i < 3; ++i) {
		times[i]->tell();
	}
}


