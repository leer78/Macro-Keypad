# Macro-Keypad
Macro keypad makes accessing regular shortcuts and buttons far more convenient

Name
Macro Keypad

DESCRIPTION

A macro keypad with several 3x3 keyswitch buttons that utilize an Arduino Pro Micro to extend the functionality of my main keyboard. My primary focus was to add convenient shortcuts for tools that I regularly use.

VISUALS

I intially started by 3D printing several main components of this project. Reusing 3D printed keycaps from a .stl file on the web (source unknown), I started to develop a framework for the main body. This portion actually took me much longer than expected, as the prints had to be perfectly sized so that the key switches could fit snuggly without the need for adhesives. 

I took this opportunity to solder a device for the first time rather than buying a more expensive PCB board. In the image below, I first created three rows of diodes which were connected to one of the two pins. For efficiency, I connected the diode wires to eachother directly rather than connecting them by wire. I felt that this was fine as there would be very few loose wires anyways, so I didn't worry about shorts. 

![1](https://user-images.githubusercontent.com/74937113/117227209-511dfa80-ade4-11eb-9c58-a4904fa6fd2f.jpg)

Once I attached three columns of regular wire, I ordered my microcontroller. At the recommendation of numerous online sources, I concluded that the Arduino Pro Micro would fit perfectly in this project as the main controller. 

![2](https://user-images.githubusercontent.com/74937113/117227218-5418eb00-ade4-11eb-9b0f-26ac4e0662a6.jpg)

At this point, I was able to solder three red wires to the ends of each column, and black wires to the rows. The colour choice simply aided in keeping my design organized. Once these were attached to the pro micro, the keypad was actually functional since I created much of the code before hand. As mentioned before, this was my first experience soldering, so I planned to connect my wires to every other pin. I had the space for it, so spacing them out would ensure that any mistakes weren't as devestating.

![6](https://user-images.githubusercontent.com/74937113/117228586-52045b80-ade7-11eb-9c25-480cad9e5223.png)

I technically had finished my original goal of making a working keypad. However, I felt that having only 1 set of keybinds was very limiting. I planned to have a page button (the bottom right key) that would allow for me to switch between pages. The best way that I came up with to indicated the current page was using a binary indicator for each page. Using three LEDs, I figured that I'd have 7 potential pages. 1's were HIGH, while 0's represented LOW.

1. - 1 0 0
2. - 0 1 0
3. - 0 0 1
4. - 1 1 0
5. - 0 1 1
6. - 1 0 1
7. - 1 1 1

If I needed the extra flexibility, I thought of using a blinking light which would be a 2. But after some thinking, I decided that blinkers would be too confusing and generally distracting, so I settled for the latter. Here is my testing using a breadboard without having to solder the components just yet. 

![3](https://user-images.githubusercontent.com/74937113/117231513-53d11d80-aded-11eb-900e-d0ee94c2bcbd.jpg)


I had to calculate simple circuitry values such as what voltage my LEDs would use and the strength of their resistors. This was done using Ohm's Law and was straight forward as each LED would be seperate in their own series loops. 

Once the light emitting diodes and resistors were soldered together, I connected them to my Arduino as follows. I forgot to include the resistors in the planning, but I did account for them!

![7](https://user-images.githubusercontent.com/74937113/117230265-b674ea00-adea-11eb-87af-e3fac6dc9452.png)

My final steps were to design the main casing and the bottom panel. I went through several iterations of the body, but this is the one I came up with. The top grooves allowed for a stable friction security mechanism, which kept the keys in place. The LED holes and supports also had to be accounted for. The bottom panel essentially uses friction to be held in place. I wanted something that would not move while in daily use, but easy to remove for maintenance or adjustments. 

![4](https://user-images.githubusercontent.com/74937113/117227234-58dd9f00-ade4-11eb-8b52-ad30677da713.png)

And here is the final design!

![5](https://user-images.githubusercontent.com/74937113/117227236-59763580-ade4-11eb-8d2a-2614964dda7d.jpg)



Usage
As I only have access to a laptop, I do not have access to the number pad that would often come with keyboards for a desktop. This macro keypad can be easily programmed to execute keyboard shortcuts and functions.

For example, I currently have my first page as general buttons like volume, copy & paste, etc. My second page is meant soley for software shortcuts, like opening Google Chrome, Spotify and Teams. The remaining pages are keybinds for certain programs like Discord, Microsoft Teams, and several games. 


SUPPORT

If you plan on attempting this project yourself, just reach out to me! I found that talking to people with more experience really helped me, as this was something I'd never done before. I looked through many similar designs online, reached out to my peers and academic associates from my University, and joined online communities to get a well rounded viewpoint on the aspects of my project.

I can be contacted at leer78@mcmaster.ca.

ROADMAP

The entire project took about a weeks worth of time. 
Day 1 - 3: Designing, modelling, and 3D printing the key caps and switches.
Day 3-4: Soldering the circuit matrix.
Day 4-5: Researching and adding LED functionality.
Day 6: Programming the shortcuts.
Day 7: Testing different cases and bottem panels.

