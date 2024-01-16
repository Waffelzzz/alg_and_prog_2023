#include <vector>
#include <algorithm>
#include <iomanip>

class Clock : public IClock, public IRunnable {
private:
    struct Event {
        IRunnable* client;
        Time time;
        bool operator<(const Event& other) const {
            return time < other.time;
        }
    };

    std::vector<Event> events;

public:
    void add(IRunnable* client, Time time) override {
        Event event = { client, time };
        events.push_back(event);
        std::sort(events.begin(), events.end());
    }

    bool next() override {
        if (events.empty()) {
            return false;
        }

        Event nextEvent = events.front();
        events.erase(events.begin());

        std::cout << std::setfill('0') << std::setw(2) << nextEvent.time.hours << ":"
            << std::setw(2) << nextEvent.time.minutes << ":"
            << std::setw(2) << nextEvent.time.seconds << " ";
        nextEvent.client->run();

        return true;
    }

    void run() override {
        while (next()) {
            // Keep processing events until there are no more events.
        }
    }
};

class OSUpdater : public IRunnable {
public:
    void run() override {
        std::cout << "OSUpdater" << std::endl;
    }
};

class Alarm : public IRunnable {
public:
    void run() override {
        std::cout << "Alarm" << std::endl;
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() override {
        std::cout << "ActivityChecker" << std::endl;
    }
};
