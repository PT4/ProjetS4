#!/bin/bash

chemin=$(pwd);

echo "===> Entrez votre mot de passe <===";
sudo -i;

echo "===> Quelle est votre Architecture 32/64 bits <===";
echo "Etes-vous en architecture 32 bits? y/n"; 
read archi;

while [ "$archi" != "y" ] && [ "$archi" != "n" ] && [ "$archi" != "Y" ] && [ "$archi" != "N" ]
do
	echo "Etes-vous en architecture 32 bits? y/n"; 
	read archi;
done

cd "$pwd";

if [ "$archi" != "y" ] || [ "$archi" != "Y" ]
then
	tar -xvf SFML-1.6-sdk-linux-32.tar.gz;
else
	tar -xvf SFML-1.6-sdk-linux-64.tar.gz;
fi

apt-get build-dep libsfml;

cd SFML-1.6;

make;

make install;

make sfml-samples;

apt-get install libcsfml1.6-dev;

cd ..;

rm -r ./SFML-1.6;
