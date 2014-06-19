//
//  Timer.h
//  BallGame
//

#ifndef __BasicGameEngine__Timer__
#define __BasicGameEngine__Timer__

#include <sstream>
#include <stdint.h>

using namespace std;

namespace BGengine
{
	class Timer
	{
	private:
		int startTicks;
		int pauseTicks;
        
		bool paused;
		bool started;
        
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void resume();
		int getTicks();
        
		bool isStarted();
		bool isPaused();
		~Timer();
	};
    
} // namespace BGengine

#endif /* defined(__BasicGameEngine__Timer__) */
