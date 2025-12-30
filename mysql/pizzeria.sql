/* =======================
   DATABASE
   ======================= */

CREATE DATABASE IF NOT EXISTS pizzeria;
USE pizzeria;


/* =======================
   ITEMS
   ======================= */

CREATE TABLE items (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    size ENUM('Small','Medium','Large','XLarge'),
    itemType ENUM('Pizza','Pasta','Sides','Drink','Combo') NOT NULL,
    category VARCHAR(45),
    price INT NOT NULL,                 -- whole rupees only
    description TEXT
);


/* =======================
   OFFERS
   ======================= */

CREATE TABLE offers (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(50) NOT NULL,
    description TEXT,
    itemType ENUM('Pizza','Pasta','Sides','Drink','Combo') NOT NULL,
    discount INT NOT NULL,               -- percentage
    onWeekDay INT NOT NULL COMMENT '0=Sun ... 6=Sat (C++ tm_wday)'
);


/* =======================
   CUSTOMERS
   ======================= */

CREATE TABLE customers (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(45) NOT NULL
);


/* =======================
   ORDERS
   ======================= */

CREATE TABLE orders (
    id INT AUTO_INCREMENT PRIMARY KEY,
    cId INT NOT NULL,
    createdAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    subTotal INT,
    discountAmount INT,
    grandTotal INT,
    status VARCHAR(20) DEFAULT 'PLACED',

    CONSTRAINT fk_orders_customers
        FOREIGN KEY (cId) REFERENCES customers(id)
);


/* =======================
   ORDER ITEMS
   ======================= */

CREATE TABLE order_items (
    id INT AUTO_INCREMENT PRIMARY KEY,
    orderId INT NOT NULL,
    itemId INT NOT NULL,
    quantity INT NOT NULL,
    price INT NOT NULL,                  -- snapshot item price
    itemDiscount INT,
    name VARCHAR(50) NOT NULL,

    CONSTRAINT fk_order_items_orders
        FOREIGN KEY (orderId) REFERENCES orders(id),

    CONSTRAINT fk_order_items_items
        FOREIGN KEY (itemId) REFERENCES items(id)
);

/* =======================
   PIZZAS – THE OGs
   ======================= */

INSERT INTO items (name, size, itemType, category, price, description) VALUES
('Margherita','Small','Pizza','The OGs',199,'Classic mozzarella, tomato sauce and basil'),
('Margherita','Medium','Pizza','The OGs',299,'Classic mozzarella, tomato sauce and basil'),
('Margherita','Large','Pizza','The OGs',399,'Classic mozzarella, tomato sauce and basil'),
('Margherita','XLarge','Pizza','The OGs',499,'Classic mozzarella, tomato sauce and basil'),

('Cheese Lovers','Small','Pizza','The OGs',249,'Mozzarella, cheddar and parmesan loaded pizza'),
('Cheese Lovers','Medium','Pizza','The OGs',349,'Mozzarella, cheddar and parmesan loaded pizza'),
('Cheese Lovers','Large','Pizza','The OGs',449,'Mozzarella, cheddar and parmesan loaded pizza'),
('Cheese Lovers','XLarge','Pizza','The OGs',549,'Mozzarella, cheddar and parmesan loaded pizza'),

('Veggies Supreme','Small','Pizza','The OGs',229,'Loaded with fresh vegetables and olives'),
('Veggies Supreme','Medium','Pizza','The OGs',329,'Loaded with fresh vegetables and olives'),
('Veggies Supreme','Large','Pizza','The OGs',429,'Loaded with fresh vegetables and olives'),
('Veggies Supreme','XLarge','Pizza','The OGs',529,'Loaded with fresh vegetables and olives'),

('Neapolitan Pizza','Small','Pizza','The OGs',269,'Thin crust Italian pizza with basil'),
('Neapolitan Pizza','Medium','Pizza','The OGs',369,'Thin crust Italian pizza with basil'),
('Neapolitan Pizza','Large','Pizza','The OGs',469,'Thin crust Italian pizza with basil'),
('Neapolitan Pizza','XLarge','Pizza','The OGs',569,'Thin crust Italian pizza with basil');


/* =======================
   PIZZAS – INDIAN ZAIKAS (VEG)
   ======================= */

INSERT INTO items (name, size, itemType, category, price, description) VALUES
('Tandoori Paneer','Small','Pizza','Indian Veg',249,'Paneer, onion, capsicum with mint chutney'),
('Tandoori Paneer','Medium','Pizza','Indian Veg',349,'Paneer, onion, capsicum with mint chutney'),
('Tandoori Paneer','Large','Pizza','Indian Veg',449,'Paneer, onion, capsicum with mint chutney'),
('Tandoori Paneer','XLarge','Pizza','Indian Veg',549,'Paneer, onion, capsicum with mint chutney'),

('Makhani Pizza','Small','Pizza','Indian Veg',269,'Rich buttery makhani sauce with paneer'),
('Makhani Pizza','Medium','Pizza','Indian Veg',369,'Rich buttery makhani sauce with paneer'),
('Makhani Pizza','Large','Pizza','Indian Veg',469,'Rich buttery makhani sauce with paneer'),
('Makhani Pizza','XLarge','Pizza','Indian Veg',569,'Rich buttery makhani sauce with paneer'),

('Paneer 65','Small','Pizza','Indian Veg',259,'Spicy paneer 65 with onions and coriander'),
('Paneer 65','Medium','Pizza','Indian Veg',359,'Spicy paneer 65 with onions and coriander'),
('Paneer 65','Large','Pizza','Indian Veg',459,'Spicy paneer 65 with onions and coriander'),
('Paneer 65','XLarge','Pizza','Indian Veg',559,'Spicy paneer 65 with onions and coriander'),

('Flamin Hot','Small','Pizza','Indian Veg',269,'Extra spicy pizza with chilies and jalapenos'),
('Flamin Hot','Medium','Pizza','Indian Veg',369,'Extra spicy pizza with chilies and jalapenos'),
('Flamin Hot','Large','Pizza','Indian Veg',469,'Extra spicy pizza with chilies and jalapenos'),
('Flamin Hot','XLarge','Pizza','Indian Veg',569,'Extra spicy pizza with chilies and jalapenos');


/* =======================
   PIZZAS – INDIAN ZAIKAS (NON-VEG)
   ======================= */

INSERT INTO items (name, size, itemType, category, price, description) VALUES
('Bhuna Murg','Small','Pizza','Indian Non-Veg',279,'Chicken in spicy bhuna masala'),
('Bhuna Murg','Medium','Pizza','Indian Non-Veg',379,'Chicken in spicy bhuna masala'),
('Bhuna Murg','Large','Pizza','Indian Non-Veg',479,'Chicken in spicy bhuna masala'),
('Bhuna Murg','XLarge','Pizza','Indian Non-Veg',579,'Chicken in spicy bhuna masala'),

('Butter Chicken Pizza','Small','Pizza','Indian Non-Veg',289,'Creamy butter chicken with cheese'),
('Butter Chicken Pizza','Medium','Pizza','Indian Non-Veg',389,'Creamy butter chicken with cheese'),
('Butter Chicken Pizza','Large','Pizza','Indian Non-Veg',489,'Creamy butter chicken with cheese'),
('Butter Chicken Pizza','XLarge','Pizza','Indian Non-Veg',589,'Creamy butter chicken with cheese'),

('Tandoori Chicken Pizza','Small','Pizza','Indian Non-Veg',269,'Tandoori chicken with yogurt sauce'),
('Tandoori Chicken Pizza','Medium','Pizza','Indian Non-Veg',369,'Tandoori chicken with yogurt sauce'),
('Tandoori Chicken Pizza','Large','Pizza','Indian Non-Veg',469,'Tandoori chicken with yogurt sauce'),
('Tandoori Chicken Pizza','XLarge','Pizza','Indian Non-Veg',569,'Tandoori chicken with yogurt sauce'),

('Keema Do Pyaza','Small','Pizza','Indian Non-Veg',299,'Minced mutton with onions'),
('Keema Do Pyaza','Medium','Pizza','Indian Non-Veg',399,'Minced mutton with onions'),
('Keema Do Pyaza','Large','Pizza','Indian Non-Veg',499,'Minced mutton with onions'),
('Keema Do Pyaza','XLarge','Pizza','Indian Non-Veg',599,'Minced mutton with onions');


/* =======================
   PASTA
   ======================= */

INSERT INTO items (name, itemType, category, price, description) VALUES
('Tandoori Chicken Pasta','Pasta','Non-Veg Pasta',300,'Creamy pasta with smoky tandoori chicken and a rich, spiced tomato sauce.'),
('Palak Paneer Pasta','Pasta','Veg Pasta',280,'Delicious fusion of creamy spinach sauce and paneer in a comforting pasta dish, spiced with Indian masalas.'),
('Spicy Pesto Pasta','Pasta','Veg Pasta',250,'A fresh twist on classic pesto, with mint, coriander, and green chilies for a bold Indian flavor.'),
('Penne Arrabbiata (Spicy)','Pasta','Veg Pasta',220,'Penne pasta tossed in a fiery, garlicky tomato sauce with a hint of Indian red chili heat.'),
('Butter Chicken Pasta','Pasta','Non-Veg Pasta',350,'Tender pasta in a rich and creamy butter chicken sauce, with juicy chunks of chicken and aromatic spices.');


/* =======================
   SIDES
   ======================= */

INSERT INTO items (name, itemType, category, price, description) VALUES
('Garlic Bread','Sides','Sides',99,'Fresh garlic bread'),
('Cheesy Garlic Bread','Sides','Sides',129,'Garlic bread topped with cheese'),
('Onion Rings','Sides','Sides',149,'Crispy onion rings'),
('French Fries','Sides','Sides',129,'Golden fried potato fries'),
('Crispy Paneer Bites','Sides','Sides',169,'Crispy fried paneer bites'),
('Chicken Wings','Sides','Sides',199,'Buffalo or BBQ chicken wings'),
('Samosa Bites','Sides','Sides',99,'Mini samosas served with chutney');


/* =======================
   DRINKS
   ======================= */

INSERT INTO items (name, itemType, category, price,size) VALUES
('Coca Cola','Drink','Cold Drink',20,"250Ml"),
('Sprite','Drink','Cold Drink',20,"250ML"),
('Fanta','Drink','Cold Drink',20,"250ML"),
('Coca Cola ','Drink','Cold Drink',35,"500ML"),
('Sprite','Drink','Cold Drink',35,"500ML"),
('Fanta','Drink','Cold Drink',35,"500ML"),
('Coca Cola ','Drink','Cold Drink',55,"1L"),
('Sprite','Drink','Cold Drink',55,"1L"),
('Fanta','Drink','Cold Drink',55,"1L");


/* =======================
   COMBOS
   ======================= */

INSERT INTO items (name, itemType, category, price, description) VALUES
('Solo Combo','Combo','Combo Offer',299,'Margherita Pizza S + Samosa + 1 Cold Drink 250ml'),
('Couple Combo','Combo','Combo Offer',499,'Flamin Hot M + Garlic Bread + 1 Cold Drink 500ml'),
('Family Feast','Combo','Combo Offer',799,'Paneer 65 L + Garlic Bread + 1 Cold Drink 1 Ltr'),
('Party Pack','Combo','Combo Offer',999,'Bhuna Murg XL + Penne Arrabbiata Pasta + 1 Cold Drink 1 Ltr');
