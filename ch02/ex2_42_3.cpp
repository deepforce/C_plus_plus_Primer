#include <iostream>
#include "include/ex2_42.h"

int main()
{
    Sales_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.CalcRevenue(totalPrice);

        Sales_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.CalcRevenue(transPrice);

            if (total.bookNo == trans.bookNo) {
                total.AddData(trans);
            }
            else {
                total.Print();
                total.SetData(trans);
            }
        }
        total.Print();
        return 0;
    }
    else {
        std::cerr << "No Data?!" << std::endl;
        return -1;
    }
}