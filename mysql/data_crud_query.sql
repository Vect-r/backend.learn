-- C - Create
-------------
Users:
mysql> create table users(id int primary key auto_increment, fullname varchar(255), age int not null, is_active bool default true);

Posts :
mysql> create table posts(id int primary key auto_increment, title varchar(255), content text, post_id int not null, foreign key (post_id) references users(id));

Comments:
mysql> create table comments (id int primary key auto_increment, user_id int not null, foreign key(user_id) references users(id));

Likes:
mysql> create table likes (id int primary key auto_increment, user_id int not null, foreign key(user_id) references users(id));

mysql> show tables;
+-----------------+
| Tables_in_blogs |
+-----------------+
| comments        |
| likes           |
| posts           |
| users           |
+-----------------+

mysql> insert into users(fullname, age)values("brijesh gondaliya", 29);
mysql> insert into users(fullname, age)values("ravi gondaliya", 32), ("jay kothari", 45);

-- R - Read
-------------
mysql> select * from users;

-- U - Update
-------------
mysql> update users set fullname="jay shah", age=35 where id = 3;

mysql> update users set is_active=0 where id < 3;

-- Operator	Description	Example
-------------------------------
-- =	    Equal to	
-- >	    Greater than	
-- <	    Less than	
-- >=	    Greater than or equal to	
-- <=	    Less than or equal to	
-- <>	    Not equal to

-- D - Delete
-------------
mysql> delete from where id = 3;
mysql> delete from users where id < 4;