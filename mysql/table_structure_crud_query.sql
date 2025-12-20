C |
----------------
mysql> create table blog (id int primary key auto_increment, title varchar(255), content text);

R |
----------------
mysql> show tables;
+-----------------+
| Tables_in_blogs |
+-----------------+
| blog            |
+-----------------+

mysql> describe blog;
+---------+--------------+------+-----+---------+----------------+
| Field   | Type         | Null | Key | Default | Extra          |
+---------+--------------+------+-----+---------+----------------+
| id      | int          | NO   | PRI | NULL    | auto_increment |
| title   | varchar(255) | YES  |     | NULL    |                |
| content | text         | YES  |     | NULL    |                |
+---------+--------------+------+-----+---------+----------------+

U |
----------------

Add new col:
mysql> alter table *blog* add created_at timestamp default current_timestamp;

Modify col:
mysql> alter table blog modify title varchar(255) not null;

Drop col:
mysql> alter table blog drop created_at;

D |
----------------
Detele table data only
mysql> truncate table blog;

Delete table structure with data
mysql> drop table blog;