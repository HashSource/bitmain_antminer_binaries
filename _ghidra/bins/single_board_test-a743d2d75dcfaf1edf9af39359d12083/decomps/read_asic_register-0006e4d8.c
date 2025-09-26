
void read_asic_register(uint8_t chain,uint8_t mode,uint8_t chip_addr,uint8_t reg_addr)

{
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  uint8_t mode_local;
  uint8_t chain_local;
  
  send_get_status_command(chain,mode,(uint)chip_addr,(uint)reg_addr);
  return;
}

