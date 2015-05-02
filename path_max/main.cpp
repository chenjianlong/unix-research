#include <unistd.h>
#include <iostream>

using namespace std;

int main(void)
{
    long max = pathconf("/", _PC_NAME_MAX);
    if (-1 == max) {
        cerr << "Failed to call pathconf with NAME_MAX" << endl;
    } else {
        cout << "NAME_MAX = " << max << endl;
    }

    max = pathconf("/", _PC_PATH_MAX);
    if (-1 == max) {
        cerr << "Failed to call pathconf with PATH_MAX" << endl;
    } else {
        cout << "PATH_MAX = " << max << endl;
    }

    return 0;
}
// vim: set et ts=4 sts=4 sw=4:
