FILE=./testShell00
echo $(`rm testShell00`)
echo $(`touch testShell00`)

for ((i = 0 ; i < 16 ; i++)); do
  echo $i >> $FILE
done
echo $(`echo " " >> testShell00`)

echo $(`chmod 455 testShell00`)
echo $(`touch -t 202106020730.00 $FILE`)
echo $(`tar -cf testShell00.tar testShell00`)
echo "Done!"