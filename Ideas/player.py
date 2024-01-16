import builtins
# Creating player class

class Player:

    def __init__(self, n):
        self.score = 0
        if n is None:
            self.name = "test" 
        else:
            self.name = n 
    
    def __repr__(self) -> str:
        return "Player()"
    def __str__(self) -> str:
        return f"{self.name} has the {self.score} points"
    
    def __iadd__(self, other):
        self.score += int(other) 
        return self
    def __isub__(self, other):
        self.score -= other
        if self.score < 0:
            self.score = 0
        return self

    def __lt__(self, other):
        return self.score < other.score
    def __gt__(self, other):
        return self.score > other.score

def main():
    p = Player("Player1")
    x = Player("Player2")
    p += 5
    
    x += 30
    print(x<p)

if __name__ == "__main__":
    main()
