#include <tins/tins.h>
#include <cassert>
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>

using namespace std;
//using namespace Tins;

// Function to generate random data
void random_string(char *s);

int main() 
{	
	// declare the sender object and set "eth10" as the ethernet port
    Tins::PacketSender sender("eth10");
    // create variable to store random data
	char *s = new char [1206];
    int rand_no;
    
    // Infinite loop to continually send data
	while(1){		
		random_string(s);
		Tins::EthernetII pkt = Tins::EthernetII() / Tins::IP("255.255.255.255") / Tins::UDP() / Tins::RawPDU(s);
		sender.send(pkt); // send it through eth10
		usleep(400); // 400us delay between successive UDP packets
	}

}


void random_string(char *s) {
    static const char characters[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //srand(time(NULL));
    // Assign s to a randomly generated series of characters from among the characters listed above
    for (int i = 0; i < 1206; ++i) {
        s[i] = characters[rand() % (sizeof(characters) - 1)];
    }
}
