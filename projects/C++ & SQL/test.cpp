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
#include <conio.h>

using namespace std;


string currentUser;

class DBConn{
  private: 
  sql::Connection* con;
  public:
   DBConn() {
        sql::mysql::MySQL_Driver* driver =
            sql::mysql::get_mysql_driver_instance();

        sql::ConnectOptionsMap props;
        props["hostName"] = "127.0.0.1";
        props["port"] = 3306;
        props["userName"] = "root";
        props["password"] = "root";

        con = driver->connect(props);
        con->setSchema("school");
    }

    ~DBConn() {
        delete con;
    }

    sql::Connection* get() {
        return con;
    }
};

void clrscr() {
    system("@cls||clear");
}

string askPassword(){
    std::string password;
    char ch;
    while ((ch = _getch()) != 13) { // 13 is the ASCII code for Carriage Return (Enter)
        if (ch == 8) { // Handle backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b"; // Move back, overwrite with space, move back again
            }
        } else {
            password += ch;
            std::cout << '*';
        }
    }
    return password;
}


int main()
{
  try {
    sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance(); // Define Driver

    sql::ConnectOptionsMap props;
    props["hostName"] = "127.0.0.1";
    props["port"] = 3306;
    props["userName"] = "root";
    props["password"] = "root";

    //Define Connection info Map;


    sql::Connection *con = driver->connect(props); // create connection
    con->setSchema("users"); // Setting default schema;


    sql::Statement *stmt = con->createStatement();//Creating cursor

  login_prompt: //login prompt goto label
    string username;
    cout << "Username: ";
    getline(cin, username);

    cout<<"Password: ";
    string password = askPassword();

    sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM profiles WHERE username = ? and password = ?"); //Prepares statement for preventing SQL Injection

    pstmt->setString(1, username); // Adding Parameters at Pos 1
    pstmt->setString(2, password); // Adding Parameters at Pos 2

    sql::ResultSet *res = pstmt->executeQuery(); // Execute Query
    cout<<endl;

    bool found = false;
    while (res->next()) {
      found = true;
      clrscr();
      currentUser = res->getString("name");
      std::cout<< "Welcome, " << res->getString("name")<< std::endl;
    }

    if (!found){
      std::cout << "Error, Username or Password is incorrect. Please Try Again" << std::endl;
      goto login_prompt;
    }

    delete res;
    delete pstmt;
    delete con;
  } catch (sql::SQLException &e) {
    std::cout << "MySQL Error: " << e.what() << std::endl;
  }
}
