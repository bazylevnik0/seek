Tool for connecting to random sites and generate .bmp images from titles.<br>
<hr>
<hr>
install: <br>
1) Install Python, something like this:<br>
    "<b>sudo apt-get install python3</b>"<br>
    "<b>sudo apt-get install pip3</b>"<br>
2) Install BeatifulSoup for python, like this:"<b>pip3 install beautifulsoup4</b>"<br>
3) Install SDL, something like this:"<b>sudo apt-get install libsdl2-2.0-0 libsdl2-dbg libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dbg libsdl2-image-dev</b>"<br>
4) Compile interpretator: "<b>gcc interpretator.c `sdl2-config --cflags` -o interpretator `sdl2-config --libs`</b>"<br>
<hr>
launch: <br>
<b>"bash script.sh"</b> and wait results in folder "output"... repeat<br>
<hr><hr>
*it is for linux, but all libs cross-plotform, check docs
