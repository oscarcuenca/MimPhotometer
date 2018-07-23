# MimPhotometer
Making a Photometer with Led and ESP8266 WeMos D1

Hardware WeMos D1 In order to uplead sketch I have Select in my EDI COM10, upload speed 115200, CPU Frequency 160 MHz. At the same time I fix the net into Wifi ESP8266 range and disconnect the Wifi Router. Not sure why but if not make this I get error espcomm_upload:error

Connected first step by USB First Test with red Led A0 as input Signal, This one transform light into electric signal, connected to Anode of the led. Forrest M. Mims III, 1970 Catode is connected to GND

This first test has been successful geting in Serial Port data representing the Electric Signal.

Next Step is

to connect 3 colors leds. (Red, Green and Blue)
Get data into EPROOM
Get data into SD locally
Connect ESP to the Wifi and transmit data to Internet
Connect to differents ESP´S to share data.
As final Goal is to build a network of ESP´s Connected all together sharing data ans sending it to a Gateway.
