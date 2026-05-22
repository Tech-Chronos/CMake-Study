#include "math.h"
#include <pthread.h>

using namespace std;
pthread_mutex_t _mtx = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    cout << "1 + 2 = " << add(1,2) << endl;
    cout << "1 - 2 = " << sub(1,2) << endl;
    cout << "1 * 2 = " << multiply(1,2) << endl;
    cout << "1 / 2 = " << divide(1,2) << endl;
    return 0;
}