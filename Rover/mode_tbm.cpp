#include "mode.h"
#include "Rover.h"

bool ModeTBM::_enter()
{
    stop_vehicle();

    // for test 
    do_state = false;
    do_start_time = 0;

    return true;
}

void ModeTBM::update()
{
    do_state = false;

    stop_vehicle();

    if(do_start_time == 0)
    {
        do_start_time = millis();
    }

    hal.console->printf("do ");
 
    if(millis() - do_start_time > 5000)
    {
        hal.console->print("\n");
        do_state = true;
        hal.console->printf("finish do something\n");

        do_start_time = 0;
    }

    if(finish_do_something())
    {
        rover.set_mode(rover.mode_auto, ModeReason::GCS_COMMAND);
    }
}

bool ModeTBM::finish_do_something()
{   
    bool ret = false;

    if(do_state)
    {
        ret = true;
        do_state = false;
    }

    return ret;
}

void ModeTBM::_exit()
{

}
