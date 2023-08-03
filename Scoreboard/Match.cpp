#include <string>
#include "Match.hpp"
Match::Match(const std::string& homeTeam, const std::string& awayTeam)
    : awayScore(0), homeScore(0), homeTeam(homeTeam), awayTeam(awayTeam) {}

int Match::getAwayScore() const {
    return awayScore;
}

int Match::getHomeScore() const {
    return homeScore;
}

const std::string& Match::getHomeTeam() const {
    return homeTeam;
}

const std::string& Match::getAwayTeam() const {
    return awayTeam;
}

void Match::setAwayScore(int score) {
    awayScore = score;
}

void Match::setHomeScore(int score) {
    homeScore = score;
}