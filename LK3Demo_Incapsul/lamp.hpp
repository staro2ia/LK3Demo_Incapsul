//
//  lamp.hpp
//  LK3Demo_Incapsul
//
//  Created by Павел Тимош on 04/10/2018.
//  Copyright © 2018 Павел Тимош. All rights reserved.
//

#ifndef lamp_hpp
#define lamp_hpp


class Lamp {
public:
    Lamp();
    Lamp(bool state, float brightness, int temperature);
    Lamp(const Lamp& lamp);
    
    Lamp operator= (const Lamp& lamp);
    
    bool state() const;
    float brightness() const;
    int temperature() const;
    
    void setTemperature(int t);
    void setBrightness(float b);
    
    void turnOn();
    void turnOff();
    
    
private:
    bool state_;
    float brightness_;
    int temperature_;
};

#endif /* lamp_hpp */
