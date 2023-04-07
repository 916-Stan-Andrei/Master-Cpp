#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"

class Repo {
private:
	DynamicVector<Tutorial> repo;
public:
	Repo() {};
	
	int add_tutorial(Tutorial);

	int delete_tutorial(Tutorial);

	int update_tutorial(Tutorial);

	int find_tutorial(std::string title, std::string presenter);

	DynamicVector<Tutorial> get_all_tutorials() { return repo; };

};
