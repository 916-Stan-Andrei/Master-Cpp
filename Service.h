#pragma once
#include "Repo.h"

class Service {
private:
	Repo repository;
public:
	explicit Service(Repo repo) :repository(repo) {}

	void add_tut(Tutorial);

	void del_tut(Tutorial);

	void upd_tut(Tutorial);

	DynamicVector<Tutorial> get_tuts() { return this->repository.get_all_tutorials(); };

	void populate();
	
};
