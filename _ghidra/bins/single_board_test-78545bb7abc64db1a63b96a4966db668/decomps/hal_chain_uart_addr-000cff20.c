
/* WARNING: Unknown calling convention */

int32_t hal_chain_uart_addr(uint32_t chain_id)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    if (chains[iVar1].chain_id == chain_id) {
      return chains[iVar1].uart_index;
    }
    iVar1 = iVar2;
  } while (iVar2 != 0x10);
  return -2;
}

