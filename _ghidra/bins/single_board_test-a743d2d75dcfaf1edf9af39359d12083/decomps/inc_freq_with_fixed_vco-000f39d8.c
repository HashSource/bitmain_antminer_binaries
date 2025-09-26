
void inc_freq_with_fixed_vco(uint8_t chain,uint8_t pll_id,float target_freq)

{
  pllparameter_t target_pll_parameter;
  pllparameter_t pllparameter;
  double dVar1;
  float target_freq_local;
  uint8_t pll_id_local;
  uint8_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t divider_conf_count;
  pll_divider_conf_t pll_divider_conf [49];
  pll_userdivider_t pll_user_divider;
  pllparameter_t target_pll_param;
  float temp_freq;
  uint32_t divider_conf_index;
  
  divider_conf_count = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar1 = (double)target_freq;
  printf("%s: chain::%u, pll_id::%u, freq::%.2f, \n\n","inc_freq_with_fixed_vco",(uint)chain,
         (uint)pll_id,dVar1);
  snprintf(tmp1,0x800,"chain::%u, pll_id::%u, freq::%.2f, \n",(uint)chain,(uint)pll_id,
           (int)((ulonglong)dVar1 >> 0x20),(double)target_freq);
  log_to_file(tmp1,time_stamp);
  memset(&target_pll_param,0,6);
  memset(pll_divider_conf,0,0x188);
  get_pllparam_divider(target_freq,&target_pll_param,&pll_user_divider,(float *)0x0);
  target_pll_parameter.postdiv2 = target_pll_param.postdiv2;
  target_pll_parameter.postdiv1 = target_pll_param.postdiv1;
  target_pll_parameter.refdiv = target_pll_param.refdiv;
  target_pll_parameter._3_1_ = target_pll_param._3_1_;
  target_pll_parameter.fbdiv = target_pll_param.fbdiv;
  get_vco_pll_divider_conf(target_pll_parameter,pll_divider_conf,&divider_conf_count);
  for (divider_conf_index = 0; divider_conf_index < divider_conf_count;
      divider_conf_index = divider_conf_index + 1) {
    target_pll_param.postdiv1 = pll_divider_conf[divider_conf_index].post_div1;
    target_pll_param.postdiv2 = pll_divider_conf[divider_conf_index].post_div2;
    if (50.0 < ((25.0 / (float)target_pll_param.refdiv) * (float)target_pll_param.fbdiv) /
               (float)(longlong)
                      (int)((uint)target_pll_param.postdiv2 * (uint)target_pll_param.postdiv1)) {
      pllparameter.postdiv2 = target_pll_param.postdiv2;
      pllparameter.postdiv1 = target_pll_param.postdiv1;
      pllparameter.refdiv = target_pll_param.refdiv;
      pllparameter._3_1_ = target_pll_param._3_1_;
      pllparameter.fbdiv = target_pll_param.fbdiv;
      set_chain_pllparameter(chain,'\0',pllparameter);
      usleep(100000);
    }
  }
  return;
}

