#include <Arduino.h>
#include <TickerScheduler.h>
#include <easyMesh.h>

#define LED D4

#define   MESH_PREFIX     "whateverYouLike"
#define   MESH_PASSWORD   "somethingSneeky"
#define   MESH_PORT       5555

easyMesh  mesh;
TickerScheduler ts(4);
bool onFlag = true;


void blink()
{
	Serial.println("blink " + String(onFlag));
	onFlag = !onFlag;
	//digitalWrite( LED, onFlag);
}

void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("startHere: Received from %d msg=%s\n", from, msg.c_str());
}

void newConnectionCallback( bool adopt ) {
  Serial.printf("startHere: New Connection, adopt=%d\n", adopt);
}

void setup()
{
	Serial.begin(115200);

	Serial.println("Start mesh");

	pinMode( LED, OUTPUT );

	 mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

	 mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT );

	 mesh.setReceiveCallback( &receivedCallback );
	 mesh.setNewConnectionCallback( &newConnectionCallback );

	 ts.add(1,500,blink,false);

}


void loop()
{

	mesh.update();

	//delay(500);


	ts.update();
}
