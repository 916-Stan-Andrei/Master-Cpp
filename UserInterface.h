#pragma once
#include "Service.h"

class UserInterface {
private:
	Service service;
	DynamicVector<Tutorial> watchlist;

	//ADMIN
	void ui_add_tut();
	void ui_del_tut();
	void ui_upd_tut();
	
	void print_all_tuts();
	void print_admin_menu();

	//USER
	void explore_by_presenter();
	void delete_from_watchlist();
	void print_watchlist();

	void print_watchlist_menu();
	void print_user_menu();


public:
	UserInterface(Service serv) : service(serv) {}
	void run_admin();
	void run_user();
	void run_app();

};

