#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


class Player {
private:
    string *history;    // array of penalties the Player has received
    int points;
public:
    string name;
    Player() : name("Computer"), points(0), history(NULL) {};
    Player(string s) : name(s), points(0), history(NULL) {};
    void add_points(int);   // add points to Player
    friend std::ostream& operator<<(std::ostream&, const Player&);

};
// adding points to Player
void Player::add_points(int n){
    points += n;
}
// Overload << for Player
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player name: " << player.name << ", Points: " << player.points;
    return os;
}

// list of players 
class PlayerList {
private:
    int max_size;   // max size of list, default is 4.
    Player *list_of_players; // pointer to an array of Player datatypes
    int player_count;   // number of players in the list
public:
    PlayerList(): list_of_players(new Player[4]), player_count(0), max_size(4){}
    PlayerList(int);
    PlayerList(Player, int);
    void add_player(Player);    // add player to PlayerList array
    
    friend std::ostream& operator<<(std::ostream& os, const PlayerList& playerList);
};

// Overload << for PlayerList
std::ostream& operator<<(std::ostream& os, const PlayerList& player_list) {
    for (int i = 0; i < player_list.player_count; ++i) {
        os << player_list.list_of_players[i] << endl;
    }
    return os;
}

// PlayerList Constructor with Player and max_size 
PlayerList::PlayerList(Player p, int m){
    player_count = 0;
    max_size = m;
    list_of_players = new Player[max_size]; 
    add_player(p);
}

// PlayerList Constructor with max_size 
PlayerList::PlayerList(int m){
    player_count = 0;
    max_size = m;
    list_of_players = new Player[max_size]; 
}

// Adds a player to the list of players
void PlayerList::add_player(Player p){
    if (player_count < max_size){   // if theres enough space in the array
        list_of_players[player_count] = p;
        player_count++;
    } else {                        // otherwise error message
        std::cerr << "Player list is at max capacity!!! Could not add " << p.name << endl;
    }
}


main() {
    Player p1("Soda");
    Player p2("Burger");
    Player p3("Fries");
    Player p4("Nugget");

    PlayerList scoreboard;
    scoreboard.add_player(p1);
    scoreboard.add_player(p2);
    scoreboard.add_player(p3);
    scoreboard.add_player(p4);

    Player p5("Carrot");        // Carrot shouldn't be added
    scoreboard.add_player(p5);
    cout << scoreboard;         // Should display Sode, Burger, Fries, Nugget
    return 0;
}