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
    
    def __add__(self, other):
        self.score += other
    def __sub__(self, other):
        self.score -= other
        if self.score < 0:
            self.score = 0

def main():
    p = Player("Player1")
    print(p)
    p + 5
    print(p)
    p - 3
    print(p)
    p - 100
    print(p)

if __name__ == "__main__":
    main()
