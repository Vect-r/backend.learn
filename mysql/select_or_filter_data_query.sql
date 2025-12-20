mysql> SELECT * from users;
+----+---------------+-----+-----------+
| id | fullname      | age | is_active |
+----+---------------+-----+-----------+
|  4 | Amit Sharma   |  25 |         1 |
|  5 | Neha Patel    |  22 |         1 |
|  6 | Rohit Verma   |  30 |         0 |
|  7 | Priya Singh   |  27 |         1 |
|  8 | Karan Mehta   |  35 |         1 |
|  9 | Anjali Desai  |  24 |         0 |
| 10 | Vikram Joshi  |  40 |         1 |
| 11 | Pooja Nair    |  28 |         1 |
| 12 | Sandeep Kumar |  33 |         0 |
| 13 | Riya Malhotra |  21 |         1 |
+----+---------------+-----+-----------+
10 rows in set (0.00 sec)

mysql> SELECT * from posts;
+----+-----------------------+------------------------------------------+---------+
| id | title                 | content                                  | user_id |
+----+-----------------------+------------------------------------------+---------+
| 21 | Introduction to MySQL | Basics of MySQL database.                |       4 |
| 22 | MySQL CRUD            | Create, Read, Update, Delete operations. |       4 |
| 23 | Django Basics         | Introduction to Django framework.        |       5 |
| 24 | Django Models         | Understanding Django ORM.                |       5 |
| 25 | React Overview        | Introduction to React JS.                |       6 |
| 26 | React Hooks           | useState and useEffect explained.        |       6 |
| 27 | Node.js Intro         | Getting started with Node.js.            |       7 |
| 28 | Express.js            | API development using Express.           |       7 |
| 29 | REST vs GraphQL       | Differences between REST and GraphQL.    |       8 |
| 30 | GraphQL Basics        | Queries and Mutations in GraphQL.        |       8 |
+----+-----------------------+------------------------------------------+---------+
10 rows in set (0.00 sec)

mysql> SELECT * from comments;
+----+---------+--------------------------+
| id | user_id | content                  |
+----+---------+--------------------------+
|  1 |       4 | Very helpful post!       |
|  2 |       5 | Nice explanation ?       |
|  3 |       6 | I learned something new. |
+----+---------+--------------------------+
3 rows in set (0.00 sec)

mysql> SELECT * from likes;
+----+---------+---------+
| id | user_id | post_id |
+----+---------+---------+
|  7 |       4 |      21 |
|  8 |       5 |      21 |
|  9 |       6 |      22 |
| 10 |       7 |      22 |
| 11 |       8 |      23 |
+----+---------+---------+