# MartEditBW
version 0.1

MartEditBW allows to edit the items of every shop  in Black/White (untested in White tbh) and edit the price of every item.
This app does not support adding additional items to the shop or editing BP price.

If the application fails to open try installing the [VC redistribution](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170)

## Required Tools

1. Download [TinkeDSi](https://github.com/R-YaTian/TinkeDSi/releases)
2. Download [Knarc-UI](https://github.com/dev-cyw/Knarc-UI/releases)
3. Download [Nintendo_DS_Compressors](https://www.romhacking.net/utilities/826/)
4. Download [HxD](https://mh-nexus.de/en/hxd/)

## How to use
(Ignore the fact that some Tinke screenshots say Pokemon White 2, I'm a dumbass. You should find the same files in the same place when you open the correct ROM)
### Item Tab
__THESE STEPS ONLY HAS TO BE PERFORMED ONCE PER ROM:__

1. Extract file ``y9.bin`` using Tinke         
![](resources/tinke_y9.png)
2. Open the file ``y9.bin`` using HxD
3. Go to the line ``000002B0`` and change the last byte from ``03`` to ``02``           
![](resources/hxd_y9_mod.png)
4. Save the ``y9.bin`` file
5. Reimport the ``y9.bin`` file into your ROM using Tinke
![](resources/tinke_y9_change.png)

__THESE STEPS HAVE TO BE PERFORMED EVERYTIME YOU MAKE CHANGES TO THE MARTS:__

1. Extract file ``overlay9_21`` using Tinke           
![](resources/tinke_ovl21.png)
2. Open a cmd console in the folder where you stored the [Nintendo_DS_Compressors](https://www.romhacking.net/utilities/826/) tools               
![](resources/open_cmd.png)
3. From the command console use the ``blz`` exe with the decompress option (``-d``) on the ``overlay9_21`` file:
  - The generic command is ``blz.exe -d [your overlay path]/overlay9_21``
  - Since I have the ``blz.exe`` and ``overlay9_21`` in the same forlder, and I opened the cmd from that folder the command I need to use is ``blz.exe -d overlay9_21``            
![](resources/blz_cmd.png)
4. Now open MartEditBW and using the ``...`` button find and select the ``overlay9_21`` file
5. All the marts should load and you can now change the items in them (remember you have to Save after each mart modification)
6. Once you have applied the changes you want, reimport the ``overlay9_21`` file into your ROM using Tinke            
![](resources/tinke_ovl21_change.png)

### Price Tab

