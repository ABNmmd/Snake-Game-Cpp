#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class ScoreManager {
public:
    void addScore(int score);
    std::vector<int> getTopScores(int count);
    void loadScores();
    void saveScores();

private:
    std::vector<int> scores;
};

#endif