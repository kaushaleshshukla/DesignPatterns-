class beverage {
public:
  string description = "Unknown Beverage";

  virtual string getDescription() { return description; }
  virtual float getCost() = 0;
};
