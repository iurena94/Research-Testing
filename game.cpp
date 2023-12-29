#include <iostream>
#include <string>
#include <random>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string;

// games are made out of matchs 
// linked list

class Match {
public:
    string gamemode;   // "FFA", "1_vs_ALL", "2_vs_2"
    int match_number;
    // string objective;
    // string minigames(string);    // picks a random objective from the corresponding gamemode list
    string random_gamemode();
    Match(int);
    Match* next;
    Match* prev;
};

Match::Match(int r) {
    gamemode = random_gamemode();
    next = NULL;
    prev = NULL;
    match_number = r;
    //objective = minigames(gamemode);
}


string Match::random_gamemode() {
    string choice[3] = {"FFA", "1 vs ALL", "2 vs 2"};
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,2);
    return choice[distribution(generator)];
}

/* // minigame method
string minigames(string g){
    string path = g + ".txt";
    ifstream file.opem (path)
}
*/


class Game{
private:
    Match* head;
    Match* tail;
public:
    Match* list_of_matchs;
    void add_match();
    void end_game();
    Game();
    ~Game();
    int game_size; // number of matchs in list_of_matchs
};

Game::~Game() {
    while (head != nullptr) {
        Match* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    return 0;
}