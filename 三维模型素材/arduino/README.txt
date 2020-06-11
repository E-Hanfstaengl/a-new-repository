                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


https://www.thingiverse.com/thing:2328572
Raspberry Pi Zero HAB Shield Adapter by Anathae is licensed under the Creative Commons - Attribution - Non-Commercial - Share Alike license.
http://creativecommons.org/licenses/by-nc-sa/3.0/

# Summary

Arduino shield that uses a Raspberry Pi Zero as a component to add a compact in place keyboard, monitor, mouse interface to an Arduino project.

# How I Designed This

## Corrections

Discovered tonight, the schematic and board layout that I uploaded originally did not have the seven pin header that allows both setting the logic voltage level for the arduino as well as allowing the Zero to power the Arudino, but only had a four pin header for allowing the Zero to power the Arduino.  Uploaded the correct files.  Sorry for the confusion.

## Design notes.

I have a Pi Alamode addon for the original Raspberry Pi B.  I also have a Raspberry Pi Zero.  This is my take on taking the combination to at least one extreme.

No 3D files in the object, just a screen grab from Sketchup from file I used to check fitment of the shield board to the Zero.

I took the measurements from my reference model of the [Zero](http://www.thingiverse.com/thing:1612021) and used them to add the through mounting holes as well as the placement of the two by twenty 0.1 inch pitch pin header on the Zero in the Eagle CAD design.  This, in combination with printing out the resulting pcb and checking the placement of the OTG cable and the mini HDMI to HDMI adapter allowed me to find a good placement for the Zero as well as placement for the components on the board.

Single sided PCB are fairly easy for a DIYer to create at home.  By going with an eight pin dual n-channel MOSFET and four 1206 surface mount pull up resistors, I was able to get the entire circuit on one side with no jumpers required.  To do so, I had to route some of the signals in between the pads for the resistors.  

The seven pins near the one end of the board are used to select logic voltage of the Arduino board as well as select if the 5 and 3.3 volts from the Zero is passed on to the Arduino or not.

This board basically maps the RX/TX pins of the Zero to the TX/RX pins of the Arduino.  One complication of this is that the Arudino Uno (at least up to and including the R3 version) has 5 volt TTL serial, but the Zero had 3.3 volt TTL serial.  

There are a couple of ways of dealing with this, but the design used in this iteration of this board, I wired up an N-Channel enhancement MOSFET as a bidirectional logic level shifter between the Arduino and the Zero.  If pins 1 and 2 of the seven pin male pin header are shorted with a jumper, the 3.3 volt supply of the Zero is routed to the Arduino side of the level shifter.  with pins 2 and 3 of the header shorted, the 5 volt supply of the Zero is routed to the Arduino side of the level shifter.

Starting with the revision 3 of the Arduino Uno, a pin that is held at the logic voltage level of the Arduino has been added.  On the Arudino Due, this pin is at 3.3 volts, and on the Arduino Uno R3, it is at 5 volts.  If I had been willing to use jumpers, it might have been possible to route this pin from the Arduino to the logic level shifter to allow automatic selection of the IO voltage level by the shield from the Arduino, but for this iteration of this board I decided single sided was more important.

Pins 4 and 5 of the 7 pin pin header shorted out connect the 5 volt supply of the Zero and the Arduino.  Pins 6 and 7 shorted out connect the 3.3 volt supply.  There are limits to the Zero's power supply and you should check the power requirements of your stack of Arduino and shields to make sure you can power it from the Zero if you decide to do this.  The rather short look I did online convinced me that it would be a good idea to add these jumpers to allow for either powering the Zero and the Arduino independently, or allowing the Zero to power the Arduino.

The cut out in the corner of this shield is to allow for space around the mini HDMI adapter on the Zero.  This provides no strain relief.  Best practice would be to design a case for this that properly supports the adapter, or perhaps using a mini HDMI to full size HDMI cable instead to try and prevent the surface mounted HDMI port on the Zero from getting ripped off due to deflection of the video cable.

One of the mounting holes for the Arduino ends up being very close to being directly under the OTG port on the Zero.  A right angle OTG cable might be short enough in that access that you can use a stand off on either side of this shield to mount it to other shields in your stack.  The power port on the Zero will require a right angle cable to be plugged in.  From my measurements (haven't confirmed it yet, sorry) the right angle USB A to USB B Micro cable from StarTech should fit in this location.

The fourty pin (two by twenty) pin header connecting the Zero to this shield will likely have to be put in "upside down" with the long side of the pins going trough the shield, and the short side soldered down through the top size of the Zero.  With this pin header in it's normal orientation, it may interfere with signal traces on the bottom of shields above this board.  A right angle seven pin header should be used for the voltage selection as well for similar reasons.  To keep this header from preventing one of the mounting holes on the Arduino from being used, it will have to point toward the Zero.  If requested, I can move this header down so that is can point out from between the two mounting holes on this end.

I tried to place the voltage selection header far enough away from the camera port on the Zero to allow for it to be used.

# Comments Requested

Constructive comments on this design greatly appreciated.

If you like this idea and can think of a stack of boards that you would like to use it in, I'd be thrilled to find out.  Myself, I plan to use it with and Arduino Uno, and the Pronteer Arduino CNC shield.