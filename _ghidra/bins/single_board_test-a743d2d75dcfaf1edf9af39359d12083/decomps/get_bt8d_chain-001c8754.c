
/* WARNING: Unknown calling convention */

int32_t get_bt8d_chain(uint32_t chain)

{
  int32_t iVar1;
  uint uVar2;
  uint32_t val;
  
  val = 0;
  fpga_read(0xf,&val);
  if (chain == 0) {
    uVar2 = val & 0x3f;
  }
  else if (chain == 1) {
    uVar2 = (val << 0x12) >> 0x1a;
  }
  else if (chain == 2) {
    uVar2 = (val << 10) >> 0x1a;
  }
  else {
    if (chain != 3) {
      return -1;
    }
    uVar2 = (val << 2) >> 0x1a;
  }
  if (uVar2 != 0) {
    if (uVar2 != 1) {
      if (uVar2 == 3) {
        iVar1 = 6000000;
      }
      else if (uVar2 == 4) {
        iVar1 = 12000000;
      }
      else {
        iVar1 = 25000000;
        if (uVar2 != 5) {
          iVar1 = 0x1c200;
        }
      }
      return iVar1;
    }
    return 1500000;
  }
  return 3000000;
}

