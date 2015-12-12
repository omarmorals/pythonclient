#include <Ethernet.h> //Load Ethernet Library
#include <EthernetUdp.h> //Load UDP Library
#include <SPI.h> //Load the SPI Library
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 2, 66);
//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //Assign a mac address
//IPAddress ip(192, 168, 2, 2); //Assign my IP adress
unsigned int localPort = 5000; //Assign a Port to talk over
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
String datReq; //String for our data
int packetSize; //Size of Packet
EthernetUDP Udp; //Define UDP Object
 
void setup() {
  
Serial.begin(1200); //Turn on Serial Port
Ethernet.begin(mac, ip); //Initialize Ethernet
Udp.begin(localPort); //Initialize Udp
delay(1500);//delay
Serial.print("im working");
}
 
void loop() {
  
  packetSize = Udp.parsePacket(); //Read theh packetSize
  
  if(packetSize>0){ //Check to see if a request is present
  
  Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); //Reading the data request on the Udp
  String datReq(packetBuffer); //Convert packetBuffer array to string datReq
  
  if (datReq =="Red") { //See if Red was requested
  
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());  //Initialize Packet send
    Udp.print("You are Asking for Red"); //Send string back to client 
    Udp.endPacket(); //Packet has been sent
  }
   if (datReq =="Green") { //See if Green was requested
  
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());  //Initialize Packet send
    Udp.print("You are Asking for Green"); //Send string back to client 
    Udp.endPacket(); //Packet has been sent
   }
    if (datReq =="Blue") { //See if Red was requested
  
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());  //Initialize Packet send
    Udp.print("You are Asking for Blue"); //Send string back to client 
    Udp.endPacket(); //Packet has been sent
    }
  }
  memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
}
