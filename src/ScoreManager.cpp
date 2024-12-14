#include "ScoreManager.hpp"

void ScoreManager::addScore(int score) {
    scores.push_back(score);
    std::sort(scores.rbegin(), scores.rend());
    if (scores.size() > 5) {
        scores.pop_back();
    }
    saveScores();
}

std::vector<int> ScoreManager::getTopScores(int count) {
    return std::vector<int>(scores.begin(), scores.begin() + std::min(count, static_cast<int>(scores.size())));
}

void ScoreManager::loadScores() {
    std::ifstream file("scores.txt");
    int score;
    while (file >> score) {
        scores.push_back(score);
    }
    file.close();
}

void ScoreManager::saveScores() {
    std::ofstream file("scores.txt");
    for (int score : scores) {
        file << score << std::endl;
    }
    file.close();
}