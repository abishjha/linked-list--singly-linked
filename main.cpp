#include<iostream>
#include<string> //just in case the input type is string...not required for other data types
#include"LinkedList.cpp"

//change int to change the data type of the value stored in the node
typedef int linkedListType;

int main() {
     int input;
     linkedListType data;

     LinkedList<linkedListType> list;
     do {
          std::cout << "please select the operation you want to execute\n"
               << "\t1. append\t"
               << "\t2. remove tail\t"
               << "\t3. push\t"
               << "\t\t4. pop\n"
               << "\t5. remove i\t"
               << "\t6. get i\t"
               << "\t7. add i\t"
               << "\t8. print\n"
               << "\t9. delete\t"
               << "\t10. reverse\t"
               << "\t11. rotate\t"
               << "\t12. random shuffle\n"
               << "\t13. size\t"
               << "\t-1. exit\n\t: ";
          std::cin >> input;
          if (input > 0 && input < 14) {
               if (input == 1 || input == 3 || input == 7) {
                    std::cout << "\tplease enter the value to add: ";
                    std::cin >> data;
               }
               else
                    data = NULL;

               list.perform_operation(input, data);
          }
          else if (input == -1)
               return 0;
          else
               std::cout << "\tplease enter a valid input\n" << std::endl;
     } while (input != -1);

     return 0;
}
