
void set_user_divider(uint32_t chain,uint8_t chip_addr,uint8_t pll_id)

{
  uint8_t pll_id_local;
  uint8_t chip_addr_local;
  uint32_t chain_local;
  pll_userdivider_t userdivider;
  
  set_asic_pllparameter_userdivider((uint8_t)chain,(uint)chip_addr,pll_id,(pll_userdivider_t)0x0);
  return;
}

