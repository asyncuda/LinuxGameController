build:
	gcc -Wall -o ../jsGamePad.out jsGamePad.c jsAPI.c uinput_set.c DeviceEvent.c input-event-lua.c -llua5.3
js:
	gcc -Wall -c jsAPI.c 		
old:
	gcc -Wall GamePad_main.c DeviceEvent.c DeviceConfig.c input-event-lua.c -o GamePad.out -L. -I/home/usual/lua-5.3.4/src -llua -lm -ldl
device:
	gcc -Wall -c DeviceEvent.c
config:
	gcc -Wall -c DeviceConfig.c -L. -I/home/usual/lua-5.3.4/src -llua -lm -ldl 		
input:
	gcc -Wall input-event-lua.c -o input.out -L. -I/home/usual/lua-5.3.4/src -llua -lm -ldl

	gcc -Wall -c jsAPI.c -L. -I/home/usual/lua-5.3.4/src -llua -lm -ldl 		
