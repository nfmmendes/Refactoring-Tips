#include <iostream>
#include <cmath>
#include <cassert>

/**
 * @brief This function calculates how much an event is outside a time window. 
 * @param time_window_begin The time window start moment.
 * @param time_window_end The time window end moment.
 * @param event_time The moment when the event happens
 */
void time_window_deviation(int time_window_begin, int time_window_end, int event_time){
	int total_deviation = 0;
	
	// Standard approach 
	if(event_time < time_window_begin)
		total_deviation += time_window_begin - event_time; 
	if(event_time > time_window_end)
		total_deviation += event_time - time_window_end;

	// Shorter code
	// In this way we avoid a 'if' command repetition and we are sure that only 
	// non negative values are added to total deviation. If we use it two evaluate
	// two time window extremities we can avoid writting 4 lines of code.
	int recalculated_total_deviation = 0;
	recalculated_total_deviation += std::max(0, time_window_begin - event_time); 
	recalculated_total_deviation += std::max(0, event_time - time_window_end); 
	
	assert(recalculated_total_deviation == total_deviation); 
}

int main() { 

	time_window_deviation(3, 5, 7);
	time_window_deviation(3, 4, 4);
	time_window_deviation(3, 9, 7);
	time_window_deviation(1, 5, 4);
	time_window_deviation(2, 8, 3);
	time_window_deviation(2, 4, 1);

	return 0; 
}