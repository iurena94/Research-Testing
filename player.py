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


def main():
    p = Player("one")
    print(p)

if __name__ == "__main__":
    main()
