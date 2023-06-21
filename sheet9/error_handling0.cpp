#include<iostream>

using namespace std;

class ex_demo

{

private:

    int a;

    int b;

public:

    ex_demo() {}

    class DIVIDE {}; //abstract class for exception

    void getdata()

    {

        cout<<"Enter dividend and divisor:"<<endl;

        cin>>a>>b;

    }

    void divide()

    {

        if(b!=0)

        {

            cout<<"Result(A/B) = "<<a/b<<endl;

        }

        else

        {

            throw DIVIDE();

        }

    }

};

int main()

{

    ex_demo ex;

    ex.getdata();

    try

    {

        ex.divide();

    }

    catch(ex_demo::DIVIDE)

    {

        cout<<"Exception: Divide Error"<<endl;

    }

    return 0;

}

