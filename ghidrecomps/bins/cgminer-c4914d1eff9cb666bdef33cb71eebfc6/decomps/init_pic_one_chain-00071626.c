
int init_pic_one_chain(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  int ret;
  
  if (dev->chain_exist[chain] == 1) {
    iVar1 = dsPIC33EP16GS202_reset_pic(chain);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = dsPIC33EP16GS202_jump_to_app_from_loader((uint)chain);
    if (iVar1 != 0) {
      return iVar1;
    }
    sleep(1);
    iVar1 = dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\0');
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}

