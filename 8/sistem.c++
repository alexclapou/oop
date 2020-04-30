#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "Intro To C" << endl;
    cout << "Intro To C++" << endl;
    cout << "Intro To Java" << endl;

    string topicName;

    cout << "\t\tWhich Topic You Want to edit: ";
    getline(cin, topicName);

    topicName = "notepad \"" + topicName + "\"";

    system(topicName.c_str());
    return 0;
}
