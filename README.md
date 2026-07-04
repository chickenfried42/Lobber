# Lobber
A multi-tool radio transmitter capable of controlling whatever you want. Its main reason for existence is to control a quadcopter I'm making, though.
It features:
- An ESP32 devboard 
- Two joysticks
- An accelerometer+gyro
- An NRF24L01 radio transceiver
- An OLED display
- An IR receiver used to copy and relay signals across greater distancess
Why is it called a Lobber?<br>
I like how the word sounds and I couldn't think of anything else. Its also my favorite projectile shooter in the hit game Cuphead

<img width="1235" height="857" alt="image" src="https://github.com/user-attachments/assets/613b7486-7f1b-4fc1-bb67-199a01df0c69" />

<img width="947" height="641" alt="image" src="https://github.com/user-attachments/assets/516b0533-9397-4fde-8e51-6dd2d598f446" />
<img width="897" height="663" alt="image" src="https://github.com/user-attachments/assets/0a548369-17e5-462e-83bb-f51c189fb79e" />
<img width="669" height="541" alt="image" src="https://github.com/user-attachments/assets/af755d14-d18a-4076-bf0d-40ee71de20db" /><br>
<img width="198" height="240" alt="image" src="https://github.com/user-attachments/assets/45ca6b96-22c7-4f61-9e97-674236531a58" />




# Assembly
This was assembled on two breadboards. Note that one breadboard had one of its side rails removed to make the whole thing less wide. <br>
- The cylindrical button things should be inserted from below the the cover
- The small pins are used to keep the joysticks in place. You may need to sand them before inserting them into the holes, as they don't fit very well
<br>
<img width="1157" height="855" alt="image" src="https://github.com/user-attachments/assets/e1427f27-db77-407c-913a-ec66a7925296" /><br><br>

# Wiring 
The wiring is as follows (but is somewhat flexible):<br>
- The imu and display use default i2c pins for the esp32
- The NRF24L01 uses the default spi pins, CS is pin 5, and CE is pin 4
- The buttons and joysticks can be wired anywhere as long as the firmware is tweaked a little
- The IR receiver's signal pin is wired to pin 13
- A bunch of buttons (obviously)



<br>
*Firmware may be a little incomplete tho


# BOM
|Name             |Qty  |Price/Unit ($)|Link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|-----------------|-----|--------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|Esp32            |1    |5.21          |https://www.aliexpress.us/item/3256808584827377.html?spm=a2g0o.productlist.main.1.43991a2bmL0byc&algo_pvid=aab6ed35-5c00-47da-8f11-921797a1ca8d&algo_exp_id=aab6ed35-5c00-47da-8f11-921797a1ca8d-0&pdp_ext_f=%7B%22order%22%3A%221154%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%213.14%212.85%21%21%2121.21%2119.28%21%4021033d1217831359894054377efc21%2112000046602507590%21sea%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&curPageLogUid=aZhCseKckxbb&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008771142129%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                 |
|Joysticks        |2    |1.19          |https://www.aliexpress.us/item/3256808897847272.html?spm=a2g0o.order_list.order_list_main.28.1bb61802Uf8ZEe&gatewayAdapt=glo2usa                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
|Tactile Switches |4    |2.57          |https://www.aliexpress.us/item/3256804784951471.html?spm=a2g0o.productlist.main.4.9a0c4fb8wce1OG&aem_p4p_detail=20260703204025809285708755440002972460&algo_pvid=690dd0f3-ee82-40d1-9945-fac9f6cd50e6&algo_exp_id=690dd0f3-ee82-40d1-9945-fac9f6cd50e6-3&pdp_ext_f=%7B%22order%22%3A%223964%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.62%212.57%21%21%212.62%212.57%21%402103122117831364250726763ecbf0%2112000031200483143%21sea%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&curPageLogUid=WmdAzJaw5dfP&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005004971266223%7C_p_origin_prod%3A&search_p4p_id=20260703204025809285708755440002972460_1                                                                                                                                                      |
|MPU6050 breakout |1    |2.71          |https://www.aliexpress.us/item/3256807462344600.html?spm=a2g0o.productlist.main.1.63244922KiGyJU&algo_pvid=8265e72d-f143-4dcc-8173-12834d4ffe79&algo_exp_id=8265e72d-f143-4dcc-8173-12834d4ffe79-0&pdp_ext_f=%7B%22order%22%3A%22583%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.71%212.71%21%21%2118.30%2118.30%21%402103122117831367286912566ecbec%2112000041645887089%21sea%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&curPageLogUid=mx2pONRM8Hyh&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007648659352%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                  |
|IR Receiver 38khz|1    |1.78          |https://www.aliexpress.us/item/3256807990185007.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.1.2817izFPizFPl4&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=083fdf62-68d3-4d5f-b136-c5f008d7431a&_t=gps-id%3ApcDetailTopMoreOtherSeller%2Cscm-url%3A1007.40050.354490.0%2Cpvid%3A083fdf62-68d3-4d5f-b136-c5f008d7431a%2Ctpp_buckets%3A668%232846%238108%231977&pdp_ext_f=%7B%22order%22%3A%22681%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21USD%211.93%211.84%21%21%2113.01%2112.38%21%40210327ef17831368062333666e11e7%2112000044118964695%21rec%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005008176499759%7C_p_origin_prod%3A|
|SSD1306          |1    |4.17          |https://www.aliexpress.us/item/3256805954920554.html?spm=a2g0o.productlist.main.4.83af198bC3Bbkn&aem_p4p_detail=2026070320503312935497816503180002957711&algo_pvid=b2397792-65f0-4e61-a073-93db302ca01a&algo_exp_id=b2397792-65f0-4e61-a073-93db302ca01a-3&pdp_ext_f=%7B%22order%22%3A%2227695%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%212.74%212.74%21%21%2118.49%2118.49%21%4021032f3717831370335866153e0467%2112000035944225407%21sea%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&curPageLogUid=gnXG8jOLTMyR&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006141235306%7C_p_origin_prod%3A&search_p4p_id=2026070320503312935497816503180002957711_1                                                                                                                                               |
|NRF24L01         |1    |1.9           |https://www.aliexpress.us/item/3256808149584928.html?spm=a2g0o.productlist.main.4.13f22a0dycf8kL&aem_p4p_detail=202607032051347277186822209150002898628&algo_pvid=67cda7e6-993a-458b-99ed-950aceccdc31&algo_exp_id=67cda7e6-993a-458b-99ed-950aceccdc31-3&pdp_ext_f=%7B%22order%22%3A%22153%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%215.58%211.90%21%21%2137.66%2112.80%21%40210318a717831370945232208e1740%2112000045000990300%21sea%21US%217004005172%21X%211%210%21n_tag%3A-29919%3Bd%3A67e545d3%3Bm03_new_user%3A-29895&curPageLogUid=Tk2vdVdgps8I&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008335899680%7C_p_origin_prod%3A&search_p4p_id=202607032051347277186822209150002898628_1                                                                                                                                                   |
|BT3x8 Self Tapping Screws         |4    |1.07           |https://us.store.bambulab.com/products/bt3-socket-head-cap-self-tapping-screws-shcs-new?id=42382271611016|
|Jumper Wires     |<4269|              |theyre really common                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|Total            |     |20.6         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |



# Journal

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
