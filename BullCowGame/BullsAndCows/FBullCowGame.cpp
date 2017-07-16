#include "FBullCowGame.hpp"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return true; }

void FBullCowGame::Reset()
{
    return;
}
