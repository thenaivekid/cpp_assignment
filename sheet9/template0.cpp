	
#include<iostream>

using namespace std;



//function template printArray definition

template <typename T>

void printArray(T *array,int count)

{

    for(int i=0; i<count; i++)

        cout<<array[i]<<" "<<endl;

}

//end of the function



int main()

{

    int a[4]= {1,2,3,4};

    double b[5]= {1.1,2.2,3.3,4.4,5.5};

    char c[6]= "Hello";

    cout<<" Array a contains: "<<endl;

    printArray(a,4);

    cout<<" Array b contains: "<<endl;

    printArray(b,5);

    cout<<" Array c contains: "<<endl;

    printArray(c,6);

    return 0;

}