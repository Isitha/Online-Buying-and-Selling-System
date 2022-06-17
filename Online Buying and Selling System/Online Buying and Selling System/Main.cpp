#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

// Start : Styles
int k = 12;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loadingAnimation() {
	const char x = 219;

	std::cout << "LOADING ";
	for (int i = 0; i <= 35; i++) {
		std::cout << x;
		if (i <= 15)
			Sleep(100);
		else if (i > 15 && i <= 30)
			Sleep(50);
		else
			Sleep(25);
	}
	std::cout << " 100%...";
	Sleep(500);
}
void printName1() {
	std::cout << "\t\t\t\t\t      ____        _ _ " << std::endl;
	std::cout << "\t\t\t\t\t     / __ \\      | (_) " << std::endl;
	std::cout << "\t\t\t\t\t    | |  | |_ __ | |_ _ __   ___ " << std::endl;
	std::cout << "\t\t\t\t\t    | |  | | '_ \\| | | '_ \\ / _ \\ " << std::endl;
	std::cout << "\t\t\t\t\t    | |__| | | | | | | | | |  __/" << std::endl;
	std::cout << "\t\t\t\t\t     \\____/|_| |_|_|_|_| |_|\\___|" << std::endl;

	std::cout << "\n\t\t  ____              _                               _    _____      _ _ _ " << std::endl;
	std::cout << "\t\t |  _ \\		   (_)                             | |  / ____|    | | (_) " << std::endl;
	std::cout << "\t\t | |_) |_   _ _   _ _ _ __   __ _    __ _ _ __   __| | | (___   ___| | |_ _ __   __ _ " << std::endl;
	std::cout << "\t\t |  _ <| | | | | | | | '_ \\ / _` |  / _` | '_ \\ / _` |  \\___ \\ / _ \\ | | | '_ \\ / _` | " << std::endl;
	std::cout << "\t\t | |_) | |_| | |_| | | | | | (_| | | (_| | | | | (_| |  ____) |  __/ | | | | | | (_| | " << std::endl;
	std::cout << "\t\t |____/ \\__,_|\\__, |_|_| |_|\\__, |  \\__,_|_| |_|\\__,_| |_____/ \\___|_|_|_|_| |_|\\__, | " << std::endl;
	std::cout << "\t\t	       __/ |         __/ |                                               __/ | " << std::endl;
	std::cout << "\t\t	      |___/         |___/                                               |___/ " << std::endl;

	std::cout << "\n\t\t\t\t\t   _____           _ " << std::endl;
	std::cout << "\t\t\t\t\t  / ____|         | | " << std::endl;
	std::cout << "\t\t\t\t\t | (___  _   _ ___| |_ ___ _ __ ___ " << std::endl;
	std::cout << "\t\t\t\t\t  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ " << std::endl;
	std::cout << "\t\t\t\t\t  ____) | |_| \\__ \\ ||  __/ | | | | | " << std::endl;
	std::cout << "\t\t\t\t\t |_____/ \\__, |___/\\__\\___|_| |_| |_| " << std::endl;
	std::cout << "\t\t\t\t\t          __/ | " << std::endl;
	std::cout << "\t\t\t\t\t         |___/ " << std::endl;
}
void printName2() {
	std::cout << "\n\n\t\t\t\t>>==============================================<<" << std::endl;
	std::cout << "\t\t\t\t======>> ONLINE BUYING AND SELLING SYSTEM <<======" << std::endl;
	std::cout << "\t\t\t\t>>==============================================<<\n\n" << std::endl;
}
// End : Styles


// Buyer class
class Buyer {
private:
	int id;
	std::string name;
	std::string username;
	std::string password;

public:
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	std::string getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
	std::string getUsername() {
		return username;
	}
	void setUsername(std::string username) {
		this->username = username;
	}
	std::string getPassword() {
		return password;
	}
	void setPassword(std::string password) {
		this->password = password;
	}

	Buyer* next;

	Buyer() {
		setId(NULL);
		setName("");
		setUsername("");
		setPassword("");
	}
	Buyer(int Id, std::string Name, std::string Username, std::string Password) {
		setId(Id);
		setName(Name);
		setUsername(Username);
		setPassword(Password);
	}
};
// Buyer Linked List
class BuyerLinkedList {
public:
	Buyer* head;

	BuyerLinkedList();
	BuyerLinkedList(Buyer* b);
	Buyer* idExists(int id);
	Buyer* usernameExists(std::string username);
	void insertBuyer(Buyer* b);
	void deleteBuyer(int id);
	void showBuyer();
};
BuyerLinkedList::BuyerLinkedList() {
	head = NULL;
}
BuyerLinkedList::BuyerLinkedList(Buyer* b) {
	head = b;
}
Buyer* BuyerLinkedList::idExists(int id) {
	Buyer* temp = NULL;
	Buyer* ptr = head;
	while (ptr != NULL) {
		if (ptr->getId() == id) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
Buyer* BuyerLinkedList::usernameExists(std::string username) {
	Buyer* temp = NULL;
	Buyer* ptr = head;
	while (ptr != NULL) {
		if (ptr->getUsername() == username) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
void BuyerLinkedList::insertBuyer(Buyer* b) {
	if (idExists(b->getId()) != NULL) {
		std::cout << "\n\n\t\t\t\t  Buyer Already Exists..." << std::endl;
	}
	else if (usernameExists(b->getUsername()) != NULL) {
		std::cout << "\n\n\t\t\t\t  This Username Already Exists..." << std::endl;
	}
	else {
		if (head == NULL) {
			head = b;
			std::cout << "\n\n\t\t\t\t  Buyer Created Successfully...";
		}
		else {
			Buyer* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = b;
			std::cout << "\n\n\t\t\t\t  Buyer Created Successfully...";
		}
	}
}
void BuyerLinkedList::deleteBuyer(int id) {
	if (head->getId() == id) {
		head = head->next;
		std::cout << "\n\t\t\t\tAccount Deleted Successfully...";
	}
	else {
		Buyer* temp = NULL;
		Buyer* prevPtr = head;
		Buyer* currentPtr = head->next;
		while (currentPtr != NULL) {
			if (currentPtr->getId() == id) {
				temp = currentPtr;
				currentPtr = NULL;
			}
			else {
				prevPtr = prevPtr->next;
				currentPtr = currentPtr->next;
			}
		}
		if (temp != NULL) {
			prevPtr->next = temp->next;
			std::cout << "\n\t\t\t\tAccount Deleted Successfully...";
		}
	}
}
void BuyerLinkedList::showBuyer() {
	if (head == NULL) {
		std::cout << "\n\t\t\t\tBuyers Account Not Created Yet....";
	}
	else {
		std::cout << "\n\t\t\t\tBuyers : \n";
		Buyer* temp = head;

		while (temp != NULL) {
			std::cout << "\t\t\t\t(" << temp->getId() << ", " << temp->getName() << ", " << temp->getUsername() << ", " << temp->getPassword() << ") ---> " << std::endl;
			temp = temp->next;
		}
	}
}

// Seller class
class Seller {
private:
	int id;
	std::string name;
	std::string username;
	std::string password;
	std::string shopName;

public:
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	std::string getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
	std::string getUsername() {
		return username;
	}
	void setUsername(std::string username) {
		this->username = username;
	}
	std::string getPassword() {
		return password;
	}
	void setPassword(std::string password) {
		this->password = password;
	}
	std::string getShopName() {
		return shopName;
	}
	void setShopName(std::string shopName) {
		this->shopName = shopName;
	}

	Seller* next;

	Seller() {
		setId(NULL);
		setName("");
		setUsername("");
		setPassword("");
		setShopName("");
	}
	Seller(int Id, std::string Name, std::string Username, std::string Password, std::string ShopName) {
		setId(Id);
		setName(Name);
		setUsername(Username);
		setPassword(Password);
		setShopName(ShopName);
	}
};
// Seller Linked List
class SellerLinkedList {
public:
	Seller* head;

	SellerLinkedList();
	SellerLinkedList(Seller* s);
	Seller* idExists(int id);
	Seller* usernameExists(std::string username);
	void insertSeller(Seller* s);
	void deleteSeller(int id);
	void showSeller();
};
SellerLinkedList::SellerLinkedList() {
	head = NULL;
}
SellerLinkedList::SellerLinkedList(Seller* s) {
	head = s;
}
Seller* SellerLinkedList::idExists(int id) {
	Seller* temp = NULL;
	Seller* ptr = head;
	while (ptr != NULL) {
		if (ptr->getId() == id) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
Seller* SellerLinkedList::usernameExists(std::string username) {
	Seller* temp = NULL;
	Seller* ptr = head;
	while (ptr != NULL) {
		if (ptr->getUsername() == username) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
void SellerLinkedList::insertSeller(Seller* b) {
	if (idExists(b->getId()) != NULL) {
		std::cout << "\n\n\t\t\t\t  Seller Already Exists..." << std::endl;
	}
	else if (usernameExists(b->getUsername()) != NULL) {
		std::cout << "\n\n\t\t\t\t  This Username Already Exists..." << std::endl;
	}
	else {
		if (head == NULL) {
			head = b;
			std::cout << "\n\n\t\t\t\t  Seller Created Successfully...";
		}
		else {
			Seller* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = b;
			std::cout << "\n\n\t\t\t\t  Buyer Created Successfully...";
		}
	}
}
void SellerLinkedList::deleteSeller(int id) {
	if (head->getId() == id) {
		head = head->next;
		std::cout << "\n\t\t\t\tAccount Deleted Successfully...";
	}
	else {
		Seller* temp = NULL;
		Seller* prevPtr = head;
		Seller* currentPtr = head->next;
		while (currentPtr != NULL) {
			if (currentPtr->getId() == id) {
				temp = currentPtr;
				currentPtr = NULL;
			}
			else {
				prevPtr = prevPtr->next;
				currentPtr = currentPtr->next;
			}
		}
		if (temp != NULL) {
			prevPtr->next = temp->next;
			std::cout << "\n\t\t\t\tAccount Deleted Successfully...";
		}
	}
}
void SellerLinkedList::showSeller() {
	if (head == NULL) {
		std::cout << "\n\t\t\t\tSeller Account Not Created Yet....";
	}
	else {
		std::cout << "\n\t\t\t\tSellers : \n";
		Seller* temp = head;

		while (temp != NULL) {
			std::cout << "\t\t\t\t(" << temp->getId() << ", " << temp->getName() << ", " << temp->getUsername() << ", " << temp->getPassword() << ", " << temp->getShopName() << ") ---> " << std::endl;
			temp = temp->next;
		}
	}
}

// Product class
class Product {
private:
	int sellerId;
	int id;
	std::string category;
	std::string name;
	int stock;
	double price;

public:
	int getSellerId() {
		return sellerId;
	}
	void setSellerId(int sellerId) {
		this->sellerId = sellerId;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	std::string getCategory() {
		return category;
	}
	void setCategory(std::string category) {
		this->category = category;
	}
	std::string getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
	int getStock() {
		return stock;
	}
	void setStock(int stock) {
		this->stock = stock;
	}
	double getPrice() {
		return price;
	}
	void setPrice(double price) {
		this->price = price;
	}
	Product* next;

	Product() {
		setSellerId(NULL);
		setId(NULL);
		setCategory("");
		setName("");
		setStock(0);
		setPrice(0);
	}
	Product(int sellerId, int id, std::string category, std::string name, int stock, double price) {
		setSellerId(sellerId);
		setId(id);
		setCategory(category);
		setName(name);
		setStock(stock);
		setPrice(price);
	}
};
// Product Linked List
class ProductLinkedList {
public:
	Product* head;

	ProductLinkedList();
	ProductLinkedList(Product* p);
	Product* idExists(int id);
	void insertProduct(Product* p);
	void deleteProduct(int sellerId, int id);
	void deleteProduct2(int sellerId);
	void showProducts(int sellerId);
	void showProducts2();
};
ProductLinkedList::ProductLinkedList() {
	head = NULL;
}
ProductLinkedList::ProductLinkedList(Product* p) {
	head = p;
}
Product* ProductLinkedList::idExists(int id) {

	Product* temp = NULL;
	Product* ptr = head;
	while (ptr != NULL) {
		if (ptr->getId() == id) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
void ProductLinkedList::insertProduct(Product* p) {
	if (idExists(p->getId()) != NULL) {
		std::cout << "\n\n\t\t\t\t  Product ID Already Exists..." << std::endl;
	}
	else {
		if (head == NULL) {
			head = p;
			std::cout << "\n\n\t\t\t\t  Product Inserted Successfully...";
		}
		else {
			Product* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = p;
			std::cout << "\n\n\t\t\t\t  Product Inserted Successfully...";
		}
	}
}
void ProductLinkedList::deleteProduct(int sellerId, int id) {
	if (head == NULL) {
		std::cout << "\n\t\t\t\tProduct List Already Empty... Cant delete..." << std::endl;
	}
	else if (head != NULL) {
		if (head->getId() == id && head->getSellerId() == sellerId) {
			head = head->next;
			std::cout << "\n\t\t\t\tProduct Deleted Successfully with ID : " << id << std::endl;
		}
		else {
			Product* temp = NULL;
			Product* prevptr = head;
			Product* currentptr = head->next;
			while (currentptr != NULL) {
				if (currentptr->getId() == id && currentptr->getSellerId() == sellerId) {
					temp = currentptr;
					currentptr = NULL;
				}
				else {
					prevptr = prevptr->next;
					currentptr = currentptr->next;
				}
			}
			if (temp != NULL) {
				prevptr->next = temp->next;
				std::cout << "\n\t\t\t\tProduct Deleted Successfully with ID value : " << id << std::endl;
			}
			else {
				std::cout << "\n\t\t\t\tProduct Doesn't exist with ID value : " << id << std::endl;
			}
		}
	}
}
void ProductLinkedList::deleteProduct2(int sellerId) {
	if (head != NULL) {
		if (head->getSellerId() == sellerId) {
			head = head->next;
		}
		else {
			Product* temp = NULL;
			Product* prevptr = head;
			Product* currentptr = head->next;
			while (currentptr != NULL) {
				if (currentptr->getSellerId() == sellerId) {
					temp = currentptr;
					currentptr = NULL;
				}
				else {
					prevptr = prevptr->next;
					currentptr = currentptr->next;
				}
			}
			if (temp != NULL) {
				prevptr->next = temp->next;
			}
		}
	}
}
void ProductLinkedList::showProducts(int sellerId) {

	Product* temp = head;

	k = 12;
	int no = 1;

	std::cout << "\t\t\t=====================================================================================" << std::endl;
	std::cout << "\t\t\t|                                 PRODUCT TABLE                                     |" << std::endl;
	std::cout << "\t\t\t=====================================================================================" << std::endl;
	std::cout << "\t\t\t|   No   |   ID   |    CATEGORY    |       NAME       |   STOCK   |      PRICE      |" << std::endl;
	std::cout << "\t\t\t=====================================================================================" << std::endl;
	while (temp != NULL) {
		if (temp->getSellerId() == sellerId) {
			gotoxy(29, k);
			std::cout << no << "." << std::endl;
			gotoxy(38, k);
			std::cout << temp->getId() << std::endl;
			gotoxy(47, k);
			std::cout << temp->getCategory() << std::endl;
			gotoxy(65, k);
			std::cout << temp->getName() << std::endl;
			gotoxy(83, k);
			std::cout << temp->getStock() << std::endl;
			gotoxy(94, k);
			std::cout << "Rs." << temp->getPrice() << std::endl;
			k += 2;
			no++;
		}
		temp = temp->next;
	}
	std::cout << "\t\t\t-------------------------------------------------------------------------------------" << std::endl;
}
void ProductLinkedList::showProducts2() {
	if (head == NULL) {
		std::cout << "\n\t\t\t\tProducts Not Inserted Yet....";
	}
	else {
		Product* temp = head;

		k = 12;
		int no = 1;

		std::cout << "\t\t\t=====================================================================================" << std::endl;
		std::cout << "\t\t\t|                                 PRODUCT TABLE                                     |" << std::endl;
		std::cout << "\t\t\t=====================================================================================" << std::endl;
		std::cout << "\t\t\t|   No   |   ID   |    CATEGORY    |       NAME       |   STOCK   |      PRICE      |" << std::endl;
		std::cout << "\t\t\t=====================================================================================" << std::endl;
		while (temp != NULL) {
			gotoxy(29, k);
			std::cout << no << "." << std::endl;
			gotoxy(38, k);
			std::cout << temp->getId() << std::endl;
			gotoxy(47, k);
			std::cout << temp->getCategory() << std::endl;
			gotoxy(65, k);
			std::cout << temp->getName() << std::endl;
			gotoxy(83, k);
			std::cout << temp->getStock() << std::endl;
			gotoxy(94, k);
			std::cout << "Rs." << temp->getPrice() << std::endl;
			temp = temp->next;
			std::cout << "\t\t\t-------------------------------------------------------------------------------------" << std::endl;
			k += 2;
			no++;
		}
	}
}

// Order Class
class Order {
private:
	int buyerId;
	int id;
	int productId;
	std::string product;
	//std::string category;
	int quantity;
	double price;
	double total;

public:
	int getBuyerId() {
		return buyerId;
	}
	void setBuyerId(int buyerId) {
		this->buyerId = buyerId;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	int getProductId() {
		return productId;
	}
	void setProductId(int productId) {
		this->productId = productId;
	}
	std::string getProduct() {
		return product;
	}
	void setProduct(std::string product) {
		this->product = product;
	}
	int getQuantity() {
		return quantity;
	}
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	double getPrice() {
		return price;
	}
	void setPrice(double price) {
		this->price = price;
	}
	double getTotal() {
		return total;
	}
	void setTotal(double total) {
		this->total = total;
	}

	Order* next;
	Order() {
		setId(NULL);
		setProduct("");
		setQuantity(NULL);
		setPrice(NULL);
		setTotal(NULL);
	}
	Order(int id, std::string product, int quantity, double price, double total) {
		setId(id);
		setProduct(product);
		setQuantity(quantity);
		setPrice(price);
		setTotal(total);
	}
};
class OrderLinkedList {
public:
	Order* head;

	OrderLinkedList();
	OrderLinkedList(Order* o);
	Order* idExists(int id);
	void insertOrder(Order* o);
	void deleteOrder(int buyerId, int id);
	void showOrders(int buyerId);
};
OrderLinkedList::OrderLinkedList() {
	head = NULL;
}
OrderLinkedList::OrderLinkedList(Order* o) {
	head = o;
}
Order* OrderLinkedList::idExists(int id) {
	Order* ptr = head;
	Order* temp = NULL;
	while (ptr != NULL) {
		if (ptr->getId() == id) {
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}
void OrderLinkedList::insertOrder(Order* o) {
	if (idExists(o->getId()) != NULL) {
		std::cout << "\n\n\t\t\t\t  Order ID Already Exists..." << std::endl;
	}
	else {
		if (head == NULL) {
			head = o;
			std::cout << "\n\n\t\t\t\t  Order Inserted Successfully...";
		}
		else {
			Order* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = o;
			std::cout << "\n\n\t\t\t\t  Order Inserted Successfully...";
		}
	}
}
void OrderLinkedList::deleteOrder(int buyerId, int id) {

	if (head == NULL) {
		std::cout << "\n\t\t\t\tOrder list already Empty... Cant delete..." << std::endl;
	}
	else if (head != NULL) {
		if (head->getId() == id && head->getBuyerId() == buyerId) {
			head = head->next;
			std::cout << "\n\t\t\t\tOrder Deleted Successfull with ID : " << id << std::endl;
		}
		else {
			Order* temp = NULL;
			Order* prevptr = head;
			Order* currentptr = head->next;
			while (currentptr != NULL) {
				if (currentptr->getId() == id && currentptr->getBuyerId() == buyerId) {
					temp = currentptr;
					currentptr = NULL;
				}
				else {
					prevptr = prevptr->next;
					currentptr = currentptr->next;
				}
			}
			if (temp != NULL) {
				prevptr->next = temp->next;
				std::cout << "\n\t\t\t\tOrder Deleted Successfull with ID : " << id << std::endl;
			}
			else {
				std::cout << "\n\t\t\t\tOrder Doesn't exist with ID : " << id << std::endl;
			}
		}
	}
}
void OrderLinkedList::showOrders(int buyerId) {

	Order* temp = head;

	k = 12;
	int no = 1;
	double subtotal = 0;

	std::cout << "\t\t  ======================================================================================" << std::endl;
	std::cout << "\t\t  |                                    ORDER TABLE                                     |" << std::endl;
	std::cout << "\t\t  ======================================================================================" << std::endl;
	std::cout << "\t\t  |   No   |   ID   |      PRODUCT      |  QUANTITY   |     PRICE     |      TOTAL     |" << std::endl;
	std::cout << "\t\t  ======================================================================================" << std::endl;
	while (temp != NULL) {
		if (temp->getBuyerId() == buyerId) {
			gotoxy(22, k);
			std::cout << no << "." << std::endl;
			gotoxy(32, k);
			std::cout << temp->getId() << std::endl;
			gotoxy(40, k);
			std::cout << temp->getProduct() << std::endl;
			gotoxy(63, k);
			std::cout << temp->getQuantity() << std::endl;
			gotoxy(73, k);
			std::cout << "Rs." << temp->getPrice() << std::endl;
			gotoxy(89, k);
			std::cout << "Rs." << temp->getTotal() << std::endl;
			subtotal += temp->getTotal();
			k += 2;
			no++;
		}
		temp = temp->next;
	}
	std::cout << "\t\t  ======================================================================================" << std::endl;
	std::cout << "\t\t                                      SUBTOTAL ==>>                      Rs." << subtotal << std::endl;
	std::cout << "\t\t  ======================================================================================" << std::endl;
}

BuyerLinkedList b;
SellerLinkedList s;
ProductLinkedList p;
OrderLinkedList o;

int main() {
	system("color 71");
	printName1();
	gotoxy(33, 26);
	loadingAnimation();
	system("cls");



menu:
	system("color E4");
	int id, proId, stock, quantity;
	std::string name, username, password, shopName, category, product;
	double price, total;
	int choise = 0;
	printName2();
	std::cout << "\t\t\t\t    01. Login As a Buyer        -->\n" << std::endl;
	std::cout << "\t\t\t\t    02. Login As a Seller       -->\n" << std::endl;
	std::cout << "\t\t\t\t    03. Create Buyer Account    -->\n" << std::endl;
	std::cout << "\t\t\t\t    04. Create Seller Account   -->\n" << std::endl;
	std::cout << "\t\t\t\t    05. Exit System             -->\n\n" << std::endl;
	std::cout << "\t\t\t\t    Choose Your Choice : ";

	Buyer* buyer = new Buyer();
	Seller* seller = new Seller();

	std::cin >> choise;
	switch (choise) {
	case 1:
		system("cls");
		printName2();
		std::cout << "\n\t\t\t\tBuyer Account";
		std::cout << "\n\t\t\t\t=============\n";
		std::cout << "\n\t\t\t\t  Enter Username : ";
		std::cin >> username;
		std::cout << "\n\t\t\t\t  Enter Password : ";
		std::cin >> password;
		if (b.usernameExists(username) != NULL) {
			Buyer* PTR = b.head;
			Buyer* TEMP = NULL;
			while (PTR != NULL) {
				if (PTR->getUsername() == username) {
					TEMP = PTR;
				}
				PTR = PTR->next;
			}
			if (TEMP->getPassword() == password) {
			buyer:
				Order* order = new Order;

				system("cls");
				printName2();
				std::cout << "\t\t\t\t    01. Order a Product          -->\n" << std::endl;
				std::cout << "\t\t\t\t    02. Show Orders              -->\n" << std::endl;
				std::cout << "\t\t\t\t    03. Delete Order             -->\n" << std::endl;
				std::cout << "\t\t\t\t    04. Update Order             -->\n" << std::endl;
				std::cout << "\t\t\t\t    05. Change Account Settings  -->\n" << std::endl;
				std::cout << "\t\t\t\t    06. Delete Account           -->\n" << std::endl;
				std::cout << "\t\t\t\t    07. Goto Main Menu           -->\n\n" << std::endl;
				std::cout << "\t\t\t\t    Choose Your Choice : ";
				std::cin >> choise;
				switch (choise) {
				case 1:
					system("cls");
					printName2();
					p.showProducts2();
					if (p.head != NULL) {
						std::cout << "\n\t\t\t\tEnter Order ID : ";
						std::cin >> id;
						std::cout << "\n\t\t\t\tEnter Product ID to Order : ";
						std::cin >> proId;
						if (p.idExists(proId) != NULL) {
							Product* ptr = p.head;
							Product* temp = NULL;
							while (ptr != NULL) {
								if (ptr->getId() == proId) {
									temp = ptr;
								}
								ptr = ptr->next;
							}
							std::cout << "\n\t\t\t\tEnter Quantity : ";
							std::cin >> quantity;
							order->setBuyerId(TEMP->getId());
							order->setId(id);
							order->setProductId(proId);
							order->setProduct(temp->getName());
							order->setPrice(temp->getPrice());
							if (quantity > temp->getStock()) {
								std::cout << "\n\t\t\t\tNot enough products...";
							}
							else {
								order->setQuantity(quantity);
								order->setTotal(temp->getPrice() * quantity);
								o.insertOrder(order);
								temp->setStock(temp->getStock() - quantity);
							}
						}
						else {
							std::cout << "\n\t\t\t\tProduct Dosen't Exists...";
						}
					}
					system("pause>0");
					system("cls");
					goto buyer;
					break;
				case 2:
					system("cls");
					printName2();
					o.showOrders(TEMP->getId());
					system("pause>0");
					system("cls");
					goto buyer;
					break;
				case 3:
					system("cls");
					printName2();
					o.showOrders(TEMP->getId());
					if (o.head != NULL) {
						gotoxy(25, k + 2);
						std::cout << "Enter Order ID to Delete : ";
						std::cin >> id;
						o.deleteOrder(TEMP->getId(), id);
					}
					system("pause>0");
					system("cls");
					goto buyer;
					break;
				case 4:
					system("cls");
					printName2();
					o.showOrders(TEMP->getId());
					if (o.head->getBuyerId() != NULL) {
						gotoxy(25, k + 2);
						std::cout << "Enter Id of what Order do you want to Update : ";
						std::cin >> id;
						Order* ptr = o.idExists(id);
						if (ptr != NULL && ptr->getBuyerId() == TEMP->getId()) {
							std::cout << "\n\t\t\t\tEnter New Details : " << std::endl;
							std::cout << "\n\t\t\t\t  Enter Quantity : ";
							std::cin >> quantity;
							ptr->setQuantity(quantity);
							std::cout << "\n\t\t\t\tOrder Data Updated Successfully..." << std::endl;
						}
						else {
							std::cout << "\n\t\t\t\tOrder Doesn't exist with ID value : " << id << std::endl;
						}
					}
					system("pause>0");
					system("cls");
					goto buyer;
					break;
				case 5:
					system("cls");
					printName2();
					std::cout << "\n\t\t\t\t  ID : " << TEMP->getId() << std::endl;
					std::cout << "\n\t\t\t\t  Old Name : " << TEMP->getName() << std::endl;
					std::cout << "\n\t\t\t\t  Old Username : " << TEMP->getUsername() << std::endl;
					std::cout << "\n\t\t\t\t  Old Password : " << TEMP->getPassword() << std::endl;
					std::cout << "\n\n\t\t\t\t  Insert Your New Details : " << std::endl;
					std::cout << "\n\t\t\t\t  Enter Your Name : ";
					std::cin >> name;
					std::cout << "\n\t\t\t\t  Enter Your Username : ";
					std::cin >> username;
					std::cout << "\n\t\t\t\t  Enter Your Password : ";
					std::cin >> password;
					TEMP->setName(name);
					TEMP->setUsername(username);
					TEMP->setPassword(password);
					std::cout << "\n\t\t\t\tAccount Details Updated Successfully...";
					system("pause>0");
					goto buyer;
					break;
				case 6:
					system("cls");
					printName2();
					std::cout << "\n\t\t\t\tAre you sure Do you want to Delete Your Account : " << std::endl;
					std::cout << "\n\t\t\t\t01. Yes" << std::endl;
					std::cout << "\n\t\t\t\t02. No" << std::endl;
					std::cout << "\n\t\t\t\t    Choose Your Choice : ";
					int ch;
					std::cin >> ch;
					switch (ch) {
					case 1:
						s.deleteSeller(TEMP->getId());
						system("pause>0");
						system("cls");
						goto menu;
						break;
					case 2:
						system("cls");
						goto buyer;
						break;
					default:
						std::cout << "\n\t\t\t\tInvalid Option...Pleas Try Again..." << std::endl;
						system("pause>0");
						system("cls");
						goto buyer;
						break;
					}
					break;
				case 7:
					system("cls");
					goto menu;
					break;
				default:
					std::cout << "\n\n\t\t\t\t  Invalid Option.... " << std::endl;
					std::cout << "\n\t\t\t\t  Try Again -->>";
					system("pause>0");
					system("cls");
					goto buyer;
					break;
				}
			}
			else {
				std::cout << "\n\t\t\t\t  Password is Incorrect...";
				system("pause>0");
				system("cls");
				goto menu;
			}
		}
		else {
			std::cout << "\n\t\t\t\t  Username is Incorrect...";
			system("pause>0");
			system("cls");
			goto menu;
		}
		break;
	case 2:
		system("cls");
		printName2();
		std::cout << "\n\t\t\t\tSeller Account";
		std::cout << "\n\t\t\t\t==============\n";
		std::cout << "\n\t\t\t\t  Enter Username : ";
		std::cin >> username;
		std::cout << "\n\t\t\t\t  Enter Password : ";
		std::cin >> password;
		if (s.usernameExists(username) != NULL) {
			Seller* PTR = s.head;
			Seller* TEMP = NULL;
			while (PTR != NULL) {
				if (PTR->getUsername() == username) {
					TEMP = PTR;
				}
				PTR = PTR->next;
			}
			if (TEMP->getPassword() == password) {
			seller:
				Product* product = new Product();
				system("cls");
				printName2();
				std::cout << "\t\t\t\t==>> " << TEMP->getShopName() << " Shop <<==" << std::endl;
				std::cout << "\t\t\t\t======================================\n" << std::endl;
				std::cout << "\t\t\t\t 01. Insert a Product         -->\n" << std::endl;
				std::cout << "\t\t\t\t 02. Show Products            -->\n" << std::endl;
				std::cout << "\t\t\t\t 03. Delete Product           -->\n" << std::endl;
				std::cout << "\t\t\t\t 04. Update Product           -->\n" << std::endl;
				std::cout << "\t\t\t\t 05. Change Account Settings  -->\n" << std::endl;
				std::cout << "\t\t\t\t 06. Delete Account           -->\n" << std::endl;
				std::cout << "\t\t\t\t 07. Goto Main Menu           -->\n\n" << std::endl;
				std::cout << "\t\t\t\t Choose Your Choice : ";
				std::cin >> choise;
				switch (choise) {
				case 1:
					system("cls");
					printName2();
					std::cout << "\t\t\t\t  Enter Product ID : ";
					std::cin >> id;
					std::cout << "\n\t\t\t\t  Enter Product Category : ";
					std::cin >> category;
					std::cout << "\n\t\t\t\t  Enter Product Name : ";
					std::cin >> name;
					std::cout << "\n\t\t\t\t  Enter Product Stock : ";
					std::cin >> stock;
					std::cout << "\n\t\t\t\t  Enter Product Price : ";
					std::cin >> price;
					product->setSellerId(TEMP->getId());
					product->setId(id);
					product->setCategory(category);
					product->setName(name);
					product->setStock(stock);
					product->setPrice(price);
					p.insertProduct(product);
					system("pause>0");
					system("cls");
					goto seller;
					break;
				case 2:
					system("cls");
					printName2();
					p.showProducts(TEMP->getId());
					system("pause>0");
					system("cls");
					goto seller;
					break;
				case 3:
					system("cls");
					printName2();
					p.showProducts(TEMP->getId());
					if (p.head != NULL) {
						gotoxy(25, k + 2);
						std::cout << "Enter Product ID to Delete : ";
						std::cin >> id;
						p.deleteProduct(TEMP->getId(), id);
					}
					system("pause>0");
					system("cls");
					goto seller;
					break;
				case 4:
					system("cls");
					printName2();
					p.showProducts(TEMP->getId());
					if (p.head->getSellerId() != NULL) {
						gotoxy(25, k + 2);
						std::cout << "Enter Id of what Product do you want to Update : ";
						std::cin >> id;
						Product* ptr = p.idExists(id);
						if (ptr != NULL && ptr->getSellerId() == TEMP->getId()) {
							std::cout << "\n\t\t\t\tEnter New Details : " << std::endl;
							std::cout << "\n\t\t\t\t  Product Category : ";
							std::cin >> category;
							std::cout << "\n\t\t\t\t  Product Name : ";
							std::cin >> name;
							std::cout << "\n\t\t\t\t  Product Stock : ";
							std::cin >> stock;
							std::cout << "\n\t\t\t\t  Product Price : ";
							std::cin >> price;
							ptr->setCategory(category);
							ptr->setName(name);
							ptr->setStock(stock);
							ptr->setPrice(price);
							std::cout << "\n\t\t\t\tProduct Data Updated Successfully..." << std::endl;
						}
						else {
							std::cout << "\n\t\t\t\tProduct Doesn't exist with ID value : " << id << std::endl;
						}

					}
					system("pause>0");
					system("cls");
					goto seller;
					break;
				case 5:
					system("cls");
					printName2();
					std::cout << "\n\t\t\t\t  ID : " << TEMP->getId() << std::endl;
					std::cout << "\n\t\t\t\t  Old Name : " << TEMP->getName() << std::endl;
					std::cout << "\n\t\t\t\t  Old Username : " << TEMP->getUsername() << std::endl;
					std::cout << "\n\t\t\t\t  Old Password : " << TEMP->getPassword() << std::endl;
					std::cout << "\n\t\t\t\t  Old Shop Name : " << TEMP->getShopName() << std::endl;
					std::cout << "\n\n\t\t\t\t  Insert Your New Details : " << std::endl;
					std::cout << "\n\t\t\t\t  Enter Your Name : ";
					std::cin >> name;
					std::cout << "\n\t\t\t\t  Enter Your Username : ";
					std::cin >> username;
					std::cout << "\n\t\t\t\t  Enter Your Password : ";
					std::cin >> password;
					std::cout << "\n\t\t\t\t  Enter Your Shop Name : ";
					std::cin >> shopName;
					TEMP->setName(name);
					TEMP->setUsername(username);
					TEMP->setPassword(password);
					TEMP->setShopName(shopName);
					std::cout << "\n\t\t\t\tAccount Details Updated Successfully...";
					system("pause>0");
					goto seller;
					break;
				case 6:
					system("cls");
					printName2();
					std::cout << "\n\t\t\t\tAre you sure Do you want to Delete Your Account : " << std::endl;
					std::cout << "\n\t\t\t\t01. Yes" << std::endl;
					std::cout << "\n\t\t\t\t02. No" << std::endl;
					std::cout << "\n\t\t\t\t    Choose Your Choice : ";
					int ch;
					std::cin >> ch;
					switch (ch) {
					case 1:
						s.deleteSeller(TEMP->getId());
						p.deleteProduct2(TEMP->getId());
						system("pause>0");
						system("cls");
						goto menu;
						break;
					case 2:
						system("cls");
						goto seller;
						break;
					default:
						std::cout << "\n\t\t\t\tInvalid Option...Pleas Try Again..." << std::endl;
						system("pause>0");
						system("cls");
						goto seller;
						break;
					}
					break;
				case 7:
					system("cls");
					goto menu;
					break;
				default:
					std::cout << "\n\n\t\t\t\t  Invalid Option.... " << std::endl;
					std::cout << "\n\t\t\t\t  Try Again -->>";
					system("pause>0");
					system("cls");
					goto seller;
					break;
				}
			}
			else {
				std::cout << "\n\t\t\t\t  Password is Incorrect...";
				system("pause>0");
				system("cls");
				goto menu;
			}
		}
		else {
			std::cout << "\n\t\t\t\t  Username is Incorrect...";
			system("pause>0");
			system("cls");
			goto menu;
		}
		break;
	case 3:
		// Create Buyer Account
		system("cls");
		system("color F5");
		printName2();
		std::cout << "\t\t\t\t  Enter Buyer ID : ";
		std::cin >> id;
		std::cout << "\n\t\t\t\t  Enter Your Name : ";
		std::cin >> name;
		std::cout << "\n\t\t\t\t  Enter Your Username : ";
		std::cin >> username;
		std::cout << "\n\t\t\t\t  Enter Your Password : ";
		std::cin >> password;
		buyer->setId(id);
		buyer->setName(name);
		buyer->setUsername(username);
		buyer->setPassword(password);
		b.insertBuyer(buyer);
		system("pause>0");
		system("cls");
		goto menu;
		break;
	case 4:
		// Create Seller Account
		system("cls");
		system("color F5");
		printName2();
		std::cout << "\t\t\t\t  Enter Seller ID : ";
		std::cin >> id;
		std::cout << "\n\t\t\t\t  Enter Your Name : ";
		std::cin >> name;
		std::cout << "\n\t\t\t\t  Enter Your Username : ";
		std::cin >> username;
		std::cout << "\n\t\t\t\t  Enter Your Password : ";
		std::cin >> password;
		std::cout << "\n\t\t\t\t  Enter Your Shop Name : ";
		std::cin >> shopName;
		seller->setId(id);
		seller->setName(name);
		seller->setUsername(username);
		seller->setPassword(password);
		seller->setShopName(shopName);
		s.insertSeller(seller);
		system("pause>0");
		system("cls");
		goto menu;
		break;

	case 5:
		system("cls");
		printName1();
		exit(0);
		break;

	default:
		std::cout << "\n\n\t\t\t\t  Invalid Option.... " << std::endl;
		std::cout << "\n\t\t\t\t  Try Again -->>";
		system("pause>0");
		system("cls");
		goto menu;
		break;
	}
}