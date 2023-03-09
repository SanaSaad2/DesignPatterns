#include<iostream>

class IQuackBehavior
{
public:
	IQuackBehavior() { std::cout << "IQuackBehavior constructor " << std::endl; }
	virtual void quack() = 0;
	virtual ~IQuackBehavior() {};
};

class IFlyBehavior
{
public:
	IFlyBehavior() { std::cout << "IFlyBehavior constructor " << std::endl; }
	virtual void fly() = 0;
	virtual ~IFlyBehavior() {};
}
;
class ISwimBehavior
{
public:
	ISwimBehavior() { std::cout << "ISwimBehavior constructor " << std::endl; }
	virtual void Swim() = 0;
	virtual ~ISwimBehavior() {};

};

// Types of quacking or not 

class SimpleQuack : public IQuackBehavior
{
public:
	SimpleQuack() { std::cout << "SimpleQuack constructor " << std::endl; }
	void quack() { std::cout << "the simple QuackBehavior" << std::endl; };
	~SimpleQuack() { std::cout << "SimpleQuack destructor " << std::endl; };
};


class NoQuack : public IQuackBehavior
{
public:
	NoQuack() { std::cout << "NoQuack constructor " << std::endl; }
	void quack() { std::cout << "No QuackBehavior" << std::endl; };
	~NoQuack(){ std::cout << "NoQuack destructor " << std::endl; }
}
;

//  Types of flying or not


class SimpleFlying : public IFlyBehavior
{
public:
	SimpleFlying():IFlyBehavior() { std::cout << "SimpleFlying constructor " << std::endl; }
	void fly() { std::cout << "the simple flyBehaviour" << std::endl; };
	~SimpleFlying(){ std::cout << "SimpleFlying destructor " << std::endl; }
};


class Nofly : public IFlyBehavior
{
public:
	Nofly() :IFlyBehavior() { std::cout << "Nofly constructor " << std::endl; }
	void fly() { std::cout << "No FlyBehavior" << std::endl; };
	~Nofly(){ std::cout << "NoFly destructor " << std::endl; }
};



//  Types of Swiming or not

class SimpleSwiming : public ISwimBehavior
{
public:
	SimpleSwiming(): ISwimBehavior() { std::cout << "SimpleSwiming constructor " << std::endl; }
	void Swim() { std::cout << "the simple SwimBehaviour " << std::endl; };
	~SimpleSwiming(){ std::cout << "SimpleSwiming destructor " << std::endl; }
};

class NoSwim: public ISwimBehavior
{
public:
	NoSwim():ISwimBehavior(){ std::cout << "NoSwim constructor " << std::endl; }
	void Swim() { std::cout << "No SwimBehaviour " << std::endl; };
	~NoSwim(){ std::cout << "NoSwim called " << std::endl; }
};


// Context 

class Duck
{
private : 

	std::unique_ptr<IQuackBehavior> qb;
	std::unique_ptr<IFlyBehavior>  fb;
	std::unique_ptr<ISwimBehavior> db;

public:

	/*

	************************Constructors**********************************************************

	*/
	
	//constructeur par deplacement 
	
	Duck(std::unique_ptr<IQuackBehavior>&& _qb, std::unique_ptr<IFlyBehavior>&& _fb, std::unique_ptr<ISwimBehavior>&& _db)
	{
		std::cout << "Duck constructeur par deplacement" << std::endl;
		qb = std::move(_qb);
		fb = std::move(_fb);
		db = std::move(_db);

	};
	
	//constructeur par defaut 
	Duck() = delete; 

	//constructeur par copie 
	Duck(const Duck & ) = delete;
	/*
	************************Operators**********************************************************

	*/

	/*
	
	************************Getters**********************************************************
	
	*/

	const std::unique_ptr<IQuackBehavior>   &		 getQuackingBehavior()  const { return this->qb; };
	const std::unique_ptr<IFlyBehavior>     &		 getFlyingBehavior()    const { return this->fb; };
	const std::unique_ptr<ISwimBehavior> &			 getSwimmingBehavior()  const { return this->db; };


	/*

	************************Setters**********************************************************

	*/


	void set_quackType(std::unique_ptr<IQuackBehavior>& _quack)			{ this->qb=std::move(_quack); };
	void set_flyType(std::unique_ptr<IFlyBehavior>& _fly)				{ this->fb = std::move(_fly); };
	void set_SwimType(std::unique_ptr<ISwimBehavior>& _Swim)			{ this->db = std::move(_Swim); };
	

	virtual ~Duck()
	{
		std::cout << "destructorDuck called " << std::endl;
	}


};


int main()
{
	Duck NoQuackingFlyingSwimingDuck(std::make_unique<NoQuack>(), std::make_unique<SimpleFlying>(), std::make_unique<SimpleSwiming>());
	
	(NoQuackingFlyingSwimingDuck.getSwimmingBehavior())->Swim();
	(NoQuackingFlyingSwimingDuck.getFlyingBehavior())->fly();
	(NoQuackingFlyingSwimingDuck.getQuackingBehavior())->quack();

	return 0;
}

//cons and pros 