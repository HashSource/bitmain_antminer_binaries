
void * statusServiceThread(void *param)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  int *piVar8;
  ssize_t sVar9;
  void *param_local;
  char tmp42 [2048];
  char endofrequest [5];
  int test_value;
  int testID;
  char sendbuf [3];
  int recvlen;
  char strSendbuf [10240];
  uchar buf [4096];
  sockaddr_in from;
  char recvbuf [10240];
  timeval timeout;
  int bError;
  int len;
  int ret;
  int s1;
  int res_mode;
  int sentlen;
  int buflen;
  char *precvbuf;
  
  timeout.tv_sec = 3;
  timeout.tv_usec = 0;
  memset(recvbuf,0,0x2800);
  precvbuf = recvbuf;
  buflen = 0;
  recvlen = 0;
  sendbuf[2] = '\0';
  testID = -1;
  test_value = -1;
  sendbuf[0] = '\r';
  sendbuf[1] = '\n';
  builtin_strncpy(endofrequest,"\r\n\r\n",5);
  memset(recvbuf,0,0x2800);
  do {
    if (ExitServer == true) goto LAB_0007982c;
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
    pcVar2 = strstr(recvbuf,endofrequest);
  } while (pcVar2 == (char *)0x0);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"find http request end flag!",0x1c);
    _applog(7,tmp42,false);
  }
LAB_0007982c:
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"get http=%s",recvbuf);
    _applog(7,tmp42,false);
  }
  if (((recvbuf[0] == 'G') && (recvbuf[1] == 'E')) && ((recvbuf[2] == 'T' && (recvbuf[3] == ' '))))
  {
    pcVar2 = strstr(recvbuf + 4,"/rate");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(recvbuf + 4,"/test");
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr(recvbuf + 4,"/ideal_rate");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr(recvbuf + 4,"/max_rate");
          if (pcVar2 == (char *)0x0) {
            close((int)param);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              builtin_strncpy(tmp42,"statusServiceThread exit for Error cmd!",0x28);
              _applog(7,tmp42,false);
            }
            return (void *)0x0;
          }
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
        __isoc99_sscanf(recvbuf + 4,"/test.%d.%d",&testID,&test_value);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"cmd : get test = %d",testID);
          _applog(7,tmp42,false);
        }
        res_mode = 1;
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
    iVar3 = setsockopt((int)param,1,0x15,&timeout,8);
    if (iVar3 == 0) {
      iVar3 = setsockopt((int)param,1,0x14,&timeout,8);
      if (iVar3 == 0) {
        if (res_mode == 1) {
          if (testID == 0x20b) {
            get_miner_info((char *)buf);
          }
          else {
            sprintf((char *)buf,"OK get test=%d",testID);
          }
        }
        if (res_mode == 0) {
          if (freq_scan_status == 1) {
            iVar3 = get_ideal_hash_rate_fixed();
            iVar3 = convirt_total_rate(iVar3);
            sprintf((char *)buf,"%d",iVar3);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searching",10);
          }
        }
        if (res_mode == 2) {
          if (freq_scan_status == 1) {
            iVar3 = get_ideal_hash_rate();
            iVar3 = convirt_total_rate(iVar3);
            sprintf((char *)buf,"%d",iVar3);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searching",10);
          }
        }
        if (res_mode == 3) {
          if (freq_scan_status == 1) {
            iVar3 = get_ideal_hash_rate_max();
            iVar3 = convirt_total_rate(iVar3);
            sprintf((char *)buf,"%d",iVar3);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else if (freq_scan_status == 0) {
            builtin_memcpy(buf,"searchin",8);
            buf[8] = 'g';
            buf[9] = '\0';
          }
          else {
            builtin_memcpy(buf,"searching",10);
          }
        }
        sVar4 = strlen((char *)buf);
        iVar3 = sprintf(strSendbuf,"HTTP/1.0  200  OK%s",sendbuf);
        iVar5 = sprintf(strSendbuf + iVar3,"Server: SearchFreqServer%s",sendbuf);
        iVar6 = sprintf(strSendbuf + iVar3 + iVar5,"Cache-Control: no-cache%s",sendbuf);
        iVar6 = iVar3 + iVar5 + iVar6;
        iVar3 = sprintf(strSendbuf + iVar6,"Pragma: no-cache%s",sendbuf);
        iVar6 = iVar6 + iVar3;
        iVar3 = sprintf(strSendbuf + iVar6,"Content-Type: text/plain%s",sendbuf);
        iVar6 = iVar6 + iVar3;
        iVar3 = sprintf(strSendbuf + iVar6,"Content-Length: %d%s",sVar4,sendbuf);
        sprintf(strSendbuf + iVar6 + iVar3,"Connection: Keep-Alive%s",endofrequest);
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
            sVar7 = strlen(strSendbuf);
            sVar9 = send((int)param,strSendbuf + sentlen,sVar7 - sentlen,0);
            if ((sVar9 == -1) && (piVar8 = __errno_location(), *piVar8 == 0xb)) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                builtin_strncpy(tmp42,"statusServiceThread send http timeout, try again...",0x34);
                _applog(7,tmp42,false);
              }
              usleep(100000);
            }
            else {
              if (sVar9 < 1) {
                close((int)param);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  builtin_strncpy(tmp42,"statusServiceThread send http response error",0x2c);
                  tmp42._44_4_ = tmp42._44_4_ & 0xffffff00;
                  _applog(7,tmp42,false);
                }
                return (void *)0x0;
              }
              sentlen = sentlen + sVar9;
            }
            sVar7 = strlen(strSendbuf);
          } while (((uint)sentlen < sVar7) && (ExitServer != true));
          sVar7 = strlen(strSendbuf);
          if ((sVar7 <= (uint)sentlen) || (ExitServer != false)) break;
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
          sVar9 = send((int)param,buf + sentlen,sVar4 - sentlen,0);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"send http data ret=%d",sVar9);
            _applog(7,tmp42,false);
          }
          if (sVar9 < 1) break;
          sentlen = sentlen + sVar9;
          if (((int)sVar4 <= sentlen) || (ExitServer == true)) goto LAB_0007aa30;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"statusServiceThread send http data error",0x28);
          tmp42._40_4_ = tmp42._40_4_ & 0xffffff00;
          _applog(7,tmp42,false);
        }
LAB_0007aa30:
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

