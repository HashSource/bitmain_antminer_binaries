
int wait_iic_ok(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = check_asic_reg_with_addr(0x20,param_1,param_2,1);
  if (iVar1 == 0) {
    cgsleep_ms(1);
    iVar1 = check_asic_reg_with_addr(0x20,param_1,param_2,1);
    if (iVar1 == 0) {
      cgsleep_ms(1);
    }
  }
  return iVar1;
}

