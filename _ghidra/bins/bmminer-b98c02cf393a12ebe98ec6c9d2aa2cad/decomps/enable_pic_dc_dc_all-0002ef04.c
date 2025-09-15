
void enable_pic_dc_dc_all(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    while (*(int *)(dev + (uVar2 + 2) * 4) != 1) {
      uVar2 = uVar2 + 1;
      if (uVar2 == 0x10) {
        return;
      }
    }
    uVar1 = uVar2 & 0xff;
    uVar2 = uVar2 + 1;
    enable_pic_dc_dc(uVar1);
    cgsleep_ms(1);
  } while (uVar2 != 0x10);
  return;
}

