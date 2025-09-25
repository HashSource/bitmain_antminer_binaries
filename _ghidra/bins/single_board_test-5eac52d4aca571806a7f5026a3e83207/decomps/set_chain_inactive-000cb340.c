
/* WARNING: Unknown calling convention */

int32_t set_chain_inactive(uint8_t which_chain)

{
  int32_t iVar1;
  chain_inactive_t cStack_10;
  
  iVar1 = generate_chain_inactive_command(&cStack_10);
  if (iVar1 == 0) {
    iVar1 = send_command(which_chain,cStack_10.v,5);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

