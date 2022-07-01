Board: 		STM32F3D-discovery </br>
MCU: 		STM32F303VCT6 </br>

# Abstraction:
Outputing HSI clock source</br>

# Description:
To do this we should first get familiar with MCO capability in MCU.</br>

What is MCO capability?</br>
  <pre>MCO capability allows us to output the clock onto the MCO pin.</pre></br>
Where is MCO pin?</br>
  <pre>As stated in MCU datasheet, MCO pin is multiplexed on PA8 (8th pin in port GPIOA), so for using MCO pin we should change PA8 to AF.</pre></br></br>
  
  
Now that we have been familiered with MCO capability, it's time to check out the steps needed for doing the project: </br>
1-Enable GPIOA peripheral clock</br>
  <pre>becasue MCO pin is multiplexed on PA8</pre></br>
2-Change PA8 functionality to MCO </br>
  <pre>For doing this, we should set PA8 mode to alternate functionality mode and then determine on which alternate functionality it should work.</pre></br>
3-determine MCO clock source</br></br>

After completing the above steps, we can use a low cost usb logic analyzer to watch the outputed clock signal on the computer. The output is look like sth like below:</br>
![logic_analyzer_output](https://gcdnb.pbrd.co/images/XPKiOaezFph3.png)
</br></br>
As stated in in STM32F3-DISK board user manual, its MCU has a 8MHz internal RC oscillator. So the above output is correct and we've done the project correctly.
