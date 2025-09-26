
/* WARNING: Unknown calling convention */

int32_t send_set_address_command(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  set_address_t command;
  
  iVar1 = generate_set_address_command(which_asic_address,&command);
  if (iVar1 == 0) {
    iVar1 = send_command(which_chain,command.v,5);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

