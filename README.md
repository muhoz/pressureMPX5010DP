# pressureMPX5010DP
                                                     A simple code to use Arduino pressure sensor MPX5010DP

This is a simple code to use a pressure sensor MPX5010DP to detect gas. The idea there is to be able to detect the presence of gas and count the elapsed time to know the consumption made in the house.

To know the consumption, we have take the case of our african homes. Here, we sell bottle gas with different types of weight but we will focus on the 13.5Kg. 
By surfing on the web we see that on average, a household with a firecooker of 4 fire can make 130 hours to finish, we will use this information to evaluate the consumption of the bottle.

The connection between the MPX5010DP and the Arduino is simple:



MPX5010DP             ------------------             Arduino

5V                ----------------------------          5V

GND                         ---------------             GND

OUTPUT                      ---------------             Analog Pin(A2)


An image of the sensor :  ![image](https://user-images.githubusercontent.com/71699176/136206913-744372e9-0f20-49b5-9857-89bd33fd65cd.png)

Source: Octopart.com

