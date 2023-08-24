
/***************Firmware permettant la liaison USB via CANBUS par BZO_Concept*****************
 * 
 *         v1.0. version de base, seule la communication USB régulière est transmise.
 * 
 *utiliser 2 STM32F103C8T6 flashés avec ce firmware, puis reliés ensemble par CAN sur PB11 PB12
 *par l'intermediaire d'un MCP2551 chacun. liaison 1000KBS obligatoire.
 *
 *téléversement pour Arduino: possible avec appui sur le bouton RESET de l'arduino au lancement.
 *
 *utiliser PB9 PB10 pour la liaison USB (Serial1). utiliser un convertisseur TTL/Serie coté PC.
 *
 **********************************************************************************************/

#include "hal_conf_extra.h"
#include "STM32_CAN.h"

STM32_CAN Can( CAN1, DEF, RX_SIZE_64, TX_SIZE_16 );

static CAN_message_t CAN_RX_msg;
static CAN_message_t CAN_TX_msg;

int OctetTX = 0;
int OctetRX = 0;

void setup() {
  Serial1.begin(115200);     //connexion USB  PB9 PB10
  Can.begin();               //CANBUS        PB11 PB12       
  Can.setBaudRate(1000000);
}

void emetteur(){

  if (Serial1.available() > 0){
  OctetTX = Serial1.read();
  
    CAN_TX_msg.id = 0x29A;
    CAN_TX_msg.len = 1;
    CAN_TX_msg.buf[0] = OctetTX;
    
  Can.write(CAN_TX_msg);
}
}

void recepteur(){
  
  if (Can.read(CAN_RX_msg)) {
  OctetRX = CAN_RX_msg.buf[0];
  
  Serial1.write(OctetRX);
}
}
  
void loop() {

emetteur();

recepteur();

}

//END//
