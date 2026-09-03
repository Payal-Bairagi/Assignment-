#include<iostream>
#include<string>
#include<memory>
using namespace std;

class AudioClip {
    private:
     string name;
     double duration;
     string getname() const ;
    

public:
//constructor called object is created
  AudioClip(string n, double d) : name(n), duration(d) {
        cout << "AudioClip [" << name << "] loaded (" << duration << "s)" << endl;
    }
//destructor :
    ~AudioClip() {
        cout << "AudioClip [" << name << "] destroyed" << endl;
    }
//getter function:returns name of audio clip.
    string getName() const {
        return name;
     }
     //getter function:returns duration of Clip.
    double getDuration() const { 
        return duration; 
    }
};

int main(){
// created shared object.
     auto audio = make_shared<AudioClip>("explosion", 3.5);

//weak_ptr :-no ownership,no memory control.
    weak_ptr<AudioClip> observer = audio;

    // use lock to access object safely
    if (auto clip = observer.lock()) {
        cout << "Clip alive: " << clip->getName() << endl;
    }

//reset shared_ptr-> object destroyed
    audio.reset();

//check if object is deleted.
    if (observer.expired()) {
        cout << "Clip already unloaded." << endl;
}
return 0;
}