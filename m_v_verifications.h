using namespace std;
bool format_mode_exists(string mode) {
	if (mode == "speed0") {
		return true;
	}
	if (mode == "disk0") {
		return true;
	}
	return false;
}