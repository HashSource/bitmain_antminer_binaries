
uint wait_iic_ok(uint chip_addr,uint chain,_Bool update)

{
  uint uVar1;
  _Bool update_local;
  uint chain_local;
  uint chip_addr_local;
  uint ret;
  int fail_time;
  
  fail_time = 0;
  while( true ) {
    if (1 < fail_time) {
      return 0;
    }
    uVar1 = check_asic_reg_with_addr(0x1c,(uchar)chip_addr,chain,1);
    if (uVar1 != 0) break;
    fail_time = fail_time + 1;
    cgsleep_ms(1);
  }
  return uVar1;
}

