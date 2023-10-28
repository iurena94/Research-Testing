# Creating player class

class Player:

    def __init__(self, n):
        self.score = 0
        if n is None:
            self.name = "test" 
        else:
            self.name = n 


def main():
    pass

if __name__ == "__main__":
    main()
