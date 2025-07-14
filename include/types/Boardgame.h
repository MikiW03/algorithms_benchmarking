#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <string>

class Boardgame {
private:
    std::string name;
    std::string publisher;
    int minPlayers;
    int maxPlayers;
    int playTime;
    int complexity;
    int funFactor;
    float funPerMinutePerPlayer;

    static std::string truncate(const std::string& str, size_t length);
    void calculateFunPerMinutePerPlayer();

public:
    explicit Boardgame(std::string name = "", std::string publisher = "",
              int minPlayers = 1, int maxPlayers = 1,
              int playTime = 5, int complexity = 1, int funFactor = 1);

    bool operator<(const Boardgame& other) const;
    bool operator>(const Boardgame& other) const;

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getPublisher() const;
    [[nodiscard]] int getMinPlayers() const;
    [[nodiscard]] int getMaxPlayers() const;
    [[nodiscard]] int getPlayTime() const;
    [[nodiscard]] int getComplexity() const;
    [[nodiscard]] int getFunFactor() const;
};

#endif