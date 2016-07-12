#pragma once
#include "settings.h"
#include <map>
#include <vector>
#include <thread>

using namespace std;

class Switcher {
public:
	bool getIsRunning();
	void firstLoad();
	void load();
	void start();
	void stop();
	void openUI();
	string getSettingsFilePath();
	void setSettingsFilePath(string path);
	thread switcherThread;
private:
	bool isRunning = true;
	Settings settings;
	map<string, Data> settingsMap;
	vector<string> sceneRoundTrip;
	void switcherThreadFunc();
	bool isWindowFullscreen();
	string GetActiveWindowTitle();
};