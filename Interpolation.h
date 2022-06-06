#ifndef LERP_INCLUDE
#define LERP_INCLUDE

float lerp(float ti, float tf, float t );
void set_choreograph_lerp(float ti, float tf, float duration);
void step_advance(float t );
float get_lerp_value();

#endif