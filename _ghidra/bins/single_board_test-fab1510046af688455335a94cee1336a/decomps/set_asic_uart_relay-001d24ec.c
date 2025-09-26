
/* WARNING: Unknown calling convention */

int32_t set_asic_uart_relay(uint8_t which_chain,uint32_t which_asic_address,uint32_t gap_cnt,
                           _Bool is_ro_relay,_Bool is_co_relay)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\0',which_asic_address,0x2c,
                     is_co_relay & 1 | (is_ro_relay & 1) << 1 | gap_cnt << 0x10);
  return iVar1;
}

