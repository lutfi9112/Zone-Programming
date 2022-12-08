#include<iostream>
#include"Presint11.h"
#define print(x) std::cout<<x<<std::endl

std::ostream& operator<<(std::ostream& os, const Vec2d& v) {
    return os << '{' << v.x << ',' << v.y << '}';
}

int main() {

    Presint11B* presint11b = new Presint11B();
    print(presint11b->isInside(Vec2d(2.960661314162164, 101.69116531504184)));

    
    
    
    
    
    

    

    

    
    
    

    
    
    
    delete presint11b;
    return 0;
}