
// Interface that all quacking behavior classes implements
class quackingBehavior{
public:
	virtual void sound() = 0;
};

class mute : public quackingBehavior{
public:
	void sound(){
		cout<<"Silence"<<endl;
	}
};

class quack : public quackingBehavior{
public:
	void sound(){
		cout<<"Quack Quack"<<endl;
	}
};

class squeak : public quackingBehavior{
public:
	void sound(){
		cout<<"Squeak"<<endl;
	}
};