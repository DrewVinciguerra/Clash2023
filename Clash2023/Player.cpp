
#include "Player.h"



Player::Player()
{
	health = 10;
	movement = 0;
	m_name = "unknown";

	player_id = 0;
}

int Player::Id() {
	return player_id;
}

void Player::Id(int number) {
	player_id = number;
}


void Player::Name(std::string target_name) {
	m_name = target_name;
}

std::string Player::Name() {
	return m_name;
}

void Player::HitPoints(int hitpoints) {
	health = hitpoints;
}

int Player::HitPoints() {
	return health;
}

/*void Player::PlayerNumber(int number) {
	player_number = number;
}

int Player::PlayerNumber() {
	return player_number;
}*/

std::vector<Creature>* Player::CreatureVector() {
	return &creature_vector;
}

void Player::SummoningLocation(int x, int y) {
	summoning_location = std::make_pair(x, y);
}

std::pair<int, int> Player::SummoningLocation() {
	return summoning_location;
}
