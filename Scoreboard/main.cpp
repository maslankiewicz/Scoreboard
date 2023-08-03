#include <iostream>
#include "Scoreboard.hpp"

void testScoreboard() {

    Scoreboard scoreboard;

    scoreboard.startNewMatch("Mexico", "Canada");
    scoreboard.updateScore(0, 0, 5);

    scoreboard.startNewMatch("Spain", "Brazil");
    scoreboard.updateScore(1, 10, 2);

    scoreboard.startNewMatch("Germany", "France");
    scoreboard.updateScore(2, 2, 2);

    scoreboard.startNewMatch("Uruguay", "Italy");
    scoreboard.updateScore(3, 6, 6);

    scoreboard.startNewMatch("Argentina", "Australia");
    scoreboard.updateScore(4, 3, 1);

    std::cout << "Matches Summary:" << std::endl;
    std::vector<Match> summary = scoreboard.getMatchesSummary();
    for (const auto& match : summary) {
        std::cout << match.getHomeTeam() << " " << match.getHomeScore() << " - "
            << match.getAwayTeam() << " " << match.getAwayScore() << std::endl;
    }

    //// Test case for starting a new match
    if (summary.size() != 5) {
        std::cout << "Test 1 - Failed: Incorrect number of matches in the summary.\n";
    }
    else {
        std::cout << "Test 1 - Passed: Correct number of matches in the summary.\n";
    }

    //// Test case for updating the score of a match
    if (summary[0].getHomeScore() != 6 || summary[0].getAwayScore() != 6) {
        std::cout << "Test 2 - Failed: Incorrect scores for match 0.\n" << "actual score:" << summary[0].getHomeScore() << "-" << summary[0].getAwayScore();
    }
    else {
        std::cout << "Test 2 - Passed: Correct scores for match 0.\n";
    }
    //// Test case for finishing a match
    scoreboard.finishMatch(1);
    summary = scoreboard.getMatchesSummary();
    if (summary.size() != 4) {
        std::cout << "Test 3 - Failed: Incorrect number of matches after finishing a match.\n";
    }
    else {
        std::cout << "Test 3 - Passed: Correct number of matches after finishing a match.\n";
    }

    scoreboard.startNewMatch("Poland", "Austria");
    scoreboard.updateScore(4, 7, 5);

    std::cout << "Matches Summary:" << std::endl;
    summary = scoreboard.getMatchesSummary();
    for (const auto& match : summary) {
        std::cout << match.getHomeTeam() << " " << match.getHomeScore() << " - "
            << match.getAwayTeam() << " " << match.getAwayScore() << std::endl;
    }
}

void testScoreboardWithSameScores()
{
    Scoreboard scoreboard;
    scoreboard.startNewMatch("Mexico", "Canada");
    scoreboard.updateScore(0, 0, 5);

    scoreboard.startNewMatch("Spain", "Brazil");
    scoreboard.updateScore(1, 0, 5);

    scoreboard.startNewMatch("Germany", "France");
    scoreboard.updateScore(2, 0, 5);

    scoreboard.startNewMatch("Uruguay", "Italy");
    scoreboard.updateScore(3, 6, 6);

    scoreboard.startNewMatch("Argentina", "Australia");
    scoreboard.updateScore(4, 3, 1);
    std::cout << "Matches Summary:" << std::endl;
    std::vector<Match> summary = scoreboard.getMatchesSummary();
    for (const auto& match : summary) {
        std::cout << match.getHomeTeam() << " " << match.getHomeScore() << " - "
            << match.getAwayTeam() << " " << match.getAwayScore() << std::endl;
    }
}

int main() {
    testScoreboard();
    testScoreboardWithSameScores();
    return 0;
}