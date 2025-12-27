#include <iostream>
#include <stdexcept>
#include <string>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <cstdlib>
#include <map>

#include <conio.h>
#include <vector>
#include <string>

#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r' // Carriage return character

int sepLen = 120, Bc = 0, discountOffer = 0, weekDay;
bool hasDiscount=false;
int currOrderId = 1;



void sleep(int secs) {
    // Sleep for 2 seconds
    // this_thread::sleep_for(std::chrono::seconds(2));
    this_thread::sleep_for(chrono::seconds(secs));
}

void clrscr() {
    system("@cls||clear");
}

sql::Connection *getConnection() {
    static sql::Connection *con = nullptr;

    if (con == nullptr) {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

        sql::ConnectOptionsMap props;
        props["hostName"] = "127.0.0.1";
        props["port"] = 3306;
        props["userName"] = "root";
        props["password"] = "root";

        con = driver->connect(props);
        con->setSchema("pizzeria");
    }

    return con;
}



enum itemTypes {
    Pizza,
    Pasta,
    Sides,
    Drink,
    Combo
};

enum servingSize {
    Small,
    Medium,
    Large,
    XLarge
};

class DateTimeObj {
private:
    chrono::system_clock::time_point current_time;

public:
    // Constructor to store the current time
    DateTimeObj(){
        current_time = chrono::system_clock::now();
    }

    // Method to get formatted time as string (e.g., "Sunday, December 21, 2025 14:30:00")
    string getFormattedTime() const {
        time_t time_t_now = chrono::system_clock::to_time_t(current_time);
        stringstream ss;
        ss << put_time(localtime(&time_t_now), "%a, %B %d, %Y %I:%M %p");
        return ss.str();
    }

    string getTime() const {
        time_t time_t_now = chrono::system_clock::to_time_t(current_time);
        stringstream ss;
        ss << put_time(localtime(&time_t_now), "%I:%M %p");
        return ss.str();
    }

    // Method to get the weekday index (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int getWeekdayIndex() const {
        time_t time_t_now = chrono::system_clock::to_time_t(current_time);
        tm tm = *localtime(&time_t_now);
        return tm.tm_wday; // Weekday index (0 = Sunday, 6 = Saturday)
    }

    // Method to get the abbreviated weekday name (e.g., "Sun", "Mon")
    string getWeekdayAbbr() const {
        time_t time_t_now = chrono::system_clock::to_time_t(current_time);
        stringstream ss;
        ss << put_time(localtime(&time_t_now), "%a"); // Abbreviated weekday name
        return ss.str();
    }

    // Method to get the full weekday name (e.g., "Sunday", "Monday")
    string getWeekdayFull() const {
        time_t time_t_now = chrono::system_clock::to_time_t(current_time);
        stringstream ss;
        ss << put_time(localtime(&time_t_now), "%A"); // Full weekday name
        return ss.str();
    }
};

struct Offer{
    int weekDay;
    int discount;
    sql::SQLString title;
    sql::SQLString desc;
    sql::SQLString type;
};

struct Customer{
    int id;
    string name;
};

struct Order{
    int id;
    int quantity;
    int price;
    sql::SQLString type;
};



DateTimeObj Dobj;
Offer currOffer;
Customer currCust;


void reset() {
    sepLen = 120, Bc = 0, discountOffer = 0, weekDay, hasDiscount = false;
    memset(&currCust,0,sizeof(currCust));

}


void setCustomer(){
    currCust.id=1;
}

int selectOption(const vector<string>& menuOptions, const string& prompt) {
    // vector<string> menuOptions = {"Option 1", "Option 2", "Option 3", "Exit"};
    int selectedIndex = 0;
    bool selecting = true;
    char key;

    while (selecting) {
        // displayMenu(menuOptions, selectedIndex);
        // system("cls");
        clrscr();
        cout << prompt << endl
             << endl;

        for (size_t i = 0; i < menuOptions.size(); ++i)
        {
            if (i == selectedIndex)
            {
                // Highlight the selected option (e.g., using an arrow)
                cout << " -> " << menuOptions[i] << endl;
            }
            else
            {
                cout << "    " << menuOptions[i] << endl;
            }
        }

        key = _getch(); // Get the first character of the keypress

        if (key == (char)224 || key == (char)0)
        {
            // If it's an extended key (like an arrow key)
            key = _getch(); // Get the second character for the specific key

            switch (key) {
            case KEY_UP:
                if (selectedIndex > 0) {
                    selectedIndex--;
                }
                else {
                    selectedIndex = menuOptions.size() - 1; // Wrap around to bottom
                }
                break;
            case KEY_DOWN:
                if (selectedIndex < menuOptions.size() - 1) {
                    selectedIndex++;
                }
                else
                {
                    selectedIndex = 0; // Wrap around to top
                }
                break;
            }
        }
        else if (key == KEY_ENTER)
        {
            // Enter key was pressed, stop selecting
            selecting = false;
        }
    }
    // system("cls");
    clrscr();
    // cout << "You selected: " << menuOptions[selectedIndex] << endl;
    return selectedIndex;
    // Perform action based on selectedIndex
    // e.g., if (selectedIndex == 3) { return 0; }
}

void seperator() {
    for (int i = 0; i < sepLen; i++){
        cout << "=";
    }
    cout << endl;
}

void star_seperator() {
    for (int i = 0; i < sepLen; i++){
        cout << "*";
    }
    cout << endl;
}

void askName() {
    // sql::Connection* con = getConnection();
    cout << "Your Good name please: ";
    getline(cin, currCust.name);
}

int askQuantity() {
    int q;
    cout << "Enter Quantity? ";
    cin >> q;
    return q;
}

void greetings() {
    seperator();
    cout<<Dobj.getWeekdayIndex();
    cout << "Greetings from Zaika Pizzeria\n (Aroma of Indian Flavours blended with Italian Cuisine)" << endl
         << endl
         << "\t\t\t\t\t\t\t\t" << Dobj.getFormattedTime() << endl;
    seperator();
    cout << endl;
    askName();
    // cout << "Hello User, What would like to have today" << endl;
}

void setOffer(){
    sql::Connection* con = getConnection();
    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM offers where onWeekDay=?");
    pstmt->setInt(1,Dobj.getWeekdayIndex());
    sql::ResultSet* s = pstmt->executeQuery();

    while(s->next()){
        hasDiscount=true;
        currOffer.weekDay=weekDay;
        currOffer.title=s->getString("title");
        // cout<<s->getString("title")<<endl;
        currOffer.desc=s->getString("description");
        currOffer.type=s->getString("itemType");
        currOffer.discount=s->getInt("discount");
        sleep(3);
    }
}

void headers(){
    seperator();
    cout << "Zaika Pizzeria Biller | Customer Name: " << currCust.name ;
    if (hasDiscount){
        cout << " | " << currOffer.title << ":"<< currOffer.desc;
    }
    cout << " | " << Dobj.getTime() << endl;
    
}

string sql2stdString(sql::SQLString ok){
    return ok.asStdString();
}

vector<string> resultSet2VecStr(sql::ResultSet* p,string& k){
    vector<string> o;
    while (p->next()){
        o.push_back(sql2stdString(p->getString(k)));
        cout<<o[o.size()-1];
    }

    return o;
}

void add2Order(Order item){
    sql::Connection* con = getConnection();
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO order_items(orderId,itemId,quantity,price,itemDiscount) VALUES(?,?,?,?,?)");

    int discount=0;
    if (item.type==currOffer.type){
        //if discount is there
        discount=currOffer.discount;
    }

    pstmt->setInt(1,currOrderId);
    pstmt->setInt(2,item.id);
    pstmt->setInt(3,item.quantity);
    pstmt->setInt(4,item.price);
    pstmt->setInt(5,discount);

    bool a = pstmt->execute();
    if (a){
        cout<<"Added to order_items"<<endl;
    }

}

void choosePizza(){
    sql::Connection* con = getConnection();
    sql::Statement* stmt = con->createStatement();
    map<float, sql::SQLString> pizzas;
    vector<string> getSizes;

    float choice;
    sql::SQLString pizza, size;
    int quantity;
    
    menu:
        headers();
        sql::ResultSet* pizzaCats = stmt->executeQuery("select distinct category from items where itemType='Pizza';");
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT DISTINCT name FROM items WHERE itemType = 'Pizza' AND category = ?");
        sql::PreparedStatement* catPriceStmt = con->prepareStatement("SELECT DISTINCT price FROM items WHERE itemType = 'Pizza' AND category = ?");
        sql::ResultSet* sizes = stmt->executeQuery("select distinct size from items where size is not null;");
        cout<<left<<setfill(' ');
        seperator();
        cout << "Pizza" << endl;
        seperator();
        
        // printf("%-40s","Items");
        cout<<setw(40)<<"Items";
        while(sizes->next()){
            string size = sql2stdString(sizes->getString("size"));
            string h = "("+size+")";
            getSizes.push_back(size);
            printf("%-20s",h);
        }
        cout<<endl;
        star_seperator();
        int catSel=0,pizzSel=0;
        int catIter=1,pizzIter=1;
        while (pizzaCats->next()){
            sql::SQLString category = pizzaCats->getString("category");
            cout <<catIter<<". "<<category << endl;
            // printf("%-40s","");
            cout<<setw(42)<<"";
            
            catPriceStmt->setString(1,category);
            sql::ResultSet* ps = catPriceStmt->executeQuery();
            while (ps->next()){
                cout<<setw(20)<<ps->getInt("price");
            }
            cout<<endl;
            
            pstmt->setString(1,category);
            sql::ResultSet* rs = pstmt->executeQuery();

            while(rs->next()){
                cout<<" "<<catIter<<"."<<pizzIter<<" "<<rs->getString("name")<<endl;
                pizzas[catIter+(pizzIter/10.0f)] = rs->getString("name");
                pizzIter++;
            }

            delete rs;
            delete ps;
            pizzIter=1,catIter++;
            star_seperator();
        }

        // for (auto person : pizzas) {
        //     cout << person.first << " is: " << person.second << "\n";
        // }

    choose_menu:
        cout<<"Enter Choice as 1.1"<<endl;
        cout<<"Select Pizza: ";
        cin>>choice;
        if (choice==0){
            goto menu;
        }
        try{
            cout<<pizzas.at(choice);
            pizza = pizzas.at(choice);
        } catch (const out_of_range& e){
            clrscr();
            cerr<<"Please try again"<<endl;
            sleep(2);
            clrscr();
            goto menu;
        }

    choose_size:
        headers();
        seperator();
        string prompt = "Select size for "+pizzas.at(choice)+" Pizza";
        int sizeSel = selectOption(getSizes,prompt);
        // cout<< getSizes[sizeSel]<<endl;
        size=getSizes[sizeSel];
        cout<<size<<endl;

    ask_quantity:
        quantity = askQuantity();
        if (quantity<1){
            cout<<"Quantity should be 1 or above. Please try again"<<endl;
            goto ask_quantity;    
        }

    pizza_info:
        sql::PreparedStatement* pizzaInfoStmt = con->prepareStatement("SELECT id,name,price,size,itemType FROM items WHERE name=? AND size=?");
        pizzaInfoStmt->setString(1,pizza);
        pizzaInfoStmt->setString(2,size);
        sql::ResultSet* pizzaInfo = pizzaInfoStmt->executeQuery();
        while(pizzaInfo->next()){
            cout<<pizzaInfo->getInt("id")<<" "<<pizzaInfo->getString("name")<<" "<<pizzaInfo->getInt("price")<<" "<<pizzaInfo->getString("size")<<" "<<"Quantity: "<<quantity;
            Order currItem = {pizzaInfo->getInt("id"),quantity,pizzaInfo->getInt("price"),pizzaInfo->getString("itemType")};
            add2Order(currItem);
        }

    
    
    
    // choose_again:
    //     int repeat;
    //     cout<<"Want to select another Pizza"<<endl<<"1. Yes"<<endl<<"2. No"<<endl;
    //     cin>>repeat;
    //     switch(repeat){
    //         case 1:
    //             goto menu;
    //             break;
    //     }


    
    delete catPriceStmt;
    delete pizzaCats;
    delete stmt;
    delete pstmt;
}

void choosePasta() {}

void chooseDrink() {}

void chooseSides() {}

void chooseCombo() {}

void mainMenu(){
    vector<string> menuOptions = {"Pizza", "Pasta", "Sides & Dips", "Coldrinks", "Combo Offers"};

    void (*functptr[])() = {
        choosePizza,
        choosePasta,
        chooseSides,
        chooseDrink,
        chooseCombo};
    seperator();
    string prompt = "Hello "+to_string(currOrderId)+" "+ currCust.name + ", What Would you like to have Today";
    int o = selectOption(menuOptions, prompt);
    // cout<<"Selected Option: "<< menuOptions[o] << endl;
    functptr[o]();
}

int getLastIdFromTable(string& table){
    sql::Connection* con = getConnection();
    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM ? order by id desc limit 1");
    sql::ResultSet* rs = pstmt->executeQuery();

    int id;
    while(rs->next()){
        id=rs->getInt("id");
    }
    delete rs;
    delete pstmt;
    return id;

}

void createOrder(){
    sql::Connection* con = getConnection();
    sql::Statement* stmt = con->createStatement();
    
    stmt->execute("INSERT INTO orders(cId) VALUES(1)");

    sql::ResultSet* rs =  stmt->executeQuery("SELECT id FROM orders ORDER BY id DESC LIMIT 1");
    while(rs->next()){
        currOrderId=rs->getInt("id");
    }
    delete stmt;
}

int main(){
    menu:
        setOffer();
        setCustomer();
        // createOrder();
        system("mode 121,40");
        greetings();
        mainMenu();

    return 0;
}