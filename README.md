# Lobber
A multi-tool radio transmitter capable of controlling whatever




# 6/29/2026 - Built the prototype on a breadboard
I started by drawing out a rough idea of what I wanted to make. This is supposed to be a multi-controller, but its going to be primarily used for controlling a drone I'm making, so a pair of valuable components were two joysticks. I gathered the one I already have (the other one is on its way from Aliexpress). The remote will also feature an accelerometer/gyroscope (an MPU6050 I had lying around), since I'm thinking of using that for controlling games. The drone I plan to use this on will have the ability to send IR signals like a flipper (to mess with TVs and stuff), so I also included an IR receiver to capture and copy things like TV remotes. Most importantly, I used an NRF24L01 breakout for the radio.<br><br>
I wired everything in a fashion that was similar to how the final result would look, although the wires stick up more than I'd like them to, but I will solve that later. I might have to keep everything in a breadboard, since I'll need this done by a deadline, and JLCPCB takes a bit long.<br>
After everything was wired up to the ESP32, I tested each component.
First was the MPU6050, which was a pain to get working. I had wired it perfectly to the best of my knowledge, but the Adafruit MPU6050 library refused to recognize it. After some digging I learned about the whoami address mismatch common among clones. The legit address was 0x68, when the legit one was 0x98. This was solved by modifying the library to recognize the latter.<br><br>
I wasn't very familiar with infrared communication, so I spent some time googling and learning about them. Plus, the IR receiver was freshly desoldered from an old toy, so I had to mess around with it to learn the pinout.<br><br>
While testing the radio transmitter, the receiver code I had set up before miraculously stopped working. I lost my head trying to figure out why nothing was successfully flashing to the microcontroller, and its fix was simply restarting vscode, which was mildly annoying.<br><br>
I then added some more parts, namely a display and some buttons. Here is the result thus far:<br><br>
<img width="1112" height="649" alt="image" src="https://github.com/user-attachments/assets/b1c4143a-a993-4491-8062-ffc4fc1b1bff" /><br>
Time Spent: 5 hours
