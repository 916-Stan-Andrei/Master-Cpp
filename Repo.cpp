#include "Repo.h"

//Adds a tutorial to the repo. Returns 0 if the tutorial we want to add already exists in the repo and 1 if the operation is a success.
int Repo::add_tutorial(Tutorial tutorial) {
	if (this->find_tutorial(tutorial.get_title(), tutorial.get_presenter()) != -1)
		return 0;
	this->repo.addItem(tutorial);
	return 1;
}

//Search for a tutorial with a title and presenter given. Returns the position of the tutorial if it exists in the repos, -1 otherwise.
int Repo::find_tutorial(std::string title, std::string presenter) {
	Tutorial tut;
	for (int i = 0; i < this->repo.getSize(); i++) {
		tut = this->repo.getElement(i);
		if (tut.get_title() == title && tut.get_presenter() == presenter)
			return i;
	}
	return -1;
}

//Deletes a tutorial from the repo . Returns 0 if the tutorial we want to delete is not int the repo, 1 if the operation is a succecss.
int Repo::delete_tutorial(Tutorial tutorial) {
	int pos = this->find_tutorial(tutorial.get_title(), tutorial.get_presenter());
	if (pos == -1)
		return 0;
	this->repo.deleteItem(pos);
	return 1;
}

//Updates the duration, likes and the link of a tutorial with a title and presenter given. Returns 0 if the tutorial we want to update is not in
//the repo, 1 if the operation is a success.
int Repo::update_tutorial(Tutorial tutorial) {
	int pos = this->find_tutorial(tutorial.get_title(), tutorial.get_presenter());
	if (pos == -1)
		return 0;
	this->repo.updateItem(pos, tutorial);
	return 1;
}
