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
    next = nullptr;
    prev = nullptr;
    match_number = r;
    //objective = minigames(gamemode);
}


string Match::random_gamemode() {
    string choice[3] = {"FFA", "1 vs ALL", "2 vs 2"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 2);
    return choice[distribution(gen)];
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
    int game_size; // number of matches in list_of_matches
    void add_match();
    void end_game();
    Game();
    ~Game();
    void display(); // displays current match number, gamemode, and objective
};

Game::Game() {
    head = nullptr;
    tail = nullptr;
    game_size = 0;
}

Game::~Game() {
    while (tail != nullptr) {
        Match* temp = tail;
        tail = tail->next;
        delete temp;
    }
}

void Game::display() {
    cout << "Round #" << head->match_number << " | ";
    cout << head->gamemode << " | ";
    cout << "Objective: " << endl; // point to objective
}

void Game::add_match() {
    game_size++;
    Match *new_match = new Match(game_size);
    if (head == nullptr && tail == nullptr){    // going from zero to one game
        tail = new_match;
        head = new_match;
    } else if (head == tail){   // going from one to two games
        head = new_match;
        head->prev = tail;
        tail->next = head;
    } else {                    // adding matches past two games
        head->next = new_match;
        new_match->prev = head;
        head = new_match;
    }
}

int main(){
    Game start;
    start.add_match();
    start.display();
    start.add_match();
    start.display();
    start.add_match();
    start.display();
    return 0;
}