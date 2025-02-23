// Target Interface
class Duck 
{
    public:
        void quack() = 0;
        void fly() = 0;
};

// Adaptee
class Turkey 
{
    public:
        void gobble() = 0;
        void fly() = 0;
};

class WildTurkey : public Turkey
{
    public:
        void gobble() { std::cout<<"Gobble Gobble"<<endl; }
        void fly() { std::cout<< "I'm flying short distance"<<endl;}
};

// Object Adapter
class TurkeyAdapter : public Duck
{
    public:
        void quack() { turkey.gobble(); }
        void fly() { turkey.fly(); }

    private:
        Turkey turkey;
};