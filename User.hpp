#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "change_perms.hpp"

class User;
void load_user(User& nU, std::string& filename);
void save_user(User& u, std::string& filename);

class User
{
private:
	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User() : _name("default"), _login("default"), _pass("default") { }
	User(const char* n, const char* l, const char* p) : _name(n), _login(l), _pass(p) {}
	User(std::string& filename) { load_user(*this, filename); }

	std::string getName() { return _name; }
	std::string getLogin() { return _login; }
	std::string getPass() { return _pass; }

public:
	void setName(std::string& name) { _name = name; }
	void setLogin(std::string& login) { _login = login; }
	void setPass(std::string& pass) { _pass = pass; }
};

void load_user(User& nU, std::string& filename)
{
	std::string n;
	std::string l;
	std::string p;

	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);

	if (file.is_open())
	{
		file >> l >> n >> p;

		file.close();
	}

	nU.setLogin(l);
	nU.setName(n);
	nU.setPass(p);

}

void save_user(User& u, std::string& filename)
{

	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << u.getLogin() << ' ' << u.getName() << ' ' << u.getPass() << '\n';
		file.close();
	}

	remove_all_permissions(filename);

}
