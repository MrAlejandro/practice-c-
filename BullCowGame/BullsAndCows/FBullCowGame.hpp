#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

class FBullCowGame {
public:
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();

    
private:
    int MyCurrentTry = 1;
    int MyMaxTries = 2;
    bool IsIsogram(std::string);
};
