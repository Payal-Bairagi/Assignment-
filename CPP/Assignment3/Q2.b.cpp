#include<iostream>
#include<string>
#include<memory>
using namespace std;
 class Texture {
private:
    string name;
    int width, height;
 };
    class Shader {
private:
    string name;
    string type;  // "vertex" or "fragment"
public:
//Constructor
    Shader(string n , string t) : name(n), type(t) {
        cout << "[Shader Compiled] " << name << " (" << type << ")" << endl;
    }
//destructor
    ~Shader() {
        cout << "[Shader Destroyed] " << name << endl;
    }
//getter function
    string getName() const { return name; }
};
    int main() {
        //create shared object
        auto shader = make_shared<Shader>("main_vert", "vertex");
//initial reference count = 1
        cout << shader.use_count();  // 1
//Copy pointer-> cont increase
        {
            auto rendererRef = shader;
            cout << "Ref count: " << shader.use_count() << endl; // 2

            auto editorRef = shader;
            cout << "Ref count: " << shader.use_count() << endl; // 3
        }
//when coutn becomes 0 -> object is destroyed
        cout << "Ref count: " << shader.use_count() << endl; // 1

        return 0;
    }