// Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments

// -  veena, guitar, sitar, sarod and mandolin under string()

// -  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()

// -  tabla, mridangam, bangos, drums and tambour under perc()

// It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows

// Type of instruments to be displayed

// a.  String instruments

// b.  Wind instruments

// c.  Percussion instruments

// The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.
#include <iostream>
#include <string>
#include <vector>

class Musician{
    protected:
        std::vector<std::string> string_instruments;
        std::vector<std::string> wind_instruments;
        std::vector<std::string> perc_instruments;
    public:
        void string(){
            string_instruments.push_back("veena");
            string_instruments.push_back("guitar");
            string_instruments.push_back("sitar");
            string_instruments.push_back("sarod");
            string_instruments.push_back("mandolin");

            print(string_instruments);
        }

        void wind(){
            wind_instruments.push_back("flute");
            wind_instruments.push_back("clarinet");
            wind_instruments.push_back("saxophone");
            wind_instruments.push_back("nadhaswaram");
            wind_instruments.push_back("piccolo");

            print(wind_instruments);
        }

        void perc(){
            perc_instruments.push_back("tabla");
            perc_instruments.push_back("mridangam");
            perc_instruments.push_back("bangos");
            perc_instruments.push_back("drums");
            perc_instruments.push_back("tambour");
            
            print(perc_instruments);
        }


        void print(std::vector<std::string> instruments) const{
            std::cout << "----------------" << std::endl;
            std::cout << "Instruments: " << std::endl;
            for(int i=0; i<instruments.size(); i++){
                std::cout << instruments[i] << std::endl;
            }
            std::cout << "----------------" << std::endl;
        }
};
  
class TypeIns: public Musician{
    public:
        void get() const {
            std::cout << "Type of instruments to be displayed" << std::endl;
            std::cout << "a. String instruments" << std::endl;
            std::cout << "b. Wind instruments" << std::endl;
            std::cout << "c. Percussion instruments" << std::endl;
        }

        void show(char choice) const{
            if (choice == 'a'){
                print(string_instruments);
            }
            else if (choice == 'b'){
                print(wind_instruments);
            }
            else if (choice == 'c'){
                print(perc_instruments);
            }
            else{
                std::cout << "Invalid choice" << std::endl;
            }
        }
};

int main(){
    TypeIns t;
    t.string();
    t.wind();
    t.perc();
    t.get();
    
    char choice;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    t.show(choice);
    return 0;
}