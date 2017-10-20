#include <iostream>
#include <assert.h>

#include "List.hpp"

using namespace std;

int main(){
    List<int> lizt;

    lizt.push(5);
    lizt.push(6);
    lizt.push(7);
    lizt.push(8);

    List<int> otherLizt(lizt);
    assert(lizt == otherLizt);
    /*
    for(int i=0; i<4; i++) {
        assert(lizt[i] == i+5);
    }
    */

    return 0;
}
