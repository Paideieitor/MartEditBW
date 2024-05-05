MartEditBW
version 0.1

MartEditBW allows to edit the items of every shop  in Black/White and edit the price of every item.
This app does not support adding additional items to the shop.

If the application fails to open try installing the [VC redistribution](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170)

How to use

Item Tab
To edit the items extract the overlay9_0021.bin file using Kiwi.ds editor or CrystalTile2 (I tried using Tinke but the file seems to be compressed or sliced)
Once extracted, load the file it in MartEditBW using the File search, select the shop, the slot and the new item you want to change
To save your changes use the Save button when you are done editing a shop, a new .bin file will be created with the changes (saving multiple times does not create multiple files)
Once all the changes have been saved use Tinke to change the overlay9_21 file for our changed overlay9_0021.bin

Price Tab
To edit the prices extract the UNPACKED folder a/0/2/4 using Tinke
Once the folder is extracted, load it in MartEditBW the Folder search, select the item and input the new price
To save the price use the Save button on every object that is changed, a Changed folder will be created in the same dirtectory the extracted files are where the changed files will be stored
Once all changes have been made use Tinke to unpack the a/0/2/4 folder and replace each file from the Changed folder individually
When all the files have been changed (still in Tinke), remember to PACK the a/0/2/4 folder
