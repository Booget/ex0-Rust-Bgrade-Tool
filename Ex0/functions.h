#pragma once

namespace functions
{
	void query_sleep(int ms);
	void move_mouse(double speed, float x, float y);
	void sendKeyPress();
	float convert(float usersens, int fov, float val);

	namespace misc {
		void log(std::string text);
	}
}
