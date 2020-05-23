
// Interface that all flying behavior classes implements
class flyingBehavior{
public:
	virtual void fly() = 0;
};

class flyWithWings : public flyingBehavior{
	void fly(){
		cout<<"I'm flying with Wings"<<endl;
	}
};

class flyLikeRocket : public flyingBehavior{
	void fly(){
		cout<<"I can fly like Rocket"<<endl;
	}
}

class noFly : public flyingBehavior{
	void fly(){
		cout<<"I can't fly"<<endl;
	}
}

