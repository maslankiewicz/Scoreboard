#ifndef MATCH_HPP
#define MATCH_HPP
#include "../ScoreboardTests/pch.h"
#include <string>

class Match {
private:
    int awayScore;
    int homeScore;
    std::string homeTeam;
    std::string awayTeam;

public:
    Match(const std::string& homeTeam, const std::string& awayTeam);

    // Getters
    int getAwayScore() const;
    int getHomeScore() const;
    const std::string& getHomeTeam() const;
    const std::string& getAwayTeam() const;

    // Setters
    void setAwayScore(int score);
    void setHomeScore(int score);
};

#endif // MATCH_HPP