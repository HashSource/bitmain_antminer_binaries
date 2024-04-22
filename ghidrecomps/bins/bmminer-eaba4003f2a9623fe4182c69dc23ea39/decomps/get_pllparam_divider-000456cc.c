
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
restart_cal:
  do {
    if ((int)((uint)(pll_vco < DAT_00045ac0) << 0x1f) < 0) {
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
    fVar3 = ((float)(longlong)(int)(uint)bVar1 * pll_vco) / 25.0;
    fVar4 = pll_vco / freq;
    uVar5 = (uint)(0.0 < fVar4) * (int)fVar4;
    fVar4 = fVar4 - (float)(ulonglong)uVar5;
    if ((int)((uint)(fVar4 < decimals_last) << 0x1f) < 0) {
      postdiv = (uchar)uVar5;
      pll_vco_choice = pll_vco;
      decimals_last = fVar4;
      refdiv_choice = bVar1;
      fbdiv_choice = (0.0 < fVar3) * (char)(int)fVar3;
    }
    pll_vco = pll_vco - pll_vco_step;
  } while (pll_vco < 2000.0 == NAN(pll_vco));
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
      fVar3 = (float)(ulonglong)postdiv / (float)(longlong)(int)(uint)pll_div;
      fVar4 = fVar3 - (float)(ulonglong)((uint)(0.0 < fVar3) * (int)fVar3);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"pll_div decimals %f postdiv_f %f",tmp42,(double)fVar4,(double)fVar3);
        _applog(7,tmp42,false);
      }
    } while (-1 < (int)((uint)((double)fVar4 < DAT_00045ab8) << 0x1f));
    postdiv = __aeabi_uidiv(postdiv,pll_div);
LAB_00045a12:
    if ((pll_div == 2) && ((postdiv & 1) != 0)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        tmp42[0] = s_need_recal_1_00077f0c[0];
        tmp42[1] = s_need_recal_1_00077f0c[1];
        tmp42[2] = s_need_recal_1_00077f0c[2];
        tmp42[3] = s_need_recal_1_00077f0c[3];
        tmp42[4] = s_need_recal_1_00077f0c[4];
        tmp42[5] = s_need_recal_1_00077f0c[5];
        tmp42[6] = s_need_recal_1_00077f0c[6];
        tmp42[7] = s_need_recal_1_00077f0c[7];
        tmp42[8] = s_need_recal_1_00077f0c[8];
        tmp42[9] = s_need_recal_1_00077f0c[9];
        tmp42[10] = s_need_recal_1_00077f0c[10];
        tmp42[11] = s_need_recal_1_00077f0c[11];
        tmp42[12] = (char)ram0x00077f18;
        _applog(5,tmp42,false);
      }
      if (pll_vco_choice == 2000.0 || pll_vco_choice < 2000.0 != NAN(pll_vco_choice)) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s________________Set_freq_don_t_ok_00077f60[0];
          tmp42[1] = s________________Set_freq_don_t_ok_00077f60[1];
          tmp42[2] = s________________Set_freq_don_t_ok_00077f60[2];
          tmp42[3] = s________________Set_freq_don_t_ok_00077f60[3];
          tmp42[4] = s________________Set_freq_don_t_ok_00077f60[4];
          tmp42[5] = s________________Set_freq_don_t_ok_00077f60[5];
          tmp42[6] = s________________Set_freq_don_t_ok_00077f60[6];
          tmp42[7] = s________________Set_freq_don_t_ok_00077f60[7];
          tmp42[8] = s________________Set_freq_don_t_ok_00077f60[8];
          tmp42[9] = s________________Set_freq_don_t_ok_00077f60[9];
          tmp42[10] = s________________Set_freq_don_t_ok_00077f60[10];
          tmp42[11] = s________________Set_freq_don_t_ok_00077f60[11];
          tmp42[12] = s________________Set_freq_don_t_ok_00077f60[12];
          tmp42[13] = s________________Set_freq_don_t_ok_00077f60[13];
          tmp42[14] = s________________Set_freq_don_t_ok_00077f60[14];
          tmp42[15] = s________________Set_freq_don_t_ok_00077f60[15];
          tmp42[16] = s________________Set_freq_don_t_ok_00077f60[16];
          tmp42[17] = s________________Set_freq_don_t_ok_00077f60[17];
          tmp42[18] = s________________Set_freq_don_t_ok_00077f60[18];
          tmp42[19] = s________________Set_freq_don_t_ok_00077f60[19];
          tmp42[20] = s________________Set_freq_don_t_ok_00077f60[20];
          tmp42[21] = s________________Set_freq_don_t_ok_00077f60[21];
          tmp42[22] = s________________Set_freq_don_t_ok_00077f60[22];
          tmp42[23] = s________________Set_freq_don_t_ok_00077f60[23];
          tmp42[24] = s________________Set_freq_don_t_ok_00077f60[24];
          tmp42[25] = s________________Set_freq_don_t_ok_00077f60[25];
          tmp42[26] = s________________Set_freq_don_t_ok_00077f60[26];
          tmp42[27] = s________________Set_freq_don_t_ok_00077f60[27];
          tmp42[28] = s________________Set_freq_don_t_ok_00077f60[28];
          tmp42[29] = s________________Set_freq_don_t_ok_00077f60[29];
          tmp42[30] = s________________Set_freq_don_t_ok_00077f60[30];
          tmp42[31] = s________________Set_freq_don_t_ok_00077f60[31];
          tmp42[32] = s________________Set_freq_don_t_ok_00077f60[32];
          tmp42[33] = s________________Set_freq_don_t_ok_00077f60[33];
          tmp42[34] = s________________Set_freq_don_t_ok_00077f60[34];
          tmp42[35] = s________________Set_freq_don_t_ok_00077f60[35];
          tmp42[36] = s________________Set_freq_don_t_ok_00077f60[36];
          tmp42[37] = s________________Set_freq_don_t_ok_00077f60[37];
          tmp42[38] = s________________Set_freq_don_t_ok_00077f60[38];
          tmp42[39] = s________________Set_freq_don_t_ok_00077f60[39];
          tmp42[40] = s________________Set_freq_don_t_ok_00077f60[40];
          tmp42[41] = s________________Set_freq_don_t_ok_00077f60[41];
          tmp42[42] = s________________Set_freq_don_t_ok_00077f60[42];
          tmp42[43] = s________________Set_freq_don_t_ok_00077f60[43];
          tmp42[44] = s________________Set_freq_don_t_ok_00077f60[44];
          tmp42[45] = s________________Set_freq_don_t_ok_00077f60[45];
          tmp42[46] = s________________Set_freq_don_t_ok_00077f60[46];
          tmp42[47] = s________________Set_freq_don_t_ok_00077f60[47];
          tmp42[48] = s________________Set_freq_don_t_ok_00077f60[48];
          tmp42[49] = s________________Set_freq_don_t_ok_00077f60[49];
          tmp42[50] = s________________Set_freq_don_t_ok_00077f60[50];
          tmp42[51] = s________________Set_freq_don_t_ok_00077f60[51];
          tmp42[52] = s________________Set_freq_don_t_ok_00077f60[52];
          tmp42[53] = s________________Set_freq_don_t_ok_00077f60[53];
          tmp42[54] = s________________Set_freq_don_t_ok_00077f60[54];
          tmp42[55] = s________________Set_freq_don_t_ok_00077f60[55];
          tmp42._56_2_ = (undefined2)ram0x00077f98;
          _applog(3,tmp42,false);
        }
        *pll_param = 0x780111;
        *divider = '\x0f';
        return -1;
      }
      pll_vco = pll_vco_choice;
      bVar2 = true;
      goto restart_cal;
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
      fVar3 = (float)(ulonglong)postdiv / (float)(longlong)(int)(uint)postdiv1;
    } while (-1 < (int)((uint)((double)(fVar3 - (float)(ulonglong)((uint)(0.0 < fVar3) * (int)fVar3)
                                       ) < DAT_00045d08) << 0x1f));
    postdiv2 = (0.0 < fVar3) * (char)(int)fVar3;
LAB_00045b8e:
    if ((postdiv1 < postdiv2) || (7 < postdiv2)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        tmp42[0] = s_need_recal_2_00077f1c[0];
        tmp42[1] = s_need_recal_2_00077f1c[1];
        tmp42[2] = s_need_recal_2_00077f1c[2];
        tmp42[3] = s_need_recal_2_00077f1c[3];
        tmp42[4] = s_need_recal_2_00077f1c[4];
        tmp42[5] = s_need_recal_2_00077f1c[5];
        tmp42[6] = s_need_recal_2_00077f1c[6];
        tmp42[7] = s_need_recal_2_00077f1c[7];
        tmp42[8] = s_need_recal_2_00077f1c[8];
        tmp42[9] = s_need_recal_2_00077f1c[9];
        tmp42[10] = s_need_recal_2_00077f1c[10];
        tmp42[11] = s_need_recal_2_00077f1c[11];
        tmp42[12] = (char)ram0x00077f28;
        _applog(5,tmp42,false);
      }
      if (pll_vco_choice != 2000.0 && pll_vco_choice < 2000.0 == NAN(pll_vco_choice)) {
        pll_vco = pll_vco_choice;
        bVar2 = true;
        goto restart_cal;
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
        tmp42[0] = s________________Set_freq_don_t_ok_00077f60[0];
        tmp42[1] = s________________Set_freq_don_t_ok_00077f60[1];
        tmp42[2] = s________________Set_freq_don_t_ok_00077f60[2];
        tmp42[3] = s________________Set_freq_don_t_ok_00077f60[3];
        tmp42[4] = s________________Set_freq_don_t_ok_00077f60[4];
        tmp42[5] = s________________Set_freq_don_t_ok_00077f60[5];
        tmp42[6] = s________________Set_freq_don_t_ok_00077f60[6];
        tmp42[7] = s________________Set_freq_don_t_ok_00077f60[7];
        tmp42[8] = s________________Set_freq_don_t_ok_00077f60[8];
        tmp42[9] = s________________Set_freq_don_t_ok_00077f60[9];
        tmp42[10] = s________________Set_freq_don_t_ok_00077f60[10];
        tmp42[11] = s________________Set_freq_don_t_ok_00077f60[11];
        tmp42[12] = s________________Set_freq_don_t_ok_00077f60[12];
        tmp42[13] = s________________Set_freq_don_t_ok_00077f60[13];
        tmp42[14] = s________________Set_freq_don_t_ok_00077f60[14];
        tmp42[15] = s________________Set_freq_don_t_ok_00077f60[15];
        tmp42[16] = s________________Set_freq_don_t_ok_00077f60[16];
        tmp42[17] = s________________Set_freq_don_t_ok_00077f60[17];
        tmp42[18] = s________________Set_freq_don_t_ok_00077f60[18];
        tmp42[19] = s________________Set_freq_don_t_ok_00077f60[19];
        tmp42[20] = s________________Set_freq_don_t_ok_00077f60[20];
        tmp42[21] = s________________Set_freq_don_t_ok_00077f60[21];
        tmp42[22] = s________________Set_freq_don_t_ok_00077f60[22];
        tmp42[23] = s________________Set_freq_don_t_ok_00077f60[23];
        tmp42[24] = s________________Set_freq_don_t_ok_00077f60[24];
        tmp42[25] = s________________Set_freq_don_t_ok_00077f60[25];
        tmp42[26] = s________________Set_freq_don_t_ok_00077f60[26];
        tmp42[27] = s________________Set_freq_don_t_ok_00077f60[27];
        tmp42[28] = s________________Set_freq_don_t_ok_00077f60[28];
        tmp42[29] = s________________Set_freq_don_t_ok_00077f60[29];
        tmp42[30] = s________________Set_freq_don_t_ok_00077f60[30];
        tmp42[31] = s________________Set_freq_don_t_ok_00077f60[31];
        tmp42[32] = s________________Set_freq_don_t_ok_00077f60[32];
        tmp42[33] = s________________Set_freq_don_t_ok_00077f60[33];
        tmp42[34] = s________________Set_freq_don_t_ok_00077f60[34];
        tmp42[35] = s________________Set_freq_don_t_ok_00077f60[35];
        tmp42[36] = s________________Set_freq_don_t_ok_00077f60[36];
        tmp42[37] = s________________Set_freq_don_t_ok_00077f60[37];
        tmp42[38] = s________________Set_freq_don_t_ok_00077f60[38];
        tmp42[39] = s________________Set_freq_don_t_ok_00077f60[39];
        tmp42[40] = s________________Set_freq_don_t_ok_00077f60[40];
        tmp42[41] = s________________Set_freq_don_t_ok_00077f60[41];
        tmp42[42] = s________________Set_freq_don_t_ok_00077f60[42];
        tmp42[43] = s________________Set_freq_don_t_ok_00077f60[43];
        tmp42[44] = s________________Set_freq_don_t_ok_00077f60[44];
        tmp42[45] = s________________Set_freq_don_t_ok_00077f60[45];
        tmp42[46] = s________________Set_freq_don_t_ok_00077f60[46];
        tmp42[47] = s________________Set_freq_don_t_ok_00077f60[47];
        tmp42[48] = s________________Set_freq_don_t_ok_00077f60[48];
        tmp42[49] = s________________Set_freq_don_t_ok_00077f60[49];
        tmp42[50] = s________________Set_freq_don_t_ok_00077f60[50];
        tmp42[51] = s________________Set_freq_don_t_ok_00077f60[51];
        tmp42[52] = s________________Set_freq_don_t_ok_00077f60[52];
        tmp42[53] = s________________Set_freq_don_t_ok_00077f60[53];
        tmp42[54] = s________________Set_freq_don_t_ok_00077f60[54];
        tmp42[55] = s________________Set_freq_don_t_ok_00077f60[55];
        tmp42._56_2_ = (undefined2)ram0x00077f98;
        _applog(3,tmp42,false);
      }
      return -1;
    }
  }
LAB_00045d10:
  if (pll_freq != (float *)0x0) {
    *pll_freq = ((25.0 / (float)(longlong)(int)(uint)refdiv_choice) *
                (float)(longlong)(int)(uint)fbdiv_choice) /
                (float)(longlong)(int)((uint)postdiv2 * (uint)postdiv1);
  }
  *pll_param = (uint)postdiv2 |
               (uint)fbdiv_choice << 0x10 | (uint)refdiv_choice << 8 | (uint)postdiv1 << 4;
  *divider = pll_div;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Want freq %f  real freq %f",tmp42,(double)freq,
             (double)(((25.0 / (float)(longlong)(int)(uint)refdiv_choice) *
                      (float)(longlong)(int)(uint)fbdiv_choice) /
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

