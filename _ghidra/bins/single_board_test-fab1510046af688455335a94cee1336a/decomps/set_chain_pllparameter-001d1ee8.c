
int32_t set_chain_pllparameter(uint8_t which_chain,uint8_t which_pll,pllparameter_t pllparameter)

{
  int32_t iVar1;
  pllparameter_t pllparameter_local;
  
  pllparameter_local.postdiv2 = pllparameter.postdiv2;
  iVar1 = set_pllparameter(which_chain,'\x01',0,which_pll,
                           (pllparameter_t)
                           ((uint6)CONCAT14(pllparameter_local.postdiv2,pllparameter._0_4_) &
                           0xffff000000ff));
  return iVar1;
}

