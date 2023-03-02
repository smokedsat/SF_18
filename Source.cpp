#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "Message.hpp"
#include "User.hpp"
#include "demo_perms.hpp"

namespace fs = std::filesystem;

int main()
{
	std::string messages_txt{ "messages.txt" };
	std::string users_txt{ "users.txt" };

	std::cout << "Permissions for " << messages_txt << std::endl;
	demo_perms(fs::status(messages_txt).permissions());

	std::cout << std::endl << "Permissions for " << users_txt << std::endl;
	demo_perms(fs::status(users_txt).permissions());
	std::cout << std::endl;

	User us1((const char*)"semen", (const char*)"smok", (const char*)"pass");
	User us2((const char*)"snen", (const char*)"smodfk", (const char*)"passss");
	User us3;

	save_user(us1,users_txt);
	save_user(us2, users_txt);
	load_user(us3, users_txt);

	Message mess1((const char*)"Hello", (const char*)"Me", (const char*)"Myself");
	Message mess2(messages_txt);
	Message mess3;

	save_message(mess1, messages_txt);
	save_message(mess2, messages_txt);
	load_message(mess3, messages_txt);

	std::cout <<"_______________" << std::endl <<  "Permissions for " << messages_txt << std::endl;
	demo_perms(fs::status(messages_txt).permissions());

	std::cout << std::endl << "Permissions for " << users_txt << std::endl;
	demo_perms(fs::status(users_txt).permissions());
	std::cout << std::endl;

}