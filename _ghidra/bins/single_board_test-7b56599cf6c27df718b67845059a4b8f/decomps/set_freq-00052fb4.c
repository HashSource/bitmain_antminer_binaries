
void set_freq(uint32_t chain,uint8_t mode,uint8_t chip_addr,uint8_t pll_id,pll_conf pll_config)

{
  uint8_t pll_id_local;
  uint8_t chip_addr_local;
  uint8_t mode_local;
  uint32_t chain_local;
  
  set_chain_pllparameter((uint8_t)chain,pll_id,pll_config.pll_param);
  return;
}

