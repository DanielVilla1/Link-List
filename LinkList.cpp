#include <iostream>
using namespace std;

struct Product {
    Product* next = NULL;

    string prodName = "";
    int cost = 0, quantity = 0;
};

int Menu(){
    int choice;
    cout << "Menu"
        << "\n1. Add Product"
        << "\n2. View Product"
        << "\n3. Exit"
        << "\nInput choice: "; cin >> choice;
    return choice;
}

void AddProduct(Product* head, Product* tail, int * counter) {
    Product* temp = new Product;
    cout << "\nAdd Product";
    
    cout << "\nEnter Product Name: ";
    cin >> head->prodName;

    cout << "\nEnter Quantity: ";
    cin >> head->quantity;

    cout << "\nEnter Price: ";
    cin >> head->cost;

    if (!head) {
        tail = temp;
        head = temp;
        temp->next = NULL;
    }
    else {
        temp->next = tail;

    }
       
}
int main()
{
    int choice, optionLoop, counter = 0;
    Product* head = NULL, * tail = NULL, * temp = NULL, * prev = NULL;

    do
    {
    choice = Menu();
    if (choice == 1) {
        AddProduct(head, tail);
    }
    else if (choice == 2) {
        cout << "\nAvailable Products\n";

        temp = tail;

        if (temp) {
            do
            {
                cout << "\nProduct: " << temp->prodName << " \nStocks Left: " << temp->quantity << " \nPrice: " << temp->cost << "\n";

                if (temp->next == NULL) 
                    break;

                temp = temp->next;
            } while (true);
        }
        else
        {
            cout << "\nNo Products Yet\n";
        }
    }
    else if (choice == 3) {
        system("cls");
        cout << "\nThank you!\n";
        exit(0);
    }
    else {
        cout << "\nInvalid Input! Please try Again.";}

    cout << "\nWould you like to Continue?"
        << "\n[1] Yes or [0] No"
        << "\nInput: "; cin >> optionLoop;
        system("cls");
    } while (optionLoop == 1);
}
