
#include "Player.h"



Player::Player()
{
	health = 10;
	movement = 0;
	m_name = "unknown";
	player_number = 0;

	HRESULT hCreateGuid = CoCreateGuid(&id);
}

GUID Player::get_id() {
	return id;
}

void Player::name(std::string target_name) {
	m_name = target_name;
}

std::string Player::get_name() {
	return m_name;
}

void Player::hit_points(int hitpoints) {
	health = hitpoints;
}

int Player::hit_points() {
	return health;
}

void Player::PlayerNumber(int number) {
	player_number = number;
}

int Player::PlayerNumber() {
	return player_number;
}
