Board: 		STM32F3D-discovery </br>
MCU: 		STM32F303VCT6 </br>

# Abstraction : </br>
Switching system clock to HSE and measure it</br>

# Description : </br>
This project is similar to 003HSI_Measurement, but before configure MCO pin we should enable HSE and set it as system clock.</br>
So for doing this project, we should do the following steps : </br>
1- Enable the HSE clock</br>
<pre>
By enabling HSEON bit in RCC_CR, HSE clock is enabled
</pre>
2- Specify the way that HSE is provided
<pre>
As we know there is two ways that HSE can be provided to the MCU : 
a) By connecting external crystal
b) By bypassing external crystal 
As mentioned in STM32F3-DISK board's user manual, HSE is provided from ST-LINK circuit and we can specify it using HSEBYP bit in RCC_CR.
</pre>
3-Switch the system clock to HSE
<pre>
This setting can be done by configuring SW bits in RCC_CFGR register.
</pre>
4-Do MCO settings to measure it
