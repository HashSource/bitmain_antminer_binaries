
/* WARNING: Unknown calling convention */

uint check_reg_temp(uchar device,uint reg,uchar data,uchar write,uchar chip_addr,int chain)

{
  uint uVar1;
  uint ret;
  uint chip_addr_00;
  int iVar2;
  
  chip_addr_00 = (uint)chip_addr;
  if (write == '\0') {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      wait_iic_ok(chip_addr_00,chain,false);
      read_temp(device,reg,data,'\0',chip_addr,chain);
      cgsleep_ms(1);
      uVar1 = wait_iic_ok(chip_addr_00,chain,true);
      cgsleep_ms(1);
      if ((((uVar1 << 0x10) >> 0x18 == reg) && ((uVar1 & 0xff) != 0xff)) && ((uVar1 & 0xff) != 0x7f)
         ) {
LAB_000328c8:
        if (iVar2 != 2) {
          return uVar1;
        }
        return 0;
      }
    } while (iVar2 == 1);
  }
  else {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      wait_iic_ok(chip_addr_00,chain,false);
      read_temp(device,reg,data,write,chip_addr,chain);
      wait_iic_ok(chip_addr_00,chain,true);
      cgsleep_ms(1);
      wait_iic_ok(chip_addr_00,chain,false);
      read_temp(device,reg,'\0','\0',chip_addr,chain);
      uVar1 = wait_iic_ok(chip_addr_00,chain,true);
      cgsleep_ms(1);
      if (((uVar1 << 0x10) >> 0x18 == reg) || ((uVar1 & 0xff) == (uint)data)) goto LAB_000328c8;
    } while (iVar2 == 1);
  }
  return 0;
}

