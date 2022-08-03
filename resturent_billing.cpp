#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

private:
    double total_tax;

public:
    Restaurant(int food_item_codes[], string food_item_names[], int food_item_prices[])
    {
        for (int i = 0; i < 12; i++)
        {
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_names[i] = food_item_names[i];
            this->food_item_prices[i] = food_item_prices[i];
        }
        total_tax = 0;
    }
    void add_tax(double tax)
    {
        total_tax += tax;
    }
};

Restaurant *take_input()
{
    int n;
    cin >> n;
    int food_item_codes[n], food_item_prices[n];
    string food_item_names[n];
    for (int i = 0; i < n; i++)
    {
        cin >> food_item_codes[i];
        cin.ignore();
        getline(cin, food_item_names[i]);
        cin >> food_item_prices[i];
    }
    Restaurant *restaurant = new Restaurant(food_item_codes, food_item_names, food_item_prices);
    return restaurant;
}

void print_menu(Restaurant *restaurant)
{
    cout << "\n\t\t\t  Make Bill" << endl;
    cout << "\t\t\t-------------" << endl
         << endl;
    cout << "Item Code\tItem Name\t\t\tItem Price" << endl
         << "===========================================================" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << restaurant->food_item_codes[i] << "\t\t" << restaurant->food_item_names[i] << "\t\t" << restaurant->food_item_prices[i] << endl;
    }
}

void take_order(Restaurant *restaurant)
{
    int table_no, n;

    cout << endl
         << endl
         << "Enter Table No: ";
    cin >> table_no;
    cout << "Enter No of Items: ";
    cin >> n;
    int food_item_codes[n], food_item_quantities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Item " << i + 1 << " Code: ";
        cin >> food_item_codes[i];
        int found = 0;
        for (int j = 0; j < 12; j++)
        {
            if (food_item_codes[i] == restaurant->food_item_codes[j])
            {
                cout << "Enter Item " << i + 1 << " Quantity: ";
                cin >> food_item_quantities[i];
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            cout << "Item Not Found, Try Again!" << endl;
            i--;
        }
    }

    cout << "\t\t\t\t\t  BILL SUMMARY" << endl;
    cout << "\t\t\t\t\t----------------" << endl;

    cout << "Table No: " << table_no << endl;
    cout << "Item Code\tItem Name\t\t\tItem Quantity\tItem Price\tTotal Price" << endl
         << "============================================================================================" << endl;
    int total_price = 0;
    for (int i = 0; i < n; i++)
    {
        cout << food_item_codes[i] << "\t\t";
        for (int j = 0; j < 12; j++)
        {
            if (food_item_codes[i] == restaurant->food_item_codes[j])
            {
                cout << restaurant->food_item_names[j] << "\t\t";
                break;
            }
        }
        cout << food_item_quantities[i] << "\t\t";
        for (int j = 0; j < 12; j++)
        {
            if (food_item_codes[i] == restaurant->food_item_codes[j])
            {
                cout << restaurant->food_item_prices[j] << "\t\t" << food_item_quantities[i] * restaurant->food_item_prices[j] << endl;
                total_price += food_item_quantities[i] * restaurant->food_item_prices[j];
                break;
            }
        }
    }
    cout << "TAX: \t\t\t\t\t\t\t\t\t\t" << (double)total_price * 0.05 << endl;
    restaurant->add_tax((double)total_price * 0.05);
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "NET TOTAL: \t\t\t\t\t\t\t\t\t" << (double)total_price + (double)total_price * 0.05 << " Taka" << endl;
}

int main()
{
    Restaurant *restaurant = take_input();
Flag:
    print_menu(restaurant);
    take_order(restaurant);
    cout << endl
         << "Do you want to take order again? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y')
    {
        goto Flag;
    }
    return 0;
}
