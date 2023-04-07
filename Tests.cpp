#include "Tests.h"
#include "DynamicVector.h"
#include "Tutorial.h"
#include "Repo.h"
#include "Service.h"
#include <cassert>

void test_DynamicVector() {
	DynamicVector<int> v;
	v.addItem(2);
	v.addItem(15);
	v.addItem(21);
	assert(v.getElement(0) == 2);
	assert(v.getElement(1) == 15);
	assert(v.getElement(2) == 21);
	assert(v.getSize() == 3);
	v.deleteItem(1);
	assert(v.getSize() == 2);
	assert(v.getElement(1) == 21);
	v.updateItem(0, 16);
	assert(v.getElement(0) == 16);
}

void test_Tutorial() {
	Tutorial t("test_title", "test_presenter", "duration", 404, "link");
	assert(t.get_title() == "test_title");
	assert(t.get_presenter() == "test_presenter");
	assert(t.get_duration() == "duration");
	assert(t.get_likes() == 404);
	assert(t.get_link() == "link");
}

void test_Repo() {
	Repo r;
	assert(r.add_tutorial(Tutorial("test_title", "test_presenter", "duration", 404, "link")) == 1);
	assert(r.add_tutorial(Tutorial("test_title1", "test_presenter1", "duration", 404, "link")) == 1);
	assert(r.add_tutorial(Tutorial("test_title2", "test_presenter2", "duration", 404, "link")) == 1);
	assert(r.find_tutorial("test_title", "test_presenter") == 0);
	assert(r.find_tutorial("test_title1", "test_presenter1") == 1);
	assert(r.find_tutorial("test_title2", "test_presenter2") == 2);
	assert(r.find_tutorial("test_title3", "test_presenter3") == -1);
	assert(r.delete_tutorial(Tutorial("test_title1", "test_presenter1", "duration", 404, "link")) == 1);
	assert(r.find_tutorial("test_title1", "test_presenter1") == -1);
	assert(r.find_tutorial("test_title2", "test_presenter2") == 1);
	assert(r.update_tutorial(Tutorial("test_title2", "test_presenter2", "duration1", 404, "link1")) == 1);
	DynamicVector<Tutorial> v(r.get_all_tutorials());
	assert(v.getElement(1).get_duration() == "duration1");
	assert(v.getElement(1).get_likes() == 404);
	assert(v.getElement(1).get_link() == "link1");
}

void test_Service() {
	Repo r;
	Service s{ r };
	s.populate();
	assert(s.get_tuts().getSize() == 10);
	try {
		s.add_tut(Tutorial("C++ Full Course for free", "Bro Code", "6:00:00", 35000, "https://www.youtube.com/watch?v=-TkoO8Z07hI&ab_channel=BroCode"));
		assert(false);
	}
	catch (std::exception ex) {
		assert(true);
	}

	assert(s.get_tuts().getSize() == 10);
	try {
		s.del_tut(Tutorial("C++ Full Course for free", "Bro Code", "6:00:00", 35000, "https://www.youtube.com/watch?v=-TkoO8Z07hI&ab_channel=BroCode"));
		assert(true);
	}
	catch (std::exception ex) {
		assert(false);
	}
	assert(s.get_tuts().getSize() == 9);
	try {
		s.del_tut(Tutorial("C++ Full Course for free", "Bro Code", "6:00:00", 35000, "https://www.youtube.com/watch?v=-TkoO8Z07hI&ab_channel=BroCode"));
		assert(false);
	}
	catch (std::exception ex) {
		assert(true);
	}
	assert(s.get_tuts().getSize() == 9);
	try {
		s.upd_tut(Tutorial("C++ Tutorial for Beginners", "Programming with Mosh", "1", 1, "1"));
		assert(true);
	}
	catch (std::exception ex) {
		assert(false);
	}
}


void Tests::test_all()
{
	test_DynamicVector();
	test_Tutorial();
	test_Repo();
	test_Service();
}
