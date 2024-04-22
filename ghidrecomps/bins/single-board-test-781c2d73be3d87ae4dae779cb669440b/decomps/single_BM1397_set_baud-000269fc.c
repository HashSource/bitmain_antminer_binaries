
/* WARNING: Unknown calling convention */

void single_BM1397_set_baud(uchar which_chain,uchar chip_addr,uint asic_baud,_Bool mode)

{
  uint uVar1;
  int divider;
  uint uVar2;
  int iVar3;
  misc_ctrl_t misc_reg;
  
  if (asic_baud == 4) {
    uVar2 = 0;
    uVar1 = 3;
LAB_00026a1c:
    misc_reg.v = gBM1397_MISC_CONTROL_reg & 0xf0ffe0ff | uVar1 << 8 | uVar2 << 0x18;
    if (2 < asic_baud - 3) goto LAB_00026a34;
  }
  else {
    if (asic_baud == 5) {
      iVar3 = 1;
    }
    else {
      if (asic_baud != 3) {
        uVar1 = asic_baud & 0x1f;
        uVar2 = (asic_baud << 0x17) >> 0x1c;
        goto LAB_00026a1c;
      }
      iVar3 = 7;
    }
    misc_reg.v = gBM1397_MISC_CONTROL_reg & 0xf0ffe0ff | iVar3 << 8;
  }
  misc_reg.v = misc_reg.v | 0x10000;
  set_baud_ext(which_chain,chip_addr,mode);
LAB_00026a34:
  gBM1397_MISC_CONTROL_reg = (uint)misc_reg;
  BM1397_set_config(which_chain,chip_addr,'\x18',misc_reg.v,mode);
  return;
}

