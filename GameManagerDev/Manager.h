#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "IState.h"
#include "GameMainState.h"
#include "MainMenuState.h"

enum class StateTypeTask
{
	DO_NOTHING,
	MAIN_MENU_STATE,
	GAME_MAIN_STATE,
	CLOSE_GAME_STATE
};

class Manager
{
private:
	static StateTypeTask state_type_task;
	std::unique_ptr<IState> current_state;
	sf::RenderWindow* window;

public:
	Manager();

	void processInput(const sf::Event& event);
	void update(const float& delta_time);
	void render(sf::RenderWindow& window);
	static void SwitchOnState(const StateTypeTask& task);
	
private:
	void SwitchStateIfNeed();
};
