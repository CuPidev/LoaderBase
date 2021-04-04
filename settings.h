#pragma once
#include <iostream>
#include <vector>

namespace Settings
{
	static bool AutoInject = false;
	static int Tab = 0;
	static int SelectedGame = NULL;
	const std::vector<const char*> Games = { "CSGO","Rust","Escape from Tarkov","Unturned","Valorant" };
}