# ToneGenerator for NEC

[Project sample](AtWork/Images/Presentation.jpg)

Il s’agit de réaliser un petit générateur de son et d’ultrason afin de faire connaitre au public, le monde des chauve-souris lors des NEC ( nuit européenne des chauve-souris).

This involves creating a small sonic and ultrasonic generator in order to raise awareness of the world of bats during the NEC (European Bat Night).

_____________________________________________________________

## Projet initial : 
La première version du générateur de son/ultarson étais axée sur un NE555 bien connus de nos ancien dont je fais partie, mais le principal inconvénient est sa stabilité dans le temps ceci dû au composant utilisé pour la génération du signal rectangulaire analogique. De nombreux utilisateur se plaignais des erreurs de fréquence assez importante dû au vieillissement des résistances du contacteur rotatif et des condensateurs. 
## Project actuel : 
Etant donné le nombre de réparation qui m’étais demandé, j’ai décidé de mettre ce projet au gout du jour. Dès lors, J’ai basé ce nouvel opus sur un Arduino Pro-Mini (5V) qui lui restera suffisamment stable en fréquence grâce a son Xtal de 16Mhz et donc en faire aussi un appareil de calibrage pour les anciens détecteurs tel que les anciens Petterson ou de vérifier l’état de vos micro ultrasonique. J’ai donc gardé cette idée axée autour du contacteur rotatif (un potentiomètre linaire peut aussi faire l’affaire) avec une combinaison permettant d’atteindre une fréquence maximum de 32KHz, bien sur il faut que le HP piezo arrive à diffuser cette fréquence. 
Ce montage fonctionne sur une pile de 9V, mais peut-être facilement adapté pour une alimentation 12v en y ajoutant un régulateur AMS1117—5V (ensemble D1-IC1).

### Descriptif : 
L’ensemble est axé sur l’Arduino Pro Mini soudé sur un petit circuit imprimé que vous trouverais dans le dossier PCB-SMD. Il est possible de faire soi-même ce circuit en utilisant d’anciennes résistances plutôt que l’utilisation des composant de surface. Mais l’idée est de faire fabriquer l’ensemble de vos circuits par une société tel que JLCPCB qui propose le montage des composants SMD et de le tropicaliser plus facilement avec un vernis adéquat. Il faut compter à ce jour (2024) +/-24€ + port pour 20 pièces. Il vous restera à souder le contacteur rotatif, l’Arduino et quelque fils entre les autres composants du projet.
### PCB & Gerber
Dans le dossier **Dossier -JLCPCB** se trouve, les fichiers pour JLCPCB ou votre fabriquant favori,
Vous y trouverais aussi les fichiers Gerber, les fichier KidCad 7.xx ainsi que ses librairies et une version PDf de ces fichiers.

### AtWork
Ce dossier comprend la liste du matériel dont vous avez besoin, le plan de câblage, un exemple de plan d’assemblage du boitier en bois, le STL pour imprimer le support du circuit si vous ne voulez pas le coller au boitier et quelques images.
Imprimez ‘pannel.jpg’ et plastifiiez-le. Il sera la face supérieure sur laquelle sera fixé l’interrupteur et le commutateur rotatif à 12 positions 
### Software
Inutile de dire que le software se trouve dans ce dossier 😉

Je vous souhaite bien du plaisir pour réaliser ce petit projet cher au passionné des chauve-souris dont je fais partie dans le groupe des volontaire Plecotus de Natagora Belgique. 

___________________________________________________________________________________________________ 

## Initial project: 
The first version of the sonic/ultarsonic generator was based on a NE555 well known to our elders of which I am a part, but the main disadvantage is its stability over time, due to the component used for the generation of the analog rectangular signal. Many users complained of fairly large frequency errors due to the aging of the rotary contactor resistors and capacitors. 
## Current project: 
Given the number of repairs that were required of me, I decided to bring this project up to date. From then, I based this new opus on an Arduino Pro-Mini (5V) which will remain sufficiently stable in frequency wit Xtal 16Mhz inside and therefore also make it a calibration device for old detectors such as the old Petterson or check the condition of your ultrasonic microphone. I therefore kept this idea centered around the rotary contactor (a linear potentiometer can also used) with a combination allowing a maximum frequency of 32KHz to be reached, of course the piezo speaker must be able to diffuse this frequency. This assembly runs on a 9V battery, but can easily be adapted for a 12v power supply by adding an AMS1117—5V regulator (D1-IC1 set). 
### Description:
 The whole thing is focused on the Arduino Pro Mini soldered on a small printed circuit that you would find in the PCB-SMD folder. It is possible to make this circuit yourself using old resistors rather than using surface components. But the idea is to have all of your circuits manufactured by a company such as JLCPCB which offers the assembly of SMD components and to tropicalize it more easily with a suitable varnish. As of today (2024), you need to count +/-24€ + shipping for 20 pieces. You will still have to solder the rotary contactor, the Arduino and some wires between the other components of the project. 
### PCB & Gerber
In the floder **Dossier-JLCPCB** you will find the files for JLCPCB or your favorite manufacturer, You will also find Gerber files, KidCad 7.xx files as well as its libraries and a PDF version of these files. 
### AtWork
This file includes the list of materials you need, the wiring plan, an example of an assembly plan for the wooden case, the STL to print the circuit support if you do not want to glue it to the case and some images. 
Print ‘pannel.jpg’ and laminate it. It will be the upper face on which the switch and the 12-positions rotary switch will be fixed. 
 
###Software
Needless to say, the software is in this folder 😉
I wish you a lot of fun carrying out this little project dear to the bat enthusiast of which I am a part in the group of Plecotus volunteers from Natagora Belgium.
