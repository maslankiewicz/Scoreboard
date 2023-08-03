Scoreboard Project - Readme

Description:
--------------
The Scoreboard project is a C++ application that simulates a scoreboard for sports matches. It allows users to start new matches, update match scores, finish matches, and get a summary of matches sorted based on scores.

Features:
---------
1. Add a new match: Users can start a new match by providing the names of the home team and away team.

2. Update match scores: Users can update the scores of ongoing matches with new values for the home and away teams.

3. Finish a match: Users can finish a match, removing it from the scoreboard.

4. Get matches summary: Users can obtain a summary of matches, sorted based on the sum of home and away scores.

5. Error handling: The application checks for negative scores and disallows adding matches between the same team, displaying appropriate error messages.

Files:
-------
- Scoreboard.hpp, Scoreboard.cpp: The Scoreboard class that manages the list of matches and provides functions to handle match operations.

- Match.hpp, Match.cpp: The Match class representing individual sports matches with their scores and team names.

- pch.h, pch.cpp: Precompiled header files used for faster compilation.

- ScoreboardTests.cpp: Unit tests for the Scoreboard and Match classes using the MSTest framework.

Building and Running the Project:
----------------------------------
1. Ensure you have a C++ compiler installed on your system.

2. Open the "Scoreboard.sln" file in Visual Studio 2019.

3. Build the solution (Ctrl + Shift + B) to compile the project.

4. To run the unit tests, go to "Test" > "Run" > "All Tests" in Visual Studio.

Usage:
------
1. Include the Scoreboard.hpp and Match.hpp files in your C++ project.

2. Create a Scoreboard object to manage the matches.

3. Use the provided functions in the Scoreboard class to manage matches:
   - Use startNewMatch to add new matches.
   - Use updateScore to update match scores.
   - Use finishMatch to finish a match.
   - Use getMatchesSummary to obtain a sorted summary of matches.

Example:
--------
#include "Scoreboard.hpp"

int main() {
    Scoreboard scoreboard;

    scoreboard.startNewMatch("TeamA", "TeamB");
    scoreboard.updateScore(0, 2, 1);

    scoreboard.startNewMatch("TeamX", "TeamY");
    scoreboard.updateScore(1, 0, 5);

    // ... and so on.

    return 0;
}

Contributing:
-------------
If you would like to contribute to the project or report any issues, please create a new branch and submit a pull request.


Contact:
--------
For any inquiries or feedback, please contact maslankiewicz.agnieszka@gmail.com
