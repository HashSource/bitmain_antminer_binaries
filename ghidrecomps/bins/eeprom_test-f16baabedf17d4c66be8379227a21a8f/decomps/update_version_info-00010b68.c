
int update_version_info(uint8_t chain,uint8_t pcb,uint8_t bom)

{
  _Bool _Var1;
  _Bool _Var2;
  uint uVar3;
  uint8_t bom_local;
  uint8_t pcb_local;
  uint8_t chain_local;
  _Bool ret;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    uVar3 = 0xffffffff;
  }
  else {
    _Var1 = eeprom_set_pcb_version(chain,pcb);
    _Var2 = eeprom_set_bom_version(chain,bom);
    uVar3 = (uint)(_Var2 && _Var1);
  }
  return uVar3;
}

