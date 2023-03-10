#include<iostream>

using namespace std; 

class notifier 
{
public:
	notifier() {};
	virtual void notify()=0;
	virtual void sendMessage()=0;
	virtual ~notifier() {};

};

class ApplicationNotifier : public notifier
{
public : 
	ApplicationNotifier() { cout << "The application creation" << endl; };
	~ApplicationNotifier() { cout << "The application death" << endl; };
	void notify() { cout << "send notification from the application" << endl; };
	void sendMessage() { cout << "sendMessage from the application" << endl; };

};

class notifierDecorator : public notifier
{
protected: 
	notifier *  _notifier;
public: 
	notifierDecorator(notifier* notifier) { _notifier = notifier; };
	void notify() { cout << "send notification from the Decorator" << endl; };
	virtual ~notifierDecorator() {};
	virtual void sendMessage() {};

};


class SmsNotifier : public notifierDecorator
{
public: 
	SmsNotifier(notifier* notifier):notifierDecorator(notifier) {};
	~SmsNotifier() {};
	void sendMessage() { _notifier->sendMessage(); cout << "send message from SMS" << endl; };
};

class EmailNotifier : public notifierDecorator
{
public:
	EmailNotifier(notifier* notifier) :notifierDecorator(notifier) {};
	~EmailNotifier() {};
	void sendMessage() { _notifier->sendMessage() ;  cout << "send message from Mailbox" << endl;};
};

class PostNotifier : public notifierDecorator
{
public:
	PostNotifier(notifier* notifier) :notifierDecorator(notifier) {};
	~PostNotifier() {};
	void sendMessage() { _notifier->sendMessage(); cout << "send message from Post" << endl;};
};

