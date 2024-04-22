
/* WARNING: Unknown calling convention */

void enable_pic_dc_dc_all(void)

{
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      enable_pic_dc_dc((uchar)i);
      cgsleep_ms(1);
    }
  }
  return;
}

