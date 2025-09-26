
/* WARNING: Unknown calling convention */

int32_t hal_chain_max_num(void)

{
  int iVar1;
  chain_conf_info *pcVar2;
  
  iVar1 = 0;
  pcVar2 = chains;
  while( true ) {
    while (((pcVar2->chain_id != 0xff || (pcVar2->uart_index != 0xff)) || (pcVar2->plug != 0xff))) {
      pcVar2 = pcVar2 + 1;
      iVar1 = iVar1 + 1;
      if (pcVar2 == (chain_conf_info *)fans) {
        return 0x10;
      }
    }
    if (pcVar2->reset == 0xff) break;
    pcVar2 = pcVar2 + 1;
    iVar1 = iVar1 + 1;
    if (pcVar2 == (chain_conf_info *)fans) {
      return 0x10;
    }
  }
  return iVar1;
}

