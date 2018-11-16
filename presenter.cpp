#include <iostream>

int main(){
    std::string line;
    while (std::getline(std::cin,line)) {
        std::cout<<"hey:"<<line<<std::endl;
    }
    std::cout<<"closed :|"<<std::endl;
}
