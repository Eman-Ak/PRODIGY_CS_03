/*Build a tool that assesses the strength of a password based on criteria such as length, presence of uppercase and lowercase letters, numbers, and special characters. Provide feedback to users on the password's strength*/

#include<iostream>
#include <string>
using namespace std;

bool has_LowerCase(string password){
    for(int i=0; i<password.length(); i++){
        if(islower(password[i])){
            return true;
        }
    }
    return false;
}

bool has_UpperCase(string password){
    for(int i=0; i<password.length(); i++){
        if(isupper(password[i])){
            return true;
        }
    }
    return false;
}

bool has_number(string password){
    for(int i=0; i<password.length(); i++){
        if(isdigit(password[i])){
            return true;
        }
    }
    return false;
}

bool has_specialChar(string password){
    for(int i=0; i<password.length(); i++){
        if(!isalnum(password[i])){
            return true;
        }
    }
    return false;
}

bool length(string password){
    if(password.length()>=8){
        return true;
    }
    return false;
}

string assess_pass_strength(string password){
    if(has_LowerCase(password) && has_UpperCase(password) && has_number(password) && has_specialChar(password) && length(password)){
        return "Strong";
    }
    else if(has_LowerCase(password) && has_UpperCase(password) && has_number(password) && length(password)){
        return "Moderate";
    }
    else if(has_LowerCase(password) && has_UpperCase(password) && length(password)){
        return "Weak";
    }
    else{
        return "Very Weak";
    }
}

int main()
{
    string password;
    cout<<"Password should contain at least 8 characters, one uppercase letter, one lowercase letter, one number and one special character"<<endl;
    cout<<"Enter your password:";
    cin>>password;
    has_LowerCase(password);
    has_UpperCase(password);
    has_number(password);
    has_specialChar(password);
    length(password);
    cout<<"Your password is "<<assess_pass_strength(password)<<endl;
    return 0;

}
