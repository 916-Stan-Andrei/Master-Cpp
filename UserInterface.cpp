#include "UserInterface.h"
#include<iostream>
#include<Windows.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include <cstdlib>


using namespace std;



void UserInterface::print_admin_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	cout << "||~~~~~~~~~~ ADMIN MODE ~~~~~~~~~~||" << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "print => Displays all turorials" << endl;
	cout << "add => The admin can add a new tutorial" << endl;
	cout << "delete => The admin can delete an existing tutorial" << endl;
	cout << "update => The admin can update an existing tutorial" << endl;
	cout << "x => Exit the menu." << endl;
	SetConsoleTextAttribute(h, 15);
}



void UserInterface::print_watchlist_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	cout << "open => open link;" << endl;
	cout << "add => add to watchlist;" << endl;
	cout << "next => go to the next tutorial;" << endl;
	cout << "stop => exit this option." << endl;
	SetConsoleTextAttribute(h, 15);
}

void UserInterface::print_user_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	cout << "explore => Explore tutorials;" << endl;
	cout << "delete => Delete a tutorial from watchlist;" << endl;
	cout << "watchlist => See your watchlist;" << endl;
	cout << "x => Exit the menu." << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 15);
}

//##################### ADMIN MODE ###########################

void UserInterface::print_all_tuts()
{
	DynamicVector<Tutorial> list = this->service.get_tuts();
	Tutorial tut;
	if (list.getSize() == 0)
		cout << "The database is empty!" << endl;

	for (int i = 0; i < list.getSize(); i++) {
		tut = list.getElement(i);
		cout << "Title: " << tut.get_title() << "\tPresenter: " << tut.get_presenter() << "\tDuration: " << tut.get_duration() << "\tLikesNb: " << tut.get_likes() << "\tLink: " << tut.get_link() << endl;	
	}
}

void UserInterface::ui_add_tut()
{
	std::string title, presenter, duration, link, likes;

	cout << "Give the title:";
	getline(cin, title);

	cout << "Give the presenter:";
	getline(cin, presenter);
	for (char c = '0'; c <= '9'; c++)
		while (presenter.find(c) != string::npos)
		{
			cout << "The presenter should contain only letters! Try again:";
			getline(cin, presenter);
			c = 10;
		}

	cout << "Give the video duration:";
	getline(cin, duration);

	cout << "Give the number of likes:";
	getline(cin, likes);

	for (char c : likes) 
		if (!isdigit(c)) {
			cout << "The number of likes should contain only digits!";
			break;
		}
	while (stoi(likes) < 0)
	{
		cout << "The number of likes shuldn't be a negative number! Try again:";
		getline(cin, likes);
	}

	cout << "Give the link:";
	getline(cin, link);

	try {
		this->service.add_tut(Tutorial(title, presenter, duration, stoi(likes), link));
		cout << "Tutorial added successfully!" << endl;
	}
	catch (std::exception e) {
		cout << e.what();
	}

}

void UserInterface::ui_del_tut()
{
	std::string title, presenter;

	cout << "Give the title:";
	getline(cin, title);

	cout << "Give the presenter:";
	getline(cin, presenter);
	for (char c = '0'; c <= '9'; c++)
		while (presenter.find(c) != string::npos)
		{
			cout << "The presenter should contain only letters! Try again:";
			getline(cin, presenter);
			c = 10;
		}
	
	try {
		this->service.del_tut(Tutorial(title, presenter, "", 0, ""));
		cout << "Tutorial deleted successfully!" << endl;
	}
	catch (std::exception e) {
		cout << e.what();
	}
}

void UserInterface::ui_upd_tut()
{
	string title, presenter, new_duration, new_likes, new_link;
	cout << "Give the title:";
	getline(cin, title);

	cout << "Give the presenter:";
	getline(cin, presenter);
	for (char c = '0'; c <= '9'; c++)
		while (presenter.find(c) != string::npos)
		{
			cout << "The presenter should contain only letters! Try again:";
			getline(cin, presenter);
			c = 10;
		}

	cout << "Give the new video duration:";
	getline(cin, new_duration);

	cout << "Give the new number of likes:";
	getline(cin, new_likes);
	for (char c : new_likes)
		if (!isdigit(c)) {
			cout << "The number of likes should contain only digits!Try again:";
			getline(cin, new_likes);
			break;
		}
	while (stoi(new_likes) < 0)
	{
		cout << "The number of likes shuldn't be a negative number! Try again:";
		getline(cin, new_likes);
	}

	cout << "Give the new link:";
	getline(cin, new_link);

	try {
		this->service.upd_tut(Tutorial(title, presenter, new_duration, stoi(new_likes), new_link));
		cout << "Tutorial updated succcessfully!";
	}catch (std::exception e) { cout << e.what(); }

}



void UserInterface::run_admin()
{
	std::string option;
	print_admin_menu();
	service.populate();
	int ok = 1;
	while (ok)
	{
		cout << "Please choose an option:";
		getline(std::cin, option);

		if (option == "print")
		{
			print_all_tuts();
			cout << endl;
		}
		else if (option == "add")
		{
			ui_add_tut();
			cout << endl;
		}
		else if (option == "delete")
		{
			ui_del_tut();
			cout << endl;
		}
		else if (option == "update")
		{
			ui_upd_tut();
			cout << endl;
		}
		else if (option == "x")
			ok = 0;
		else std::cout << "Wrong input!" << endl;
	}
}

//############################# USER MODE #################################

void UserInterface::explore_by_presenter()
{
	string presenter;
	string option;
	cout << "Enter presenter filter (or x):";
	getline(cin, presenter);
	auto filtered_list = this->service.get_tuts();
	if (presenter != "x") {
		for (int i = filtered_list.getSize() - 1; i >= 0; i--) {
			if (filtered_list.getElement(i).get_presenter() != presenter)
				filtered_list.deleteItem(i);
		}
	}

	bool exit = false;
	while (1) {
		for (int i = 0; i < filtered_list.getSize(); i++) {
			cout << "Current tutorial:" << endl;
			Tutorial tut = filtered_list.getElement(i);
			cout << "Title: " << tut.get_title() << "\tPresenter: " << tut.get_presenter() << "\tDuration: " << tut.get_duration() << "\tLikesNb: " << tut.get_likes() << "\tLink: " << tut.get_link() << endl;
			print_watchlist_menu();
			cout << "Please choose an option:";
			getline(cin, option);
			if (option == "open") {
				string link = tut.get_link();
				string command = "start " + link;
				system(command.c_str());
				i--;
			}
			else if (option == "add") {
				this->watchlist.addItem(tut);
				cout << "Tutorial added successfully to your watchlist!" << endl;
			}
			else if (option == "next") {
				continue;
			}
			else if (option == "stop") {
				exit = true;
				cout << endl;
			}
			else {
				cout << "Try again!" << endl;
				i--; }
			if (exit) break;
		}
		if (exit) break;
	}	
}

void UserInterface::delete_from_watchlist()
{
	string title, presenter, like;
	cout << "Please give the title of the tutorial:";
	getline(cin, title);
	cout << "Please give the presenter of the tutorial:";
	getline(cin, presenter);
	bool found = false;
	int pos;
	Tutorial tut;
	for (int i = 0; i < this->watchlist.getSize(); i++) {
		pos = i;
		tut = this->watchlist.getElement(i);
		if (title == tut.get_title() && presenter == tut.get_presenter()) {
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "You never added this tutorial in your watchlist!";
	else {
		cout << "Did you like the tutorial?[y/n]";
		getline(cin, like);
		if (like == "y") {
			int size = this->service.get_tuts().getSize();
			for (int i = 0; i < size; i++) {
				Tutorial tut2 = this->service.get_tuts().getElement(i);
				if (tut.get_title() == tut2.get_title() && tut.get_presenter() == tut2.get_presenter()) {
					service.del_tut(tut2);
					size--;
					service.add_tut(Tutorial(tut2.get_title(), tut2.get_presenter(), tut2.get_duration(), tut2.get_likes() + 1, tut2.get_link()));
				}
			}
		}
		watchlist.deleteItem(pos);
		cout << "Tutorial deleted successfully from your watchlist!" << endl;
	}
}

void UserInterface::print_watchlist()
{
	Tutorial tut;
	if (this->watchlist.getSize() == 0)
		cout << "Your watchlist is empty!" << endl;

	for (int i = 0; i < this->watchlist.getSize(); i++) {
		tut = this->watchlist.getElement(i);
		cout << "Title: " << tut.get_title() << "\tPresenter: " << tut.get_presenter() << "\tDuration: " << tut.get_duration() << "\tLikesNb: " << tut.get_likes() << "\tLink: " << tut.get_link() << endl;
	}

}


void UserInterface::run_user()
{
	string option;
	this->service.populate();
	if (service.get_tuts().getSize() == 0)
		cout << "We don't have any tutorial to show you! Please come later!" << endl;
	while (1) {
		print_user_menu();
		cout << "Please choose an option:";
		getline(cin, option);
		if (option == "explore") {
			explore_by_presenter();
		}
		else if (option == "delete") {
			delete_from_watchlist();
		}
		else if (option == "watchlist") {
			print_watchlist();
		}
		else if (option == "x")
			break;
	}

}


//############################# APP #################################
void UserInterface::run_app()
{
	std::string mode;
	cout << "Please choose the mode (admin/user): ";
	getline(std::cin, mode);

	if (mode == "admin")
		run_admin();
	else if (mode == "user") run_user();
	else cout << "You don't deserve to use my app :/";
}
