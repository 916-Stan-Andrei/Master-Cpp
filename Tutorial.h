#pragma once
#include<iostream>

class Tutorial {
private:
	std::string title, presenter, duration, link;
	int likes;
public:
	Tutorial();
	Tutorial(const std::string title, const std::string presenter, const std::string duration, const int likes, const std::string link);

	//getters
	std::string get_title() const { return title; }
	std::string get_presenter() const { return presenter; }
	std::string get_duration() const { return duration; }
	std::string get_link() const { return link; }
	int get_likes() const { return likes; }

};