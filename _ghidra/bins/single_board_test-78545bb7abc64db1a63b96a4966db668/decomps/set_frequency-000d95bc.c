
/* WARNING: Unknown calling convention */

int32_t set_frequency(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,uint8_t which_pll
                     ,uint32_t frequency)

{
  pllparameter_t pll_parameter;
  int32_t iVar1;
  pll_userdivider_t user_divider;
  pllparameter_t pllparameter;
  
  iVar1 = get_pllparam_divider((float)frequency,&pllparameter,&user_divider,(float *)0x0);
  if (iVar1 == 0) {
    pll_parameter.postdiv2 = '\0';
    pll_parameter.refdiv = '\0';
    pll_parameter._3_1_ = 0;
    pll_parameter.postdiv1 = pllparameter.postdiv1;
    pll_parameter.fbdiv._0_1_ = pllparameter.postdiv2;
    pll_parameter.fbdiv._1_1_ = 0;
    iVar1 = set_pllparameter(which_chain,mode,which_asic_address,which_pll,pll_parameter);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

