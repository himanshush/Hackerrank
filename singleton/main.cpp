#include <iostream>

using namespace std;

class singletonClass public
{
public:
    static singletonClass* getInstance();
private:
    static singletonClass* p_Instance;
    singletonClass(){}; //private so not able to call
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
