#include<iostream>
#include<vector>
using namespace std;

enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};
using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;
typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers){
    for(const auto& header :headers){
        cout << header.first << ": " << header.second << endl;
    }
}
int main(){
    HeaderList headers =  {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer token123"},
        {"User-Agent", "Mozilla/5.0"}
    };
    cout << "Request Headers:" << endl;
    printHeaders(headers);

    Port serverPort = 8080;
    RequestId reqId = 1748293847;

    cout << "Server Port: " << serverPort << endl;
    cout << "Request ID: " << reqId << endl;

    return 0;
}