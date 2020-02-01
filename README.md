# Sa2CustomGarden
## A mod base to replace a selected garden model for Sonic adventure 2!
Did you ever want to modify the chao garden models? Or even create your own custom Gardens? Well, now is your time!*
Using this mod you can replace the stage geometry of the selected garden and have your chao roam around in a new environment!

* SET files are kinda complicated to edit yet, so the gardens cant be fully custom yet

## What you will need
- Your stage as an sa2blvl file
- Possibly a modified texture file of the original garden saved as a .pak
- The newest zip file from the release section of this github repo -> https://github.com/Justin113D/Sa2CustomGarden/releases

## How to set up
First, extract the folder inside the downloaded zip to the mods folder of sonic adventure 2. </br>
Open the mod.ini file, and change the Name, Description and Author to how you want them to be. </br>
Next you will need your sa2blvl file. It has to be named "**LandTable.sa2blvl**" (without quotation marks) for the game to find the file. </br>
If you replace the textures of the original garden, simply put your .pak into the gd_pc/PAK/ directory; Note that the file needs the same name as the original texture file of the garden that you are replacing, but be cautious when renaming (if you have to rename)! You cant just rename the file, you need to open it inside texture editor (see SATools) and save it with the correct filename. </br>
If you dont replace the textures, you should probably delete the gd_pc folder (considering you dont replace anything else). </br>
**Note:** If some textures arent working correctly, then you might want to check the global index of the added textures in the texture file, as those shouldnt be reused throughout the game. You can view which global indices are taken on this page: https://mm.reimuhakurei.net/misc/sa2pcgbix.txt ; simply check which id isnt taken yet and set the global index of the new texture to it!


We are almost done! Open the mod loader for sa2, go to your mod, select it, and click "configure" below the mod list. In there, you can set which garden to replace and what the new texture count is. </br>
**Leaving the texture count at 0 will use the default texture count of the original texture file!** </br>
Now save, and test your mod ingame!

## Enjoy!
No need to credit me, its the custom garden that counts! I hope to see some crazy gardens ^~^
