
int32_t set_clock_select_control
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t pulse_mode,
                  uint8_t clk_sel)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,mode,which_asic_address,0x3c,(pulse_mode & 3) << 1 | 0x80008b00);
  return iVar1;
}

