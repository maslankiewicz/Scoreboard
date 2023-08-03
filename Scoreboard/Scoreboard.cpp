#include "Scoreboard.hpp"
#include <algorithm>
#include <iostream>
void Scoreboard::startNewMatch(const std::string& homeTeam, const std::string& awayTeam) {
    if (homeTeam == awayTeam) {
        std::cout << "Error: Cannot add a match between the same team: " << homeTeam << " ." << std::endl;
        return;
    }
    matches.emplace_back(homeTeam, awayTeam);
}

void Scoreboard::updateScore(int matchIndex, int homeScore, int awayScore) {
    // Check for negative scores
    if (homeScore < 0 || awayScore < 0) {
        // Log an error when a match is updated with a negative number
        std::cout << "Error: Negative scores are not allowed! Failed to update the score." << std::endl;
        return;
    }
    matches[matchIndex].setHomeScore(homeScore);
    matches[matchIndex].setAwayScore(awayScore);
}

void Scoreboard::finishMatch(int matchIndex) {
    matches.erase(matches.begin() + matchIndex);
}

std::vector<Match> Scoreboard::getMatchesSummary() const {
    std::vector<Match> summary = matches;
    std::sort(summary.begin(), summary.end(),
        [](const Match& a, const Match& b) {
            if (a.getHomeScore() + a.getAwayScore() != b.getHomeScore() + b.getAwayScore() ||
                a.getHomeScore() + a.getAwayScore() == b.getHomeScore() + b.getAwayScore() )
                return a.getHomeScore() + a.getAwayScore() > b.getHomeScore() + b.getAwayScore();
            return &a < &b;
        });
    return summary;
}