#include <iostream>

using namespace std;

class Book{
    string title;
    string author;

public:
    Book(std::string title_val, std::string author_val):
        title(title_val), author(author_val) {
    }


    void getBook(){
        cout<<"Book: "<<title<<endl<<"Author: "<<author;
    }


};

int main(){
    Book my_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    my_book.getBook();
}
