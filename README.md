# Semi-Realistic TinkerCAD Traffic Light Circuit
A semi-realistic traffic light circuit was created in TinkerCAD with Arduinos and micro:bits. This repo contains the source code for the project and was created for the purpose of tracking scraps and projects for a hackathon. 3D Model and circuit!

**[Find the project here!](https://www.tinkercad.com/things/aTAbVHVReYn-realistic-ish-traffic-light?sharecode=yxpimFw48Sh7uL3CR5kw6gxLFxUi6zwyi1_lv7-vQRQ)**

![image](https://github.com/user-attachments/assets/25972859-0ec8-443e-aff1-8ed65eef2c12)
![image](https://github.com/user-attachments/assets/476a21ba-f560-4ab8-8662-cf9eae6be145)

## The 3D Model:

The 3D Model pictures 3 things. A traffic light, push-to-cross button, and crosswalk countdown meter thingy. I put a decent amount of attention to detail into it :D. The traffic light has a cover over the top, used in real life to block snow and rain. It also serves to block sunlight, making the colour of the bulb more visable. Same goes for the countdown thingy (still don't got a name for it :/). The push-to-cross button has a small LED, used in my city (Toronto, Canada) to show that the button worked and the traffic light will let you cross soon.


## Features of circuit:
- Fully functional traffic lights and phases
- Pedestrian countdown timer and vehicle "detection"
- Realistic** pedestrian locator tones and activation tone

** Depending on where you live it may sound different lol

## Why did I make this?
This is a project for the summer hackathon Arcade. I chose to make this because, well, I'm a traffic nerd. It was an extremely fun ~~and painful to fix~~ project. I wanted to try out making circuits for basically the first time ever, and in the process, I realized fixing them is a huge pain. I also realized just how painfully hard it is to cater to people of all needs with accessibility features. That part alone took me a good nearly 2 hours.

## Notes:
- This is very, wait no, _EXTREMELY_ laggy, likely because there 2 micro:bits and 2 Arduinos lol
- There are 2 phases, basically 2 directions of travel, left is phase 2, and right is phase 3, all stuff except the Arduinos in the middle are mirror copies
- To activate the signal on your half, press A _or_ B on the micro:bit, _or_ move the distance sensor within 50 cm, then wait! The other side gets a countdown before their signal goes red and you get the green!
- There's a buzzer on your half, it makes a lower-pitched beep to simulate a locator tone, used in real life by the blind to feel for the button, they find it by sound! Pressing it makes a higher-pitched beep, to show it worked. The sound may not play due to the lag, I spent like 10 minutes debugging it just to realize its lag lol. 

## Note for the reviewers at Arcade!
TinkerCAD provides a virtual code editor and simulator, for which there is no git function. I have uploaded screenshots and videos in my sessions as scraps. I've uploaded my updated code as I went as more scraps.

Here's the link again in case, https://www.tinkercad.com/things/aTAbVHVReYn-realistic-ish-traffic-light?sharecode=yxpimFw48Sh7uL3CR5kw6gxLFxUi6zwyi1_lv7-vQRQ
