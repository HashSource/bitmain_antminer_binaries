
void inc_freq_with_matrix(float *matrix,int len)

{
  uint8_t pll_id;
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  _pll_conf pll_config;
  int len_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t userdivider;
  _pll_conf target;
  float asic_freq;
  int cycle_pll_id;
  int PLL_1;
  int PLL_0;
  float freq_start;
  float freq_end;
  int domain_asic;
  int domain;
  float freq_step;
  float chain_min_freq;
  int j;
  int i;
  float curr_freq;
  int step_id;
  int step_count;
  
  fVar5 = get_freq_matrix_min(matrix,len);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : get all chain min freq %f\n","inc_freq_with_matrix",SUB84((double)fVar5,0),
         (int)((ulonglong)(double)fVar5 >> 0x20));
  snprintf(tmp1,0x100,"get all chain min freq %f",tmp1,(double)fVar5);
  log_to_file(tmp1,time_stamp);
  iVar1 = (g_rt.config)->domains;
  iVar2 = (g_rt.config)->asics_in_domain;
  fVar6 = get_freq_matrix_max(matrix,len);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq from %.2f to %.2f by matrix\n","inc_freq_with_matrix",SUB84((double)fVar5,0)
         ,(int)((ulonglong)(double)fVar5 >> 0x20),(double)fVar6);
  snprintf(tmp1,0x100,"set freq from %.2f to %.2f by matrix",tmp1,(double)fVar5,(double)fVar6);
  log_to_file(tmp1,time_stamp);
  pll_id = g_pll_id;
  if (fVar5 < fVar6) {
    if (fVar6 <= fVar5) {
      step_count = (int)(longlong)((((fVar5 - fVar6) + 6.25) - 0.01) / 6.25);
    }
    else {
      step_count = (int)(longlong)((((fVar6 - fVar5) + 6.25) - 0.01) / 6.25);
    }
    for (step_id = 1; step_id <= step_count; step_id = step_id + 1) {
      for (i = 0; i < iVar2; i = i + 1) {
        for (j = 0; j < iVar1; j = j + 1) {
          fVar3 = matrix[i + iVar2 * j];
          memset(&target,0,8);
          if (fVar6 <= fVar5) {
            curr_freq = fVar5 - (float)(longlong)step_id * 6.25;
            if ((int)((uint)(curr_freq < fVar6) << 0x1f) < 0) {
              curr_freq = fVar6;
            }
          }
          else {
            curr_freq = (float)(longlong)step_id * 6.25 + fVar5;
            if (fVar6 < curr_freq) {
              curr_freq = fVar6;
            }
          }
          set_user_divider((g_rt.config)->chain,(uint8_t)((i + iVar2 * j & 0xffU) << 1),'\0');
          if (fVar3 < curr_freq) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            iVar4 = i + iVar2 * j;
            printf("%s : asic %d set end freq %.2f\n","inc_freq_with_matrix",iVar4,iVar4,
                   (double)fVar3);
            snprintf(tmp1,0x100,"asic %d set end freq %.2f",i + iVar2 * j,(double)fVar3);
            log_to_file(tmp1,time_stamp);
          }
          else {
            get_pllparam_divider(curr_freq,&target.pll_param,&userdivider,(float *)0x0);
            target.usr_divider = userdivider.userdivider0;
            pll_config.pll_param.fbdiv = target.pll_param.fbdiv;
            pll_config.usr_divider = userdivider.userdivider0;
            pll_config._7_1_ = target._7_1_;
            pll_config.pll_param.postdiv1 = target.pll_param.postdiv1;
            pll_config.pll_param.postdiv2 = target.pll_param.postdiv2;
            pll_config.pll_param.refdiv = target.pll_param.refdiv;
            pll_config.pll_param._3_1_ = target.pll_param._3_1_;
            set_freq_mix((g_rt.config)->chain,'\0',(uint8_t)((i + iVar2 * j & 0xffU) << 1),pll_id,
                         pll_config);
          }
        }
      }
      usleep(30000);
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq by matrix over\n","inc_freq_with_matrix");
  builtin_strncpy(tmp1,"set freq by matrix over",0x18);
  log_to_file(tmp1,time_stamp);
  return;
}

