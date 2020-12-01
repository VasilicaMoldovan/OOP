:: sa nu ne deranjeze cu pathul de fiecare data
@echo off

nasm -fobj bytes_sum.asm
nasm -fobj sesi.asm

alink prob14.obj modul.obj -oPE -subsys console -entry start

echo Done!
pause