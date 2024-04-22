
/* WARNING: Unknown calling convention */

int init_pic(void)

{
  uint8_t i;
  
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    init_pic_one_chain((uint)i);
  }
  pic_heart_beat_func((void *)0x0);
  return 0;
}

