
/* WARNING: Unknown calling convention */

int32_t set_chain_pllparameter_postdivider
                  (uint8_t which_chain,uint8_t which_pll,uint8_t postdiv1,uint8_t postdiv2)

{
  byte bVar1;
  int32_t iVar2;
  pll_parameter_t pllparameter;
  
  if (which_pll < 3) {
    bVar1 = "\b`d"[which_pll];
    get_register_cache_value(hashboard_cache_level,which_chain,0,(uint)bVar1,&pllparameter.v);
    pllparameter.v._0_1_ = pllparameter.v._0_1_ & 0x88 | (postdiv1 & 7) << 4 | postdiv2 & 7;
    iVar2 = send_set_config_command(which_chain,'\x01',0,(uint)bVar1,pllparameter.v);
    return iVar2;
  }
  return -1;
}

