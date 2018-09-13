# YunOSC-Animation 

Yuntech Open Source Club Animation
雲科開放原始碼研究社的螢幕保護程式:33

![Animation](https://raw.githubusercontent.com/garyparrot/garyparrot.github.io/master/osca.png)

## Requirement for library

```
libcaca-dev - development files for libcaca ver 0.99
libcaca0 - colour ASCII art library ver 0.99
glibc - GNU C library
```

## Guide for execute program
This guide perform on Debian.

Btw there is no guide for Arch users, you all know how it goes.

```
$ sudo apt-get install libcaca-dev libcaca0
$ sh -c 'gcc `pkg-config --libs --cflags caca` osca.c ascii_art/ascii_art.c drawing/draws.c drawing/patterns.c'
$ ./a.out
```

## Key 

|Key|Function|
|---|---|
|q|Move the hat down one character|
|a|Move the hat up one character|
|w|Move the title up one character|
|s|Move the title down one character|
|c|Change the color of drop-down-effect|
|\<ESC\>|Exit YunOSC Screen Saver|
