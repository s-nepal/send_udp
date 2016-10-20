#include <tins/tins.h>
#include <cassert>
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
using namespace Tins;
void random_string(char *s);
int main() 
{
    PacketSender sender;
	char *s = new char [1206];
    int rand_no;
    NetworkInterface iface("eth10");
	while(1){		
		random_string(s);
		EthernetII pkt = EthernetII() / IP("255.255.255.255") / UDP() / RawPDU(s);
		sender.send(pkt, iface); // send it through eth0
		usleep(400);
	}

	// if you're sending multiple packets, you might want to create
	// the NetworkInterface object once
	// NetworkInterface iface("eth10"); 
	// sender.send(pkt, iface);

}


void random_string(char *s) {
    static const char characters[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //srand(time(NULL));
    for (int i = 0; i <1206; ++i) {
        s[i] = characters[rand() % (sizeof(characters) - 1)];
    }
}
