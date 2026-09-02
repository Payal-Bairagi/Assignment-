#include<iostream>
#include <iomanip>
using namespace std;
class IMS{
    static int productID;
    string name;
    double price;
    int quantity;
    int thisID;
public:
       //setters
       void setProductID(int id) {
            if(id > 0) {
                this->productID = id;
            }
            else {
                cout << "Enter the product ID!!" << endl;
            }
        }
    void setName(const string& n) {
            if(n != "" && n != "  "){
                name = n;
            }
            else {
                cout << "Name cannot be empty!" << endl;
            }

        }

        void setPrice(double prize) {
            if(prize > 0) {
                this->price = prize;
            }
            else {
                cout << "Enter the right prize!!" << endl;
            }
        }
         void setQuantity(int quantity) {
            if(quantity > 0) {
                this->quantity = quantity;
            }
            else {
                cout << "Enter the  quantity!!" << endl;
            }
        }
      //getters
      int getProductID() const {
            return productID;
        }

        string getName() const {
            return name;
        }

        double getPrice() const {
            return price;
        }

        int getQuantity() const {
            return quantity;
        }     
       
void acceptDetails(){
    int id ,q;
    double p;
    string n;

    cout<<"Enter the productID:"<<endl;
    cin>>id;
    setProductID(id);

    cin.ignore();
    cout<< "Enter the name of the product:"<<endl;
    getline(cin,n);
    setName(n);


    
    cout<<"Enter the price of the product:"<<endl;
    cin>>p;
    setPrice(p);

    
    cout<<"Enter the quantity of the product:"<<endl;
    cin>>q;
    setQuantity(q);
  
} 
  //Calculate total     
       double totalValue() const{
        return price * quantity;
       }   
       //Low stock check                           
bool isLowStock(int threshold) const{
        return quantity < threshold;
    }
    // display details
        void displayDetails() const {
    cout << thisID;

    // spacing for ID
    if (thisID < 10) cout << "\t\t";
    else cout << "\t";

    cout << name;

    // spacing for name
    if (name.length() < 8) cout << "\t\t";
    else cout << "\t";

    cout << price << "\t"
         << quantity << "\t"
         << totalValue();

    if (isLowStock(10)) {
        cout << "\tLOW STOCK";
    }

    cout << endl;
}
    };
int IMS::productID = 0;


int main(){
   const int size =2;
   IMS p[size];
   for(int i=0;i<size;i++){
        cout<<"\nEnter the details of product "<<i+1<<endl;
        p[i].acceptDetails();
         }
        cout << "\n========== INVENTORY REPORT ==========\n";
cout << "ID\t\tName\t\tPrice\tQty\tTotal\tStatus\n";
cout << "------------------------------------------------------------\n";
              for(int i = 0; i< size; i++) {
                p[i].displayDetails();
              }
              // highest total
              int maxindex = 0;
              for(int i = 1; i < size; i++) {
                if(p[i].totalValue() > p[maxindex].totalValue()) {
                    maxindex = i;
                }
              } 
              cout << "\n========== INVENTORY REPORT ==========\n";
cout << "ID\t\tName\t\tPrice\tQty\tTotal\tStatus\n";
cout << "------------------------------------------------------------\n";
              //threshold 
                int threshold = 10;;  
                cout << "Enter the threshold value :";

                cout << "\nLow stock products:\n";
cout << "-----------------------------------\n";

                  for (int i = 0; i < 2; i++) {    
                      if (p[i].isLowStock(threshold)) {
                            p[i].displayDetails();
    }
}
                return 0;
            }