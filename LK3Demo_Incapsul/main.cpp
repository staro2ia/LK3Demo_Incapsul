//
//  main.cpp
//  LK3Demo_Incapsul
//
//  Created by Павел Тимош on 04/10/2018.
//  Copyright © 2018 Павел Тимош. All rights reserved.
//

#include <iostream>

using namespace std;

#include "lamp.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Lamp lamp1;
    
    lamp1.setTemperature(4000);
    lamp1.setBrightness(20);
    lamp1.turnOn();
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
