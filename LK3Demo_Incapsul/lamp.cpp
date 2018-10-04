//
//  lamp.cpp
//  LK3Demo_Incapsul
//
//  Created by Павел Тимош on 04/10/2018.
//  Copyright © 2018 Павел Тимош. All rights reserved.
//

#include "lamp.hpp"

Lamp::Lamp()
    : state_(false), brightness_(100), temperature_(2700)
{ }

Lamp::Lamp(bool state, float brightness, int temperature)
    : state_(state), brightness_(brightness), temperature_(temperature)
{ }

Lamp::Lamp(const Lamp& lamp)
    : state_(lamp.state_), brightness_(lamp.brightness_), temperature_(lamp.temperature_)
{ }

Lamp Lamp::operator= (const Lamp& lamp){
    this->state_ = lamp.state_;
    this->brightness_ = lamp.brightness_;
    this->temperature_ = lamp.temperature_;
    
    return *this;
}

bool Lamp::state() const{
     return this->state_;
}

float Lamp::brightness() const {
     return this->brightness_;
}

int Lamp::temperature() const{
    return this->temperature_;
}

void Lamp::setTemperature(int t) {
    
}

void Lamp::setBrightness(float b) {
    
}

void Lamp::turnOn() {
    state_ = true;
}

void Lamp::turnOff() {
    state_ = false;
}
