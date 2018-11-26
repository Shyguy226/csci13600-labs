#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

using std::string;

class Time {
public:
  int h;
  int m;
};

enum Genre{ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
  string title;
  Genre genre;
  int duration;
};

class TimeSlot {
public:
  Movie movie;
  Time startTime;
};

void printTime (Time time) {
  std::cout << time.h << ":" << time.m;
}

void printMovie(Movie mv){
  string g;
  switch (mv.genre) {
  case ACTION : g = "ACTION"; break;
  case COMEDY : g = "COMEDY"; break;
  case DRAMA : g = "DRAMA"; break;
  case ROMANCE : g = "ROMANCE"; break;
  case THRILLER : g = "THRILLER"; break;
  }
  std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

int minutesSinceMidnight (Time time){
  int ans = 0;
  ans += time.m;
  ans += time.h*60;
  return ans;
}

int minutesUntil(Time earlier, Time later){
  int ans = 0;
  int early = minutesSinceMidnight(earlier);
  int late = minutesSinceMidnight(later);
  ans = late - early;
  return ans;
}

Time addMinutes(Time time0, int min){
  int newm = time0.m;
  int newh = time0.h;
  newm += min;
  newh += newm/60;
  newm = newm%60;
  Time ans {newh, newm};
  return ans;
}

void printTimeSlot(TimeSlot ts){
  printMovie(ts.movie);
  std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by ";
  Time end = addMinutes(ts.startTime, ts.movie.duration);
  std::cout << end.h << ":" << end.m << "]" << std::endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  Time time = addMinutes(ts.startTime, ts.movie.duration);
  TimeSlot ans {nextMovie, time};
  return ans;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  if(minutesUntil(ts1.startTime,ts2.startTime) <= 0){
    if(minutesUntil(addMinutes(ts2.startTime, ts2.movie.duration), ts1.startTime) < 0)
      return true;
  }
  else {
    if(minutesUntil(addMinutes(ts1.startTime, ts1.movie.duration), ts2.startTime) < 0)
      return true;
  }
  return false;
}
