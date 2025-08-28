
int get_pllparam_divider(float freq,uint *pll_param,uchar *divider,float *pll_freq)

{
  byte bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float *pll_freq_local;
  uchar *divider_local;
  uint *pll_param_local;
  float freq_local;
  char tmp42 [2048];
  float real_freq;
  uint postdiv_i_1;
  float postdiv_f_1;
  uint postdiv_i;
  float postdiv_f;
  uchar post_div_choice;
  float decimals;
  uint pll_out_div_i;
  float pll_out_div_f;
  uchar fbdiv;
  uchar refdiv;
  float min_vco;
  float max_vco;
  _Bool need_recal;
  float decimals_last;
  uchar postdiv;
  uchar pll_div;
  uchar postdiv2;
  uchar postdiv1;
  uchar refdiv_choice;
  uchar fbdiv_choice;
  float pll_vco_step;
  float pll_vco_choice;
  float pll_vco;
  
  decimals_last = 25.0;
  bVar2 = false;
  pll_vco = 3200.0;
LAB_00045738:
  do {
    if ((int)((uint)(pll_vco < 3125.0) << 0x1f) < 0) {
      pll_vco_step = 12.5;
    }
    else {
      pll_vco_step = 25.0;
    }
    if (bVar2) {
      pll_vco = pll_vco_choice - pll_vco_step;
      bVar2 = false;
      decimals_last = 25.0;
    }
    bVar1 = (0.0 < 25.0 / pll_vco_step) * (char)(int)(25.0 / pll_vco_step);
    fVar3 = ((float)bVar1 * pll_vco) / 25.0;
    fVar4 = pll_vco / freq;
    uVar5 = (uint)(0.0 < fVar4) * (int)fVar4;
    fVar4 = fVar4 - (float)uVar5;
    if ((int)((uint)(fVar4 < decimals_last) << 0x1f) < 0) {
      postdiv = (uchar)uVar5;
      pll_vco_choice = pll_vco;
      decimals_last = fVar4;
      refdiv_choice = bVar1;
      fbdiv_choice = (0.0 < fVar3) * (char)(int)fVar3;
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
      bVar2 = pll_div < 3;
      pll_div = pll_div - 1;
      if (bVar2) goto LAB_00045a12;
      fVar3 = (float)postdiv / (float)pll_div;
      fVar4 = fVar3 - (float)((uint)(0.0 < fVar3) * (int)fVar3);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"pll_div decimals %f postdiv_f %f",tmp42,(double)fVar4,(double)fVar3);
        _applog(7,tmp42,false);
      }
    } while (-1 < (int)((uint)(fVar4 < 0.0001) << 0x1f));
    postdiv = __aeabi_uidiv(postdiv,pll_div);
LAB_00045a12:
    if ((pll_div == 2) && ((postdiv & 1) != 0)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 1",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(5,tmp42,false);
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
      bVar2 = true;
      goto LAB_00045738;
    }
    if (postdiv < 8) {
      postdiv1 = postdiv;
      postdiv2 = '\x01';
      goto LAB_00045d10;
    }
    postdiv1 = '\a';
    postdiv2 = '\x01';
    do {
      bVar2 = postdiv1 == '\0';
      postdiv1 = postdiv1 - 1;
      if (bVar2) goto LAB_00045b8e;
      fVar3 = (float)postdiv / (float)postdiv1;
    } while (-1 < (int)((uint)(fVar3 - (float)((uint)(0.0 < fVar3) * (int)fVar3) < 0.0001) << 0x1f))
    ;
    postdiv2 = (0.0 < fVar3) * (char)(int)fVar3;
LAB_00045b8e:
    if ((postdiv1 < postdiv2) || (7 < postdiv2)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        builtin_strncpy(tmp42,"need recal 2",0xc);
        tmp42._12_4_ = (uint)(uint3)tmp42._13_3_ << 8;
        _applog(5,tmp42,false);
      }
      if (2000.0 < pll_vco_choice) {
        pll_vco = pll_vco_choice;
        bVar2 = true;
        goto LAB_00045738;
      }
    }
    if ((uint)postdiv != (uint)postdiv2 * (uint)postdiv1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Don\'t find postdiv1 %d * postdiv2 %d = postdiv %d",(uint)postdiv1,
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
LAB_00045d10:
  if (pll_freq != (float *)0x0) {
    *pll_freq = ((25.0 / (float)refdiv_choice) * (float)fbdiv_choice) /
                (float)(longlong)(int)((uint)postdiv2 * (uint)postdiv1);
  }
  *pll_param = (uint)postdiv2 |
               (uint)fbdiv_choice << 0x10 | (uint)refdiv_choice << 8 | (uint)postdiv1 << 4;
  *divider = pll_div;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Want freq %f  real freq %f",tmp42,(double)freq,
             (double)(((25.0 / (float)refdiv_choice) * (float)fbdiv_choice) /
                     (float)(longlong)(int)((uint)pll_div * (uint)postdiv2 * (uint)postdiv1)));
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,
             "pll_vco %f, fbdiv %#x refdiv %#x postdiv1 %#x postdiv2 %#x, pll_divider %d ,{pll_value %#x}"
             ,tmp42,(double)pll_vco_choice,(uint)fbdiv_choice,(uint)refdiv_choice,(uint)postdiv1,
             (uint)postdiv2,(uint)*divider,*pll_param);
    _applog(5,tmp42,false);
  }
  return 0;
}

