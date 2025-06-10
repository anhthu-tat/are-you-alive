
#include <iostream>
#include <string>
using namespace std;

struct YouTubeChannel {
//public by default
    string Name; 
    int SubcribersCount;

    //constructor
    YouTubeChannel(string name, int subscribersCount){
        Name = name;
        SubcribersCount = subscribersCount;
    }
};

//1.instead of return void, operator must return ostream object
//2. add return line
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
//passing the 2 parameters by reference = pass the original
//are not going to be copied, pass the original themselves
//pass-by reference: parameters are not "cheap to copy" (not numbers)
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubcribersCount << endl;
    return COUT;
//succesfully overloaded the insertion operator

}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("TAT", 50);
    //insertion operator "<<" works with 2 operand: "cout"& "yt1"
    //these 2 operands will be passed as parameters to operator funtion
    //"cout" is of type "ostream" 
    cout << yt1;
    //now we can cout a YouTubeChannel type the same way we cout a number

    YouTubeChannel yt2 = YouTubeChannel("NTA", 500);
    cout << yt1 << yt2;
    //can not print the next ytchannel
    //1.instead of return void, operator must return ostream object
    //2. add return line

    operator<<(cout, yt1);

    cin.get();
}
