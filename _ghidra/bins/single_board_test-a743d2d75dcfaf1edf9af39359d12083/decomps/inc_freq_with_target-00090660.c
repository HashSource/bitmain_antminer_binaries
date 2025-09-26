
void inc_freq_with_target(float *curr_matrix,float *last_matrix,int len,int pll)

{
  _pll_conf pll_config;
  int iVar1;
  int iVar2;
  float freq;
  int pll_local;
  int len_local;
  float *last_matrix_local;
  float *curr_matrix_local;
  pll_userdivider_t userdivider;
  _pll_conf target;
  float curr_freq;
  uint8_t chip_addr;
  int domain_asic;
  int domain;
  int j;
  int i;
  
  iVar1 = (g_rt.config)->domains;
  iVar2 = (g_rt.config)->asics_in_domain;
  for (i = 0; i < iVar2; i = i + 1) {
    for (j = 0; j < iVar1; j = j + 1) {
      freq = curr_matrix[i + iVar2 * j];
      memset(&target,0,8);
      get_pllparam_divider(freq,&target.pll_param,&userdivider,(float *)0x0);
      target.usr_divider = userdivider.userdivider0;
      pll_config.pll_param.fbdiv = target.pll_param.fbdiv;
      pll_config.usr_divider = userdivider.userdivider0;
      pll_config._7_1_ = target._7_1_;
      pll_config.pll_param.postdiv1 = target.pll_param.postdiv1;
      pll_config.pll_param.postdiv2 = target.pll_param.postdiv2;
      pll_config.pll_param.refdiv = target.pll_param.refdiv;
      pll_config.pll_param._3_1_ = target.pll_param._3_1_;
      set_freq_mix((g_rt.config)->chain,'\0',(char)i + (char)j * (char)iVar2,(uint8_t)pll,pll_config
                  );
    }
  }
  return;
}

