#include "types/Boardgame.h"
#include <algorithm>

std::string Boardgame::truncate(const std::string& str, size_t length) {
    return str.substr(0, std::min(str.length(), length));
}

void Boardgame::calculateFunPerMinutePerPlayer() {
    float avgPlayers = (minPlayers + maxPlayers) / 2.0f;
    funPerMinutePerPlayer = (funFactor * 3.0f + (11 - complexity) * 2.0f) / (playTime * avgPlayers);
}

Boardgame::Boardgame(std::string name, std::string publisher, 
                     int minPlayers, int maxPlayers,
                     int playTime, int complexity, int funFactor)
    : name(truncate(name, 25))
    , publisher(truncate(publisher, 25))
    , minPlayers(std::clamp(minPlayers, 1, 10))
    , maxPlayers(std::clamp(maxPlayers, minPlayers, 10))
    , playTime(std::clamp(playTime, 5, 480))
    , complexity(std::clamp(complexity, 1, 10))
    , funFactor(std::clamp(funFactor, 1, 10))
{
    calculateFunPerMinutePerPlayer();
}

bool Boardgame::operator<(const Boardgame& other) const {
    return funPerMinutePerPlayer < other.funPerMinutePerPlayer;
}

bool Boardgame::operator>(const Boardgame& other) const {
    return other < *this;
}

const std::string& Boardgame::getName() const { 
    return name; 
}

const std::string& Boardgame::getPublisher() const { 
    return publisher; 
}

int Boardgame::getMinPlayers() const { 
    return minPlayers; 
}

int Boardgame::getMaxPlayers() const { 
    return maxPlayers; 
}

int Boardgame::getPlayTime() const { 
    return playTime; 
}

int Boardgame::getComplexity() const { 
    return complexity; 
}

int Boardgame::getFunFactor() const { 
    return funFactor; 
} 