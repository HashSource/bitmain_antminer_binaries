
/* WARNING: Unknown calling convention */

int32_t send_chain_inactive_command(uint8_t which_chain)

{
  int32_t iVar1;
  chain_inactive_t command;
  
  iVar1 = generate_chain_inactive_command(&command);
  if (iVar1 == 0) {
    iVar1 = send_command(which_chain,command.v,5);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

