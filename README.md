# Retro Nixie IN-12 Clock

![nixietest](https://github.com/user-attachments/assets/17673e0f-60ab-4cf8-951d-83fbdfcb5482)

This clock is based on [GreatScott project](https://www.instructables.com/Make-Your-Own-Retro-Nixie-Clock-With-an-RTC/).
I've ordered a few pcb of his design and repurposed them to also build other clocks. 

For PCB assembly you should follow GreatScott's instrucions, however I've changed RTC module from DS1307 to more accurate **DS3231**

Instead of using more expensive Nixie IN-14, I've used **Nixie IN-12** tubes.
Wiring of the tubes is similar but very annoying due to a need solder a cable between lamp's output and original IN-14's spot on pcb.

I've added a button for easy time setting. You are setting the blinking digit by shor-pressing and moving to another digit by long-pressing.
First hours than minutes and seconds are automaticly set to 0.

Now the clocks implements [this](https://surfncircuits.com/2019/04/06/eliminating-nixie-tube-cathode-poisoning-bi-quinary-digit-ghosting-and-heavily-oxidized-leads/) anti cathode poisoning routine by cycling through every digit for small period of time.

Design of the case in stl and f3d formats you can find [there](/Case)

Arduino code you can find [there](/Code)

## License
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](https://creativecommons.org/licenses/by-nc-sa/4.0/)
