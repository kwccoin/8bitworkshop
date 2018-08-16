﻿

#include <string.h>
#include <nes.h>

#include "neslib.h"

typedef unsigned char byte;

#pragma data-name (push,"CHARS")

const unsigned char TILESET[8*128] = {/*{w:8,h:8,bpp:1,count:128,brev:1}*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x7c,0x7c,0x7c,0x38,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6c,0x6c,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6c,0xfe,0x6c,0xfe,0x6c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xfe,0xd0,0xfe,0x16,0xfe,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xce,0xdc,0x38,0x76,0xe6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x6c,0x7c,0xec,0xee,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x70,0x70,0x70,0x70,0x70,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x38,0x38,0x38,0x38,0x38,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6c,0x38,0x6c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0xfe,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x1e,0x3c,0x78,0xf0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7c,0xee,0xee,0xee,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x78,0x38,0x38,0x38,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x0e,0x7c,0xe0,0xee,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x0e,0x3c,0x0e,0x0e,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0x7e,0xee,0xee,0xfe,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0xe0,0xfc,0x0e,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xe0,0xfc,0xee,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xee,0x1c,0x1c,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0x7c,0xee,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0xee,0x7e,0x0e,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x60,0x60,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x38,0x70,0x70,0x38,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x38,0x1c,0x1c,0x38,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0x1c,0x38,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7c,0xee,0xee,0xee,0xe0,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0xee,0xee,0xfe,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0xee,0xfc,0xee,0xee,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0xe0,0xe0,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0xec,0xee,0xee,0xee,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xe0,0xf0,0xe0,0xe0,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xe0,0xf8,0xe0,0xe0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xe0,0xee,0xee,0xee,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xee,0xfe,0xee,0xee,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x38,0x38,0x38,0x38,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x0e,0x0e,0x0e,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xfc,0xf8,0xec,0xee,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xe0,0xe0,0xe0,0xee,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc6,0xee,0xfe,0xfe,0xee,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xce,0xee,0xfe,0xfe,0xee,0xe6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0xee,0xee,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xfc,0xee,0xee,0xee,0xfc,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xee,0xee,0xee,0xec,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0xee,0xee,0xee,0xfc,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0xe0,0x7c,0x0e,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x38,0x38,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xee,0xee,0xee,0xee,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xee,0xee,0x6c,0x38,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xee,0xfe,0xfe,0xee,0xc6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0x7c,0x38,0x7c,0xee,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xee,0xee,0xee,0x7c,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x1c,0x38,0x70,0xe0,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#pragma data-name(pop)

//
// MUSIC ROUTINES
//

// Namespace(bias=1.0, freq=111860.8, length=64, maxbits=13.0, upper=41)
// 439.0 0.943191918851 41
const int note_table_41[64] = {
4318, 4076, 3847, 3631, 3427, 3235, 3053, 2882, 2720, 2567, 2423, 2287, 2159, 2037, 1923, 1815, 1713, 1617, 1526, 1440, 1360, 1283, 1211, 1143, 1079, 1018, 961, 907, 856, 808, 763, 720, 679, 641, 605, 571, 539, 509, 480, 453, 428, 403, 381, 359, 339, 320, 302, 285, 269, 254, 240, 226, 213, 201, 190, 179, 169, 160, 151, 142, 134, 126, 119, 113, };

// Namespace(bias=1.0, freq=111860.8, length=64, maxbits=13, upper=49)
// 440.5 1.79281159771 49
const int note_table_49[64] = {
4304, 4062, 3834, 3619, 3416, 3224, 3043, 2872, 2711, 2559, 2415, 2279, 2151, 2031, 1917, 1809, 1707, 1611, 1521, 1436, 1355, 1279, 1207, 1139, 1075, 1015, 958, 904, 853, 805, 760, 717, 677, 639, 603, 569, 537, 507, 478, 451, 426, 402, 379, 358, 338, 319, 301, 284, 268, 253, 239, 225, 213, 201, 189, 179, 168, 159, 150, 142, 134, 126, 119, 112, };

// Namespace(bias=1.0, freq=111860.8, length=64, maxbits=12, upper=63)
// 443.6 14.2328382554 63
const int note_table_63[64] = {
2137, 4034, 3807, 3593, 3392, 3201, 3022, 2852, 2692, 2541, 2398, 2263, 2136, 2016, 1903, 1796, 1695, 1600, 1510, 1425, 1345, 1270, 1199, 1131, 1068, 1008, 951, 898, 847, 800, 755, 712, 672, 634, 599, 565, 533, 503, 475, 448, 423, 399, 377, 356, 336, 317, 299, 282, 266, 251, 237, 224, 211, 199, 188, 177, 167, 158, 149, 141, 133, 125, 118, 111, };

// Namespace(bias=-1.0, freq=55930.4, length=64, maxbits=12, upper=53)
// 443.7 8.47550713772 53
const int note_table_tri[64] = {
2138, 2018, 1905, 1798, 1697, 1602, 1512, 1427, 1347, 1272, 1200, 1133, 1069, 1009, 953, 899, 849, 801, 756, 714, 674, 636, 601, 567, 535, 505, 477, 450, 425, 401, 379, 358, 338, 319, 301, 284, 268, 253, 239, 226, 213, 201, 190, 179, 169, 160, 151, 142, 135, 127, 120, 113, 107, 101, 95, 90, 85, 80, 76, 72, 68, 64, 60, 57, };

const int* note_table = note_table_63;
byte music_index = 0;
byte cur_duration = 0;

const byte music1[]; // music data -- see end of file
const byte* music_ptr = music1;

byte next_music_byte() {
  return *music_ptr++;
}

#define DUTY_75 0xc0
#define DUTY_50 0x80
#define DUTY_25 0x40
#define DUTY_12 0x00

#define DUTY (DUTY_25 | 0x1)	// decay rate == 1

void play_music() {
  static byte ch = 0;
  if (music_ptr) {
    while (cur_duration == 0) {
      byte note = next_music_byte();
      if ((note & 0x80) == 0) {
        int period = note_table[note & 63];
        if (ch == 0) {
          APU.pulse[0].period_low = period & 0xff;
          APU.pulse[0].len_period_high = period >> 8;
          APU.pulse[0].control = DUTY;
        } else {
          APU.pulse[1].period_low = period & 0xff;
          APU.pulse[1].len_period_high = period >> 8;
          APU.pulse[1].control = DUTY;
          /*
          //period = note_table_tri[note & 63];
          period >>= 1;
          APU.triangle.counter = 0xc0;
          APU.triangle.period_low = period & 0xff;
          APU.triangle.len_period_high = period >> 8;
          */
          /*
          APU.noise.control = 0x4;
          APU.noise.period = 0xe;
          APU.noise.len = 0xf;
          */
        }
        ch = ch^1;
      } else {
        if (note == 0xff)
          music_ptr = NULL;
        cur_duration = note & 63;
      }
    }
    cur_duration--;
  }
}

void start_music(const byte* music) {
  music_ptr = music;
  cur_duration = 0;
}

//put a string into the nametable

void put_str(unsigned int adr,const char *str)
{
        vram_adr(adr);
        while(1)
        {
                if(!*str) break;
                vram_put((*str++)-0x20);//-0x20 because ASCII code 0x20 is placed in tile 0 of the CHR
        }
}

const byte APUINIT[0x13] = {
  0x30,0x08,0x00,0x00,
  0x30,0x08,0x00,0x00,
  0x80,0x00,0x00,0x00,
  0x30,0x00,0x00,0x00,
  0x00,0x00,0x00
};

void init_apu() {
  // from https://wiki.nesdev.com/w/index.php/APU_basics
  memcpy((void*)0x4000, APUINIT, sizeof(APUINIT));
  APU.fcontrol = 0x40; // frame counter 5-step
  APU.status = 0x0f; // turn on all channels except DMC
}

void main(void)
{
	//copy tileset to RAM
  	vram_adr(0x0);
	vram_write((unsigned char*)TILESET, sizeof(TILESET));
        pal_col(1,0x30);//set while color
        put_str(NTADR_A(2,2),"HELLO, WORLD!");
        ppu_on_bg();//enable rendering

  	init_apu();
/*
  APU.delta_mod.control = 0x1;
  //APU.delta_mod.output = 0x0;
  APU.delta_mod.address = 0xff;
  APU.delta_mod.length = 0xff;
  APU.status = 0x10;
*/
  
  music_ptr = 0;
  while (1) {
    if (!music_ptr) start_music(music1);
    waitvsync();
    play_music();
  }
}

//
// MUSIC DATA -- "The Easy Winners" by Scott Jopline
//
const byte music1[] = {
	0x2a,0x1e,0x98,0x33,0x27,0xa4,0x31,0x25,0x8c,0x2f,0x23,0x8c,0x2e,0x22,0x8c,0x2c,
	0x20,0x8c,0x2a,0x1e,0x98,0x28,0x1c,0x8c,0x27,0x1b,0x98,0x25,0x19,0x8c,0x23,0x17,
	0x8c,0x22,0x12,0x8c,0x23,0x8c,0x25,0x8c,0x27,0x8c,0x28,0x1e,0x8c,0x2a,0x1c,0x8c,
	0x2c,0x1b,0x8c,0x2e,0x19,0x8c,0x2f,0x17,0x98,0x1e,0x98,0x12,0x98,0x1e,0x98,0x2f,
	0x17,0x98,0x33,0x27,0x98,0x12,0x98,0x36,0x1e,0x98,0x38,0x17,0x8c,0x36,0x8c,0x1e,
	0x8c,0x38,0x8c,0x33,0x12,0x8c,0x38,0x8c,0x36,0x1e,0x98,0x3d,0x10,0x8c,0x3b,0x8c,
	0x20,0x8c,0x37,0x8c,0x3b,0x10,0x8c,0x3d,0x8c,0x3b,0x28,0x8c,0x36,0x8c,0x17,0x98,
	0x2a,0x1e,0x8c,0x2c,0x8c,0x2e,0x12,0x8c,0x2f,0x8c,0x31,0x1e,0x8c,0x32,0x8c,0x33,
	0x17,0x98,0x33,0x1e,0x98,0x12,0x98,0x33,0x1e,0x98,0x38,0x17,0x8c,0x36,0x8c,0x27,
	0x8c,0x38,0x8c,0x36,0x18,0x8c,0x36,0x8c,0x33,0x21,0x98,0x36,0x19,0x8c,0x2e,0x8c,
	0x22,0x8c,0x36,0x8c,0x2f,0x19,0x8c,0x36,0x8c,0x2f,0x25,0x98,0x2e,0x1e,0x98,0x1c,
	0x98,0x1b,0x8c,0x2a,0x8c,0x2e,0x25,0x8c,0x34,0x8c,0x33,0x17,0x98,0x33,0x1e,0x98,
	0x12,0x98,0x33,0x27,0x98,0x38,0x17,0x8c,0x36,0x8c,0x1e,0x8c,0x38,0x8c,0x36,0x12,
	0x8c,0x38,0x8c,0x33,0x1e,0x98,0x3d,0x10,0x8c,0x3b,0x8c,0x20,0x8c,0x3d,0x8c,0x3b,
	0x1c,0x8c,0x3b,0x8c,0x38,0x1c,0x8c,0x3f,0x8c,0x1b,0x8c,0x33,0x8c,0x37,0x22,0x8c,
	0x3a,0x8c,0x3f,0x0f,0x98,0x3a,0x8c,0x3b,0x8c,0x3d,0x10,0x8c,0x3b,0x8c,0x20,0x8c,
	0x3d,0x8c,0x38,0x10,0x8c,0x3d,0x8c,0x3b,0x28,0x8c,0x36,0x8c,0x17,0x8c,0x34,0x8c,
	0x36,0x1e,0x8c,0x34,0x8c,0x33,0x17,0x8c,0x36,0x8c,0x27,0x8c,0x36,0x8c,0x30,0x12,
	0x8c,0x34,0x8c,0x1e,0x8c,0x36,0x8c,0x34,0x12,0x8c,0x33,0x8c,0x28,0x1e,0x98,0x2f,
	0x1e,0x98,0x12,0x98,0x14,0x98,0x16,0x98,0x33,0x17,0x98,0x33,0x27,0x98,0x12,0x98,
	0x33,0x1e,0x98,0x38,0x17,0x8c,0x36,0x8c,0x1e,0x8c,0x38,0x8c,0x36,0x12,0x8c,0x38,
	0x8c,0x33,0x1e,0x98,0x3d,0x10,0x8c,0x3b,0x8c,0x20,0x8c,0x3d,0x8c,0x3b,0x10,0x8c,
	0x3d,0x8c,0x38,0x28,0x8c,0x36,0x8c,0x17,0x98,0x2a,0x1e,0x8c,0x2c,0x8c,0x2e,0x12,
	0x8c,0x2f,0x8c,0x31,0x1e,0x8c,0x32,0x8c,0x33,0x17,0x98,0x33,0x1e,0x98,0x12,0x98,
	0x36,0x1e,0x98,0x38,0x17,0x8c,0x36,0x8c,0x27,0x8c,0x32,0x8c,0x36,0x18,0x8c,0x36,
	0x8c,0x36,0x21,0x98,0x36,0x19,0x8c,0x2e,0x8c,0x22,0x8c,0x36,0x8c,0x35,0x19,0x8c,
	0x36,0x8c,0x2f,0x25,0x98,0x36,0x1e,0x98,0x1c,0x98,0x1b,0x8c,0x2a,0x8c,0x2e,0x25,
	0x8c,0x34,0x8c,0x2f,0x17,0x98,0x33,0x1e,0x98,0x12,0x98,0x36,0x1e,0x98,0x38,0x17,
	0x8c,0x36,0x8c,0x1e,0x8c,0x32,0x8c,0x36,0x12,0x8c,0x38,0x8c,0x36,0x1e,0x98,0x3d,
	0x10,0x8c,0x38,0x8c,0x28,0x8c,0x3d,0x8c,0x3b,0x1c,0x8c,0x3b,0x8c,0x3d,0x1c,0x8c,
	0x37,0x8c,0x1b,0x8c,0x33,0x8c,0x37,0x16,0x8c,0x3a,0x8c,0x3f,0x1b,0x98,0x3a,0x8c,
	0x3b,0x8c,0x3d,0x10,0x8c,0x3b,0x8c,0x20,0x8c,0x3d,0x8c,0x3b,0x10,0x8c,0x3d,0x8c,
	0x38,0x28,0x8c,0x36,0x8c,0x17,0x8c,0x38,0x8c,0x36,0x1e,0x8c,0x34,0x8c,0x2f,0x17,
	0x8c,0x36,0x8c,0x27,0x8c,0x36,0x8c,0x36,0x12,0x8c,0x34,0x8c,0x1e,0x8c,0x30,0x8c,
	0x34,0x12,0x8c,0x33,0x8c,0x31,0x1e,0x98,0x2f,0x17,0x98,0x12,0x98,0x2f,0x0b,0x98,
	0x2a,0x8c,0x2b,0x8c,0x2c,0x12,0x8c,0x2d,0x8c,0x2e,0x28,0x8c,0x2e,0x8c,0x16,0x8c,
	0x36,0x8c,0x34,0x1e,0x8c,0x31,0x8c,0x2c,0x19,0x8c,0x2d,0x8c,0x2e,0x28,0x8c,0x2e,
	0x8c,0x19,0x8c,0x31,0x8c,0x2c,0x1a,0x8c,0x2e,0x8c,0x2f,0x1b,0x8c,0x2a,0x8c,0x2c,
	0x27,0x8c,0x2e,0x8c,0x2f,0x12,0x8c,0x30,0x8c,0x31,0x1e,0x8c,0x32,0x8c,0x33,0x23,
	0x8c,0x32,0x8c,0x33,0x1e,0x8c,0x33,0x8c,0x12,0x8c,0x36,0x8c,0x31,0x1e,0x8c,0x33,
	0x8c,0x34,0x25,0x8c,0x3d,0x8c,0x1e,0x8c,0x33,0x8c,0x34,0x12,0x8c,0x3d,0x8c,0x1e,
	0x8c,0x33,0x8c,0x34,0x25,0x8c,0x3d,0x8c,0x1e,0x8c,0x3b,0x8c,0x3a,0x12,0x8c,0x38,
	0x8c,0x36,0x16,0x8c,0x34,0x8c,0x33,0x17,0x8c,0x3b,0x8c,0x27,0x8c,0x32,0x8c,0x33,
	0x12,0x8c,0x3b,0x8c,0x1e,0x8c,0x32,0x8c,0x33,0x17,0x8c,0x3b,0x8c,0x27,0x8c,0x38,
	0x8c,0x36,0x12,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x2f,0x8c,0x2e,0x14,0x8c,0x2f,0x8c,
	0x30,0x2a,0x8c,0x30,0x8c,0x18,0x8c,0x36,0x8c,0x33,0x20,0x8c,0x30,0x8c,0x2e,0x1b,
	0x8c,0x2f,0x8c,0x30,0x2a,0x8c,0x30,0x8c,0x14,0x8c,0x33,0x8c,0x38,0x20,0x8c,0x33,
	0x8c,0x31,0x19,0x8c,0x30,0x8c,0x31,0x28,0x8c,0x2c,0x8c,0x1c,0x8c,0x30,0x8c,0x31,
	0x20,0x8c,0x34,0x8c,0x38,0x19,0x8c,0x33,0x8c,0x34,0x20,0x8c,0x31,0x8c,0x25,0x8c,
	0x2c,0x8c,0x28,0x8c,0x25,0x8c,0x26,0x1d,0x8c,0x29,0x20,0x8c,0x2c,0x23,0x8c,0x2f,
	0x26,0x8c,0x32,0x29,0x8c,0x32,0x29,0x98,0x32,0x29,0x98,0x35,0x8c,0x38,0x8c,0x32,
	0x8c,0x3e,0xb0,0x3f,0x8c,0x3b,0x8c,0x36,0x8c,0x33,0x8c,0x33,0x8c,0x2f,0x8c,0x27,
	0x8c,0x2a,0x8c,0x28,0x12,0x8c,0x28,0x8c,0x12,0x8c,0x2f,0x8c,0x17,0x98,0x2a,0x8c,
	0x2b,0x8c,0x2c,0x12,0x8c,0x2d,0x8c,0x2e,0x28,0x8c,0x31,0x8c,0x16,0x8c,0x36,0x8c,
	0x34,0x1e,0x8c,0x31,0x8c,0x2c,0x19,0x8c,0x2d,0x8c,0x2e,0x28,0x8c,0x2e,0x8c,0x19,
	0x8c,0x31,0x8c,0x2c,0x1a,0x8c,0x2e,0x8c,0x2f,0x1b,0x8c,0x2a,0x8c,0x2c,0x27,0x8c,
	0x2e,0x8c,0x2f,0x12,0x8c,0x30,0x8c,0x31,0x1e,0x8c,0x32,0x8c,0x33,0x17,0x8c,0x32,
	0x8c,0x33,0x27,0x8c,0x33,0x8c,0x12,0x8c,0x36,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x34,
	0x19,0x8c,0x3d,0x8c,0x28,0x8c,0x33,0x8c,0x34,0x12,0x8c,0x3d,0x8c,0x1e,0x8c,0x33,
	0x8c,0x34,0x19,0x8c,0x3d,0x8c,0x28,0x8c,0x3b,0x8c,0x3a,0x12,0x8c,0x38,0x8c,0x36,
	0x16,0x8c,0x34,0x8c,0x33,0x17,0x8c,0x3b,0x8c,0x27,0x8c,0x32,0x8c,0x33,0x12,0x8c,
	0x3b,0x8c,0x1e,0x8c,0x32,0x8c,0x33,0x17,0x8c,0x3b,0x8c,0x27,0x8c,0x38,0x8c,0x36,
	0x12,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x2f,0x8c,0x2e,0x14,0x8c,0x2f,0x8c,0x30,0x2a,
	0x8c,0x30,0x8c,0x18,0x8c,0x36,0x8c,0x33,0x20,0x8c,0x30,0x8c,0x2e,0x1b,0x8c,0x2f,
	0x8c,0x30,0x2a,0x8c,0x30,0x8c,0x14,0x8c,0x33,0x8c,0x38,0x20,0x8c,0x33,0x8c,0x31,
	0x19,0x8c,0x30,0x8c,0x31,0x28,0x8c,0x2c,0x8c,0x1c,0x8c,0x30,0x8c,0x31,0x20,0x8c,
	0x34,0x8c,0x38,0x19,0x8c,0x33,0x8c,0x34,0x20,0x8c,0x31,0x8c,0x25,0x8c,0x2c,0x8c,
	0x28,0x8c,0x25,0x8c,0x26,0x1d,0x8c,0x29,0x20,0x8c,0x2c,0x23,0x8c,0x2f,0x26,0x8c,
	0x32,0x29,0x8c,0x32,0x29,0x98,0x32,0x29,0x98,0x35,0x8c,0x2f,0x8c,0x3b,0x8c,0x3e,
	0xb0,0x3f,0x8c,0x3b,0x8c,0x36,0x8c,0x33,0x8c,0x33,0x8c,0x2f,0x8c,0x27,0x8c,0x2a,
	0x8c,0x28,0x1e,0x8c,0x28,0x8c,0x12,0x8c,0x2f,0x8c,0x17,0x98,0x2a,0x98,0x33,0x17,
	0x98,0x33,0x1e,0x98,0x12,0x98,0x33,0x1e,0x98,0x38,0x17,0x8c,0x36,0x8c,0x1e,0x8c,
	0x38,0x8c,0x36,0x12,0x8c,0x38,0x8c,0x33,0x27,0x98,0x3d,0x10,0x8c,0x3b,0x8c,0x20,
	0x8c,0x3d,0x8c,0x3b,0x10,0x8c,0x37,0x8c,0x3b,0x20,0x8c,0x36,0x8c,0x17,0x98,0x2a,
	0x1e,0x8c,0x2c,0x8c,0x2e,0x12,0x8c,0x2f,0x8c,0x31,0x1e,0x8c,0x32,0x8c,0x33,0x17,
	0x98,0x33,0x27,0x98,0x12,0x98,0x36,0x1e,0x98,0x38,0x17,0x8c,0x33,0x8c,0x27,0x8c,
	0x38,0x8c,0x36,0x18,0x8c,0x36,0x8c,0x36,0x21,0x98,0x36,0x19,0x8c,0x31,0x8c,0x22,
	0x8c,0x36,0x8c,0x2f,0x19,0x8c,0x36,0x8c,0x2f,0x25,0x98,0x36,0x1e,0x98,0x1c,0x98,
	0x1b,0x8c,0x2a,0x8c,0x2e,0x25,0x8c,0x34,0x8c,0x33,0x17,0x98,0x33,0x1e,0x98,0x12,
	0x98,0x36,0x27,0x98,0x38,0x17,0x8c,0x33,0x8c,0x1e,0x8c,0x38,0x8c,0x36,0x12,0x8c,
	0x38,0x8c,0x36,0x1e,0x98,0x3d,0x10,0x8c,0x38,0x8c,0x20,0x8c,0x3d,0x8c,0x3b,0x1c,
	0x8c,0x3b,0x8c,0x3d,0x1c,0x8c,0x37,0x8c,0x1b,0x8c,0x33,0x8c,0x37,0x22,0x8c,0x3a,
	0x8c,0x3f,0x0f,0x98,0x3a,0x8c,0x3b,0x8c,0x37,0x10,0x8c,0x3b,0x8c,0x20,0x8c,0x3d,
	0x8c,0x3b,0x1c,0x8c,0x3d,0x8c,0x3b,0x20,0x8c,0x33,0x8c,0x17,0x8c,0x38,0x8c,0x36,
	0x1e,0x8c,0x34,0x8c,0x2f,0x23,0x8c,0x36,0x8c,0x1e,0x8c,0x36,0x8c,0x36,0x12,0x8c,
	0x34,0x8c,0x1e,0x8c,0x36,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x31,0x12,0x98,0x2f,0x17,
	0x98,0x12,0x98,0x2f,0x0b,0xb0,0x34,0x28,0x98,0x34,0x28,0xa4,0x2f,0x23,0x8c,0x34,
	0x28,0x8c,0x36,0x2a,0x8c,0x38,0x98,0x2c,0xa4,0x2f,0x8c,0x34,0x8c,0x38,0x8c,0x2f,
	0x8c,0x36,0x98,0x33,0x8c,0x17,0x8c,0x33,0x8c,0x2d,0x17,0x98,0x2c,0x1c,0x98,0x10,
	0x98,0x12,0x98,0x2f,0x14,0x8c,0x30,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x2d,0x8c,0x36,
	0x8c,0x30,0x1e,0x8c,0x39,0x8c,0x1f,0x8c,0x36,0x8c,0x2f,0x20,0x8c,0x34,0x8c,0x38,
	0x2c,0x8c,0x3d,0x8c,0x1c,0x8c,0x3b,0x8c,0x38,0x23,0x8c,0x34,0x8c,0x33,0x17,0x8c,
	0x3b,0x8c,0x36,0x2d,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x1f,0x8c,0x2f,0x8c,
	0x34,0x20,0x8c,0x34,0x8c,0x38,0x1c,0x8c,0x3b,0x8c,0x23,0x8c,0x3d,0x8c,0x3b,0x14,
	0x8c,0x38,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x25,0x8c,0x36,0x8c,0x30,0x2a,0x8c,0x39,
	0x8c,0x1f,0x8c,0x36,0x8c,0x2f,0x20,0x8c,0x34,0x8c,0x38,0x23,0x8c,0x3d,0x8c,0x1c,
	0x8c,0x3b,0x8c,0x38,0x2c,0x8c,0x34,0x8c,0x36,0x19,0x8c,0x38,0x8c,0x36,0x28,0x8c,
	0x34,0x8c,0x33,0x12,0x8c,0x34,0x8c,0x2e,0x8c,0x31,0x8c,0x2f,0x23,0x98,0x32,0x1d,
	0x8c,0x36,0x1e,0x8c,0x33,0x17,0x98,0x2f,0x20,0x98,0x31,0x21,0x8c,0x39,0x8c,0x25,
	0x8c,0x36,0x8c,0x30,0x1e,0x8c,0x39,0x8c,0x1f,0x8c,0x36,0x8c,0x2c,0x8c,0x2f,0x8c,
	0x34,0x23,0x8c,0x38,0x8c,0x3d,0x1c,0x8c,0x3b,0x8c,0x38,0x23,0x8c,0x34,0x8c,0x33,
	0x23,0x8c,0x3b,0x8c,0x36,0x23,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x1f,0x8c,
	0x2f,0x8c,0x2c,0x8c,0x34,0x8c,0x38,0x1c,0x8c,0x3b,0x8c,0x38,0x17,0x8c,0x3d,0x8c,
	0x3b,0x14,0x8c,0x38,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x25,0x8c,0x36,0x8c,0x30,0x1e,
	0x8c,0x39,0x8c,0x21,0x8c,0x36,0x8c,0x20,0x8c,0x2f,0x8c,0x34,0x1c,0x8c,0x38,0x8c,
	0x3d,0x23,0x8c,0x3b,0x8c,0x38,0x1c,0x8c,0x2f,0x8c,0x2e,0x19,0x8c,0x31,0x8c,0x12,
	0x98,0x2d,0x0b,0x8c,0x33,0x98,0x2c,0x8c,0x1c,0x98,0x38,0x1c,0x8c,0x34,0x8c,0x36,
	0x17,0x8c,0x38,0x8c,0x2f,0x14,0x8c,0x30,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x2d,0x8c,
	0x36,0x8c,0x30,0x1e,0x8c,0x39,0x8c,0x1f,0x8c,0x36,0x8c,0x2f,0x20,0x8c,0x34,0x8c,
	0x38,0x2c,0x8c,0x3d,0x8c,0x1c,0x8c,0x3b,0x8c,0x38,0x23,0x8c,0x34,0x8c,0x33,0x17,
	0x8c,0x3b,0x8c,0x36,0x2d,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x1f,0x8c,0x2f,
	0x8c,0x34,0x20,0x8c,0x34,0x8c,0x38,0x1c,0x8c,0x3b,0x8c,0x23,0x8c,0x3d,0x8c,0x3b,
	0x14,0x8c,0x38,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x25,0x8c,0x36,0x8c,0x30,0x2a,0x8c,
	0x39,0x8c,0x1f,0x8c,0x36,0x8c,0x2f,0x20,0x8c,0x34,0x8c,0x38,0x23,0x8c,0x3d,0x8c,
	0x28,0x8c,0x3b,0x8c,0x38,0x23,0x8c,0x34,0x8c,0x36,0x19,0x8c,0x38,0x8c,0x36,0x28,
	0x8c,0x34,0x8c,0x33,0x1e,0x8c,0x34,0x8c,0x28,0x8c,0x31,0x8c,0x2f,0x23,0x98,0x32,
	0x1d,0x8c,0x33,0x1e,0x8c,0x3b,0x17,0x98,0x2f,0x28,0x98,0x31,0x15,0x8c,0x39,0x8c,
	0x25,0x8c,0x36,0x8c,0x30,0x1e,0x8c,0x39,0x8c,0x2b,0x8c,0x36,0x8c,0x20,0x8c,0x2f,
	0x8c,0x34,0x23,0x8c,0x38,0x8c,0x3d,0x1c,0x8c,0x3b,0x8c,0x38,0x2c,0x8c,0x34,0x8c,
	0x33,0x17,0x8c,0x3b,0x8c,0x36,0x23,0x8c,0x33,0x8c,0x31,0x1e,0x8c,0x33,0x8c,0x2b,
	0x8c,0x2f,0x8c,0x20,0x8c,0x34,0x8c,0x38,0x1c,0x8c,0x3b,0x8c,0x38,0x17,0x8c,0x3d,
	0x8c,0x32,0x14,0x8c,0x38,0x8c,0x31,0x21,0x8c,0x39,0x8c,0x19,0x8c,0x36,0x8c,0x30,
	0x1e,0x8c,0x39,0x8c,0x21,0x8c,0x36,0x8c,0x20,0x8c,0x2f,0x8c,0x34,0x28,0x8c,0x38,
	0x8c,0x3d,0x17,0x8c,0x3b,0x8c,0x38,0x1c,0x8c,0x2f,0x8c,0x2e,0x19,0x8c,0x31,0x8c,
	0x12,0x98,0x2d,0x17,0x8c,0x36,0x98,0x2c,0x8c,0x10,0x98,0x17,0x98,0x34,0x10,0x8c,
	0x2f,0x8c,0x31,0x8c,0x3e,0x8c,0x33,0x1e,0x98,0x2f,0x23,0x8c,0x31,0x8c,0x23,0x98,
	0x23,0x98,0x33,0x12,0x98,0x2f,0x23,0x8c,0x31,0x8c,0x1e,0x8c,0x2f,0x17,0x8c,0x31,
	0x16,0x8c,0x33,0x15,0x8c,0x34,0x14,0x98,0x3b,0x2c,0x8c,0x31,0x8c,0x1c,0x98,0x23,
	0x98,0x34,0x14,0x98,0x3b,0x2c,0x8c,0x31,0x8c,0x1c,0x98,0x1d,0x98,0x1e,0x98,0x3d,
	0x2d,0x8c,0x3b,0x8c,0x17,0x98,0x23,0x98,0x1b,0x98,0x3d,0x2d,0x8c,0x33,0x8c,0x17,
	0x98,0x23,0x98,0x1c,0x98,0x3d,0x2c,0x8c,0x34,0x8c,0x17,0x98,0x23,0x98,0x1c,0x98,
	0x3d,0x2c,0x8c,0x3b,0x8c,0x20,0x8c,0x2f,0x8c,0x31,0x1f,0x8c,0x32,0x8c,0x3f,0x1e,
	0x98,0x2f,0x2d,0x8c,0x31,0x8c,0x17,0x98,0x23,0x98,0x3f,0x12,0x98,0x2f,0x2d,0x8c,
	0x31,0x8c,0x12,0x8c,0x2f,0x17,0x8c,0x3d,0x16,0x8c,0x33,0x15,0x8c,0x34,0x20,0x98,
	0x2f,0x23,0x8c,0x3d,0x8c,0x1c,0x98,0x23,0x98,0x2c,0x8c,0x34,0x8c,0x38,0x1c,0x8c,
	0x3b,0x8c,0x38,0x17,0x8c,0x3d,0x8c,0x32,0x14,0x8c,0x38,0x8c,0x31,0x15,0x8c,0x39,
	0x8c,0x25,0x8c,0x36,0x8c,0x30,0x1e,0x8c,0x39,0x8c,0x21,0x8c,0x36,0x8c,0x20,0x8c,
	0x2f,0x8c,0x34,0x1c,0x8c,0x38,0x8c,0x3d,0x23,0x8c,0x3b,0x8c,0x38,0x1c,0x8c,0x2f,
	0x8c,0x2e,0x19,0x8c,0x31,0x8c,0x12,0x98,0x2d,0x17,0x8c,0x36,0x98,0x2c,0x8c,0x2c,
	0x10,0x98,0x17,0x98,0x34,0x20,0x8c,0x2f,0x8c,0x3d,0x1f,0x8c,0x32,0x8c,0x33,0x2a,
	0x98,0x2f,0x23,0x8c,0x3d,0x8c,0x17,0x98,0x23,0x98,0x33,0x1e,0x98,0x2f,0x23,0x8c,
	0x3d,0x8c,0x12,0x8c,0x2f,0x17,0x8c,0x31,0x16,0x8c,0x33,0x21,0x8c,0x38,0x14,0x98,
	0x2f,0x23,0x8c,0x31,0x8c,0x1c,0x98,0x2c,0x98,0x38,0x14,0x98,0x2f,0x23,0x8c,0x31,
	0x8c,0x1c,0x98,0x29,0x98,0x1e,0x98,0x3d,0x23,0x8c,0x33,0x8c,0x17,0x98,0x2d,0x98,
	0x1b,0x98,0x3d,0x23,0x8c,0x33,0x8c,0x17,0x98,0x2d,0x98,0x1c,0x98,0x3d,0x23,0x8c,
	0x34,0x8c,0x17,0x98,0x2c,0x98,0x1c,0x98,0x3d,0x23,0x8c,0x3b,0x8c,0x20,0x8c,0x2f,
	0x8c,0x31,0x2b,0x8c,0x32,0x8c,0x3f,0x1e,0x98,0x2f,0x23,0x8c,0x31,0x8c,0x17,0x98,
	0x2d,0x98,0x3f,0x12,0x98,0x2f,0x23,0x8c,0x31,0x8c,0x12,0x8c,0x3b,0x23,0x8c,0x31,
	0x16,0x8c,0x33,0x15,0x8c,0x34,0x14,0x98,0x2f,0x23,0x8c,0x3d,0x8c,0x28,0x98,0x23,
	0x98,0x20,0x8c,0x34,0x8c,0x38,0x1c,0x8c,0x3b,0x8c,0x38,0x23,0x8c,0x3d,0x8c,0x3b,
	0x14,0x8c,0x38,0x8c,0x31,0x15,0x8c,0x39,0x8c,0x19,0x8c,0x36,0x8c,0x30,0x1e,0x8c,
	0x39,0x8c,0x2d,0x8c,0x36,0x8c,0x20,0x8c,0x2f,0x8c,0x34,0x1c,0x8c,0x38,0x8c,0x3d,
	0x17,0x8c,0x3b,0x8c,0x38,0x1c,0x8c,0x2f,0x8c,0x2e,0x25,0x8c,0x31,0x8c,0x12,0x98,
	0x2d,0x0b,0x8c,0x33,0x98,0x2c,0x8c,0x2c,0x10,0x98,0x17,0x98,0x34,0x10,0xff,        
};