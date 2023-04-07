#include "Service.h"

void Service::add_tut(Tutorial tut) {
	int func = this->repository.add_tutorial(tut);
	if (func == 0)
		throw std::exception("Can't add lol!");
}

void Service::del_tut(Tutorial tut) {
	int func = this->repository.delete_tutorial(tut);
	if (func == 0)
		throw std::exception("Can't delete lol!");

}

void Service::upd_tut(Tutorial tut) {
	int func = this->repository.update_tutorial(tut);
	if (func == 0)
		throw std::exception("Can't update lol!");
}

void Service::populate()
{
	add_tut(Tutorial("C++ Full Course for free", "Bro Code", "6:00:00", 35000, "https://www.youtube.com/watch?v=-TkoO8Z07hI&ab_channel=BroCode"));
	add_tut(Tutorial("C++ Tutorial for Beginners", "Programming with Mosh", "1:22:55", 36000, "https://www.youtube.com/watch?v=ZzaPdXTrSb8&ab_channel=ProgrammingwithMosh"));
	add_tut(Tutorial("Introducere în programare", "Videotutorial.ro", "15:52", 7600, "https://www.youtube.com/watch?v=JjY9U9lu37I&ab_channel=Videotutorial.ro"));
	add_tut(Tutorial("C++ Tutorial for Beginners", "freeCodeCamp.org", "4:01:18", 260000, "https://www.youtube.com/watch?v=vLnPwxZdW4Y&ab_channel=freeCodeCamp.org"));
	add_tut(Tutorial("C++ Programming Course", "freeCodeCamp.org", "1:07:07:29", 103000, "https://www.youtube.com/watch?v=8jLOx1hD3_o&ab_channel=freeCodeCamp.org"));
	add_tut(Tutorial("Object Oriented Programming (OOP) in C++ Course", "freeCodeCamp.org", "1:30:25", 50000, "https://www.youtube.com/watch?v=wN0x9eZLix4&ab_channel=freeCodeCamp.org"));
	add_tut(Tutorial("C++ in 100 Seconds", "Fireship", "2:45", 51000, "https://www.youtube.com/watch?v=MNeX4EGtR5Y&ab_channel=Fireship"));
	add_tut(Tutorial("Welcome to C++", "TheCherno", "7:04", 21000, "https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&ab_channel=TheCherno"));
	add_tut(Tutorial("Introduction to C++", "AnisulIslam", "4:39", 6000, "https://www.youtube.com/watch?v=0T4mPpbNs_8&list=PLgH5QX0i9K3q0ZKeXtF--CZ0PdH1sSbYL&ab_channel=AnisulIslam"));
	add_tut(Tutorial("Templates in C++", "TheCherno", "17:57", 17000, "https://www.youtube.com/watch?v=I-hZkUa9mIs&ab_channel=TheCherno"));

}


