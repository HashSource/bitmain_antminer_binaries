
void inc_freq_with_matrix(float *matrix,int len)

{
  uint8_t pll_id;
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  undefined4 uVar8;
  _pll_conf pll_config;
  int len_local;
  float *matrix_local;
  char tmp42 [256];
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
  dVar7 = (double)fVar5;
  snprintf(tmp42,0x100,"get all chain min freq %f",tmp42,dVar7);
  puts(tmp42);
  iVar1 = (g_rt.config)->domains;
  iVar2 = (g_rt.config)->asics_in_domain;
  fVar6 = get_freq_matrix_max(matrix,len);
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
        for (j = 0; uVar8 = (undefined4)((ulonglong)dVar7 >> 0x20), j < iVar1; j = j + 1) {
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
            iVar4 = i + iVar2 * j;
            dVar7 = (double)CONCAT44(uVar8,iVar4);
            snprintf(tmp42,0x100,"end chain=%d asic=%d set end freq %.2f",(g_rt.config)->chain,iVar4
                     ,uVar8,(double)fVar3);
            puts(tmp42);
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
            iVar4 = i + iVar2 * j;
            dVar7 = (double)CONCAT44(pll_config._4_4_,iVar4);
            snprintf(tmp42,0x100,"middle chain = %d asic=%d set freq to %.2f",(g_rt.config)->chain,
                     iVar4,pll_config._4_4_,(double)curr_freq);
            puts(tmp42);
          }
        }
      }
      usleep(30000);
    }
  }
  return;
}

