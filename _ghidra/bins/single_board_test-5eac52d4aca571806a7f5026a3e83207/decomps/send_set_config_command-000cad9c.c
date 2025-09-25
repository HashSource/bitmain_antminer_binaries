
/* WARNING: Unknown calling convention */

int32_t send_set_config_command
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint32_t reg_address
                  ,uint32_t reg_data)

{
  int32_t iVar1;
  set_config_t command;
  
  iVar1 = generate_set_config_command(mode,which_asic_address,reg_address,reg_data,&command);
  if (iVar1 == 0) {
    send_command(which_chain,command.v,9);
    if (mode == '\x01') {
      which_asic_address = 0;
    }
    set_register_cache_value
              ((uint)(mode != '\x01'),which_chain,which_asic_address,reg_address,reg_data);
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

