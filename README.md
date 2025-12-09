## Template project for Nucelo-F767zi using Premake5

This project uses Premake5 to generate Makefiles. Note that Premake5 does not support Ninja, so you cannot generate Ninja build files.

Another known issue is that the make clean command does not remove the build folder. You will need to either add that functionality manually to the Makefile or remove the folder manually.

You may also want to include flags in the mcu_stm32f767.lua file. For any new microcontroller, you should create a new configuration file where you define the values suitable for your specific microcontroller.


### Note:
Use it at your own risk. 
Mariwan  
