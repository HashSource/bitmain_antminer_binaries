
int get_pllparam_divider(float freq,uint32_t *pll_param,uint8_t *divider,float *pll_freq)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  float *pll_freq_local;
  uint8_t *divider_local;
  uint32_t *pll_param_local;
  float freq_local;
  char tmp42 [2048];
  float real_freq;
  uint32_t postdiv_i_1;
  float postdiv_f_1;
  uint32_t postdiv_i;
  float postdiv_f;
  float decimals;
  uint32_t pll_out_div_i;
  float pll_out_div_f;
  uint8_t fbdiv;
  uint8_t refdiv;
  float min_vco;
  float max_vco;
  _Bool need_recal;
  float decimals_last;
  uint8_t postdiv;
  uint8_t pll_div;
  uint8_t postdiv2;
  uint8_t postdiv1;
  uint8_t refdiv_choice;
  uint8_t fbdiv_choice;
  float pll_vco_step;
  float pll_vco_choice;
  float pll_vco;
  
  decimals_last = 25.0;
  bVar3 = false;
  pll_vco = 3200.0;
LAB_00022658:
  do {
    if (3125.0 <= pll_vco) {
      pll_vco_step = 25.0;
    }
    else {
      pll_vco_step = 12.5;
    }
    if (bVar3) {
      pll_vco = pll_vco_choice - pll_vco_step;
      bVar3 = false;
      decimals_last = 25.0;
    }
    uVar4 = (uint)(0.0 < 25.0 / pll_vco_step) * (int)(25.0 / pll_vco_step);
    fVar5 = ((float)(longlong)(int)(uVar4 & 0xff) * pll_vco) / 25.0;
    fVar6 = pll_vco / freq;
    uVar7 = (uint)(0.0 < fVar6) * (int)fVar6;
    fVar6 = fVar6 - (float)uVar7;
    if (fVar6 < decimals_last) {
      postdiv = (uint8_t)uVar7;
      pll_vco_choice = pll_vco;
      decimals_last = fVar6;
      refdiv_choice = (uint8_t)uVar4;
      fbdiv_choice = (0.0 < fVar5) * (char)(int)fVar5;
    }
    pll_vco = pll_vco - pll_vco_step;
  } while (2000.0 <= pll_vco);
  if (postdiv < 0x11) {
    pll_div = postdiv;
    postdiv2 = '\x01';
    postdiv1 = '\x01';
  }
  else {
    pll_div = '\x10';
    do {
      bVar1 = pll_div - 1;
      if (pll_div < 3) goto LAB_00022924;
      fVar5 = (float)postdiv / (float)bVar1;
      fVar6 = fVar5 - (float)((uint)(0.0 < fVar5) * (int)fVar5);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"pll_div decimals %f postdiv_f %f",tmp42,(double)fVar6,(double)fVar5);
        _applog(7,tmp42,false);
      }
      pll_div = bVar1;
    } while (0.0001 <= fVar6);
    postdiv = __udivsi3(postdiv,bVar1);
LAB_00022924:
    if ((bVar1 == 2) && ((postdiv & 1) != 0)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 1",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(7,tmp42,false);
      }
      if (pll_vco_choice <= 2000.0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"!!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pl",0x38);
          tmp42[0x38] = 'l';
          tmp42[0x39] = '\0';
          _applog(3,tmp42,false);
        }
        *pll_param = 0x780111;
        *divider = '\x0f';
        return -1;
      }
      pll_vco = pll_vco_choice;
      bVar3 = true;
      goto LAB_00022658;
    }
    if (postdiv < 8) {
      postdiv1 = postdiv;
      postdiv2 = '\x01';
      pll_div = bVar1;
      goto LAB_00022d38;
    }
    postdiv1 = '\a';
    postdiv2 = '\x01';
    do {
      bVar2 = postdiv1 - 1;
      if (postdiv1 == '\0') goto LAB_00022af8;
      fVar5 = (float)postdiv / (float)bVar2;
      postdiv1 = bVar2;
    } while (0.0001 <= fVar5 - (float)((uint)(0.0 < fVar5) * (int)fVar5));
    postdiv2 = (0.0 < fVar5) * (char)(int)fVar5;
LAB_00022af8:
    if ((bVar2 < postdiv2) || (7 < postdiv2)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 2",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(7,tmp42,false);
      }
      if (2000.0 < pll_vco_choice) {
        pll_vco = pll_vco_choice;
        bVar3 = true;
        goto LAB_00022658;
      }
    }
    pll_div = bVar1;
    postdiv1 = bVar2;
    if ((uint)postdiv != (uint)postdiv2 * (uint)bVar2) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Don\'t find postdiv1 %d * postdiv2 %d = postdiv %d",(uint)bVar2,
                 (uint)postdiv2,(uint)postdiv);
        _applog(3,tmp42,false);
      }
      *pll_param = 0x780111;
      *divider = '\x0f';
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        builtin_strncpy(tmp42,"!!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pl",0x38);
        tmp42[0x38] = 'l';
        tmp42[0x39] = '\0';
        _applog(3,tmp42,false);
      }
      return -1;
    }
  }
LAB_00022d38:
  if (pll_freq != (float *)0x0) {
    *pll_freq = ((25.0 / (float)refdiv_choice) * (float)fbdiv_choice) /
                (float)(longlong)(int)((uint)postdiv2 * (uint)postdiv1);
  }
  *pll_param = (uint)fbdiv_choice << 0x10 | (uint)refdiv_choice << 8 | (uint)postdiv1 << 4 |
               (uint)postdiv2;
  *divider = pll_div;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Want freq %f  real freq %f",tmp42,(double)freq,
             (double)(((25.0 / (float)refdiv_choice) * (float)fbdiv_choice) /
                     (float)(longlong)(int)((uint)pll_div * (uint)postdiv2 * (uint)postdiv1)));
    _applog(7,tmp42,false);
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,
             "pll_vco %f, fbdiv %#x refdiv %#x postdiv1 %#x postdiv2 %#x, pll_divider %d ,{pll_value %#x}"
             ,tmp42,(double)pll_vco_choice,(uint)fbdiv_choice,(uint)refdiv_choice,(uint)postdiv1,
             (uint)postdiv2,(uint)*divider,*pll_param);
    _applog(7,tmp42,false);
  }
  return 0;
}

