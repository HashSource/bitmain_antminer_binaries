
/* WARNING: Unknown calling convention */

int32_t hal_chain_max_num(void)

{
  chain_conf_info *pcVar1;
  int iVar2;
  chain_conf_info *pcVar3;
  
  iVar2 = 0;
  pcVar1 = chains;
  do {
    pcVar3 = pcVar1;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10) {
      return 0x10;
    }
    pcVar1 = pcVar3 + 1;
  } while ((((pcVar1->chain_id != 0xff) || (pcVar3[1].uart_index != 0xff)) ||
           (pcVar3[1].plug != 0xff)) || (pcVar3[1].reset != 0xff));
  return iVar2;
}

