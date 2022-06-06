
#include <iostream>
#include "Interpolation.h"

int main(int argc,char *argv[])
{
    float ti = 0;
    float tf = 100;
    float t_step = 40;
    
    set_choreograph_lerp( ti,  tf , 10.f);
    step_advance(t_step);
    std::cout << get_lerp_value() << std::endl;

}