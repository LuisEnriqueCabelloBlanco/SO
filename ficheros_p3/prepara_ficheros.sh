#!/usr/bin/bash
read dir
if [ -d $dir ]
then
	echo "Vampiro esiste"
	rm -r $dir
	mkdir $dir
else
	echo "Vampiro no esiste"
	mkdir $dir
fi
cd $dir
mkdir subdir
touch fichero1
echo "hola esto es una carta de ayuda porfavor si lees esto saqueme de la complutense">>fichero2
ln --symbolic -T fichero2 enlaceS
ln -T fichero1 enlaceH
for i in $(ls "../$dir")
do
    stat $i
done
