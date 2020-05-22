#include <iostream>
#include <string>
#include <exception>
using namespace std;

class product_name_control: public exception{
private:
	string m_error;
	string prod_name;
public:
	product_name_control(string msg, string name):m_error(msg), prod_name(name){}	
	
	const char* what() const noexcept { return m_error.c_str(); }
	
	void return_name(){ cout<<"You inputed "<<prod_name<<" but it is wrong\n";}
};

class self_life_control: public exception{
private:
	string m_error;
public:
	self_life_control(string msg):m_error(msg){}	
	const char* what() const noexcept { return m_error.c_str(); }
};


class place_order_control: public exception{
private:
	string m_error;
	string place_order;
public:
	place_order_control(string msg, string place):m_error(msg), place_order(place){}	
	const char* what() const noexcept { return m_error.c_str(); }	
	void return_place(){ cout<<"You inputed "<<place_order<<" but it is wrong\n";}	
};

class amount_control: public exception{
private:
	string m_error;
public:
	amount_control(string msg):m_error(msg){}	
	const char* what() const noexcept { return m_error.c_str(); }
};

class temperature_control: public exception{
private:
	string m_error;
public:
	temperature_control(string msg):m_error(msg){}	
	const char* what() const noexcept { return m_error.c_str(); }		
};

class humidity_control: public exception{
private:
	string m_error;
public:
	humidity_control(string msg):m_error(msg){}	
	const char* what() const noexcept { return m_error.c_str(); }		
};
