
int32_t set_asic_pllparameter
                  (uint8_t which_chain,uint32_t which_asic_address,uint8_t which_pll,
                  pllparameter_t pllparameter)

{
  int32_t iVar1;
  
  iVar1 = set_pllparameter(which_chain,'\0',which_asic_address,which_pll,
                           (pllparameter_t)
                           ((uint6)CONCAT14(pllparameter.postdiv2,pllparameter._0_4_) &
                           0xffff000000ff));
  return iVar1;
}

