#include "Tutorial.h"

Tutorial::Tutorial() : title(""), presenter(""), duration(""), likes(0), link("") {}

Tutorial::Tutorial(const std::string title, const std::string presenter, const std::string duration, const int likes, const std::string link) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
}

