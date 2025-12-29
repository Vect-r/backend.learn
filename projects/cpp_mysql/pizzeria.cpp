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
int currOrderId = 0;



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
    sql::SQLString name;
};

DateTimeObj Dobj;
Offer currOffer;
Customer currCust;


void resetFlags() {
    sepLen = 120, Bc = 0, discountOffer = 0, weekDay, hasDiscount = false;
    // memset(&currCust,0,sizeof(currCust));
    currCust = {};
}

int getLastIdFromTable(const std::string& table) {
    sql::Connection* con = getConnection();
    std::string query ="SELECT id FROM " + table + " ORDER BY id DESC LIMIT 1";

    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* rs = stmt->executeQuery(query);

    int id = -1;
    if (rs->next()) {
        id = rs->getInt("id");
    }

    delete rs;
    delete stmt;
    return id;
}


void createCustomer(){
    sql::Connection* con = getConnection();
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO customers(name) VALUES(?)");
    pstmt->setString(1,currCust.name);
    pstmt->execute();
    // string t = "customers";
    currCust.id = getLastIdFromTable("customers");

    delete pstmt;
}

void createOrder(){
    sql::Connection* con = getConnection();
    sql::PreparedStatement* stmt = con->prepareStatement("INSERT INTO orders(cId) VALUES(?)");
    stmt->setInt(1,currCust.id);
    stmt->execute();

    // sql::ResultSet* rs =  stmt->executeQuery("SELECT id FROM orders ORDER BY id DESC LIMIT 1");
    // while(rs->next()){
    //     currOrderId=rs->getInt("id");
    // }
    string t = "orders";
    currOrderId = getLastIdFromTable(t);
    delete stmt;
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
    // askName();
    cout<<"Your name please? ";
    cin>>currCust.name;
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
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO order_items(orderId,itemId,quantity,price,itemDiscount,name) VALUES(?,?,?,?,?,?)");

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
    pstmt->setString(6,item.name);

    bool a = pstmt->execute();
    // if (a){
    //     cout<<"Added to order_items"<<endl;
    // }

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
        cout<<"Select Quantity for the selected Pizza"<<pizza<<"; "<<size<<endl;

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
            sql::SQLString name = pizzaInfo->getString("name")+" "+ pizzaInfo->getString("size");
            Order currItem = {pizzaInfo->getInt("id"),quantity,pizzaInfo->getInt("price"),pizzaInfo->getString("itemType"),name};
            add2Order(currItem);
        }
        Bc++;

        delete pizzaInfo;
        delete pizzaInfoStmt;

    
    choose_again:
        vector<string> options = {"Yes, i would like to order more","No, I am fine"};
        int repeat = selectOption(options,"Would you like to order another pizza?");
        if (repeat==0){
            pizzas.clear();
            getSizes.clear();
            quantity=0,choice=0;
            pizza="",size="";
            goto menu;
        }

    
    delete catPriceStmt;
    delete pizzaCats;
    delete stmt;
    delete pstmt;
}

void choosePasta() {}

void chooseDrink() {}

void chooseSides() {}

void chooseCombo() {}

float calculateDiscount(float originalPrice, float discountPercentage) {
    float discountAmount = (originalPrice * discountPercentage) / 100;
    float finalPrice = originalPrice - discountAmount;
    return finalPrice;
}

void pressKey(){
    printf("\nPress Any Key to Continue...");
    getch();
}

int gimmeTheBillMan(){
    if (Bc==0){
        return 0;
    }
    sql::Connection* con = getConnection();
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* rs= stmt->executeQuery("SELECT * FROM order_items WHERE orderId="+to_string(currOrderId));

    sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE orders SET subTotal=?, grandTotal=? WHERE id=?");


    int total=0, subtotal=0;
    clrscr();
    seperator();
    cout<<"Customer Name: "<<currCust.name<<endl;
    cout<<"Bill Generated at: "
        <<Dobj.getFormattedTime()<<endl;
    seperator();
    cout<<left<<setfill(' ');
    cout<<setw(50)<<"Item"
        <<setw(10)<<"Quantity"
        <<setw(10)<<"Discount"
        <<setw(10)<<"Price"
        <<setw(10)<<"Total"<<endl;
    seperator();
    while(rs->next()){
        int price = rs->getInt("price"),discount = rs->getInt("itemDiscount"), quantity = rs->getInt("quantity"), value = 0;
        
        if (discount>0){
            value = calculateDiscount(price,discount);
            
        } else {
            value = price;
        }

        value = value * quantity;
        subtotal+=(price*quantity);
        total += value;

        cout<<setw(50)<<rs->getString("name")
            <<setw(10)<<quantity
            <<setw(10)<<discount
            <<setw(10)<<price
            <<setw(10)<<value<<endl;        
    }
    seperator();
    // cout<<left<<setw(50)<<"You Saved: "<<to_string(subtotal-total)<<"; "
    //     <<setw(10)<<"Total"
    //     <<setw(10)<<total<<endl;
    printf("%-10s%-59d%-10s %-10d\n","You Saved:",subtotal-total,"Total",total);
    seperator();    
    cout<<"THANKYOU FOR VISITING US. HAVE A GREAT DAY"<<endl;
    seperator();
    pstmt->setInt(1,subtotal);
    pstmt->setInt(2,total);
    pstmt->setInt(3,currOrderId);
    pstmt->execute();
    pressKey();

    delete pstmt;
    delete stmt;
    return 0;
}

int mainMenu(){
    void (*functptr[])() = {
        choosePizza,
        choosePasta,
        chooseSides,
        chooseDrink,
        chooseCombo,
    };
    menu:
        vector<string> menuOptions = {"Pizza", "Pasta", "Sides & Dips", "Coldrinks", "Combo Offers"};
        if (Bc>0){
            menuOptions.push_back("Show Bill");
        }
        seperator();
        string prompt = "Hello "+to_string(currOrderId)+" "+ currCust.name + ", What Would you like to have Today";
        int o = selectOption(menuOptions, prompt);
        // cout<<"Selected Option: "<< menuOptions[o] << endl;
        if (menuOptions.size()-1==o){
            return 0;
        }
        functptr[o]();
        goto menu;
}

int main(){
    setOffer();
    system("mode 121,40");

    menu:
        clrscr();
        greetings();
        createCustomer();
        createOrder();
        mainMenu();
        gimmeTheBillMan();
        resetFlags();
        goto menu;

    return 0;
}