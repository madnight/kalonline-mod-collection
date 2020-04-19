#pragma warning(disable: 4996)

namespace Time
{
	const std::string GetHour() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%H", &tstruct);
		return buf;
	}

	const std::string GetTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%X", &tstruct);
		return buf;
	}

	const std::string GetDate() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
		return buf;
	}

	const std::string GetYear() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y", &tstruct);
		return buf;
	}

	const std::string GetMinute() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%M", &tstruct);
		return buf;
	}

	const std::string GetMonth() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%m", &tstruct);
		return buf;
	}

	const std::string GetDay() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%d", &tstruct);
		return buf;
	}

	const std::string GetDayName() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%A", &tstruct);
		return buf;
	}
}