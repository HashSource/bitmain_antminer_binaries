
int pic_init(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  int ret;
  
  iVar1 = pic_reset(chain);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = jump_to_app_from_loader((uint)chain);
  }
  return iVar1;
}

