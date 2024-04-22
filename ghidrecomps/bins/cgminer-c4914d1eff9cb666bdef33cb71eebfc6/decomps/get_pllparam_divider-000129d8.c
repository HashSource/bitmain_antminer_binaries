
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
restart_cal:
  do {
    if ((int)((uint)(pll_vco < DAT_00012e10) << 0x1f) < 0) {
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
    fVar6 = fVar6 - (float)(ulonglong)uVar5;
    if ((int)((uint)(fVar6 < decimals_last) << 0x1f) < 0) {
      postdiv = (uint8_t)uVar5;
      pll_vco_choice = pll_vco;
      fbdiv_choice = local_874;
      refdiv_choice = uVar4;
      decimals_last = fVar6;
    }
    pll_vco = pll_vco - pll_vco_step;
  } while (pll_vco < 2400.0 == NAN(pll_vco));
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
      fVar6 = (float)(ulonglong)postdiv / (float)(longlong)(int)(uint)bVar1;
      fVar7 = fVar6 - (float)(ulonglong)((uint)(0.0 < fVar6) * (int)fVar6);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"pll_div decimals %f postdiv_f %f",tmp42,(double)fVar7,(double)fVar6);
        _applog(7,tmp42,false);
      }
      pll_div = bVar1;
    } while (-1 < (int)((uint)((double)fVar7 < DAT_00012e08) << 0x1f));
    postdiv = __udivsi3(postdiv,bVar1);
LAB_00012d38:
    if ((bVar1 == 2) && ((postdiv & 1) != 0)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_need_recal_1_0007f8ac[0];
        tmp42[1] = s_need_recal_1_0007f8ac[1];
        tmp42[2] = s_need_recal_1_0007f8ac[2];
        tmp42[3] = s_need_recal_1_0007f8ac[3];
        tmp42[4] = s_need_recal_1_0007f8ac[4];
        tmp42[5] = s_need_recal_1_0007f8ac[5];
        tmp42[6] = s_need_recal_1_0007f8ac[6];
        tmp42[7] = s_need_recal_1_0007f8ac[7];
        tmp42[8] = s_need_recal_1_0007f8ac[8];
        tmp42[9] = s_need_recal_1_0007f8ac[9];
        tmp42[10] = s_need_recal_1_0007f8ac[10];
        tmp42[11] = s_need_recal_1_0007f8ac[11];
        tmp42[12] = (char)ram0x0007f8b8;
        _applog(7,tmp42,false);
      }
      if (pll_vco_choice == 2400.0 || pll_vco_choice < 2400.0 != NAN(pll_vco_choice)) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s________________Set_freq_don_t_ok_0007f900[0];
          tmp42[1] = s________________Set_freq_don_t_ok_0007f900[1];
          tmp42[2] = s________________Set_freq_don_t_ok_0007f900[2];
          tmp42[3] = s________________Set_freq_don_t_ok_0007f900[3];
          tmp42[4] = s________________Set_freq_don_t_ok_0007f900[4];
          tmp42[5] = s________________Set_freq_don_t_ok_0007f900[5];
          tmp42[6] = s________________Set_freq_don_t_ok_0007f900[6];
          tmp42[7] = s________________Set_freq_don_t_ok_0007f900[7];
          tmp42[8] = s________________Set_freq_don_t_ok_0007f900[8];
          tmp42[9] = s________________Set_freq_don_t_ok_0007f900[9];
          tmp42[10] = s________________Set_freq_don_t_ok_0007f900[10];
          tmp42[11] = s________________Set_freq_don_t_ok_0007f900[11];
          tmp42[12] = s________________Set_freq_don_t_ok_0007f900[12];
          tmp42[13] = s________________Set_freq_don_t_ok_0007f900[13];
          tmp42[14] = s________________Set_freq_don_t_ok_0007f900[14];
          tmp42[15] = s________________Set_freq_don_t_ok_0007f900[15];
          tmp42[16] = s________________Set_freq_don_t_ok_0007f900[16];
          tmp42[17] = s________________Set_freq_don_t_ok_0007f900[17];
          tmp42[18] = s________________Set_freq_don_t_ok_0007f900[18];
          tmp42[19] = s________________Set_freq_don_t_ok_0007f900[19];
          tmp42[20] = s________________Set_freq_don_t_ok_0007f900[20];
          tmp42[21] = s________________Set_freq_don_t_ok_0007f900[21];
          tmp42[22] = s________________Set_freq_don_t_ok_0007f900[22];
          tmp42[23] = s________________Set_freq_don_t_ok_0007f900[23];
          tmp42[24] = s________________Set_freq_don_t_ok_0007f900[24];
          tmp42[25] = s________________Set_freq_don_t_ok_0007f900[25];
          tmp42[26] = s________________Set_freq_don_t_ok_0007f900[26];
          tmp42[27] = s________________Set_freq_don_t_ok_0007f900[27];
          tmp42[28] = s________________Set_freq_don_t_ok_0007f900[28];
          tmp42[29] = s________________Set_freq_don_t_ok_0007f900[29];
          tmp42[30] = s________________Set_freq_don_t_ok_0007f900[30];
          tmp42[31] = s________________Set_freq_don_t_ok_0007f900[31];
          tmp42[32] = s________________Set_freq_don_t_ok_0007f900[32];
          tmp42[33] = s________________Set_freq_don_t_ok_0007f900[33];
          tmp42[34] = s________________Set_freq_don_t_ok_0007f900[34];
          tmp42[35] = s________________Set_freq_don_t_ok_0007f900[35];
          tmp42[36] = s________________Set_freq_don_t_ok_0007f900[36];
          tmp42[37] = s________________Set_freq_don_t_ok_0007f900[37];
          tmp42[38] = s________________Set_freq_don_t_ok_0007f900[38];
          tmp42[39] = s________________Set_freq_don_t_ok_0007f900[39];
          tmp42[40] = s________________Set_freq_don_t_ok_0007f900[40];
          tmp42[41] = s________________Set_freq_don_t_ok_0007f900[41];
          tmp42[42] = s________________Set_freq_don_t_ok_0007f900[42];
          tmp42[43] = s________________Set_freq_don_t_ok_0007f900[43];
          tmp42[44] = s________________Set_freq_don_t_ok_0007f900[44];
          tmp42[45] = s________________Set_freq_don_t_ok_0007f900[45];
          tmp42[46] = s________________Set_freq_don_t_ok_0007f900[46];
          tmp42[47] = s________________Set_freq_don_t_ok_0007f900[47];
          tmp42[48] = s________________Set_freq_don_t_ok_0007f900[48];
          tmp42[49] = s________________Set_freq_don_t_ok_0007f900[49];
          tmp42[50] = s________________Set_freq_don_t_ok_0007f900[50];
          tmp42[51] = s________________Set_freq_don_t_ok_0007f900[51];
          tmp42[52] = s________________Set_freq_don_t_ok_0007f900[52];
          tmp42[53] = s________________Set_freq_don_t_ok_0007f900[53];
          tmp42[54] = s________________Set_freq_don_t_ok_0007f900[54];
          tmp42[55] = s________________Set_freq_don_t_ok_0007f900[55];
          tmp42._56_2_ = (undefined2)ram0x0007f938;
          _applog(3,tmp42,false);
        }
        *pll_param = 0x780111;
        *divider = '\x0f';
        return -1;
      }
      pll_vco = pll_vco_choice;
      bVar3 = true;
      goto restart_cal;
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
      fVar6 = (float)(ulonglong)postdiv / (float)(longlong)(int)(uint)bVar2;
      postdiv1 = bVar2;
    } while (-1 < (int)((uint)((double)(fVar6 - (float)(ulonglong)((uint)(0.0 < fVar6) * (int)fVar6)
                                       ) < DAT_00013048) << 0x1f));
    local_874 = (0.0 < fVar6) * (char)(int)fVar6;
    postdiv2 = local_874;
LAB_00012ebc:
    if ((bVar2 < postdiv2) || (7 < postdiv2)) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_need_recal_2_0007f8bc[0];
        tmp42[1] = s_need_recal_2_0007f8bc[1];
        tmp42[2] = s_need_recal_2_0007f8bc[2];
        tmp42[3] = s_need_recal_2_0007f8bc[3];
        tmp42[4] = s_need_recal_2_0007f8bc[4];
        tmp42[5] = s_need_recal_2_0007f8bc[5];
        tmp42[6] = s_need_recal_2_0007f8bc[6];
        tmp42[7] = s_need_recal_2_0007f8bc[7];
        tmp42[8] = s_need_recal_2_0007f8bc[8];
        tmp42[9] = s_need_recal_2_0007f8bc[9];
        tmp42[10] = s_need_recal_2_0007f8bc[10];
        tmp42[11] = s_need_recal_2_0007f8bc[11];
        tmp42[12] = (char)ram0x0007f8c8;
        _applog(7,tmp42,false);
      }
      if (pll_vco_choice != 2400.0 && pll_vco_choice < 2400.0 == NAN(pll_vco_choice)) {
        pll_vco = pll_vco_choice;
        bVar3 = true;
        goto restart_cal;
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
        tmp42[0] = s________________Set_freq_don_t_ok_0007f900[0];
        tmp42[1] = s________________Set_freq_don_t_ok_0007f900[1];
        tmp42[2] = s________________Set_freq_don_t_ok_0007f900[2];
        tmp42[3] = s________________Set_freq_don_t_ok_0007f900[3];
        tmp42[4] = s________________Set_freq_don_t_ok_0007f900[4];
        tmp42[5] = s________________Set_freq_don_t_ok_0007f900[5];
        tmp42[6] = s________________Set_freq_don_t_ok_0007f900[6];
        tmp42[7] = s________________Set_freq_don_t_ok_0007f900[7];
        tmp42[8] = s________________Set_freq_don_t_ok_0007f900[8];
        tmp42[9] = s________________Set_freq_don_t_ok_0007f900[9];
        tmp42[10] = s________________Set_freq_don_t_ok_0007f900[10];
        tmp42[11] = s________________Set_freq_don_t_ok_0007f900[11];
        tmp42[12] = s________________Set_freq_don_t_ok_0007f900[12];
        tmp42[13] = s________________Set_freq_don_t_ok_0007f900[13];
        tmp42[14] = s________________Set_freq_don_t_ok_0007f900[14];
        tmp42[15] = s________________Set_freq_don_t_ok_0007f900[15];
        tmp42[16] = s________________Set_freq_don_t_ok_0007f900[16];
        tmp42[17] = s________________Set_freq_don_t_ok_0007f900[17];
        tmp42[18] = s________________Set_freq_don_t_ok_0007f900[18];
        tmp42[19] = s________________Set_freq_don_t_ok_0007f900[19];
        tmp42[20] = s________________Set_freq_don_t_ok_0007f900[20];
        tmp42[21] = s________________Set_freq_don_t_ok_0007f900[21];
        tmp42[22] = s________________Set_freq_don_t_ok_0007f900[22];
        tmp42[23] = s________________Set_freq_don_t_ok_0007f900[23];
        tmp42[24] = s________________Set_freq_don_t_ok_0007f900[24];
        tmp42[25] = s________________Set_freq_don_t_ok_0007f900[25];
        tmp42[26] = s________________Set_freq_don_t_ok_0007f900[26];
        tmp42[27] = s________________Set_freq_don_t_ok_0007f900[27];
        tmp42[28] = s________________Set_freq_don_t_ok_0007f900[28];
        tmp42[29] = s________________Set_freq_don_t_ok_0007f900[29];
        tmp42[30] = s________________Set_freq_don_t_ok_0007f900[30];
        tmp42[31] = s________________Set_freq_don_t_ok_0007f900[31];
        tmp42[32] = s________________Set_freq_don_t_ok_0007f900[32];
        tmp42[33] = s________________Set_freq_don_t_ok_0007f900[33];
        tmp42[34] = s________________Set_freq_don_t_ok_0007f900[34];
        tmp42[35] = s________________Set_freq_don_t_ok_0007f900[35];
        tmp42[36] = s________________Set_freq_don_t_ok_0007f900[36];
        tmp42[37] = s________________Set_freq_don_t_ok_0007f900[37];
        tmp42[38] = s________________Set_freq_don_t_ok_0007f900[38];
        tmp42[39] = s________________Set_freq_don_t_ok_0007f900[39];
        tmp42[40] = s________________Set_freq_don_t_ok_0007f900[40];
        tmp42[41] = s________________Set_freq_don_t_ok_0007f900[41];
        tmp42[42] = s________________Set_freq_don_t_ok_0007f900[42];
        tmp42[43] = s________________Set_freq_don_t_ok_0007f900[43];
        tmp42[44] = s________________Set_freq_don_t_ok_0007f900[44];
        tmp42[45] = s________________Set_freq_don_t_ok_0007f900[45];
        tmp42[46] = s________________Set_freq_don_t_ok_0007f900[46];
        tmp42[47] = s________________Set_freq_don_t_ok_0007f900[47];
        tmp42[48] = s________________Set_freq_don_t_ok_0007f900[48];
        tmp42[49] = s________________Set_freq_don_t_ok_0007f900[49];
        tmp42[50] = s________________Set_freq_don_t_ok_0007f900[50];
        tmp42[51] = s________________Set_freq_don_t_ok_0007f900[51];
        tmp42[52] = s________________Set_freq_don_t_ok_0007f900[52];
        tmp42[53] = s________________Set_freq_don_t_ok_0007f900[53];
        tmp42[54] = s________________Set_freq_don_t_ok_0007f900[54];
        tmp42[55] = s________________Set_freq_don_t_ok_0007f900[55];
        tmp42._56_2_ = (undefined2)ram0x0007f938;
        _applog(3,tmp42,false);
      }
      return -1;
    }
  }
LAB_00013050:
  if (pll_freq != (float *)0x0) {
    *pll_freq = ((25.0 / (float)(longlong)(int)(uint)refdiv_choice) *
                (float)(longlong)(int)(uint)fbdiv_choice) /
                (float)(longlong)(int)((uint)postdiv2 * (uint)postdiv1);
  }
  *pll_param = (uint)postdiv2 |
               (uint)fbdiv_choice << 0x10 | (uint)refdiv_choice << 8 | (uint)postdiv1 << 4;
  *divider = pll_div;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Want freq %f  real freq %f",tmp42,(double)freq,
             (double)(((25.0 / (float)(longlong)(int)(uint)refdiv_choice) *
                      (float)(longlong)(int)(uint)fbdiv_choice) /
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

