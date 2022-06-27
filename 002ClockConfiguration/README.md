Board: 		STM32F3D-discovery </br>
MCU: 		STM32F303VCT6 </br>

# Abstraction:
Showing the importance of peripheral clock enabling before using a peripheral

# Description:
At first, As shown in the figure1, we tried to change the 0th pin of the GPIOA port mode to alternate function but encountered failure.(commit: f44e46e2f40c2) </br>
The failure was because of that peripheral clocks are almost disabled by default, for power saving. </br>
![figure1](https://gcdnb.pbrd.co/images/bo8vBDw68Zov.png) </br>

As second try, we enabled GPIOA peripheral clock by configureing RCC_AHBENR in RCC memory map registers and as show in the figure2, modifying the 0th bit of the GPIOA mode was successfull.(commit:822b51e6da)</br>
![figure2](https://gcdnb.pbrd.co/images/tdAD1xpP5zQM.png)

