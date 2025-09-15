
int get_pllparam_divider(float freq,uint32_t *pll_param,uint8_t *divider,float *pll_freq)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint8_t uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  uint8_t local_874;
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
  float min_vco;
  float max_vco;
  uint8_t refdiv;
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
  
  pll_vco_choice = 0.0;
  fbdiv_choice = '\0';
  refdiv_choice = '\0';
  postdiv = '\0';
  decimals_last = 25.0;
  bVar3 = false;
  pll_vco = 2800.0;
LAB_00012a6e:
  do {
    if ((int)((uint)(pll_vco < 3125.0) << 0x1f) < 0) {
      pll_vco_step = 12.5;
    }
    else {
      pll_vco_step = 25.0;
    }
    if (bVar3) {
      pll_vco = pll_vco_choice - pll_vco_step;
      bVar3 = false;
      decimals_last = 25.0;
    }
    uVar5 = (uint)(0.0 < 25.0 / pll_vco_step) * (int)(25.0 / pll_vco_step);
    local_874 = (uint8_t)uVar5;
    uVar4 = local_874;
    fVar6 = ((float)(longlong)(int)(uVar5 & 0xff) * pll_vco) / 25.0;
    local_874 = (0.0 < fVar6) * (char)(int)fVar6;
    fVar6 = pll_vco / freq;
    uVar5 = (uint)(0.0 < fVar6) * (int)fVar6;
    fVar6 = fVar6 - (float)uVar5;
    if ((int)((uint)(fVar6 < decimals_last) << 0x1f) < 0) {
      postdiv = (uint8_t)uVar5;
      pll_vco_choice = pll_vco;
      fbdiv_choice = local_874;
      refdiv_choice = uVar4;
      decimals_last = fVar6;
    }
    pll_vco = pll_vco - pll_vco_step;
  } while (2400.0 <= pll_vco);
  if (postdiv < 0x11) {
    pll_div = postdiv;
    postdiv2 = '\x01';
    postdiv1 = '\x01';
  }
  else {
    pll_div = '\x10';
    do {
      bVar1 = pll_div - 1;
      if (pll_div < 3) goto LAB_00012d38;
      fVar6 = (float)postdiv / (float)bVar1;
      fVar7 = fVar6 - (float)((uint)(0.0 < fVar6) * (int)fVar6);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"pll_div decimals %f postdiv_f %f",tmp42,(double)fVar7,(double)fVar6);
        _applog(7,tmp42,false);
      }
      pll_div = bVar1;
    } while (-1 < (int)((uint)(fVar7 < 0.0001) << 0x1f));
    postdiv = __udivsi3(postdiv,bVar1);
LAB_00012d38:
    if ((bVar1 == 2) && ((postdiv & 1) != 0)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 1",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(7,tmp42,false);
      }
      if (pll_vco_choice <= 2400.0) {
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
      goto LAB_00012a6e;
    }
    if (postdiv < 8) {
      postdiv1 = postdiv;
      postdiv2 = '\x01';
      pll_div = bVar1;
      goto LAB_00013050;
    }
    postdiv1 = '\a';
    postdiv2 = '\x01';
    do {
      bVar2 = postdiv1 - 1;
      if (postdiv1 == '\0') goto LAB_00012ebc;
      fVar6 = (float)postdiv / (float)bVar2;
      postdiv1 = bVar2;
    } while (-1 < (int)((uint)(fVar6 - (float)((uint)(0.0 < fVar6) * (int)fVar6) < 0.0001) << 0x1f))
    ;
    local_874 = (0.0 < fVar6) * (char)(int)fVar6;
    postdiv2 = local_874;
LAB_00012ebc:
    if ((bVar2 < postdiv2) || (7 < postdiv2)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 2",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(7,tmp42,false);
      }
      if (2400.0 < pll_vco_choice) {
        pll_vco = pll_vco_choice;
        bVar3 = true;
        goto LAB_00012a6e;
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
LAB_00013050:
  if (pll_freq != (float *)0x0) {
    *pll_freq = ((25.0 / (float)refdiv_choice) * (float)fbdiv_choice) /
                (float)(longlong)(int)((uint)postdiv2 * (uint)postdiv1);
  }
  *pll_param = (uint)postdiv2 |
               (uint)fbdiv_choice << 0x10 | (uint)refdiv_choice << 8 | (uint)postdiv1 << 4;
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
             ,(uint)fbdiv_choice,(double)pll_vco_choice,(uint)fbdiv_choice,(uint)refdiv_choice,
             (uint)postdiv1,(uint)postdiv2,(uint)*divider,*pll_param);
    _applog(7,tmp42,false);
  }
  return 0;
}

