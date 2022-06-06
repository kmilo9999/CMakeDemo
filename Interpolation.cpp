#include "Interpolation.h"
#include "choreograph/Choreograph.h"

ch::Timeline timeline;
ch::Output<float> target_float;

float lerp(float ti, float tf, float t )
{
  return ti + t * (tf-ti);
}

void set_choreograph_lerp(float ti, float tf, float duration)
{
     ch::Sequence<float> sequence_float(ti);
     sequence_float.then<ch::RampTo>(tf, duration);
     auto group = std::make_shared<ch::Timeline>();
     group->apply<float>(&target_float, sequence_float);
     timeline.addShared(group);
}

void step_advance(float t )
{
     timeline.step(1.0 / t);
}

float get_lerp_value()
{
    return target_float.value();
}