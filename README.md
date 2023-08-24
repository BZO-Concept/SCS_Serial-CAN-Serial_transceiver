# SCS_Serial-CAN-Serial_transceiver
System allowing long distance USB connection without interference using a CanBus line and two STM32F103C8T6 with MCP2551.

Look at the code for the pinout. both STM32F103 must be uploaded with this simple firmware on Arduino IDE.

The system will then react like a classic USB communication, regardless of the length of the CAN cable (shielding) and the environment.

Made by BZO Concept (France) for Speeduino systems. possible use on any serial link equipment.
