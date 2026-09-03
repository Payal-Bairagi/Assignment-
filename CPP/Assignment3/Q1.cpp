//============================================================================
// Name        : 1.cpp
// Author      : payal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint) {
    // enum class values need static_cast to be used in switch comparisons here
   int n  = static_cast<int>(status) ;
   switch(n){
   case 200:
	   cout<< "[" << endpoint << "] 200 OK - Request succeeded" << endl;
	   break;

   case 201:
	   cout << "[" << endpoint << "] 201 Created - Resource created" << endl;
	   break;

   case 400:
	   cout << "[" << endpoint << "] 400 Bad Request - Invalid syntax" << endl;
	   break;
   case 401:
	  cout << "[" << endpoint << "] 401 Not Found - Resource missing" << endl;

   case 404:
	    cout << "[" << endpoint << "] 404 Not Found - Resource missing" << endl;
	   break;

   case 500:
        cout << "[" << endpoint << "] 500 Server Error - Something broke" << endl;
        break;

   default:
               cout << "[" << endpoint << "] Unknown status" << endl;
   }
}
   int main() {
              cout << "=== Part A: Handling Responses ===" << endl;

       handleResponse(HttpStatus::OK, "/api/users");
       handleResponse(HttpStatus::NotFound, "/api/orders/99");
       handleResponse(HttpStatus::Unauthorized, "/api/admin");
       handleResponse(HttpStatus::ServerError, "/api/payments");

       return 0;
   }
