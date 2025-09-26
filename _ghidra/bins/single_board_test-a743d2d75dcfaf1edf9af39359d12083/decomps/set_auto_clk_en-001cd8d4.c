
int32_t set_auto_clk_en(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                       uint8_t mode_mask,_Bool auto_clk_en)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\x01',(uint)mode,0x3c,
                     (uint)(mode_mask != '\0') | (which_asic_address & 3) << 5 | 0x80008800);
  return iVar1;
}

