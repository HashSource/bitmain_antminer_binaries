
int32_t set_pllparameter(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                        uint8_t which_pll,pllparameter_t pll_parameter)

{
  int32_t iVar1;
  uint reg_data;
  float fVar2;
  byte in_stack_00000008;
  ushort in_stack_0000000c;
  
  if (which_pll < 3) {
    reg_data = (byte)pll_parameter.fbdiv - 1 & 7 | 0x40000000 |
               ((pll_parameter._0_4_ & 0xff) - 1 & 7) << 4 | (in_stack_00000008 & 0x3f) << 8 |
               (uint)(in_stack_0000000c & 0xfff) << 0x10;
    fVar2 = (25.0 / (float)(longlong)(int)(uint)in_stack_00000008) * (float)in_stack_0000000c;
    if ((1600.0 <= fVar2) && ((int)((uint)(fVar2 < 2400.0) << 0x1f) < 0)) {
      iVar1 = send_set_config_command
                        (which_chain,mode,which_asic_address,(uint)"\b`d"[which_pll],reg_data);
      return iVar1;
    }
    if ((2400.0 <= fVar2) && (fVar2 <= 3200.0)) {
      iVar1 = send_set_config_command
                        (which_chain,mode,which_asic_address,(uint)"\b`d"[which_pll],
                         reg_data | 0x10000000);
      return iVar1;
    }
  }
  return -1;
}

