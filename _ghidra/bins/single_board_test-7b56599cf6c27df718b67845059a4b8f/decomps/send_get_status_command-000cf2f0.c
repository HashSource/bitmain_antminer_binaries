
/* WARNING: Unknown calling convention */

int32_t send_get_status_command
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint32_t reg_address
                  )

{
  int32_t iVar1;
  get_status_t command;
  
  iVar1 = generate_get_status_command(mode,which_asic_address,reg_address,&command);
  if (iVar1 == 0) {
    iVar1 = send_command(which_chain,command.v,5);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

