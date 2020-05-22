#include "exception.cpp"
#include "prods_in_storage.cpp"
#include <regex>
using namespace std;

class check_values{
private:	
	string product_name;
	int shelf_life;
	string place_order;
	int amount;
	int temperature;
	int humidity;	
public:
	string Prod_name_control(){
		cout << "enter product name: ";
		getline(cin, product_name);
		
		regex r("[^\\d\\W]+");
		if (!regex_match(product_name, r)) throw product_name_control("product's name wrong", product_name);
        
        return product_name;
    }
    
    int Self_life_control(){
		cout << "enter shelf_life: ";
		cin >> shelf_life;
		if (cin.fail()){
			cin.clear();
			cin.ignore(32767, '\n');
			throw self_life_control("shelf life consist only numbers");
		}
		if (shelf_life > 1000) throw self_life_control("shelf life must be under 1000!" );
        
        return shelf_life;
    }
    
    string Place_order_control(){
		regex r("([A-Z]){3}\\d{3}");
		cout << "enter place_order: ";
		getline(cin, place_order);
		if (!regex_match(place_order, r)) throw place_order_control("place order is wrong", place_order);

		return place_order;
    }
    
    int Amount_control(){
		cout << "enter amount: ";
		cin >> amount;
		if (cin.fail()){
			cin.clear();
			cin.ignore(32767, '\n');
			throw amount_control("amount consist only numbers");
		}
		if (amount > 1000) throw amount_control("amount must be under 1000");

        return amount;
    }
    
    int Temperature_control(){
		cout << "enter temperature: ";
		cin >> temperature;
		if (cin.fail()){
			cin.clear();
			cin.ignore(32767, '\n');
			throw temperature_control("temperature consist only numbers");
		}
		if (temperature > 100) throw temperature_control("temperature must be under 100");

        return temperature;
    }
    
    int Humidity_control(){
		cout << "enter humidity: ";
		cin >> humidity;
		if (cin.fail()){
			cin.clear();
			cin.ignore(32767, '\n');
			throw 0;
		}
		if (cin.fail()){
			cin.clear();
			cin.ignore(32767, '\n');
			throw humidity_control("humidity consist only numbers");
		}
		if (humidity > 100) throw humidity_control("humidity must be under 100");

        return humidity;
    }
	
};


int main(){
	try{
	
	check_values a;
	
	//int humidity = a.Humidity_control();	
	//int temperature = a.Temperature_control();
	//int self_life = a.Self_life_control();
	
	string prod_name = a.Prod_name_control();
	string place_order = a.Place_order_control();
	
	fruit apple;
	//apple.Construct_product("PB664", a.Amount_control(), 100, prod_name, 6, 12);		
	
	}
	catch (product_name_control &exp){
		cout<<"Problem is ("<<exp.what()<<")"<<endl;
		exp.return_name();
		
	}	
	catch (place_order_control &exp){
		cout<<"Problem is ("<<exp.what()<<")"<<endl;
		exp.return_place();
		
	}	
	catch (exception &exp){
		cout<<"Problem is ("<<exp.what()<<")"<<endl;		
	}
	
	return 0;
}


