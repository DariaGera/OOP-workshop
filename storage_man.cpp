#include "prods_in_storage.cpp"
#include "interface.cpp"
using namespace std;


class storage_man: public Ideleter, public Iadder{
private:
	vector<abstract_product*> prod_in_storage;
	
public:
	void check_storage(storage & storr){
		prod_in_storage = storr.Products();
	}
	
	//delete_rotten
	void delete_item() override{
		string rotten;
		

		cout << "enter rotten product: ";
		cin >> rotten;
		for(vector<abstract_product*>:: iterator p = prod_in_storage.begin(); p!=prod_in_storage.end(); p++){			
			if ((*p) -> GetProductName() == rotten){
				int amount;
				int in_stor = (*p) -> GetAmount();

				cout << "enter amount: ";
				cin >> amount;	
				if (in_stor > amount) {in_stor -= amount; cout<<"must be "<<in_stor<<"\nbut ";}
				else cout<<"delete the whole product";
			}	
		}
		//for apple
		cout << prod_in_storage[0] -> GetAmount()<<endl;
	}
	//order_item
	void add_item() override{	
		string order;
		cout << "enter order product: ";
		cin >> order;
		for(vector<abstract_product*>:: iterator p = prod_in_storage.begin(); p!=prod_in_storage.end(); p++){			
			if ((*p) -> GetProductName() == order){
				int amount;
				int in_stor = (*p) -> GetAmount();
				cout << "enter amount: ";
				cin >> amount;	
				in_stor += amount;
			}
			else cout<<"add new product";
		}
	}
	vector<abstract_product*> Products(){return prod_in_storage;}
};

int main(){
//--------------------------------------------------------------------------------------------------------------------	
	fruit apple;
	apple.Construct_product("PB664", 23, 100, "Apple", 6, 12);
	vegetable cucumber;
	cucumber.Construct_product("PB098", 76, 45, "Cucumber", 7, 23);
	
	//using pointers because type is abstract	
    storage stor;	
	stor.prods_in_storage(&apple);
	stor.prods_in_storage(&cucumber);	
	vector<abstract_product*> prod_in_storage = stor.Products();
    
    //iterator for vector
    for(vector<abstract_product*>:: iterator p = prod_in_storage.begin(); p!=prod_in_storage.end(); p++){
        string name = (*p) -> GetProductName();
        cout << name<<endl;
    }	
//------------------------------------------------------------------------------------------------------------------------
	storage_man robo;
	robo.check_storage(stor);
	robo.delete_item();
	vector<abstract_product*> k = robo.Products();

	return 0;
}







