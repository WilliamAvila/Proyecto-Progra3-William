#include "Meteor.h"

Meteor::Meteor(int x, int y)
{
    this->x=x;
    this->y= y;
    this->image=IMG_Load("Enemies/meteor.png");
    //ctor
}

Meteor::~Meteor()
{
    //dtor
}


void Meteor :: move(){

this->y--;



}



