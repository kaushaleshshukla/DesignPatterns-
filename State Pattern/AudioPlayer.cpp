#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Forward declaration so State can reference the Context
class AudioPlayer;

// 1. STATE INTERFACE
class State {
protected:
    AudioPlayer* player;
public:
    State(AudioPlayer* p) : player(p) {}
    virtual ~State() = default;

    virtual void clickLock()     = 0;
    virtual void clickPlay()     = 0;
    virtual void clickNext()     = 0;
    virtual void clickPrevious() = 0;
    virtual std::string name() const = 0;
};

// 2. CONTEXT
class AudioPlayer {
private:
    std::unique_ptr<State> currentState;
    std::vector<std::string> playlist{"Song A", "Song B", "Song C"};
    int currentIndex = 0;
    bool playing = false;

public:
    AudioPlayer();   // sets initial ReadyState (defined after states)

    void changeState(std::unique_ptr<State> next) {
        std::cout << "  [transition -> " << next->name() << "]\n";
        currentState = std::move(next);
    }

    // Delegate user input to whatever state is active
    void clickLock()     { currentState->clickLock(); }
    void clickPlay()     { currentState->clickPlay(); }
    void clickNext()     { currentState->clickNext(); }
    void clickPrevious() { currentState->clickPrevious(); }

    // Service methods that states can call
    void startPlayback() {
        playing = true;
        std::cout << "Playing: " << playlist[currentIndex] << "\n";
    }
    void stopPlayback() {
        playing = false;
        std::cout << "Stopped: " << playlist[currentIndex] << "\n";
    }
    void nextSong() {
        currentIndex = (currentIndex + 1) % playlist.size();
        std::cout << "Next -> " << playlist[currentIndex] << "\n";
    }
    void previousSong() {
        currentIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
        std::cout << "Prev -> " << playlist[currentIndex] << "\n";
    }
    bool isPlaying() const { return playing; }
};

// 3. CONCRETE STATES
class LockedState : public State {
public:
    LockedState(AudioPlayer* p) : State(p) {}
    void clickLock() override;             // unlock
    void clickPlay() override     { std::cout << "Locked.\n"; }
    void clickNext() override     { std::cout << "Locked.\n"; }
    void clickPrevious() override { std::cout << "Locked.\n"; }
    std::string name() const override { return "Locked"; }
};

class ReadyState : public State {
public:
    ReadyState(AudioPlayer* p) : State(p) {}
    void clickLock() override;
    void clickPlay() override;
    void clickNext() override     { player->nextSong(); }
    void clickPrevious() override { player->previousSong(); }
    std::string name() const override { return "Ready"; }
};

class PlayingState : public State {
public:
    PlayingState(AudioPlayer* p) : State(p) {}
    void clickLock() override;
    void clickPlay() override;
    void clickNext() override     { player->nextSong(); }
    void clickPrevious() override { player->previousSong(); }
    std::string name() const override { return "Playing"; }
};

// 4. TRANSITIONS (defined after all states are known)
void LockedState::clickLock() {
    if (player->isPlaying())
        player->changeState(std::make_unique<PlayingState>(player));
    else
        player->changeState(std::make_unique<ReadyState>(player));
}

void ReadyState::clickLock() {
    player->changeState(std::make_unique<LockedState>(player));
}
void ReadyState::clickPlay() {
    player->startPlayback();
    player->changeState(std::make_unique<PlayingState>(player));
}

void PlayingState::clickLock() {
    player->changeState(std::make_unique<LockedState>(player));
}
void PlayingState::clickPlay() {
    player->stopPlayback();
    player->changeState(std::make_unique<ReadyState>(player));
}

// Context constructor - initial state is Ready
AudioPlayer::AudioPlayer() {
    currentState = std::make_unique<ReadyState>(this);
}

// 5. USAGE
int main() {
    AudioPlayer player;

    player.clickPlay();      // Ready -> Playing (starts Song A)
    player.clickNext();      // -> Song B
    player.clickLock();      // Playing -> Locked
    player.clickPlay();      // ignored: Locked
    player.clickNext();      // ignored: Locked
    player.clickLock();      // Locked -> Playing (was playing)
    player.clickPlay();      // Playing -> Ready (stops)
    player.clickPrevious();  // -> Song A
    player.clickLock();      // Ready -> Locked

    return 0;
}
