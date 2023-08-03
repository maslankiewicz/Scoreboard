#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP
#include <vector>
#include "Match.hpp"

class Scoreboard {
private:
    std::vector<Match> matches;

public:
    void startNewMatch(const std::string& homeTeam, const std::string& awayTeam);
    void updateScore(int matchIndex, int homeScore, int awayScore);
    void finishMatch(int matchIndex);
    std::vector<Match> getMatchesSummary() const;
};

#endif // SCOREBOARD_HPP