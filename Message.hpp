#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "change_perms.hpp"


class Message;
void load_message(Message& nM, std::string& filename);
void save_message(Message& mess, std::string& filename);

class Message
{
private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	std::string getText() { return _text; }
	std::string getSender() { return _sender; }
	std::string getReceiver() { return _receiver; }

	Message(std::string& filename) { load_message(*this, filename); }

	Message() : _text("default"), _sender("default"), _receiver("default") { }

	Message(const char* t, const char* s, const char* r) : _text(t), _receiver(r), _sender(s) {}

public:
	void setText(std::string& text) { _text = text; }
	void setSender(std::string& sender) { _sender = sender; }
	void setReceiver(std::string& receiver) { _receiver = receiver; }

};

void save_message(Message& mess, std::string& filename)
{
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);
	if (file.is_open())
	{
		// saving messages in format: text, from, to.
		file << mess.getText() << ' ' << mess.getSender() << ' ' << mess.getReceiver() << '\n';
		file.close();
	}
	
	remove_all_permissions(filename);
	
}

void load_message(Message& nM, std::string& filename)
{
	std::string text;
	std::string sender;
	std::string receiver;

	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);

	if (file.is_open())
	{
		file >> text >> sender >> receiver;

		file.close();
	}

	nM.setText(text);
	nM.setSender(sender);
	nM.setReceiver(receiver);

}
