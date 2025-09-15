
void power_on_all_chain(void)

{
  int iVar1;
  uint *puVar2;
  
  if (0 < total_exist_chain_num) {
    iVar1 = 0;
    puVar2 = (uint *)exist_chain;
    do {
      iVar1 = iVar1 + 1;
      enable_pic_dac(*puVar2 & 0xff);
      puVar2 = puVar2 + 1;
    } while (iVar1 < total_exist_chain_num);
  }
  return;
}

