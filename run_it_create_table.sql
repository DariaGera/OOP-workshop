CREATE TABLE dish (
    dish_name VARCHAR2(100) NOT NULL,
	CONSTRAINT dish_pk PRIMARY KEY (dish_name)
);

CREATE TABLE storage (
    product       VARCHAR2(50) NOT NULL,
    amount        VARCHAR2(20) NOT NULL,
    temperature   VARCHAR2(10),
    humidity      VARCHAR2(10),
	CONSTRAINT storage_pk PRIMARY KEY (product)
);


CREATE TABLE recipe (
    dish_name   VARCHAR2(100) NOT NULL,
    product     VARCHAR2(50) NOT NULL,
    amount      VARCHAR2(20) NOT NULL,
	CONSTRAINT recipe_dish_fk FOREIGN KEY ( dish_name ) REFERENCES dish ( dish_name ),
	CONSTRAINT recipe_storage_fk FOREIGN KEY ( product ) REFERENCES storage ( product ),
	CONSTRAINT recipe_pk PRIMARY KEY (dish_name, product )
);

CREATE TABLE table_res (
    table_number   INTEGER NOT NULL,
    place_amount   INTEGER NOT NULL,
    status         CHAR(1) NOT NULL,
	CONSTRAINT table_pk PRIMARY KEY ( table_number )
);

CREATE TABLE client (
    identifier     VARCHAR2(10) NOT NULL,
    table_number   INTEGER NOT NULL,
	CONSTRAINT client_table_fk FOREIGN KEY ( table_number ) REFERENCES table_res ( table_number ),
	CONSTRAINT client_pk PRIMARY KEY ( identifier )
);
				
CREATE TABLE menu (
    dish_name   VARCHAR2(100) NOT NULL,
    price       FLOAT NOT NULL,
	CONSTRAINT menu_dish_fk FOREIGN KEY ( dish_name ) REFERENCES dish ( dish_name ),
	CONSTRAINT menu_pk PRIMARY KEY ( dish_name )
);
		
CREATE TABLE client_order (
    identifier   VARCHAR2(10) NOT NULL,
    date_time     DATE NOT NULL,
    dish_name    VARCHAR2(100) NOT NULL,
	CONSTRAINT order_client_fk FOREIGN KEY ( identifier ) REFERENCES client ( identifier ),
	CONSTRAINT order_menu_fk FOREIGN KEY ( dish_name ) REFERENCES menu ( dish_name ),
	CONSTRAINT order_pk PRIMARY KEY ( date_time, identifier )
);




