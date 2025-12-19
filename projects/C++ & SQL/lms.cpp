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

sql::Connection* getConnection() {
    static sql::Connection* con = nullptr;

    if (con == nullptr) {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();

        sql::ConnectOptionsMap props;
        props["hostName"] = "127.0.0.1";
        props["port"] = 3306;
        props["userName"] = "root";
        props["password"] = "root";

        con = driver->connect(props);
        con->setSchema("users");
    }

    return con;
}

void insertProfile(const string& name, string& username, string& password) {
    sql::Connection* con = getConnection();

    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO profiles (username, name, password) VALUES (?, ?, ?)");

    pstmt->setString(1, name);
    pstmt->setString(2, username);
    pstmt->setString(3, password);
    

    pstmt->execute();
    delete pstmt;
}

void listProfiles(){
    sql::Connection* con = getConnection();
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM profiles");

    while (res->next()) {
        std::cout << res->getInt("id") << " " << res->getString("name") << " " << res->getInt("age") << std::endl;
    }

    delete res;
    delete stmt;
}

void login(){

    string username;
    cout<<"Username: "

    cout<<"Password: ";

}


int main(){
    cout<<"Hello World!!"<<endl;
}

