
int dump_eeprom(uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    iVar1 = -1;
  }
  else {
    eeprom_dump_raw(chain);
    iVar1 = 0;
  }
  return iVar1;
}

