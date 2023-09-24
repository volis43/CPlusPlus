#include <iostream>
#include <list>


using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
    list<string> words = { "death", "milk", "milk", "limonate", "pay"};
    list<int> valsi = { 43, 57, 187, 32, 74, 123 };
    list<string> re = { "vumi", "cumi", "ari", "roni", "poly", "Runny" };

    cout << "It's size words! " << words.size() << endl;
    
    cout << "It's size but numbers: " << valsi.size() << endl;

    cout << "It's just delate: " << re.size() << endl;
    
    words.remove("pay");

    for (auto word : words)
    {
        cout << word << endl;
    }

    for (auto val : valsi)
    {
        cout << val << endl;
    }

    //re.remove_if([](const string& e) {
      //  return (epw("c"));
        //});

    for (auto rei : re)
    {
        cout << rei << endl;
    }

    words.clear();

    cout << words.size() << endl;
}