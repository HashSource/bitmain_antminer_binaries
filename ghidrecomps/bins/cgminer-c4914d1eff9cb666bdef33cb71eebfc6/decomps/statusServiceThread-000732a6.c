
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * statusServiceThread(void *param)

{
  undefined2 uVar1;
  _Bool _Var2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  int *piVar9;
  ssize_t sVar10;
  undefined *puVar11;
  undefined *puVar12;
  float fVar13;
  double dVar14;
  undefined *puVar15;
  void *param_local;
  char tmp42 [2048];
  char endofrequest [5];
  int testID;
  char sendbuf [3];
  int recvlen;
  char strSendbuf [10240];
  uchar buf [8192];
  sockaddr_in from;
  char recvbuf [10240];
  timeval timeout;
  CHIP_LEVEL bin_level;
  CHIP_MINOR_TYPE minor_type;
  CHIP_MAJOR_TYPE major_type;
  int bError;
  int ret;
  int s1;
  int chain;
  int res_mode;
  int sentlen;
  int buflen;
  int len;
  char *precvbuf;
  
  timeout.tv_sec = 3;
  timeout.tv_usec = 0;
  memset(recvbuf,0,0x2800);
  precvbuf = recvbuf;
  buflen = 0;
  recvlen = 0;
  sendbuf[2] = '\0';
  testID = -1;
  sendbuf[0] = '\r';
  sendbuf[1] = '\n';
  endofrequest[4] = '\0';
  endofrequest[0] = '\r';
  endofrequest[1] = '\n';
  endofrequest[2] = '\r';
  endofrequest[3] = '\n';
  memset(recvbuf,0,0x2800);
  do {
    if (ExitServer == true) goto LAB_00073612;
    buflen = recvfrom((int)param,precvbuf,0x27ff - buflen,0,(sockaddr *)&from,(socklen_t *)&recvlen)
    ;
    if (buflen < 1) {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s__statusServiceThread_recvfrom<_0_000963c0[0];
        tmp42[1] = s__statusServiceThread_recvfrom<_0_000963c0[1];
        tmp42[2] = s__statusServiceThread_recvfrom<_0_000963c0[2];
        tmp42[3] = s__statusServiceThread_recvfrom<_0_000963c0[3];
        tmp42[4] = s__statusServiceThread_recvfrom<_0_000963c0[4];
        tmp42[5] = s__statusServiceThread_recvfrom<_0_000963c0[5];
        tmp42[6] = s__statusServiceThread_recvfrom<_0_000963c0[6];
        tmp42[7] = s__statusServiceThread_recvfrom<_0_000963c0[7];
        tmp42[8] = s__statusServiceThread_recvfrom<_0_000963c0[8];
        tmp42[9] = s__statusServiceThread_recvfrom<_0_000963c0[9];
        tmp42[10] = s__statusServiceThread_recvfrom<_0_000963c0[10];
        tmp42[11] = s__statusServiceThread_recvfrom<_0_000963c0[11];
        tmp42[12] = s__statusServiceThread_recvfrom<_0_000963c0[12];
        tmp42[13] = s__statusServiceThread_recvfrom<_0_000963c0[13];
        tmp42[14] = s__statusServiceThread_recvfrom<_0_000963c0[14];
        tmp42[15] = s__statusServiceThread_recvfrom<_0_000963c0[15];
        tmp42[16] = s__statusServiceThread_recvfrom<_0_000963c0[16];
        tmp42[17] = s__statusServiceThread_recvfrom<_0_000963c0[17];
        tmp42[18] = s__statusServiceThread_recvfrom<_0_000963c0[18];
        tmp42[19] = s__statusServiceThread_recvfrom<_0_000963c0[19];
        tmp42[20] = s__statusServiceThread_recvfrom<_0_000963c0[20];
        tmp42[21] = s__statusServiceThread_recvfrom<_0_000963c0[21];
        tmp42[22] = s__statusServiceThread_recvfrom<_0_000963c0[22];
        tmp42[23] = s__statusServiceThread_recvfrom<_0_000963c0[23];
        tmp42[24] = s__statusServiceThread_recvfrom<_0_000963c0[24];
        tmp42[25] = s__statusServiceThread_recvfrom<_0_000963c0[25];
        tmp42[26] = s__statusServiceThread_recvfrom<_0_000963c0[26];
        tmp42[27] = s__statusServiceThread_recvfrom<_0_000963c0[27];
        tmp42[28] = s__statusServiceThread_recvfrom<_0_000963c0[28];
        tmp42[29] = s__statusServiceThread_recvfrom<_0_000963c0[29];
        tmp42[30] = s__statusServiceThread_recvfrom<_0_000963c0[30];
        tmp42[31] = s__statusServiceThread_recvfrom<_0_000963c0[31];
        tmp42[32] = (char)ram0x000963e0;
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    if (buflen == 0x27ff) {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_BUFSIZE_is_too_small__000963e4[0];
        tmp42[1] = s_BUFSIZE_is_too_small__000963e4[1];
        tmp42[2] = s_BUFSIZE_is_too_small__000963e4[2];
        tmp42[3] = s_BUFSIZE_is_too_small__000963e4[3];
        tmp42[4] = s_BUFSIZE_is_too_small__000963e4[4];
        tmp42[5] = s_BUFSIZE_is_too_small__000963e4[5];
        tmp42[6] = s_BUFSIZE_is_too_small__000963e4[6];
        tmp42[7] = s_BUFSIZE_is_too_small__000963e4[7];
        tmp42[8] = s_BUFSIZE_is_too_small__000963e4[8];
        tmp42[9] = s_BUFSIZE_is_too_small__000963e4[9];
        tmp42[10] = s_BUFSIZE_is_too_small__000963e4[10];
        tmp42[11] = s_BUFSIZE_is_too_small__000963e4[11];
        tmp42[12] = s_BUFSIZE_is_too_small__000963e4[12];
        tmp42[13] = s_BUFSIZE_is_too_small__000963e4[13];
        tmp42[14] = s_BUFSIZE_is_too_small__000963e4[14];
        tmp42[15] = s_BUFSIZE_is_too_small__000963e4[15];
        tmp42[16] = s_BUFSIZE_is_too_small__000963e4[16];
        tmp42[17] = s_BUFSIZE_is_too_small__000963e4[17];
        tmp42[18] = s_BUFSIZE_is_too_small__000963e4[18];
        tmp42[19] = s_BUFSIZE_is_too_small__000963e4[19];
        tmp42[20] = (char)(short)ram0x000963f8;
        tmp42[21] = (char)((ushort)(short)ram0x000963f8 >> 8);
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    precvbuf = recvbuf + buflen;
    pcVar3 = strstr(recvbuf,endofrequest);
  } while (pcVar3 == (char *)0x0);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    tmp42[0] = s_find_http_request_end_flag__000963fc[0];
    tmp42[1] = s_find_http_request_end_flag__000963fc[1];
    tmp42[2] = s_find_http_request_end_flag__000963fc[2];
    tmp42[3] = s_find_http_request_end_flag__000963fc[3];
    tmp42[4] = s_find_http_request_end_flag__000963fc[4];
    tmp42[5] = s_find_http_request_end_flag__000963fc[5];
    tmp42[6] = s_find_http_request_end_flag__000963fc[6];
    tmp42[7] = s_find_http_request_end_flag__000963fc[7];
    tmp42[8] = s_find_http_request_end_flag__000963fc[8];
    tmp42[9] = s_find_http_request_end_flag__000963fc[9];
    tmp42[10] = s_find_http_request_end_flag__000963fc[10];
    tmp42[11] = s_find_http_request_end_flag__000963fc[11];
    tmp42[12] = s_find_http_request_end_flag__000963fc[12];
    tmp42[13] = s_find_http_request_end_flag__000963fc[13];
    tmp42[14] = s_find_http_request_end_flag__000963fc[14];
    tmp42[15] = s_find_http_request_end_flag__000963fc[15];
    tmp42[16] = s_find_http_request_end_flag__000963fc[16];
    tmp42[17] = s_find_http_request_end_flag__000963fc[17];
    tmp42[18] = s_find_http_request_end_flag__000963fc[18];
    tmp42[19] = s_find_http_request_end_flag__000963fc[19];
    tmp42[20] = s_find_http_request_end_flag__000963fc[20];
    tmp42[21] = s_find_http_request_end_flag__000963fc[21];
    tmp42[22] = s_find_http_request_end_flag__000963fc[22];
    tmp42[23] = s_find_http_request_end_flag__000963fc[23];
    tmp42[24] = s_find_http_request_end_flag__000963fc[24];
    tmp42[25] = s_find_http_request_end_flag__000963fc[25];
    tmp42[26] = s_find_http_request_end_flag__000963fc[26];
    tmp42[27] = s_find_http_request_end_flag__000963fc[27];
    _applog(7,tmp42,false);
  }
LAB_00073612:
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"get http=%s",recvbuf);
    _applog(7,tmp42,false);
  }
  if (((recvbuf[0] == 'G') && (recvbuf[1] == 'E')) && ((recvbuf[2] == 'T' && (recvbuf[3] == ' '))))
  {
    pcVar3 = strstr(recvbuf + 4,"/rate");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strstr(recvbuf + 4,"/ideal_rate");
      if (pcVar3 == (char *)0x0) {
        pcVar3 = strstr(recvbuf + 4,"/max_rate");
        if (pcVar3 == (char *)0x0) {
          pcVar3 = strstr(recvbuf + 4,"/test");
          if (pcVar3 == (char *)0x0) {
            close((int)param);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42[0] = s_statusServiceThread_exit_for_Err_000964d8[0];
              tmp42[1] = s_statusServiceThread_exit_for_Err_000964d8[1];
              tmp42[2] = s_statusServiceThread_exit_for_Err_000964d8[2];
              tmp42[3] = s_statusServiceThread_exit_for_Err_000964d8[3];
              tmp42[4] = s_statusServiceThread_exit_for_Err_000964d8[4];
              tmp42[5] = s_statusServiceThread_exit_for_Err_000964d8[5];
              tmp42[6] = s_statusServiceThread_exit_for_Err_000964d8[6];
              tmp42[7] = s_statusServiceThread_exit_for_Err_000964d8[7];
              tmp42[8] = s_statusServiceThread_exit_for_Err_000964d8[8];
              tmp42[9] = s_statusServiceThread_exit_for_Err_000964d8[9];
              tmp42[10] = s_statusServiceThread_exit_for_Err_000964d8[10];
              tmp42[11] = s_statusServiceThread_exit_for_Err_000964d8[11];
              tmp42[12] = s_statusServiceThread_exit_for_Err_000964d8[12];
              tmp42[13] = s_statusServiceThread_exit_for_Err_000964d8[13];
              tmp42[14] = s_statusServiceThread_exit_for_Err_000964d8[14];
              tmp42[15] = s_statusServiceThread_exit_for_Err_000964d8[15];
              tmp42[16] = s_statusServiceThread_exit_for_Err_000964d8[16];
              tmp42[17] = s_statusServiceThread_exit_for_Err_000964d8[17];
              tmp42[18] = s_statusServiceThread_exit_for_Err_000964d8[18];
              tmp42[19] = s_statusServiceThread_exit_for_Err_000964d8[19];
              tmp42[20] = s_statusServiceThread_exit_for_Err_000964d8[20];
              tmp42[21] = s_statusServiceThread_exit_for_Err_000964d8[21];
              tmp42[22] = s_statusServiceThread_exit_for_Err_000964d8[22];
              tmp42[23] = s_statusServiceThread_exit_for_Err_000964d8[23];
              tmp42[24] = s_statusServiceThread_exit_for_Err_000964d8[24];
              tmp42[25] = s_statusServiceThread_exit_for_Err_000964d8[25];
              tmp42[26] = s_statusServiceThread_exit_for_Err_000964d8[26];
              tmp42[27] = s_statusServiceThread_exit_for_Err_000964d8[27];
              tmp42[28] = s_statusServiceThread_exit_for_Err_000964d8[28];
              tmp42[29] = s_statusServiceThread_exit_for_Err_000964d8[29];
              tmp42[30] = s_statusServiceThread_exit_for_Err_000964d8[30];
              tmp42[31] = s_statusServiceThread_exit_for_Err_000964d8[31];
              tmp42[32] = s_statusServiceThread_exit_for_Err_000964d8[32];
              tmp42[33] = s_statusServiceThread_exit_for_Err_000964d8[33];
              tmp42[34] = s_statusServiceThread_exit_for_Err_000964d8[34];
              tmp42[35] = s_statusServiceThread_exit_for_Err_000964d8[35];
              tmp42[36] = s_statusServiceThread_exit_for_Err_000964d8[36];
              tmp42[37] = s_statusServiceThread_exit_for_Err_000964d8[37];
              tmp42[38] = s_statusServiceThread_exit_for_Err_000964d8[38];
              tmp42[39] = s_statusServiceThread_exit_for_Err_000964d8[39];
              _applog(7,tmp42,false);
            }
            return (void *)0x0;
          }
          __isoc99_sscanf(recvbuf + 4,"/test.%d",&testID);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"cmd : get test = %d",testID);
            _applog(7,tmp42,false);
          }
          res_mode = 1;
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_cmd___get_max_rate_0009649c[0];
            tmp42[1] = s_cmd___get_max_rate_0009649c[1];
            tmp42[2] = s_cmd___get_max_rate_0009649c[2];
            tmp42[3] = s_cmd___get_max_rate_0009649c[3];
            tmp42[4] = s_cmd___get_max_rate_0009649c[4];
            tmp42[5] = s_cmd___get_max_rate_0009649c[5];
            tmp42[6] = s_cmd___get_max_rate_0009649c[6];
            tmp42[7] = s_cmd___get_max_rate_0009649c[7];
            tmp42[8] = s_cmd___get_max_rate_0009649c[8];
            tmp42[9] = s_cmd___get_max_rate_0009649c[9];
            tmp42[10] = s_cmd___get_max_rate_0009649c[10];
            tmp42[11] = s_cmd___get_max_rate_0009649c[11];
            tmp42[12] = s_cmd___get_max_rate_0009649c[12];
            tmp42[13] = s_cmd___get_max_rate_0009649c[13];
            tmp42[14] = s_cmd___get_max_rate_0009649c[14];
            tmp42[15] = s_cmd___get_max_rate_0009649c[15];
            tmp42._16_3_ = (undefined3)ram0x000964ac;
            _applog(7,tmp42,false);
          }
          res_mode = 3;
        }
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_cmd___get_ideal_rate_00096478[0];
          tmp42[1] = s_cmd___get_ideal_rate_00096478[1];
          tmp42[2] = s_cmd___get_ideal_rate_00096478[2];
          tmp42[3] = s_cmd___get_ideal_rate_00096478[3];
          tmp42[4] = s_cmd___get_ideal_rate_00096478[4];
          tmp42[5] = s_cmd___get_ideal_rate_00096478[5];
          tmp42[6] = s_cmd___get_ideal_rate_00096478[6];
          tmp42[7] = s_cmd___get_ideal_rate_00096478[7];
          tmp42[8] = s_cmd___get_ideal_rate_00096478[8];
          tmp42[9] = s_cmd___get_ideal_rate_00096478[9];
          tmp42[10] = s_cmd___get_ideal_rate_00096478[10];
          tmp42[11] = s_cmd___get_ideal_rate_00096478[11];
          tmp42[12] = s_cmd___get_ideal_rate_00096478[12];
          tmp42[13] = s_cmd___get_ideal_rate_00096478[13];
          tmp42[14] = s_cmd___get_ideal_rate_00096478[14];
          tmp42[15] = s_cmd___get_ideal_rate_00096478[15];
          tmp42[16] = s_cmd___get_ideal_rate_00096478[16];
          tmp42[17] = s_cmd___get_ideal_rate_00096478[17];
          tmp42[18] = s_cmd___get_ideal_rate_00096478[18];
          tmp42[19] = s_cmd___get_ideal_rate_00096478[19];
          tmp42[20] = (char)ram0x0009648c;
          _applog(7,tmp42,false);
        }
        res_mode = 2;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_cmd___get_rate_0009645c[0];
        tmp42[1] = s_cmd___get_rate_0009645c[1];
        tmp42[2] = s_cmd___get_rate_0009645c[2];
        tmp42[3] = s_cmd___get_rate_0009645c[3];
        tmp42[4] = s_cmd___get_rate_0009645c[4];
        tmp42[5] = s_cmd___get_rate_0009645c[5];
        tmp42[6] = s_cmd___get_rate_0009645c[6];
        tmp42[7] = s_cmd___get_rate_0009645c[7];
        tmp42[8] = s_cmd___get_rate_0009645c[8];
        tmp42[9] = s_cmd___get_rate_0009645c[9];
        tmp42[10] = s_cmd___get_rate_0009645c[10];
        tmp42[11] = s_cmd___get_rate_0009645c[11];
        tmp42._12_3_ = (undefined3)ram0x00096468;
        _applog(7,tmp42,false);
      }
      res_mode = 0;
    }
    iVar4 = setsockopt((int)param,1,0x15,&timeout,8);
    if (iVar4 == 0) {
      puVar15 = (undefined *)0x8;
      iVar4 = setsockopt((int)param,1,0x14,&timeout,8);
      if (iVar4 == 0) {
        if (res_mode == 1) {
          if (testID == 0x20b) {
            getMinerInfo((char *)buf);
          }
          else if (testID == 0x20c) {
            getReopenInfo((char *)buf);
          }
          else if (testID == 0x20d) {
            getAgingInbalanceTimes((char *)buf);
          }
          else if (testID == 0x20e) {
            getDiffFreqInfo((char *)buf);
          }
          else if (testID == 0x20f) {
            _Var2 = is_T11();
            if (_Var2) {
              buf[0] = s_current_working_voltage__00096540[0];
              buf[1] = s_current_working_voltage__00096540[1];
              buf[2] = s_current_working_voltage__00096540[2];
              buf[3] = s_current_working_voltage__00096540[3];
              buf[4] = s_current_working_voltage__00096540[4];
              buf[5] = s_current_working_voltage__00096540[5];
              buf[6] = s_current_working_voltage__00096540[6];
              buf[7] = s_current_working_voltage__00096540[7];
              buf[8] = s_current_working_voltage__00096540[8];
              buf[9] = s_current_working_voltage__00096540[9];
              buf[10] = s_current_working_voltage__00096540[10];
              buf[11] = s_current_working_voltage__00096540[11];
              buf[12] = s_current_working_voltage__00096540[12];
              buf[13] = s_current_working_voltage__00096540[13];
              buf[14] = s_current_working_voltage__00096540[14];
              buf[15] = s_current_working_voltage__00096540[15];
              buf[16] = s_current_working_voltage__00096540[16];
              buf[17] = s_current_working_voltage__00096540[17];
              buf[18] = s_current_working_voltage__00096540[18];
              buf[19] = s_current_working_voltage__00096540[19];
              buf[20] = s_current_working_voltage__00096540[20];
              buf[21] = s_current_working_voltage__00096540[21];
              buf[22] = s_current_working_voltage__00096540[22];
              buf[23] = s_current_working_voltage__00096540[23];
              buf._24_2_ = (undefined2)ram0x00096558;
              len = 0x19;
              for (chain = 0; chain < 0x10; chain = chain + 1) {
                if (dev->chain_exist[chain] != 0) {
                  dVar14 = get_working_voltage_by_chain((uint8_t)chain);
                  iVar4 = sprintf((char *)(buf + len),"%2.2f ",SUB84(dVar14,0),
                                  (int)((ulonglong)dVar14 >> 0x20));
                  len = len + iVar4;
                }
              }
            }
            else {
              dVar14 = get_working_voltage();
              sprintf((char *)buf,"current working voltage=%.2f",SUB84(dVar14,0),
                      (int)((ulonglong)dVar14 >> 0x20));
            }
          }
          else if (testID == 0x210) {
            get_reopen_time_record_info((char *)buf);
          }
          else if (testID == 0x211) {
            getAginginfo((char *)buf);
          }
          else if (testID == 0x212) {
            iVar4 = get_eeprom_total_hash_rate();
            sprintf((char *)buf,"%d",iVar4);
          }
          else if (testID == 0x213) {
            iVar4 = get_ideal_hash_rate_max();
            sprintf((char *)buf,"%d",iVar4);
          }
          else if (testID == 0x214) {
            fVar13 = _get_higher_voltage();
            sprintf((char *)buf,"higher voltage=%.2f",SUB84((double)fVar13,0),
                    (int)((ulonglong)(double)fVar13 >> 0x20));
          }
          else if (testID == 0x216) {
            if (g_major_type[0] == CHIP_1393) {
              puVar11 = &UNK_000965b0;
            }
            else if (g_major_type[0] == CHIP_1391) {
              puVar11 = &UNK_000965a8;
            }
            else if (g_major_type[0] == CHIP_1397) {
              puVar11 = &DAT_0009659c;
            }
            else {
              puVar11 = &DAT_000965a4;
            }
            if (g_minor_type[0] == PKG_BSL) {
              puVar12 = &UNK_000965d0;
            }
            else if (g_minor_type[0] == PKG_BE) {
              puVar12 = &UNK_000965cc;
            }
            else if (g_minor_type[0] == PKG_B_BGM) {
              puVar12 = &UNK_000965c4;
            }
            else if (g_minor_type[0] == PKG_BE_BGM) {
              puVar12 = &UNK_000965bc;
            }
            else if (g_minor_type[0] == PKG_CE) {
              puVar12 = &DAT_000965b8;
            }
            else {
              puVar12 = &DAT_000965a4;
            }
            if (g_bin_level[0] == BIN1) {
              puVar15 = &DAT_000965ec;
            }
            else if (g_bin_level[0] == BIN2) {
              puVar15 = &DAT_000965e4;
            }
            else if (g_bin_level[0] == BIN3) {
              puVar15 = &DAT_000965dc;
            }
            else if (g_bin_level[0] == BIN4) {
              puVar15 = &DAT_000965d4;
            }
            else {
              puVar15 = &DAT_000965a4;
            }
            sprintf((char *)buf,"%s %s %s",puVar11,puVar12,puVar15);
          }
          else if (testID == 0x217) {
            dVar14 = aging_get_finish_avg_hashrate();
            sprintf((char *)buf,"average hashrate when aging finish = %.2f",SUB84(dVar14,0),
                    (int)((ulonglong)dVar14 >> 0x20));
          }
          else if (testID == 0x218) {
            iVar4 = aging_get_last_stable_time();
            sprintf((char *)buf,"aging last stable = %d seconds",iVar4);
          }
          else if (testID == 0x219) {
            aging_get_update_hashrate_info((char *)buf);
          }
          else if (testID == 0x21a) {
            sprintf((char *)buf,"find_asic_count %d with_pre_open_core %d",find_asic_with_count,
                    find_asic_with_pre_open_core_count);
          }
          else if (testID == 0x21b) {
            sprintf((char *)buf,"%d",aging_re_open_core_times);
          }
          else if (testID == 0x21c) {
            sprintf((char *)buf,"%d",force_reopen_times);
          }
          else if (testID == 0x21d) {
            puVar15 = (undefined *)dev->temp_top1[0];
            sprintf((char *)buf," %d %d %d %d %d",dev->fan_speed_top1,dev->temp_low1[0],puVar15,
                    dev->temp_low1[1],dev->temp_top1[1]);
          }
          else if (testID == 0x21e) {
            iVar4 = aging_get_sweep_temp();
            sprintf((char *)buf,"%d",iVar4);
          }
          else if (testID == 0x21f) {
            get_imbalance_domain_count((char *)buf);
          }
          else if (testID == 0x220) {
            get_avg_freq_info((char *)buf);
          }
          else if (testID == 0x221) {
            get_asic_sweep_stat((char *)buf);
          }
          else {
            sprintf((char *)buf,"OK get test=%d",testID);
          }
        }
        if (res_mode == 0) {
          if (freq_scan_status == 1) {
            iVar4 = GetTotalRate();
            iVar4 = ConvirtTotalRate(iVar4);
            sprintf((char *)buf,"%d",iVar4,buf,puVar15);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info,buf,puVar15);
          }
          else {
            uVar1 = (undefined2)ram0x000966a0;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
            else {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
          }
        }
        if (res_mode == 2) {
          if (freq_scan_status == 1) {
            iVar4 = get_eeprom_total_hash_rate();
            sprintf((char *)buf,"%d",iVar4,buf,puVar15);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info,buf,puVar15);
          }
          else {
            uVar1 = (undefined2)ram0x000966a0;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
            else {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
          }
        }
        if (res_mode == 3) {
          if (freq_scan_status == 1) {
            iVar4 = get_ideal_hash_rate_max();
            sprintf((char *)buf,"%d",iVar4);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info,buf,puVar15);
          }
          else {
            uVar1 = (undefined2)ram0x000966a0;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
            else {
              buf[0] = s_searching_00096698[0];
              buf[1] = s_searching_00096698[1];
              buf[2] = s_searching_00096698[2];
              buf[3] = s_searching_00096698[3];
              buf[4] = s_searching_00096698[4];
              buf[5] = s_searching_00096698[5];
              buf[6] = s_searching_00096698[6];
              buf[7] = s_searching_00096698[7];
              buf[8] = (char)uVar1;
              buf[9] = (char)((ushort)uVar1 >> 8);
            }
          }
        }
        sVar5 = strlen((char *)buf);
        iVar4 = sprintf(strSendbuf,"HTTP/1.0  200  OK%s",sendbuf);
        iVar6 = sprintf(strSendbuf + iVar4,"Server: SearchFreqServer%s",sendbuf);
        iVar7 = sprintf(strSendbuf + iVar4 + iVar6,"Cache-Control: no-cache%s",sendbuf);
        iVar7 = iVar4 + iVar6 + iVar7;
        iVar4 = sprintf(strSendbuf + iVar7,"Pragma: no-cache%s",sendbuf);
        iVar7 = iVar7 + iVar4;
        iVar4 = sprintf(strSendbuf + iVar7,"Content-Type: text/plain%s",sendbuf);
        iVar7 = iVar7 + iVar4;
        iVar4 = sprintf(strSendbuf + iVar7,"Content-Length: %d%s",sVar5,sendbuf);
        sprintf(strSendbuf + iVar7 + iVar4,"Connection: Keep-Alive%s",endofrequest);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_send_http_response____00096764[0];
          tmp42[1] = s_send_http_response____00096764[1];
          tmp42[2] = s_send_http_response____00096764[2];
          tmp42[3] = s_send_http_response____00096764[3];
          tmp42[4] = s_send_http_response____00096764[4];
          tmp42[5] = s_send_http_response____00096764[5];
          tmp42[6] = s_send_http_response____00096764[6];
          tmp42[7] = s_send_http_response____00096764[7];
          tmp42[8] = s_send_http_response____00096764[8];
          tmp42[9] = s_send_http_response____00096764[9];
          tmp42[10] = s_send_http_response____00096764[10];
          tmp42[11] = s_send_http_response____00096764[11];
          tmp42[12] = s_send_http_response____00096764[12];
          tmp42[13] = s_send_http_response____00096764[13];
          tmp42[14] = s_send_http_response____00096764[14];
          tmp42[15] = s_send_http_response____00096764[15];
          tmp42[16] = s_send_http_response____00096764[16];
          tmp42[17] = s_send_http_response____00096764[17];
          tmp42[18] = s_send_http_response____00096764[18];
          tmp42[19] = s_send_http_response____00096764[19];
          tmp42._20_3_ = (undefined3)ram0x00096778;
          _applog(7,tmp42,false);
        }
        while (ExitServer != true) {
          sentlen = 0;
          do {
            sVar8 = strlen(strSendbuf);
            sVar10 = send((int)param,strSendbuf + sentlen,sVar8 - sentlen,0);
            if ((sVar10 == -1) && (piVar9 = __errno_location(), *piVar9 == 0xb)) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                tmp42[0] = s_statusServiceThread_send_http_ti_0009677c[0];
                tmp42[1] = s_statusServiceThread_send_http_ti_0009677c[1];
                tmp42[2] = s_statusServiceThread_send_http_ti_0009677c[2];
                tmp42[3] = s_statusServiceThread_send_http_ti_0009677c[3];
                tmp42[4] = s_statusServiceThread_send_http_ti_0009677c[4];
                tmp42[5] = s_statusServiceThread_send_http_ti_0009677c[5];
                tmp42[6] = s_statusServiceThread_send_http_ti_0009677c[6];
                tmp42[7] = s_statusServiceThread_send_http_ti_0009677c[7];
                tmp42[8] = s_statusServiceThread_send_http_ti_0009677c[8];
                tmp42[9] = s_statusServiceThread_send_http_ti_0009677c[9];
                tmp42[10] = s_statusServiceThread_send_http_ti_0009677c[10];
                tmp42[11] = s_statusServiceThread_send_http_ti_0009677c[11];
                tmp42[12] = s_statusServiceThread_send_http_ti_0009677c[12];
                tmp42[13] = s_statusServiceThread_send_http_ti_0009677c[13];
                tmp42[14] = s_statusServiceThread_send_http_ti_0009677c[14];
                tmp42[15] = s_statusServiceThread_send_http_ti_0009677c[15];
                tmp42[16] = s_statusServiceThread_send_http_ti_0009677c[16];
                tmp42[17] = s_statusServiceThread_send_http_ti_0009677c[17];
                tmp42[18] = s_statusServiceThread_send_http_ti_0009677c[18];
                tmp42[19] = s_statusServiceThread_send_http_ti_0009677c[19];
                tmp42[20] = s_statusServiceThread_send_http_ti_0009677c[20];
                tmp42[21] = s_statusServiceThread_send_http_ti_0009677c[21];
                tmp42[22] = s_statusServiceThread_send_http_ti_0009677c[22];
                tmp42[23] = s_statusServiceThread_send_http_ti_0009677c[23];
                tmp42[24] = s_statusServiceThread_send_http_ti_0009677c[24];
                tmp42[25] = s_statusServiceThread_send_http_ti_0009677c[25];
                tmp42[26] = s_statusServiceThread_send_http_ti_0009677c[26];
                tmp42[27] = s_statusServiceThread_send_http_ti_0009677c[27];
                tmp42[28] = s_statusServiceThread_send_http_ti_0009677c[28];
                tmp42[29] = s_statusServiceThread_send_http_ti_0009677c[29];
                tmp42[30] = s_statusServiceThread_send_http_ti_0009677c[30];
                tmp42[31] = s_statusServiceThread_send_http_ti_0009677c[31];
                tmp42[32] = s_statusServiceThread_send_http_ti_0009677c[32];
                tmp42[33] = s_statusServiceThread_send_http_ti_0009677c[33];
                tmp42[34] = s_statusServiceThread_send_http_ti_0009677c[34];
                tmp42[35] = s_statusServiceThread_send_http_ti_0009677c[35];
                tmp42[36] = s_statusServiceThread_send_http_ti_0009677c[36];
                tmp42[37] = s_statusServiceThread_send_http_ti_0009677c[37];
                tmp42[38] = s_statusServiceThread_send_http_ti_0009677c[38];
                tmp42[39] = s_statusServiceThread_send_http_ti_0009677c[39];
                tmp42[40] = s_statusServiceThread_send_http_ti_0009677c[40];
                tmp42[41] = s_statusServiceThread_send_http_ti_0009677c[41];
                tmp42[42] = s_statusServiceThread_send_http_ti_0009677c[42];
                tmp42[43] = s_statusServiceThread_send_http_ti_0009677c[43];
                tmp42[44] = s_statusServiceThread_send_http_ti_0009677c[44];
                tmp42[45] = s_statusServiceThread_send_http_ti_0009677c[45];
                tmp42[46] = s_statusServiceThread_send_http_ti_0009677c[46];
                tmp42[47] = s_statusServiceThread_send_http_ti_0009677c[47];
                tmp42[48] = s_statusServiceThread_send_http_ti_0009677c[48];
                tmp42[49] = s_statusServiceThread_send_http_ti_0009677c[49];
                tmp42[50] = s_statusServiceThread_send_http_ti_0009677c[50];
                tmp42[51] = s_statusServiceThread_send_http_ti_0009677c[51];
                _applog(7,tmp42,false);
              }
              usleep(100000);
            }
            else {
              if (sVar10 < 1) {
                close((int)param);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  tmp42[0] = s_statusServiceThread_send_http_re_000967b0[0];
                  tmp42[1] = s_statusServiceThread_send_http_re_000967b0[1];
                  tmp42[2] = s_statusServiceThread_send_http_re_000967b0[2];
                  tmp42[3] = s_statusServiceThread_send_http_re_000967b0[3];
                  tmp42[4] = s_statusServiceThread_send_http_re_000967b0[4];
                  tmp42[5] = s_statusServiceThread_send_http_re_000967b0[5];
                  tmp42[6] = s_statusServiceThread_send_http_re_000967b0[6];
                  tmp42[7] = s_statusServiceThread_send_http_re_000967b0[7];
                  tmp42[8] = s_statusServiceThread_send_http_re_000967b0[8];
                  tmp42[9] = s_statusServiceThread_send_http_re_000967b0[9];
                  tmp42[10] = s_statusServiceThread_send_http_re_000967b0[10];
                  tmp42[11] = s_statusServiceThread_send_http_re_000967b0[11];
                  tmp42[12] = s_statusServiceThread_send_http_re_000967b0[12];
                  tmp42[13] = s_statusServiceThread_send_http_re_000967b0[13];
                  tmp42[14] = s_statusServiceThread_send_http_re_000967b0[14];
                  tmp42[15] = s_statusServiceThread_send_http_re_000967b0[15];
                  tmp42[16] = s_statusServiceThread_send_http_re_000967b0[16];
                  tmp42[17] = s_statusServiceThread_send_http_re_000967b0[17];
                  tmp42[18] = s_statusServiceThread_send_http_re_000967b0[18];
                  tmp42[19] = s_statusServiceThread_send_http_re_000967b0[19];
                  tmp42[20] = s_statusServiceThread_send_http_re_000967b0[20];
                  tmp42[21] = s_statusServiceThread_send_http_re_000967b0[21];
                  tmp42[22] = s_statusServiceThread_send_http_re_000967b0[22];
                  tmp42[23] = s_statusServiceThread_send_http_re_000967b0[23];
                  tmp42[24] = s_statusServiceThread_send_http_re_000967b0[24];
                  tmp42[25] = s_statusServiceThread_send_http_re_000967b0[25];
                  tmp42[26] = s_statusServiceThread_send_http_re_000967b0[26];
                  tmp42[27] = s_statusServiceThread_send_http_re_000967b0[27];
                  tmp42[28] = s_statusServiceThread_send_http_re_000967b0[28];
                  tmp42[29] = s_statusServiceThread_send_http_re_000967b0[29];
                  tmp42[30] = s_statusServiceThread_send_http_re_000967b0[30];
                  tmp42[31] = s_statusServiceThread_send_http_re_000967b0[31];
                  tmp42[32] = s_statusServiceThread_send_http_re_000967b0[32];
                  tmp42[33] = s_statusServiceThread_send_http_re_000967b0[33];
                  tmp42[34] = s_statusServiceThread_send_http_re_000967b0[34];
                  tmp42[35] = s_statusServiceThread_send_http_re_000967b0[35];
                  tmp42[36] = s_statusServiceThread_send_http_re_000967b0[36];
                  tmp42[37] = s_statusServiceThread_send_http_re_000967b0[37];
                  tmp42[38] = s_statusServiceThread_send_http_re_000967b0[38];
                  tmp42[39] = s_statusServiceThread_send_http_re_000967b0[39];
                  tmp42[40] = s_statusServiceThread_send_http_re_000967b0[40];
                  tmp42[41] = s_statusServiceThread_send_http_re_000967b0[41];
                  tmp42[42] = s_statusServiceThread_send_http_re_000967b0[42];
                  tmp42[43] = s_statusServiceThread_send_http_re_000967b0[43];
                  tmp42[44] = (char)ram0x000967dc;
                  _applog(7,tmp42,false);
                }
                return (void *)0x0;
              }
              sentlen = sVar10 + sentlen;
            }
            sVar8 = strlen(strSendbuf);
          } while (((uint)sentlen < sVar8) && (ExitServer != true));
          sVar8 = strlen(strSendbuf);
          if ((sVar8 <= (uint)sentlen) || (ExitServer != false)) break;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_send_http_data____000967e0[0];
          tmp42[1] = s_send_http_data____000967e0[1];
          tmp42[2] = s_send_http_data____000967e0[2];
          tmp42[3] = s_send_http_data____000967e0[3];
          tmp42[4] = s_send_http_data____000967e0[4];
          tmp42[5] = s_send_http_data____000967e0[5];
          tmp42[6] = s_send_http_data____000967e0[6];
          tmp42[7] = s_send_http_data____000967e0[7];
          tmp42[8] = s_send_http_data____000967e0[8];
          tmp42[9] = s_send_http_data____000967e0[9];
          tmp42[10] = s_send_http_data____000967e0[10];
          tmp42[11] = s_send_http_data____000967e0[11];
          tmp42[12] = s_send_http_data____000967e0[12];
          tmp42[13] = s_send_http_data____000967e0[13];
          tmp42[14] = s_send_http_data____000967e0[14];
          tmp42[15] = s_send_http_data____000967e0[15];
          tmp42[16] = (char)(short)ram0x000967f0;
          tmp42[17] = (char)((ushort)(short)ram0x000967f0 >> 8);
          _applog(7,tmp42,false);
        }
        sentlen = 0;
        while( true ) {
          sVar10 = send((int)param,buf + sentlen,sVar5 - sentlen,0);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"send http data ret=%d",sVar10);
            _applog(7,tmp42,false);
          }
          if (sVar10 < 1) break;
          sentlen = sVar10 + sentlen;
          if (((int)sVar5 <= sentlen) || (ExitServer == true)) goto LAB_00074a56;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_statusServiceThread_send_http_da_0009680c[0];
          tmp42[1] = s_statusServiceThread_send_http_da_0009680c[1];
          tmp42[2] = s_statusServiceThread_send_http_da_0009680c[2];
          tmp42[3] = s_statusServiceThread_send_http_da_0009680c[3];
          tmp42[4] = s_statusServiceThread_send_http_da_0009680c[4];
          tmp42[5] = s_statusServiceThread_send_http_da_0009680c[5];
          tmp42[6] = s_statusServiceThread_send_http_da_0009680c[6];
          tmp42[7] = s_statusServiceThread_send_http_da_0009680c[7];
          tmp42[8] = s_statusServiceThread_send_http_da_0009680c[8];
          tmp42[9] = s_statusServiceThread_send_http_da_0009680c[9];
          tmp42[10] = s_statusServiceThread_send_http_da_0009680c[10];
          tmp42[11] = s_statusServiceThread_send_http_da_0009680c[11];
          tmp42[12] = s_statusServiceThread_send_http_da_0009680c[12];
          tmp42[13] = s_statusServiceThread_send_http_da_0009680c[13];
          tmp42[14] = s_statusServiceThread_send_http_da_0009680c[14];
          tmp42[15] = s_statusServiceThread_send_http_da_0009680c[15];
          tmp42[16] = s_statusServiceThread_send_http_da_0009680c[16];
          tmp42[17] = s_statusServiceThread_send_http_da_0009680c[17];
          tmp42[18] = s_statusServiceThread_send_http_da_0009680c[18];
          tmp42[19] = s_statusServiceThread_send_http_da_0009680c[19];
          tmp42[20] = s_statusServiceThread_send_http_da_0009680c[20];
          tmp42[21] = s_statusServiceThread_send_http_da_0009680c[21];
          tmp42[22] = s_statusServiceThread_send_http_da_0009680c[22];
          tmp42[23] = s_statusServiceThread_send_http_da_0009680c[23];
          tmp42[24] = s_statusServiceThread_send_http_da_0009680c[24];
          tmp42[25] = s_statusServiceThread_send_http_da_0009680c[25];
          tmp42[26] = s_statusServiceThread_send_http_da_0009680c[26];
          tmp42[27] = s_statusServiceThread_send_http_da_0009680c[27];
          tmp42[28] = s_statusServiceThread_send_http_da_0009680c[28];
          tmp42[29] = s_statusServiceThread_send_http_da_0009680c[29];
          tmp42[30] = s_statusServiceThread_send_http_da_0009680c[30];
          tmp42[31] = s_statusServiceThread_send_http_da_0009680c[31];
          tmp42[32] = s_statusServiceThread_send_http_da_0009680c[32];
          tmp42[33] = s_statusServiceThread_send_http_da_0009680c[33];
          tmp42[34] = s_statusServiceThread_send_http_da_0009680c[34];
          tmp42[35] = s_statusServiceThread_send_http_da_0009680c[35];
          tmp42[36] = s_statusServiceThread_send_http_da_0009680c[36];
          tmp42[37] = s_statusServiceThread_send_http_da_0009680c[37];
          tmp42[38] = s_statusServiceThread_send_http_da_0009680c[38];
          tmp42[39] = s_statusServiceThread_send_http_da_0009680c[39];
          tmp42[40] = (char)ram0x00096834;
          _applog(7,tmp42,false);
        }
LAB_00074a56:
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_one_client_disconnected__00096838[0];
          tmp42[1] = s_one_client_disconnected__00096838[1];
          tmp42[2] = s_one_client_disconnected__00096838[2];
          tmp42[3] = s_one_client_disconnected__00096838[3];
          tmp42[4] = s_one_client_disconnected__00096838[4];
          tmp42[5] = s_one_client_disconnected__00096838[5];
          tmp42[6] = s_one_client_disconnected__00096838[6];
          tmp42[7] = s_one_client_disconnected__00096838[7];
          tmp42[8] = s_one_client_disconnected__00096838[8];
          tmp42[9] = s_one_client_disconnected__00096838[9];
          tmp42[10] = s_one_client_disconnected__00096838[10];
          tmp42[11] = s_one_client_disconnected__00096838[11];
          tmp42[12] = s_one_client_disconnected__00096838[12];
          tmp42[13] = s_one_client_disconnected__00096838[13];
          tmp42[14] = s_one_client_disconnected__00096838[14];
          tmp42[15] = s_one_client_disconnected__00096838[15];
          tmp42[16] = s_one_client_disconnected__00096838[16];
          tmp42[17] = s_one_client_disconnected__00096838[17];
          tmp42[18] = s_one_client_disconnected__00096838[18];
          tmp42[19] = s_one_client_disconnected__00096838[19];
          tmp42[20] = s_one_client_disconnected__00096838[20];
          tmp42[21] = s_one_client_disconnected__00096838[21];
          tmp42[22] = s_one_client_disconnected__00096838[22];
          tmp42[23] = s_one_client_disconnected__00096838[23];
          tmp42[24] = (char)ram0x00096850;
          _applog(7,tmp42,false);
        }
        close((int)param);
      }
      else {
        close((int)param);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_setsockopt_SO_RCVTIMEO_failed_00096520[0];
          tmp42[1] = s_setsockopt_SO_RCVTIMEO_failed_00096520[1];
          tmp42[2] = s_setsockopt_SO_RCVTIMEO_failed_00096520[2];
          tmp42[3] = s_setsockopt_SO_RCVTIMEO_failed_00096520[3];
          tmp42[4] = s_setsockopt_SO_RCVTIMEO_failed_00096520[4];
          tmp42[5] = s_setsockopt_SO_RCVTIMEO_failed_00096520[5];
          tmp42[6] = s_setsockopt_SO_RCVTIMEO_failed_00096520[6];
          tmp42[7] = s_setsockopt_SO_RCVTIMEO_failed_00096520[7];
          tmp42[8] = s_setsockopt_SO_RCVTIMEO_failed_00096520[8];
          tmp42[9] = s_setsockopt_SO_RCVTIMEO_failed_00096520[9];
          tmp42[10] = s_setsockopt_SO_RCVTIMEO_failed_00096520[10];
          tmp42[11] = s_setsockopt_SO_RCVTIMEO_failed_00096520[11];
          tmp42[12] = s_setsockopt_SO_RCVTIMEO_failed_00096520[12];
          tmp42[13] = s_setsockopt_SO_RCVTIMEO_failed_00096520[13];
          tmp42[14] = s_setsockopt_SO_RCVTIMEO_failed_00096520[14];
          tmp42[15] = s_setsockopt_SO_RCVTIMEO_failed_00096520[15];
          tmp42[16] = s_setsockopt_SO_RCVTIMEO_failed_00096520[16];
          tmp42[17] = s_setsockopt_SO_RCVTIMEO_failed_00096520[17];
          tmp42[18] = s_setsockopt_SO_RCVTIMEO_failed_00096520[18];
          tmp42[19] = s_setsockopt_SO_RCVTIMEO_failed_00096520[19];
          tmp42[20] = s_setsockopt_SO_RCVTIMEO_failed_00096520[20];
          tmp42[21] = s_setsockopt_SO_RCVTIMEO_failed_00096520[21];
          tmp42[22] = s_setsockopt_SO_RCVTIMEO_failed_00096520[22];
          tmp42[23] = s_setsockopt_SO_RCVTIMEO_failed_00096520[23];
          tmp42[24] = s_setsockopt_SO_RCVTIMEO_failed_00096520[24];
          tmp42[25] = s_setsockopt_SO_RCVTIMEO_failed_00096520[25];
          tmp42[26] = s_setsockopt_SO_RCVTIMEO_failed_00096520[26];
          tmp42[27] = s_setsockopt_SO_RCVTIMEO_failed_00096520[27];
          tmp42[28] = (char)(short)ram0x0009653c;
          tmp42[29] = (char)((ushort)(short)ram0x0009653c >> 8);
          _applog(7,tmp42,false);
        }
        sentlen = 0;
      }
    }
    else {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_setsockopt_SO_SNDTIMEO_failed_00096500[0];
        tmp42[1] = s_setsockopt_SO_SNDTIMEO_failed_00096500[1];
        tmp42[2] = s_setsockopt_SO_SNDTIMEO_failed_00096500[2];
        tmp42[3] = s_setsockopt_SO_SNDTIMEO_failed_00096500[3];
        tmp42[4] = s_setsockopt_SO_SNDTIMEO_failed_00096500[4];
        tmp42[5] = s_setsockopt_SO_SNDTIMEO_failed_00096500[5];
        tmp42[6] = s_setsockopt_SO_SNDTIMEO_failed_00096500[6];
        tmp42[7] = s_setsockopt_SO_SNDTIMEO_failed_00096500[7];
        tmp42[8] = s_setsockopt_SO_SNDTIMEO_failed_00096500[8];
        tmp42[9] = s_setsockopt_SO_SNDTIMEO_failed_00096500[9];
        tmp42[10] = s_setsockopt_SO_SNDTIMEO_failed_00096500[10];
        tmp42[11] = s_setsockopt_SO_SNDTIMEO_failed_00096500[11];
        tmp42[12] = s_setsockopt_SO_SNDTIMEO_failed_00096500[12];
        tmp42[13] = s_setsockopt_SO_SNDTIMEO_failed_00096500[13];
        tmp42[14] = s_setsockopt_SO_SNDTIMEO_failed_00096500[14];
        tmp42[15] = s_setsockopt_SO_SNDTIMEO_failed_00096500[15];
        tmp42[16] = s_setsockopt_SO_SNDTIMEO_failed_00096500[16];
        tmp42[17] = s_setsockopt_SO_SNDTIMEO_failed_00096500[17];
        tmp42[18] = s_setsockopt_SO_SNDTIMEO_failed_00096500[18];
        tmp42[19] = s_setsockopt_SO_SNDTIMEO_failed_00096500[19];
        tmp42[20] = s_setsockopt_SO_SNDTIMEO_failed_00096500[20];
        tmp42[21] = s_setsockopt_SO_SNDTIMEO_failed_00096500[21];
        tmp42[22] = s_setsockopt_SO_SNDTIMEO_failed_00096500[22];
        tmp42[23] = s_setsockopt_SO_SNDTIMEO_failed_00096500[23];
        tmp42[24] = s_setsockopt_SO_SNDTIMEO_failed_00096500[24];
        tmp42[25] = s_setsockopt_SO_SNDTIMEO_failed_00096500[25];
        tmp42[26] = s_setsockopt_SO_SNDTIMEO_failed_00096500[26];
        tmp42[27] = s_setsockopt_SO_SNDTIMEO_failed_00096500[27];
        tmp42[28] = (char)(short)ram0x0009651c;
        tmp42[29] = (char)((ushort)(short)ram0x0009651c >> 8);
        _applog(7,tmp42,false);
      }
      sentlen = 0;
    }
  }
  else {
    close((int)param);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_statusServiceThread_not_support_h_00096424[0];
      tmp42[1] = s_statusServiceThread_not_support_h_00096424[1];
      tmp42[2] = s_statusServiceThread_not_support_h_00096424[2];
      tmp42[3] = s_statusServiceThread_not_support_h_00096424[3];
      tmp42[4] = s_statusServiceThread_not_support_h_00096424[4];
      tmp42[5] = s_statusServiceThread_not_support_h_00096424[5];
      tmp42[6] = s_statusServiceThread_not_support_h_00096424[6];
      tmp42[7] = s_statusServiceThread_not_support_h_00096424[7];
      tmp42[8] = s_statusServiceThread_not_support_h_00096424[8];
      tmp42[9] = s_statusServiceThread_not_support_h_00096424[9];
      tmp42[10] = s_statusServiceThread_not_support_h_00096424[10];
      tmp42[11] = s_statusServiceThread_not_support_h_00096424[11];
      tmp42[12] = s_statusServiceThread_not_support_h_00096424[12];
      tmp42[13] = s_statusServiceThread_not_support_h_00096424[13];
      tmp42[14] = s_statusServiceThread_not_support_h_00096424[14];
      tmp42[15] = s_statusServiceThread_not_support_h_00096424[15];
      tmp42[16] = s_statusServiceThread_not_support_h_00096424[16];
      tmp42[17] = s_statusServiceThread_not_support_h_00096424[17];
      tmp42[18] = s_statusServiceThread_not_support_h_00096424[18];
      tmp42[19] = s_statusServiceThread_not_support_h_00096424[19];
      tmp42[20] = s_statusServiceThread_not_support_h_00096424[20];
      tmp42[21] = s_statusServiceThread_not_support_h_00096424[21];
      tmp42[22] = s_statusServiceThread_not_support_h_00096424[22];
      tmp42[23] = s_statusServiceThread_not_support_h_00096424[23];
      tmp42[24] = s_statusServiceThread_not_support_h_00096424[24];
      tmp42[25] = s_statusServiceThread_not_support_h_00096424[25];
      tmp42[26] = s_statusServiceThread_not_support_h_00096424[26];
      tmp42[27] = s_statusServiceThread_not_support_h_00096424[27];
      tmp42[28] = s_statusServiceThread_not_support_h_00096424[28];
      tmp42[29] = s_statusServiceThread_not_support_h_00096424[29];
      tmp42[30] = s_statusServiceThread_not_support_h_00096424[30];
      tmp42[31] = s_statusServiceThread_not_support_h_00096424[31];
      tmp42[32] = s_statusServiceThread_not_support_h_00096424[32];
      tmp42[33] = s_statusServiceThread_not_support_h_00096424[33];
      tmp42[34] = s_statusServiceThread_not_support_h_00096424[34];
      tmp42[35] = s_statusServiceThread_not_support_h_00096424[35];
      tmp42[36] = s_statusServiceThread_not_support_h_00096424[36];
      tmp42[37] = s_statusServiceThread_not_support_h_00096424[37];
      tmp42[38] = s_statusServiceThread_not_support_h_00096424[38];
      tmp42[39] = s_statusServiceThread_not_support_h_00096424[39];
      tmp42[40] = s_statusServiceThread_not_support_h_00096424[40];
      tmp42[41] = s_statusServiceThread_not_support_h_00096424[41];
      tmp42[42] = s_statusServiceThread_not_support_h_00096424[42];
      tmp42[43] = s_statusServiceThread_not_support_h_00096424[43];
      tmp42[44] = (char)ram0x00096450;
      _applog(7,tmp42,false);
    }
    sentlen = 0;
  }
  return (void *)sentlen;
}

