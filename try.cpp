#include <iostream>
#include <malloc.h>
#include <string>
#include <list>
using namespace std;

// інтерфейси

class Iworker{
	public:
		void virtual do_work() = 0;
};


class chef: public Ideleter, public Iadder, public Iworker{
	public:	
		void do_work() override{
			//time_cooking, get_dish_name
			cout<<"chef: do_work I am very good worker and i do some work"<<endl;
		}	
};

class waiter: public Ideleter, public Iworker{
	public:
		void do_work() override{ //do_work(int status)

			// status = 0 - give_menu; status = 1 - give_cheque 
			cout<<"waiter: do_work I am very good worker and i do some work"<<endl;	
		}		
};

int main(){
   
    
    cout<<"CHEF"<<endl;
    chef robo_2;
    robo_2.do_work();  
    
    
    
    cout<<"WAITER"<<endl;
    waiter robo_3;
    robo_3.do_work();      
      
	
return 0;	
}

