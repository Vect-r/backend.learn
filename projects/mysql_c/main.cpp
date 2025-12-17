#include <iostream>
#include <mysql.h>

using namespace std;
int main() {
   MYSQL* conn;
   conn = mysql_init(NULL);
   if (mysql_real_connect(conn,"localhost","root","root","users",0,NULL,0) !=0){
      cout << "Succesfully  Connected to MySQL database xxxx" << endl;
   }

    const char *query = "SELECT username, name FROM profiles";

    if (mysql_query(conn, query)){
        cout << "Query failed: " << mysql_error(conn) << endl;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))){
        cout << "user: " << row[0]<< " Name: " << row[1] << endl;
    }

    mysql_free_result(res);


    mysql_close(conn);

   return 0;
}
