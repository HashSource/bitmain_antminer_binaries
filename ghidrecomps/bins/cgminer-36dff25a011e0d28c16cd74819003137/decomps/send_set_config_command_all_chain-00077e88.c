
void send_set_config_command_all_chain
               (uint8_t mode,uint8_t dev_addr,uint8_t reg_addr,uint32_t reg_data)

{
  uint32_t reg_data_local;
  uint8_t reg_addr_local;
  uint8_t dev_addr_local;
  uint8_t mode_local;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      send_set_config_command(chain,mode,dev_addr,reg_addr,reg_data);
    }
  }
  return;
}

