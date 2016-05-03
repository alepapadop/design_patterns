#include<iostream>
#include<string>

using namespace std;


// The 'Subject interface
class IMath
{
public:
  virtual double Add(double x, double y) = 0;
  virtual double Sub(double x, double y) = 0;
  virtual double Mul(double x, double y) = 0;
  virtual double Div(double x, double y) = 0;
};

// The 'RealSubject' class
class Math : public IMath
{
public:
  double Add(double x, double y)
  {
    return x + y;
  }
  double Sub(double x, double y)
  {
    return x - y;
  }
  double Mul(double x, double y)
  {
    return x * y;
  }
  double Div(double x, double y)
  {
    return x / y;
  }
};

// The 'Proxy Object' class
class MathProxy : public IMath
{
public:
  MathProxy()
  {
    math_ = NULL;
  }
  virtual ~MathProxy()
  {
    if(math_)
      delete math_;
  }
  double Add(double x, double y)
  {
    return getMathInstance()->Add(x, y);
  }
  double Sub(double x, double y)
  {
    return getMathInstance()->Sub(x, y);
  }
  double Mul(double x, double y)
  {
    return getMathInstance()->Mul(x, y);
  }
  double Div(double x, double y)
  {
    return getMathInstance()->Div(x, y);
  }
private:
  Math* math_;
  Math* getMathInstance(void)
  {
    if(!math_)
      math_ = new Math();
    return math_;
  }
};

//The Main method
int main()
{
  // Create math proxy
  MathProxy proxy;

  //Do the math
  cout<<"4 + 2 = "<<proxy.Add(4, 2)<<endl;
  cout<<"4 - 2 = "<<proxy.Sub(4, 2)<<endl;
  cout<<"4 * 2 = "<<proxy.Mul(4, 2)<<endl;
  cout<<"4 / 2 = "<<proxy.Div(4, 2)<<endl;

  return 0;
}
