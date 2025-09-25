
void reset_bad_asic_freq(float *matrix,int len,uint8_t *state)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  _pll_conf pll_config;
  uint8_t *state_local;
  int len_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t userdivider;
  _pll_conf target;
  uint32_t step_count;
  float asic_freq;
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
      fVar4 = matrix[i + iVar3 * j];
      if (state[i + iVar3 * j] == '\0') {
        set_user_divider((g_rt.config)->chain,(uint8_t)((i + iVar3 * j & 0xffU) << 1),'\0');
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
          set_freq_mix((g_rt.config)->chain,'\0',(uint8_t)((i + iVar3 * j & 0xffU) << 1),'\0',
                       pll_config);
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        iVar5 = i + iVar3 * j;
        printf("%s : reset asic[%d] from 50 to freq:%f\n\n\n","reset_bad_asic_freq",iVar5,iVar5,
               (double)fVar4);
        snprintf(tmp1,0x100,"reset asic[%d] from 50 to freq:%f\n\n",i + iVar3 * j,(double)fVar4);
        log_to_file(tmp1,time_stamp);
      }
    }
  }
  return;
}

