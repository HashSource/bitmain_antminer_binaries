
/* WARNING: Unknown calling convention */

uint wait_iic_ok(uint chip_addr,uint chain,_Bool update)

{
  uint uVar1;
  
  uVar1 = check_asic_reg_with_addr(0x20,chip_addr,chain,1);
  if (uVar1 == 0) {
    cgsleep_ms(1);
    uVar1 = check_asic_reg_with_addr(0x20,chip_addr,chain,1);
    if (uVar1 == 0) {
      cgsleep_ms(1);
    }
  }
  return uVar1;
}

