
int tarverse_eeprom(uint8_t chain)

{
  int iVar1;
  int extraout_r3;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    iVar1 = -1;
  }
  else {
    eeprom_dump(chain);
    iVar1 = extraout_r3;
  }
  return iVar1;
}

