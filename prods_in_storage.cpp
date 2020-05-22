#include <string>
#include <vector>
#include <iostream>
using namespace std;

class abstract_product {
protected:
	string product_name;
	int shelf_life;
	string place_order;
	int amount;
	int temperature;
	int humidity;
public:
	virtual void Storage_form(int temperature, int humidity) = 0;
	
	//constructor
	void Construct_product(string placeOrder, int amoUnt, int shelfLife, string name, int temp, int humi) {
		place_order = placeOrder;
		amount = amoUnt;
		shelf_life = shelfLife;
		product_name = name;
		temperature = temp;
		humidity = humi;
	}	
	
	//destructor
	~abstract_product(){cout<<"\ndestructor(abstract_product) is called"<<endl;}
	
	//setter
	void Place_order(string placeOrder) { place_order = placeOrder; }
	void Amount(int amoUnt) { amount = amoUnt; }
	void ShelfLife(int shelfLife) { shelf_life = shelfLife; }
	void Product_name(string name) { product_name = name; }
	void Temperature(int temp) { temperature = temp; }
	void Humidity(int humi) { humidity = humi; }
	
	//getter
	int GetTemperature() { return temperature; }
	int GetHumidity() { return humidity; }
	int GetAmount() { return amount; }
	int GetShelfLife() { return shelf_life; }
	string GetProductName() { return product_name; }
};


class meat : public abstract_product {

public:
	//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};


class milk_product : public abstract_product {

public:


	//virtual function that keeps products fresh
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity<<" and special control";
	}

};


class fruit : public abstract_product {

public:
//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};

class vegetable : public abstract_product {

public:
//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};

class spices : public abstract_product {

public:
	//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};


class groats : public abstract_product {
public:
	//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};


class drink : public abstract_product {

public:
	//virtual function that keeps products fresh 
	void Storage_form(int temperature, int humidity) override {
		cout << "special temperature " << temperature << " and humidity " << humidity << " and special control";
	}

};


class storage {
private:
	//using pointers because type is abstract
	vector<abstract_product*> prod_in_storage;
public:
	void prods_in_storage(abstract_product* product) {
		prod_in_storage.push_back(product);

	}
	vector<abstract_product*> Products() { return prod_in_storage; }
};


/*
int main() {
	
	fruit apple;
	apple.Construct_product("PB664", 23, 100, "Apple", 6, 12);
	vegetable cucumber;
	cucumber.Construct_product("PB098", 76, 45, "Cucumber", 7, 23);
	
	//using pointers because type is abstract	
    storage stor;
	stor.prods_in_storage(&cucumber);
	stor.prods_in_storage(&apple);	
	vector<abstract_product*> prod_in_storage = stor.Products();
    
    //iterator for vector
    for(vector<abstract_product*>:: iterator p = prod_in_storage.begin(); p!=prod_in_storage.end(); p++){
        string name = (*p) -> GetProductName();
        cout << name<<endl;
    }

	return 0;
}
*/


