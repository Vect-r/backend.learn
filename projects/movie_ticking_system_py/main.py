current_movies={1:"Dhurandhar",2:"Ikkis",3:'Avatar Fire & Ash'}
start_sep = "*"*65

def name():
    a = input("Enter Name")
    return a

def header():
    print("Movie Tickiting System")

def choose_movies():
    def showMovies():
        for k,v in current_movies.items():
            print(f"{k}. {v}")

    showMovies()
    print("Press 0. Show all movies again")
    selecting=True
    while selecting:
        ch=int(input("Enter Choice: "))
        if ch==0:
            showMovies()
            continue 
        elif ch in current_movies:
            break
            return ch
        else:
            print("Error. Try Again")
            continue
    
        

print(start_sep)
o=choose_movies()
print(start_sep)