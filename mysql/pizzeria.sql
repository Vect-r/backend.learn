CREATE TABLE `items` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `size` ENUM ('Small', 'Medium', 'Large', 'XLarge'),
  `itemType` ENUM ('Pizza', 'Sides', 'Drink', 'Dessert', 'Combo') NOT NULL,
  `category` varchar(45),
  `price` int NOT NULL,
  `description` text NOT NULL
);

CREATE TABLE `offers` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `title` varchar(50) NOT NULL,
  `description` text,
  `itemType` ENUM ('Pizza', 'Sides', 'Drink', 'Dessert', 'Combo') NOT NULL,
  `discount` int NOT NULL,
  `onWeekDay` int NOT NULL
);

CREATE TABLE `customers` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(45) NOT NULL
);

CREATE TABLE `orders` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `cId` int NOT NULL,
  `createdAt` timestamp DEFAULT (CURRENT_TIMESTAMP),
  `subTotal` int,
  `savedAmount` int,
  `grandTotal` int,
  `status` varchar(20) DEFAULT 'PLACED'
);

CREATE TABLE `order_items` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `orderId` int NOT NULL,
  `itemId` int NOT NULL,
  `quantity` int NOT NULL,
  `price` int NOT NULL,
  `itemDiscount` int
);

ALTER TABLE `orders` ADD FOREIGN KEY (`cId`) REFERENCES `customers` (`id`);

ALTER TABLE `order_items` ADD FOREIGN KEY (`orderId`) REFERENCES `orders` (`id`);

ALTER TABLE `order_items` ADD FOREIGN KEY (`itemId`) REFERENCES `items` (`id`);
