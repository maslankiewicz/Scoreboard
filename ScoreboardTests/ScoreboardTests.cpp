#include "pch.h"
#include "CppUnitTest.h"
#include "../Scoreboard/Scoreboard.hpp"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ScoreboardTests
{
	TEST_CLASS(ScoreboardTests)
	{
	public:
		
        TEST_METHOD(TestStartNewMatch)
        {
            Scoreboard scoreboard;
            scoreboard.startNewMatch("TeamA", "TeamB");

            // Assert that the first match was added correctly.
            std::vector<Match> matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(static_cast<size_t>(1), matches.size());
            Assert::AreEqual(std::string("TeamA"), matches[0].getHomeTeam());
            Assert::AreEqual(std::string("TeamB"), matches[0].getAwayTeam());
        }
        TEST_METHOD(TestUpdateScore)
        {
            Scoreboard scoreboard;
            scoreboard.startNewMatch("TeamA", "TeamB");
            scoreboard.updateScore(0, 2, 1);

            // Assert that the scores were updated correctly.
            std::vector<Match> matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(2, matches[0].getHomeScore());
            Assert::AreEqual(1, matches[0].getAwayScore());
        }
        TEST_METHOD(TestFinishMatch)
        {
            Scoreboard scoreboard;
            scoreboard.startNewMatch("TeamA", "TeamB");
            scoreboard.finishMatch(0);

            // Assert that the match was removed from the scoreboard.
            std::vector<Match> matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(static_cast<size_t>(0), matches.size());
        }
        TEST_METHOD(TestGetMatchesSummary)
        {
            Scoreboard scoreboard;

            // Add the entries
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

            // Call the getMatchesSummary method
            std::vector<Match> summary = scoreboard.getMatchesSummary();

            // Assert that the vector is not empty
            Assert::IsTrue(summary.size() > 0);

            // Assert that the matches are sorted correctly based on the scores and team names
            for (size_t i = 1; i < summary.size(); ++i) {
                int score1 = summary[i - 1].getHomeScore() + summary[i - 1].getAwayScore();
                int score2 = summary[i].getHomeScore() + summary[i].getAwayScore();
                Assert::IsTrue(score1 >= score2 || (score1 == score2 && summary[i - 1].getHomeTeam() <= summary[i].getHomeTeam()));
            }
        }
        TEST_METHOD(TestGetMatchesSummaryWithSameScores)
        {
            Scoreboard scoreboard;

            // Add test match entries
            scoreboard.startNewMatch("Mexico", "Canada");
            scoreboard.updateScore(0, 0, 5);

            scoreboard.startNewMatch("Spain", "Brazil");
            scoreboard.updateScore(1, 0, 5);

            scoreboard.startNewMatch("Germany", "France");
            scoreboard.updateScore(2, 0, 5);

            scoreboard.startNewMatch("Uruguay", "Italy");
            scoreboard.updateScore(3, 6, 6);

            // Call the getMatchesSummary method
            std::vector<Match> summary = scoreboard.getMatchesSummary();

            // Assert that the vector is not empty
            Assert::IsTrue(summary.size() > 0);

            // Assert that the matches are sorted correctly based on the sum of home and away scores
            for (size_t i = 1; i < summary.size(); ++i) {
                int score1 = summary[i - 1].getHomeScore() + summary[i - 1].getAwayScore();
                int score2 = summary[i].getHomeScore() + summary[i].getAwayScore();
                Assert::IsTrue(score1 >= score2 || (score1 == score2 && summary[i - 1].getHomeTeam() <= summary[i].getHomeTeam()));
            }
        }
        TEST_METHOD(TestUpdateScoreWithNegativeScores)
        {
            Scoreboard scoreboard;

            // Add a match entry
            scoreboard.startNewMatch("TeamX", "TeamY");

            // Update the score with negative values
            scoreboard.updateScore(0, -1, 3);

            // Assert that the scores were not updated (should remain unchanged)
            std::vector<Match> matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(0, matches[0].getHomeScore());
            Assert::AreEqual(0, matches[0].getAwayScore());
        }
        TEST_METHOD(TestStartNewMatchWithError)
        {
            Scoreboard scoreboard;

            // Test adding a match between different teams
            scoreboard.startNewMatch("TeamA", "TeamB");
            std::vector<Match> matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(static_cast<size_t>(1), matches.size());
            Assert::AreEqual(std::string("TeamA"), matches[0].getHomeTeam());
            Assert::AreEqual(std::string("TeamB"), matches[0].getAwayTeam());

            // Test adding a match between the same team (invalid)
            std::ostringstream outputStream;
            std::streambuf* oldOutputBuffer = std::cout.rdbuf(outputStream.rdbuf()); // Redirect cout to outputStream
            scoreboard.startNewMatch("TeamC", "TeamC");
            std::string errorMessage = "Error: Cannot add a match between the same team: TeamC .\n";
            std::string consoleOutput = outputStream.str();
            std::cout.rdbuf(oldOutputBuffer); // Restore the old cout buffer

            // The function should not add the match and should print an error message.
            // So, the matches vector should still have the previous match only.
            matches = scoreboard.getMatchesSummary();
            Assert::AreEqual(static_cast<size_t>(1), matches.size());
            Assert::AreEqual(std::string("TeamA"), matches[0].getHomeTeam());
            Assert::AreEqual(std::string("TeamB"), matches[0].getAwayTeam());

            // Check that the error message is printed to the console
            Assert::AreEqual(errorMessage, consoleOutput);
        }
	};
}
