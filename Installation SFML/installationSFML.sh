#!/bin/bash
clear;
echo "================== Utilitaire d'installation de la SFML 1.6 ==================";
echo "";
echo "";
echo "===> Quelle est votre Architecture 32/64 bits <===";
echo "Etes-vous en architecture 32 bits? y/n";

read archi;

while [ "$archi" != "y" ] && [ "$archi" != "n" ] && [ "$archi" != "Y" ] && [ "$archi" != "N" ]
do
	echo "Etes-vous en architecture 32 bits? y/n";
	read archi;
done

if [ "$archi" != "y" ] || [ "$archi" != "Y" ]
then
	tar -xvf SFML-1.6-sdk-linux-32.tar.gz;
else
	tar -xvf SFML-1.6-sdk-linux-64.tar.gz;
fi

sudo apt-get build-dep libsfml;

cd SFML-1.6;

sudo make;

sudo make install;

make sfml-samples;

sudo apt-get install libcsfml1.6-dbg;

cd ..;

rm -r -f ./SFML-1.6;
