# ToneGenerator for NEC
Il s’agit de réaliser un petit générateur de son et d’ultrason afin de faire connaitre au public, le monde des chauve-souris lors des NEC ( nuit européenne des chauve-souris).

This involves creating a small sound and ultrasound generator in order to raise awareness of the world of bats during the NEC (European Bat Night).

## Projet initial : 
La première version du générateur de son/ultarson étais axée sur un NE555 bien connus de nos ancien dont je fais partie, mais le principal inconvénient est sa stabilité dans le temps ceci dû au composant utilisé pour la génération du signal rectangulaire analogique. De nombreux utilisateur se plaignais des erreurs de fréquence assez importante dû au vieillissement des résistances du contacteur rotatif et des condensateurs. 
Project actuel : 
Etant donné le nombre de réparation qui m’étais demandé, j’ai décidé de mettre ce projet au gout du jour. Dès lors, J’ai basé ce nouvel opus sur un Arduino Pro-Mini (5V) qui lui restera suffisamment stable en fréquence grâce a son Xtal de 16Mhz et donc en faire aussi un appareil de calibrage pour les anciens détecteurs tel que les anciens Petterson ou de vérifier l’état de vos micro ultrasonique. J’ai donc gardé cette idée axée autour du contacteur rotatif (un potentiomètre linaire peut aussi faire l’affaire) avec une combinaison permettant d’atteindre une fréquence maximum de 32KHz, bien sur il faut que le HP piezo arrive à diffuser cette fréquence.

## Decriptif : 
L’ensemble est axé sur l’Arduino soudé sur une petit circuit imprimé que vous trouverais dans le dossier **PCB-SMD**. Il est possible de le faire vous-même avec des anciennes résistances plutôt que l’utilisation des composant de surface. Mais l’idée est de faire fabriquer l’ensemble de vos circuits par une société tel que JCBPCB qui propose en plus de réalisation des circuits et le montage des composants SMD. Il faut compter a ce jour (2024) +/-24€ + port pour 20 pièces.
Il vous restera a souder le contacteur rotatif , l’Arduino et quelque fils entre les autres composants du projet.
Dans le dossier **Making**, se trouve, le dossiers des fichier Gerber pour JCBPCB ou votre fabriquant favori, ainsi que les plan du boitier en bois et les divers composant que j’ai utilisé pour ce projet.
Inutile de dire que le software se trouve dans le dossier **soft** 😉

Je vous souhaite bien du plaisir pour réaliser ce petit projet cher au passionné des chauve souris dont je fais partie dans le groupe des volontaire Plecotus de Natagora Belgique. 



## Initial project:
The first version of the sound/ultarson generator was based on a NE555 well known to our elders of which I am a part, but the main disadvantage is its stability over time, due to the component used for the generation of the analog rectangular signal. Many users complained of fairly significant frequency errors due to the aging of the rotary contactor resistors and capacitors.
Current project:
Given the number of repairs that were required of me, I decided to bring this project up to date. From then on, I based this new opus on an Arduino Pro-Mini (5V) which will remain sufficiently stable in frequency thanks to its Xtal of 16Mhz and therefore also make it a calibration device for old detectors such as the old Petterson or check the condition of your ultrasonic microphone. I therefore kept this idea centered around the rotary contactor (a linear potentiometer can also do the trick) with a combination allowing a maximum frequency of 32KHz to be reached, of course the piezo speaker must be able to diffuse this frequency.

## Description:
The whole thing is focused on the Arduino soldered on a small printed circuit that you will find in the **PCB-SMD** folder. It is possible to do this yourself with old resistors rather than using surface components. But the idea is to have all of your circuits manufactured by a company such as JCBPCB which offers, in addition to the creation of circuits, the direct assembly of SMD components. As of today (2024) it is necessary to count +/-24€ + shipping for 20 pieces.
You will still have to solder the rotary contactor, the Arduino and some wires between the other components of the project, it's all.
In the **Making** folder, you will find the folders with the Gerber files for JCBPCB or your favorite manufacturer, as well as the plans of the wood case and the various components that I used for this project.
Needless to say, the software is in the **soft** folder 😉

I wish you a lot of fun carrying out this little project dear to the bat enthusiast of whom I am a part in the group of Plecotus volunteers from Natagora Belgium.