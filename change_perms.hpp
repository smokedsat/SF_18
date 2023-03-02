#pragma once

#include <filesystem>

namespace fs = std::filesystem;

void give_all_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::all, fs::perm_options::add);
}

void give_others_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::others_all, fs::perm_options::add);
}

void give_group_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::group_all, fs::perm_options::add);
}

//_________________________________________________________

void remove_all_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::all, fs::perm_options::remove);
}

void remove_others_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::others_all, fs::perm_options::remove);
}

void remove_group_permissions(std::string& file)
{
	fs::permissions(file, fs::perms::group_all, fs::perm_options::remove);
}