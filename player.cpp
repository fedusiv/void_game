#include "player.h"

Player::Player() : _Step(0)
{
    Stats = new PlayerStats();
    Race = new PlayerRace();
    Class = new PlayerClass();
}

int ** Player::getPlayerStats()
{
    return Stats->getStats();
}

int Player::getPlayerLevel()
{
    return Stats->getLevel();
}

int Player::getPlayerCurrentHealth()
{
    return Stats->Health();
}

QString Player::getPlayerRaceName()
{
    return Race->getName();
}

QString Player::getPlayerClassName()
{
    return Class->getName();
}

int Player::getPlayerStep()
{
    return _Step;
}
