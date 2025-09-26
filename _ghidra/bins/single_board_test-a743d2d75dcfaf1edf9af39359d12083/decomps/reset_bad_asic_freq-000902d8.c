
void reset_bad_asic_freq(float *cur_matrix,int len,float *last_matrix)

{
  uint8_t chip_addr_00;
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  _pll_conf pll_config;
  float *last_matrix_local;
  int len_local;
  float *cur_matrix_local;
  char time_stamp [48];
  char tmp1 [2048];
  pll_userdivider_t userdivider;
  _pll_conf target;
  uint32_t step_count;
  float last_freq;
  float asic_freq;
  uint8_t chip_addr;
  int domain_asic;
  int domain;
  int j;
  int i;
  uint32_t step_id;
  float curr_freq;
  
  iVar2 = (g_rt.config)->domains;
  iVar3 = (g_rt.config)->asics_in_domain;
  for (i = 0; i < iVar3; i = i + 1) {
    for (j = 0; j < iVar2; j = j + 1) {
      chip_addr_00 = (char)i + (char)j * (char)iVar3;
      fVar4 = cur_matrix[i + iVar3 * j];
      if ((int)((uint)(fVar4 < last_matrix[i + iVar3 * j]) << 0x1f) < 0) {
        set_user_divider((g_rt.config)->chain,chip_addr_00,'\0');
        fVar1 = (((fVar4 - 50.0) + g_rt.sweep.step) - 0.01) / g_rt.sweep.step;
        for (step_id = 1; step_id <= (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
            step_id = step_id + 1) {
          memset(&target,0,8);
          if (fVar4 <= 50.0) {
            curr_freq = 50.0 - g_rt.sweep.step * (float)step_id;
            if ((int)((uint)(curr_freq < fVar4) << 0x1f) < 0) {
              curr_freq = fVar4;
            }
          }
          else {
            curr_freq = g_rt.sweep.step * (float)step_id + 50.0;
            if (fVar4 < curr_freq) {
              curr_freq = fVar4;
            }
          }
          get_pllparam_divider(curr_freq,&target.pll_param,&userdivider,(float *)0x0);
          target.usr_divider = userdivider.userdivider0;
          pll_config.pll_param.fbdiv = target.pll_param.fbdiv;
          pll_config.usr_divider = userdivider.userdivider0;
          pll_config._7_1_ = target._7_1_;
          pll_config.pll_param.postdiv1 = target.pll_param.postdiv1;
          pll_config.pll_param.postdiv2 = target.pll_param.postdiv2;
          pll_config.pll_param.refdiv = target.pll_param.refdiv;
          pll_config.pll_param._3_1_ = target.pll_param._3_1_;
          set_freq_mix((g_rt.config)->chain,'\0',chip_addr_00,'\0',pll_config);
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        iVar5 = i + iVar3 * j;
        printf("%s: reset asic[%d] freq:%f\n","reset_bad_asic_freq",iVar5,iVar5,(double)fVar4);
        snprintf(tmp1,0x800,"reset asic[%d] freq:%f",i + iVar3 * j,(double)fVar4);
        log_to_file(tmp1,time_stamp);
      }
    }
  }
  return;
}

