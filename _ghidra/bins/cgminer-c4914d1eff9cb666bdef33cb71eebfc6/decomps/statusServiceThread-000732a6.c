
void * statusServiceThread(void *param)

{
  undefined4 uVar1;
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
  builtin_strncpy(endofrequest,"\r\n\r\n",5);
  memset(recvbuf,0,0x2800);
  do {
    if (ExitServer == true) goto LAB_00073612;
    buflen = recvfrom((int)param,precvbuf,0x27ff - buflen,0,(sockaddr *)&from,(socklen_t *)&recvlen)
    ;
    if (buflen < 1) {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,":statusServiceThread recvfrom<=0",0x20);
        tmp42._32_4_ = tmp42._32_4_ & 0xffffff00;
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    if (buflen == 0x27ff) {
      close((int)param);
      uVar1 = tmp42._20_4_;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"BUFSIZE is too small!",0x16);
        tmp42._22_2_ = SUB42(uVar1,2);
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    precvbuf = recvbuf + buflen;
    pcVar3 = strstr(recvbuf,endofrequest);
  } while (pcVar3 == (char *)0x0);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"find http request end flag!",0x1c);
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
              builtin_strncpy(tmp42,"statusServiceThread exit for Error cmd!",0x28);
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
            builtin_strncpy(tmp42,"cmd : get max ra",0x10);
            tmp42[0x10] = 't';
            tmp42[0x11] = 'e';
            tmp42[0x12] = '\0';
            _applog(7,tmp42,false);
          }
          res_mode = 3;
        }
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"cmd : get ideal rate",0x14);
          tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
          _applog(7,tmp42,false);
        }
        res_mode = 2;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"cmd : get ra",0xc);
        tmp42[0xc] = 't';
        tmp42[0xd] = 'e';
        tmp42[0xe] = '\0';
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
              builtin_memcpy(buf,"current working voltage=",0x18);
              buf[0x18] = ' ';
              buf[0x19] = '\0';
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
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
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
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
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
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
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
        uVar1 = tmp42._20_4_;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"send http response...\n",0x17);
          tmp42[0x17] = SUB41(uVar1,3);
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
                builtin_strncpy(tmp42,"statusServiceThread send http timeout, try again...",0x34);
                _applog(7,tmp42,false);
              }
              usleep(100000);
            }
            else {
              if (sVar10 < 1) {
                close((int)param);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  builtin_strncpy(tmp42,"statusServiceThread send http response error",0x2c);
                  tmp42._44_4_ = tmp42._44_4_ & 0xffffff00;
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
          builtin_strncpy(tmp42,"send http data..",0x10);
          tmp42[0x10] = '.';
          tmp42[0x11] = '\0';
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
          builtin_strncpy(tmp42,"statusServiceThread send http data error",0x28);
          tmp42._40_4_ = tmp42._40_4_ & 0xffffff00;
          _applog(7,tmp42,false);
        }
LAB_00074a56:
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"one client disconnected!",0x18);
          tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
          _applog(7,tmp42,false);
        }
        close((int)param);
      }
      else {
        close((int)param);
        uVar1 = tmp42._28_4_;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"setsockopt SO_RCVTIMEO failed",0x1e);
          tmp42._30_2_ = SUB42(uVar1,2);
          _applog(7,tmp42,false);
        }
        sentlen = 0;
      }
    }
    else {
      close((int)param);
      uVar1 = tmp42._28_4_;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"setsockopt SO_SNDTIMEO failed",0x1e);
        tmp42._30_2_ = SUB42(uVar1,2);
        _applog(7,tmp42,false);
      }
      sentlen = 0;
    }
  }
  else {
    close((int)param);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"statusServiceThread not support http command",0x2c);
      tmp42._44_4_ = tmp42._44_4_ & 0xffffff00;
      _applog(7,tmp42,false);
    }
    sentlen = 0;
  }
  return (void *)sentlen;
}

