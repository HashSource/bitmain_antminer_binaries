
/* WARNING: Unknown calling convention */

int32_t hal_chain_plug_addr(uint32_t chain_id)

{
  uint32_t uVar1;
  chain_conf_info *pcVar2;
  int iVar3;
  
  uVar1 = 0;
  pcVar2 = chains;
  iVar3 = 0;
  while( true ) {
    pcVar2 = pcVar2 + 1;
    if (uVar1 == chain_id) {
      return chains[iVar3].plug;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x10) break;
    uVar1 = pcVar2->chain_id;
  }
  return -2;
}

