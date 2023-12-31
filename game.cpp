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
    // Player* winners;
    // string teams;
    //team_comp(string);
};

Match::Match(int r) {
    gamemode = random_gamemode();
    next = nullptr;
    prev = nullptr;
    match_number = r;
    //winners = nullptr;
    //objective = minigames(gamemode);
    //teams = team_comp(gamemode);
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
    bool is_ended(); // checks to see if the game has ended
    Game();
    ~Game();
    int max_players;
    int get_max_player();
    void display(); // displays current match number, gamemode, and objective
};

Game::Game() {
    head = nullptr;
    tail = nullptr;
    game_size = 0;
    max_players = get_max_player();
}

Game::~Game() {
    while (tail != nullptr) {
        Match* temp = tail;
        tail = tail->next;
        delete temp;
    }
}

int Game::get_max_player() {
    int result;
    do {
    cout << "Whats the total amount of players playing? (1 - 4): ";
    cin >> result;
    } while (result >= 1 && result <= 4);
    return result;
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

// given winning number and team composition, get a pointer to an array of the players and add a point ot the m

int main(){
    Game start;
    start.add_match();
    start.display();
    start.add_match();
    start.display();
    start.add_match();
    start.display();
    
    /*  
    Game start;
    while (!start.is_end()){
        start.add_match();
        start.display();
        start.display_teams();
        cout << "Enter winner [int]: "
        int winner;
        cin >> winner;
        start.head->winners

    }
    */
    return 0;
}