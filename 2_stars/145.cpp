#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int start_h, start_m, end_h, end_m;		//通話開始與結束的時間
int start_time, end_time;				//通話開始與結束的時間 以分鐘為單位
double day_rate['E'+1]	   = {0};
double evening_rate['E'+1] = {0};
double night_rate['E'+1]   = {0};
bool cross_day;							//通話開始時間與結束時間是否有跨越 24:00

void setRate()
{
	day_rate['A'] = 0.1;
	day_rate['B'] = 0.25;
	day_rate['C'] = 0.53;
	day_rate['D'] = 0.87;
	day_rate['E'] = 1.44;
	evening_rate['A'] = 0.06;
	evening_rate['B'] = 0.15;
	evening_rate['C'] = 0.33;
	evening_rate['D'] = 0.47;
	evening_rate['E'] = 0.8;
	night_rate['A'] = 0.02;
	night_rate['B'] = 0.05;
	night_rate['C'] = 0.13;
	night_rate['D'] = 0.17;
	night_rate['E'] = 0.3;
}

//通話時間是否有跨越 24:00
bool crossDay()
{
	if ((end_time) - (start_time) > 0)
		return false;
	else
		return true;
}

//打電話用的所有時間
int totalTime()
{
	int time = end_time - start_time;
	if (cross_day)
		return 1440 + time;
	else
		return time;
}

//通話開始時間與結束時間在 start 與 end 所形成的時間區間內的分布情況
int timeCase(int start, int end)
{
	int small = (cross_day) ? (end_time) : (start_time);
	int large = (cross_day) ? (start_time) : (end_time);

	if (small<=start && large>=end)
		return 3;		//not in time interval, one <= start, another >= end
	else if (start<=small && end>=small && start<=large && end>=large)
		return 0;		//middle
	else if (small<start && large>start && large<end)
		return 1;		//lower
	else if (small<end && small>start && large>end)
		return 2;		//upper
	else
		return -1;		//not in time interval, both <= start or both >= end
}

//取得通話時間在 day 以及 evening 區域有多長
int getTime(int intv_start, int intv_end)
{
	int interval = intv_end - intv_start;
	switch (timeCase(intv_start, intv_end)) {
		case -1:
			return (cross_day) ? (interval) : (0);
		case 0:
			return (cross_day) ? (interval - (start_time-end_time)) : (end_time - start_time);
		case 1:
			return (cross_day) ? (interval - (start_time-intv_start)) : (end_time - intv_start);
		case 2:
			return (cross_day) ? (interval - (intv_end-end_time)) : (intv_end - start_time);
		case 3:
			return (cross_day) ? (0) : (interval);
	}
}

int main()
{
	char distance;
	setRate();
	while ((cin >> distance), distance != '#') {
		string phone_number;

		cin >> phone_number >> start_h >> start_m >> end_h >> end_m;

		end_time   = end_h*60 + end_m;
		start_time = start_h*60 + start_m;
		
		cross_day = crossDay();

		int day_time	 = getTime(480, 1080);
		int evening_time = getTime(1080, 1320);
		int night_time	 = totalTime() - (evening_time+day_time);
		double money = day_time     * day_rate[distance] +
					   evening_time * evening_rate[distance] +
					   night_time   * night_rate[distance];
		
		cout.width(10);
		cout << phone_number;
		cout.width(6);
		cout << day_time;
		cout.width(6);
		cout << evening_time;
		cout.width(6);
		cout << night_time;
		cout.width(3);
		cout << distance;
		cout.width(8);
		cout << fixed << setprecision(2) << money << endl;
	}

	return 0;
}