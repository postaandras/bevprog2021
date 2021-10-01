#include <iostream>
#include "std_lib_facilities.h"

int main() {
    string first_name;
    string friend_name;
    char friend_sex=0;
    int age;
    
    cout << "Please enter the name of the person you want to write to (followed by 'enter'):\n";
    cin >> first_name;
    cout << "Please enter the name of another friend (followed by 'enter)\n";
    cin >> friend_name;
    cout << "Please also enter the sex of said friend.\n";
    cin >> friend_sex;
    cout << "Please also enter the age of said friend.\n";
    cin >> age;
    
    
    cout << "Dear " << first_name << ",\n";
    cout << "How are you? I am fine. \n I miss you. You know who I am. \n I didn't see you for a while, so I chose to write this letter to you. \n The weather is just...normal. As always. The time flows, and the kids are getting bigger day by day. \n I hope to see you soon. Take care!";
    
    
    cout << "Have you seen " << friend_name << " lately?\n";
    
    
    if(friend_sex=='m'){
        cout << "If you see " << friend_name << ", please ask him to call me\n";
    }
    else if(friend_sex=='f'){
        cout << "If you see " << friend_name << ", please ask her to call me\n";
    }
    
    cout << "I heard you just had a birthday and you are " << age << " years old.\n";
    if (age <= 0 || age >= 110)
    {
       simple_error("you're kidding!");
    }
    else {
        if (age<12)
        {
            cout << "Next year you will be " << age+1 << ".\n";
        }
        if (age==17)
        {
            cout << "Next year you will be able to vote.\n";
        }
        if (age>70)
        {
            cout << "I hope you are enjoying retirement.\n";
        }
    }
    
    
    
    cout << "Yours sincerely,\n\n\n";
    cout << "Bandi\n";
    
    
    return 0;

}


