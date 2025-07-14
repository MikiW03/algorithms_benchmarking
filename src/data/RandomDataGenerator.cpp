#include "data/RandomDataGenerator.h"
#include "types/Boardgame.h"
#include <climits>

template<typename T>
RandomDataGenerator<T>::RandomDataGenerator() : rng(std::random_device{}()) {}

template<typename T>
void RandomDataGenerator<T>::generate(IDataContainer<T>& container, int size) {
    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(-1000000, 1000000);
        for (int i = 0; i < size; i++) {
            container.set(i, dist(rng));
        }
    }
    else if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(-1000000.0, 1000000.0);
        for (int i = 0; i < size; i++) {
            container.set(i, dist(rng));
        }
    }
}


template<>
void RandomDataGenerator<int>::generate(IDataContainer<int>& container, int size) {
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    for (int i = 0; i < size; i++) {
        container.set(i, dist(rng));
    }
}

template<>
void RandomDataGenerator<std::string>::generate(IDataContainer<std::string>& container, int size) {
    std::uniform_int_distribution<int> lengthDist(3, 12);
    std::uniform_int_distribution<int> charDist(0, 25);

    for (int i = 0; i < size; i++) {
        int length = lengthDist(rng);
        std::string str;
        str.reserve(length);
        
        for (int j = 0; j < length; j++) {
            str += static_cast<char>('a'+charDist(rng));
        }
        
        container.set(i, str);
    }
}

template<>
void RandomDataGenerator<Boardgame>::generate(IDataContainer<Boardgame>& container, int size) {
    std::uniform_int_distribution<int> playersDist(1, 10);
    std::uniform_int_distribution<int> timeDist(5, 480);
    std::uniform_int_distribution<int> ratingDist(1, 10);
    
    const std::vector<std::string> publishers = {
        "Rebel", "Portal Games", "Asmodee", "Days of Wonder", 
        "Fantasy Flight", "KOSMOS", "Stonemaier Games"
    };
    
    for (int i = 0; i < size; i++) {
        int minPlayers = playersDist(rng);
        int maxPlayers = playersDist(rng);
        if (minPlayers > maxPlayers) std::swap(minPlayers, maxPlayers);
        
        container.set(i, Boardgame(
            "Game" + std::to_string(i),
            publishers[i % publishers.size()],
            minPlayers,
            maxPlayers,
            timeDist(rng),
            ratingDist(rng),
            ratingDist(rng)
        ));
    }
}

template class RandomDataGenerator<int>;
template class RandomDataGenerator<float>;
template class RandomDataGenerator<std::string>;
template class RandomDataGenerator<Boardgame>;