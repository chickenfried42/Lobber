# Lobber
A multi-tool radio transmitter capable of controlling whatever




# 6/29/2026 - Built the prototype on a breadboard
I started by drawing out a rough idea of what I wanted to make. This is supposed to be a multi-controller, but its going to be primarily used for controlling a drone I'm making, so a pair of valuable components were two joysticks. I gathered the one I already have (the other one is on its way from Aliexpress). The remote will also feature an accelerometer/gyroscope (an MPU6050 I had lying around), since I'm thinking of using that for controlling games. The drone I plan to use this on will have the ability to send IR signals like a flipper (to mess with TVs and stuff), so I also included an IR receiver to capture and copy things like TV remotes. Most importantly, I used an NRF24L01 breakout for the radio.<br><br>
I wired everything in a fashion that was similar to how the final result would look, although the wires stick up more than I'd like them to, but I will solve that later. I want to leave everything on a breadboard, since pcbs kinda take long.<br>
After everything was wired up to the ESP32, I tested each component.
First was the MPU6050, which was a pain to get working. I had wired it perfectly to the best of my knowledge, but the Adafruit MPU6050 library refused to recognize it. After some digging I learned about the whoami address mismatch common among clones. The legit address was 0x68, when the legit one was 0x98. This was solved by modifying the library to recognize the latter.<br><br>
I wasn't very familiar with infrared communication, so I spent some time googling and learning about them. Plus, the IR receiver was freshly desoldered from an old toy, so I had to mess around with it to learn the pinout.<br><br>
While testing the radio transmitter, the receiver code I had set up before miraculously stopped working. I lost my head trying to figure out why nothing was successfully flashing to the microcontroller, and its fix was simply restarting vscode, which was mildly annoying.<br><br>
I then added some more parts, namely a display and some buttons. Here is the result thus far:<br><br>
<img width="1112" height="649" alt="image" src="https://github.com/user-attachments/assets/b1c4143a-a993-4491-8062-ffc4fc1b1bff" /><br>
Time Spent: 5 hours

# 6/30/2026 & 7/1/2026 - Wrote some firmware and a dodgy driver
I added two operating modes to the lobber: Joystick mode and IMU mode. The former takes input from a joystick and moves the mouse accordingly. The latter only moves the mouse in the x and y direction. This is because I couldn't figure out all the scary math needed for getting angles from accelerometers and gyros because I'm dumb. How it works is that the transmitter sends the direction to a receiver, which relays it through a serial connection to my PC. Then, a program moves my mouse and sends keystrokes and all other things. I wrote that program in NodeJS, using the nutjs package. I wasted some time trying to build the package (since package was paywalled), but realized the core package which had everything I needed was stil installable. Anyway I got it to work after a couple hours.<br>
<img width="452" height="230" alt="image" src="https://github.com/user-attachments/assets/d54e6f4e-3d83-4540-8eb2-0beea65072e9" /><br><br><br>
Time Spent: 4 hours

# 7/2/2026 - CAD
<img width="512" alt="image" src="https://github.com/user-attachments/assets/94b727ed-84dd-4354-940f-710b77fb48d4" /><br>
<img width="512" alt="image" src="https://github.com/user-attachments/assets/97d5d2e7-7028-40d6-beff-263592dc83c1" />
After 2 days of firmware (torture), I took the morning to sketch out and model the dimensions of the bottom half of the case. Something notable was when I chose Bambu Lab's BT3x8 screws for attaching the lid, since they were self tapping. Up until today, I didn't know that "self tapping" meant the screw could make its own threads, so I've been cutting thread holes from the screw's model the whole time. To my shock, the 3d print came out perfectly.
<br><br>
Designing the lid of the case was harder, since I had to deal with the buttons, joystick, and display. <br>For the buttons, I made some holes with extruded cylinders of slightly less diameter that push the switches underneath.
<br>
For the joysticks, I couldn't find any mounting hole dimensions from the seller, so I had to measure them. My measurements were inaccurate, so I ended up with some badly placed holes (they were also too small due to carelessness). To solve that issue, I 3d printed some pins to hold them in place.<br><br>Overall I'm proud of the CAD for this project. It could have been a lot worse given my other projects..
<br><br>
<img width="512" alt="image" src="https://github.com/user-attachments/assets/9e25fd9a-8c35-4d5a-a5a2-bbac8755c5a2" />
<br><br>
Time Spent: 6 hours
