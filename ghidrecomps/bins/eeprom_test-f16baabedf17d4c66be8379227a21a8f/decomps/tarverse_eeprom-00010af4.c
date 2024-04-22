
int tarverse_eeprom(uint8_t chain)

{
  uint uVar1;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)chain;
    eeprom_dump(chain);
  }
  return uVar1;
}

