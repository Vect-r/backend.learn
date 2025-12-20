C - Create
---------------------------------------------------
mysql> create database *database_name*;
mysql> create database if not exists *database_name*;

R - Read
----------------------
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| demo1              |
| demo2              |
| information_schema |
| mysql              |
| performance_schema |
| school             |
| sys                |
+--------------------+

U - Update | Import or Export 
--------------------------------------------------------
mysqldump -u root -p *college1* > *college*.sql [Export]
mysql -u root -p *college2* < *college*.sql [Import]

D - Delete
---------------------------
mysql> drop database demo2;