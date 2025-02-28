# Retro Nixie IN-12 Clock

![nixietest](https://github.com/user-attachments/assets/17673e0f-60ab-4cf8-951d-83fbdfcb5482)

This clock is based on [GreatScott project](https://www.instructables.com/Make-Your-Own-Retro-Nixie-Clock-With-an-RTC/).
I've ordered a few pcb of his design and repurposed them to also build other clocks. 

For PCB assembly you should follow GreatScott's instrucions, however I've changed RTC module from DS1307 to more accurate **DS3231**

Instead of using more expensive Nixie IN-14, I've used **Nixie IN-12** tubes.

I've added a button for easy time setting. You are setting the blinking digit by shor-pressing and moving to another digit by long-pressing.
First hours than minutes and seconds are automaticly set to 0.

Design of the case in stl and f3d formats you can find [there](/Case)

Arduino code you can find [there](/Code)
