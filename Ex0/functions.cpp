#include "includes.h"

void functions::query_sleep(int ms) {
    LONGLONG timer_resolution;
    LONGLONG wanted_time;
    LONGLONG current_time;

    QueryPerformanceFrequency((LARGE_INTEGER*)&timer_resolution);
    timer_resolution /= 1000;

    QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
    wanted_time = current_time / timer_resolution + ms;
    current_time = 0;
    while (current_time < wanted_time) {
        QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
        current_time /= timer_resolution;
    }
}

void functions::move_mouse(double speed, float x, float y) {
    int x_ = 0, y_ = 0, t_ = 0;
    for (int i = 1; i <= (int)speed; ++i) {
        int xI = i * x / (int)speed;
        int yI = i * y / (int)speed;
        int tI = i * (int)speed / (int)speed;
        mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
        query_sleep((int)tI - (int)t_);
        x_ = xI;
        y_ = yI;
        t_ = tI;
    }
    query_sleep((int)speed);
}

void functions::sendKeyPress()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void functions::send_keyb_event(int key)
{
    WORD keyCode;

    switch (key)
    {
    case 0:
        keyCode = 0x30;
        break;
    case 1:
        keyCode = 0x31;
        break;
    case 2:
        keyCode = 0x32;
        break;
    case 3:
        keyCode = 0x33;
        break;
    case 4:
        keyCode = 0x34;
        break;
    case 5:
        keyCode = 0x35;
        break;
    case 6:
        keyCode = 0x36;
        break;
    case 7:
        keyCode = 0x37;
        break;
    case 8:
        keyCode = 0x38;
        break;
    case 9:
        keyCode = 0x39;
        break;
    }

    keybd_event(keyCode, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
}

float functions::convert(float usersens, int fov, float val)
{
    float a = (0.5 * fov * val) / (usersens * 90);

    return a;
}

