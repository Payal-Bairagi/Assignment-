#include<iostream>
#include<cstring>
#include<memory>
using namespace std;
class LogBuffer{
    char* buffer;
    int capacity;   
    int size;
    static int instanceCount;
    public:
    // Constructor — allocates char buffer of given capacity on heap
LogBuffer(int capacity);

LogBuffer(const LogBuffer& other);

LogBuffer& operator=(const LogBuffer& other);

~LogBuffer();

void append(const char* msg);

void print() const;

static int getInstanceCount();
};

int LogBuffer::instanceCount = 0;

//constructor
LogBuffer::LogBuffer(int cap) {
    capacity = cap;
    buffer = new char[capacity];
    size = 0;
    buffer[0] = '\0';        // ← THIS line — right after allocating, before anything else touches buffer
    instanceCount++;
    cout << "[LogBuffer Created]" << endl;
}
// Copy Constructor — must perform a DEEP copy
LogBuffer::LogBuffer(const LogBuffer& other){
              capacity = other.capacity;
              size = other.size;
                buffer = new char[capacity];   
                memcpy(buffer , other.buffer,size +1); //copy
                instanceCount++;
                cout << "[LogBuffer]" <<endl;
}
// Copy Assignment Operator — must handle self-assignment, release old memory,
LogBuffer&LogBuffer::operator=(const LogBuffer& other){
    if(this==&other){
        return *this; 
    }
    delete[] buffer;
    capacity = other.capacity;
    size = other.size;
    buffer = new char[capacity];
    memcpy(buffer,other.buffer,size+1);
    cout<<"[LogBuffer Assigned]"<<endl;
    return *this;
}
//Destructor
LogBuffer::~LogBuffer(){
    cout<<"[LogBuffer Destroyed]" <<endl;
    delete[] buffer;
    instanceCount--;

}
//Append message 
// function definitions OUTSIDE class

void LogBuffer::append(const char* msg){
    int msgLen = strlen(msg);
    int freespace = capacity - size - 1;
    int copyLen = min(msgLen, freespace);
}

void LogBuffer::print() const {
    cout << buffer << endl;
}

int LogBuffer::getInstanceCount() {
    return instanceCount;
}
int main() {
 // Objective 1 : Basic usage

 LogBuffer log1(256);
 log1.append("Server started on port 8080");
 log1.append(" | Request received from 192.168.1.10");
 log1.print();

 // Objective 2 : Deep copy via copy constructor
 LogBuffer log2 = log1; // copy constructor

 log2.append(" | Cached response sent");

 cout << "log1 : "; log1.print(); // must NOT contain log2's append

 cout << "log2 : "; log2.print();
 // Objective 3 : Copy assignment operator
 LogBuffer log3(128);

 log3 = log1; // copy assignment

 log3.print();

 // Objective 4 : Self-assignment guard
 log1 = log1; // must not crash or corrupt data

 log1.print();

 // Objective 5 : Static member
 cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;

 return 0;
}