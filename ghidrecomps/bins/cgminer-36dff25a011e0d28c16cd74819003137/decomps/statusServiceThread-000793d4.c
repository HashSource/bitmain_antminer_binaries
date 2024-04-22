
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * statusServiceThread(void *param)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int *piVar7;
  ssize_t sVar8;
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
  endofrequest[4] = '\0';
  endofrequest[0] = '\r';
  endofrequest[1] = '\n';
  endofrequest[2] = '\r';
  endofrequest[3] = '\n';
  memset(recvbuf,0,0x2800);
  do {
    if (ExitServer == true) goto LAB_0007982c;
    buflen = recvfrom((int)param,precvbuf,0x27ff - buflen,0,(sockaddr *)&from,(socklen_t *)&recvlen)
    ;
    if (buflen < 1) {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s__statusServiceThread_recvfrom<_0_000acbe4[0];
        tmp42[1] = s__statusServiceThread_recvfrom<_0_000acbe4[1];
        tmp42[2] = s__statusServiceThread_recvfrom<_0_000acbe4[2];
        tmp42[3] = s__statusServiceThread_recvfrom<_0_000acbe4[3];
        tmp42[4] = s__statusServiceThread_recvfrom<_0_000acbe4[4];
        tmp42[5] = s__statusServiceThread_recvfrom<_0_000acbe4[5];
        tmp42[6] = s__statusServiceThread_recvfrom<_0_000acbe4[6];
        tmp42[7] = s__statusServiceThread_recvfrom<_0_000acbe4[7];
        tmp42[8] = s__statusServiceThread_recvfrom<_0_000acbe4[8];
        tmp42[9] = s__statusServiceThread_recvfrom<_0_000acbe4[9];
        tmp42[10] = s__statusServiceThread_recvfrom<_0_000acbe4[10];
        tmp42[11] = s__statusServiceThread_recvfrom<_0_000acbe4[11];
        tmp42[12] = s__statusServiceThread_recvfrom<_0_000acbe4[12];
        tmp42[13] = s__statusServiceThread_recvfrom<_0_000acbe4[13];
        tmp42[14] = s__statusServiceThread_recvfrom<_0_000acbe4[14];
        tmp42[15] = s__statusServiceThread_recvfrom<_0_000acbe4[15];
        tmp42[16] = s__statusServiceThread_recvfrom<_0_000acbe4[16];
        tmp42[17] = s__statusServiceThread_recvfrom<_0_000acbe4[17];
        tmp42[18] = s__statusServiceThread_recvfrom<_0_000acbe4[18];
        tmp42[19] = s__statusServiceThread_recvfrom<_0_000acbe4[19];
        tmp42[20] = s__statusServiceThread_recvfrom<_0_000acbe4[20];
        tmp42[21] = s__statusServiceThread_recvfrom<_0_000acbe4[21];
        tmp42[22] = s__statusServiceThread_recvfrom<_0_000acbe4[22];
        tmp42[23] = s__statusServiceThread_recvfrom<_0_000acbe4[23];
        tmp42[24] = s__statusServiceThread_recvfrom<_0_000acbe4[24];
        tmp42[25] = s__statusServiceThread_recvfrom<_0_000acbe4[25];
        tmp42[26] = s__statusServiceThread_recvfrom<_0_000acbe4[26];
        tmp42[27] = s__statusServiceThread_recvfrom<_0_000acbe4[27];
        tmp42[28] = s__statusServiceThread_recvfrom<_0_000acbe4[28];
        tmp42[29] = s__statusServiceThread_recvfrom<_0_000acbe4[29];
        tmp42[30] = s__statusServiceThread_recvfrom<_0_000acbe4[30];
        tmp42[31] = s__statusServiceThread_recvfrom<_0_000acbe4[31];
        tmp42[32] = (char)ram0x000acc04;
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    if (buflen == 0x27ff) {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_BUFSIZE_is_too_small__000acc08[0];
        tmp42[1] = s_BUFSIZE_is_too_small__000acc08[1];
        tmp42[2] = s_BUFSIZE_is_too_small__000acc08[2];
        tmp42[3] = s_BUFSIZE_is_too_small__000acc08[3];
        tmp42[4] = s_BUFSIZE_is_too_small__000acc08[4];
        tmp42[5] = s_BUFSIZE_is_too_small__000acc08[5];
        tmp42[6] = s_BUFSIZE_is_too_small__000acc08[6];
        tmp42[7] = s_BUFSIZE_is_too_small__000acc08[7];
        tmp42[8] = s_BUFSIZE_is_too_small__000acc08[8];
        tmp42[9] = s_BUFSIZE_is_too_small__000acc08[9];
        tmp42[10] = s_BUFSIZE_is_too_small__000acc08[10];
        tmp42[11] = s_BUFSIZE_is_too_small__000acc08[11];
        tmp42[12] = s_BUFSIZE_is_too_small__000acc08[12];
        tmp42[13] = s_BUFSIZE_is_too_small__000acc08[13];
        tmp42[14] = s_BUFSIZE_is_too_small__000acc08[14];
        tmp42[15] = s_BUFSIZE_is_too_small__000acc08[15];
        tmp42[16] = s_BUFSIZE_is_too_small__000acc08[16];
        tmp42[17] = s_BUFSIZE_is_too_small__000acc08[17];
        tmp42[18] = s_BUFSIZE_is_too_small__000acc08[18];
        tmp42[19] = s_BUFSIZE_is_too_small__000acc08[19];
        tmp42[20] = (char)(short)ram0x000acc1c;
        tmp42[21] = (char)((ushort)(short)ram0x000acc1c >> 8);
        _applog(7,tmp42,false);
      }
      return (void *)0x0;
    }
    precvbuf = recvbuf + buflen;
    pcVar1 = strstr(recvbuf,endofrequest);
  } while (pcVar1 == (char *)0x0);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    tmp42[0] = s_find_http_request_end_flag__000acc20[0];
    tmp42[1] = s_find_http_request_end_flag__000acc20[1];
    tmp42[2] = s_find_http_request_end_flag__000acc20[2];
    tmp42[3] = s_find_http_request_end_flag__000acc20[3];
    tmp42[4] = s_find_http_request_end_flag__000acc20[4];
    tmp42[5] = s_find_http_request_end_flag__000acc20[5];
    tmp42[6] = s_find_http_request_end_flag__000acc20[6];
    tmp42[7] = s_find_http_request_end_flag__000acc20[7];
    tmp42[8] = s_find_http_request_end_flag__000acc20[8];
    tmp42[9] = s_find_http_request_end_flag__000acc20[9];
    tmp42[10] = s_find_http_request_end_flag__000acc20[10];
    tmp42[11] = s_find_http_request_end_flag__000acc20[11];
    tmp42[12] = s_find_http_request_end_flag__000acc20[12];
    tmp42[13] = s_find_http_request_end_flag__000acc20[13];
    tmp42[14] = s_find_http_request_end_flag__000acc20[14];
    tmp42[15] = s_find_http_request_end_flag__000acc20[15];
    tmp42[16] = s_find_http_request_end_flag__000acc20[16];
    tmp42[17] = s_find_http_request_end_flag__000acc20[17];
    tmp42[18] = s_find_http_request_end_flag__000acc20[18];
    tmp42[19] = s_find_http_request_end_flag__000acc20[19];
    tmp42[20] = s_find_http_request_end_flag__000acc20[20];
    tmp42[21] = s_find_http_request_end_flag__000acc20[21];
    tmp42[22] = s_find_http_request_end_flag__000acc20[22];
    tmp42[23] = s_find_http_request_end_flag__000acc20[23];
    tmp42[24] = s_find_http_request_end_flag__000acc20[24];
    tmp42[25] = s_find_http_request_end_flag__000acc20[25];
    tmp42[26] = s_find_http_request_end_flag__000acc20[26];
    tmp42[27] = s_find_http_request_end_flag__000acc20[27];
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
    pcVar1 = strstr(recvbuf + 4,"/rate");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(recvbuf + 4,"/test");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = strstr(recvbuf + 4,"/ideal_rate");
        if (pcVar1 == (char *)0x0) {
          pcVar1 = strstr(recvbuf + 4,"/max_rate");
          if (pcVar1 == (char *)0x0) {
            close((int)param);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42[0] = s_statusServiceThread_exit_for_Err_000accfc[0];
              tmp42[1] = s_statusServiceThread_exit_for_Err_000accfc[1];
              tmp42[2] = s_statusServiceThread_exit_for_Err_000accfc[2];
              tmp42[3] = s_statusServiceThread_exit_for_Err_000accfc[3];
              tmp42[4] = s_statusServiceThread_exit_for_Err_000accfc[4];
              tmp42[5] = s_statusServiceThread_exit_for_Err_000accfc[5];
              tmp42[6] = s_statusServiceThread_exit_for_Err_000accfc[6];
              tmp42[7] = s_statusServiceThread_exit_for_Err_000accfc[7];
              tmp42[8] = s_statusServiceThread_exit_for_Err_000accfc[8];
              tmp42[9] = s_statusServiceThread_exit_for_Err_000accfc[9];
              tmp42[10] = s_statusServiceThread_exit_for_Err_000accfc[10];
              tmp42[11] = s_statusServiceThread_exit_for_Err_000accfc[11];
              tmp42[12] = s_statusServiceThread_exit_for_Err_000accfc[12];
              tmp42[13] = s_statusServiceThread_exit_for_Err_000accfc[13];
              tmp42[14] = s_statusServiceThread_exit_for_Err_000accfc[14];
              tmp42[15] = s_statusServiceThread_exit_for_Err_000accfc[15];
              tmp42[16] = s_statusServiceThread_exit_for_Err_000accfc[16];
              tmp42[17] = s_statusServiceThread_exit_for_Err_000accfc[17];
              tmp42[18] = s_statusServiceThread_exit_for_Err_000accfc[18];
              tmp42[19] = s_statusServiceThread_exit_for_Err_000accfc[19];
              tmp42[20] = s_statusServiceThread_exit_for_Err_000accfc[20];
              tmp42[21] = s_statusServiceThread_exit_for_Err_000accfc[21];
              tmp42[22] = s_statusServiceThread_exit_for_Err_000accfc[22];
              tmp42[23] = s_statusServiceThread_exit_for_Err_000accfc[23];
              tmp42[24] = s_statusServiceThread_exit_for_Err_000accfc[24];
              tmp42[25] = s_statusServiceThread_exit_for_Err_000accfc[25];
              tmp42[26] = s_statusServiceThread_exit_for_Err_000accfc[26];
              tmp42[27] = s_statusServiceThread_exit_for_Err_000accfc[27];
              tmp42[28] = s_statusServiceThread_exit_for_Err_000accfc[28];
              tmp42[29] = s_statusServiceThread_exit_for_Err_000accfc[29];
              tmp42[30] = s_statusServiceThread_exit_for_Err_000accfc[30];
              tmp42[31] = s_statusServiceThread_exit_for_Err_000accfc[31];
              tmp42[32] = s_statusServiceThread_exit_for_Err_000accfc[32];
              tmp42[33] = s_statusServiceThread_exit_for_Err_000accfc[33];
              tmp42[34] = s_statusServiceThread_exit_for_Err_000accfc[34];
              tmp42[35] = s_statusServiceThread_exit_for_Err_000accfc[35];
              tmp42[36] = s_statusServiceThread_exit_for_Err_000accfc[36];
              tmp42[37] = s_statusServiceThread_exit_for_Err_000accfc[37];
              tmp42[38] = s_statusServiceThread_exit_for_Err_000accfc[38];
              tmp42[39] = s_statusServiceThread_exit_for_Err_000accfc[39];
              _applog(7,tmp42,false);
            }
            return (void *)0x0;
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_cmd___get_max_rate_000acce8[0];
            tmp42[1] = s_cmd___get_max_rate_000acce8[1];
            tmp42[2] = s_cmd___get_max_rate_000acce8[2];
            tmp42[3] = s_cmd___get_max_rate_000acce8[3];
            tmp42[4] = s_cmd___get_max_rate_000acce8[4];
            tmp42[5] = s_cmd___get_max_rate_000acce8[5];
            tmp42[6] = s_cmd___get_max_rate_000acce8[6];
            tmp42[7] = s_cmd___get_max_rate_000acce8[7];
            tmp42[8] = s_cmd___get_max_rate_000acce8[8];
            tmp42[9] = s_cmd___get_max_rate_000acce8[9];
            tmp42[10] = s_cmd___get_max_rate_000acce8[10];
            tmp42[11] = s_cmd___get_max_rate_000acce8[11];
            tmp42[12] = s_cmd___get_max_rate_000acce8[12];
            tmp42[13] = s_cmd___get_max_rate_000acce8[13];
            tmp42[14] = s_cmd___get_max_rate_000acce8[14];
            tmp42[15] = s_cmd___get_max_rate_000acce8[15];
            tmp42._16_3_ = (undefined3)ram0x000accf8;
            _applog(7,tmp42,false);
          }
          res_mode = 3;
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_cmd___get_ideal_rate_000accc4[0];
            tmp42[1] = s_cmd___get_ideal_rate_000accc4[1];
            tmp42[2] = s_cmd___get_ideal_rate_000accc4[2];
            tmp42[3] = s_cmd___get_ideal_rate_000accc4[3];
            tmp42[4] = s_cmd___get_ideal_rate_000accc4[4];
            tmp42[5] = s_cmd___get_ideal_rate_000accc4[5];
            tmp42[6] = s_cmd___get_ideal_rate_000accc4[6];
            tmp42[7] = s_cmd___get_ideal_rate_000accc4[7];
            tmp42[8] = s_cmd___get_ideal_rate_000accc4[8];
            tmp42[9] = s_cmd___get_ideal_rate_000accc4[9];
            tmp42[10] = s_cmd___get_ideal_rate_000accc4[10];
            tmp42[11] = s_cmd___get_ideal_rate_000accc4[11];
            tmp42[12] = s_cmd___get_ideal_rate_000accc4[12];
            tmp42[13] = s_cmd___get_ideal_rate_000accc4[13];
            tmp42[14] = s_cmd___get_ideal_rate_000accc4[14];
            tmp42[15] = s_cmd___get_ideal_rate_000accc4[15];
            tmp42[16] = s_cmd___get_ideal_rate_000accc4[16];
            tmp42[17] = s_cmd___get_ideal_rate_000accc4[17];
            tmp42[18] = s_cmd___get_ideal_rate_000accc4[18];
            tmp42[19] = s_cmd___get_ideal_rate_000accc4[19];
            tmp42[20] = (char)ram0x000accd8;
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
        tmp42[0] = s_cmd___get_rate_000acc80[0];
        tmp42[1] = s_cmd___get_rate_000acc80[1];
        tmp42[2] = s_cmd___get_rate_000acc80[2];
        tmp42[3] = s_cmd___get_rate_000acc80[3];
        tmp42[4] = s_cmd___get_rate_000acc80[4];
        tmp42[5] = s_cmd___get_rate_000acc80[5];
        tmp42[6] = s_cmd___get_rate_000acc80[6];
        tmp42[7] = s_cmd___get_rate_000acc80[7];
        tmp42[8] = s_cmd___get_rate_000acc80[8];
        tmp42[9] = s_cmd___get_rate_000acc80[9];
        tmp42[10] = s_cmd___get_rate_000acc80[10];
        tmp42[11] = s_cmd___get_rate_000acc80[11];
        tmp42._12_3_ = (undefined3)ram0x000acc8c;
        _applog(7,tmp42,false);
      }
      res_mode = 0;
    }
    iVar2 = setsockopt((int)param,1,0x15,&timeout,8);
    if (iVar2 == 0) {
      iVar2 = setsockopt((int)param,1,0x14,&timeout,8);
      if (iVar2 == 0) {
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
            iVar2 = get_ideal_hash_rate_fixed();
            iVar2 = convirt_total_rate(iVar2);
            sprintf((char *)buf,"%d",iVar2);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else {
            buf._8_2_ = (undefined2)ram0x000acd7c;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
            else {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
          }
        }
        if (res_mode == 2) {
          if (freq_scan_status == 1) {
            iVar2 = get_ideal_hash_rate();
            iVar2 = convirt_total_rate(iVar2);
            sprintf((char *)buf,"%d",iVar2);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else {
            buf._8_2_ = (undefined2)ram0x000acd7c;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
            else {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
          }
        }
        if (res_mode == 3) {
          if (freq_scan_status == 1) {
            iVar2 = get_ideal_hash_rate_max();
            iVar2 = convirt_total_rate(iVar2);
            sprintf((char *)buf,"%d",iVar2);
          }
          else if (freq_scan_status == 2) {
            sprintf((char *)buf,"searchfailed:%s",search_failed_info);
          }
          else {
            buf._8_2_ = (undefined2)ram0x000acd7c;
            if (freq_scan_status == 0) {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
            else {
              buf[0] = s_searching_000acd74[0];
              buf[1] = s_searching_000acd74[1];
              buf[2] = s_searching_000acd74[2];
              buf[3] = s_searching_000acd74[3];
              buf[4] = s_searching_000acd74[4];
              buf[5] = s_searching_000acd74[5];
              buf[6] = s_searching_000acd74[6];
              buf[7] = s_searching_000acd74[7];
            }
          }
        }
        sVar3 = strlen((char *)buf);
        iVar2 = sprintf(strSendbuf,"HTTP/1.0  200  OK%s",sendbuf);
        iVar4 = sprintf(strSendbuf + iVar2,"Server: SearchFreqServer%s",sendbuf);
        iVar5 = sprintf(strSendbuf + iVar2 + iVar4,"Cache-Control: no-cache%s",sendbuf);
        iVar5 = iVar2 + iVar4 + iVar5;
        iVar2 = sprintf(strSendbuf + iVar5,"Pragma: no-cache%s",sendbuf);
        iVar5 = iVar5 + iVar2;
        iVar2 = sprintf(strSendbuf + iVar5,"Content-Type: text/plain%s",sendbuf);
        iVar5 = iVar5 + iVar2;
        iVar2 = sprintf(strSendbuf + iVar5,"Content-Length: %d%s",sVar3,sendbuf);
        sprintf(strSendbuf + iVar5 + iVar2,"Connection: Keep-Alive%s",endofrequest);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_send_http_response____000ace44[0];
          tmp42[1] = s_send_http_response____000ace44[1];
          tmp42[2] = s_send_http_response____000ace44[2];
          tmp42[3] = s_send_http_response____000ace44[3];
          tmp42[4] = s_send_http_response____000ace44[4];
          tmp42[5] = s_send_http_response____000ace44[5];
          tmp42[6] = s_send_http_response____000ace44[6];
          tmp42[7] = s_send_http_response____000ace44[7];
          tmp42[8] = s_send_http_response____000ace44[8];
          tmp42[9] = s_send_http_response____000ace44[9];
          tmp42[10] = s_send_http_response____000ace44[10];
          tmp42[11] = s_send_http_response____000ace44[11];
          tmp42[12] = s_send_http_response____000ace44[12];
          tmp42[13] = s_send_http_response____000ace44[13];
          tmp42[14] = s_send_http_response____000ace44[14];
          tmp42[15] = s_send_http_response____000ace44[15];
          tmp42[16] = s_send_http_response____000ace44[16];
          tmp42[17] = s_send_http_response____000ace44[17];
          tmp42[18] = s_send_http_response____000ace44[18];
          tmp42[19] = s_send_http_response____000ace44[19];
          tmp42._20_3_ = (undefined3)ram0x000ace58;
          _applog(7,tmp42,false);
        }
        while (ExitServer != true) {
          sentlen = 0;
          do {
            sVar6 = strlen(strSendbuf);
            sVar8 = send((int)param,strSendbuf + sentlen,sVar6 - sentlen,0);
            if ((sVar8 == -1) && (piVar7 = __errno_location(), *piVar7 == 0xb)) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                tmp42[0] = s_statusServiceThread_send_http_ti_000ace5c[0];
                tmp42[1] = s_statusServiceThread_send_http_ti_000ace5c[1];
                tmp42[2] = s_statusServiceThread_send_http_ti_000ace5c[2];
                tmp42[3] = s_statusServiceThread_send_http_ti_000ace5c[3];
                tmp42[4] = s_statusServiceThread_send_http_ti_000ace5c[4];
                tmp42[5] = s_statusServiceThread_send_http_ti_000ace5c[5];
                tmp42[6] = s_statusServiceThread_send_http_ti_000ace5c[6];
                tmp42[7] = s_statusServiceThread_send_http_ti_000ace5c[7];
                tmp42[8] = s_statusServiceThread_send_http_ti_000ace5c[8];
                tmp42[9] = s_statusServiceThread_send_http_ti_000ace5c[9];
                tmp42[10] = s_statusServiceThread_send_http_ti_000ace5c[10];
                tmp42[11] = s_statusServiceThread_send_http_ti_000ace5c[11];
                tmp42[12] = s_statusServiceThread_send_http_ti_000ace5c[12];
                tmp42[13] = s_statusServiceThread_send_http_ti_000ace5c[13];
                tmp42[14] = s_statusServiceThread_send_http_ti_000ace5c[14];
                tmp42[15] = s_statusServiceThread_send_http_ti_000ace5c[15];
                tmp42[16] = s_statusServiceThread_send_http_ti_000ace5c[16];
                tmp42[17] = s_statusServiceThread_send_http_ti_000ace5c[17];
                tmp42[18] = s_statusServiceThread_send_http_ti_000ace5c[18];
                tmp42[19] = s_statusServiceThread_send_http_ti_000ace5c[19];
                tmp42[20] = s_statusServiceThread_send_http_ti_000ace5c[20];
                tmp42[21] = s_statusServiceThread_send_http_ti_000ace5c[21];
                tmp42[22] = s_statusServiceThread_send_http_ti_000ace5c[22];
                tmp42[23] = s_statusServiceThread_send_http_ti_000ace5c[23];
                tmp42[24] = s_statusServiceThread_send_http_ti_000ace5c[24];
                tmp42[25] = s_statusServiceThread_send_http_ti_000ace5c[25];
                tmp42[26] = s_statusServiceThread_send_http_ti_000ace5c[26];
                tmp42[27] = s_statusServiceThread_send_http_ti_000ace5c[27];
                tmp42[28] = s_statusServiceThread_send_http_ti_000ace5c[28];
                tmp42[29] = s_statusServiceThread_send_http_ti_000ace5c[29];
                tmp42[30] = s_statusServiceThread_send_http_ti_000ace5c[30];
                tmp42[31] = s_statusServiceThread_send_http_ti_000ace5c[31];
                tmp42[32] = s_statusServiceThread_send_http_ti_000ace5c[32];
                tmp42[33] = s_statusServiceThread_send_http_ti_000ace5c[33];
                tmp42[34] = s_statusServiceThread_send_http_ti_000ace5c[34];
                tmp42[35] = s_statusServiceThread_send_http_ti_000ace5c[35];
                tmp42[36] = s_statusServiceThread_send_http_ti_000ace5c[36];
                tmp42[37] = s_statusServiceThread_send_http_ti_000ace5c[37];
                tmp42[38] = s_statusServiceThread_send_http_ti_000ace5c[38];
                tmp42[39] = s_statusServiceThread_send_http_ti_000ace5c[39];
                tmp42[40] = s_statusServiceThread_send_http_ti_000ace5c[40];
                tmp42[41] = s_statusServiceThread_send_http_ti_000ace5c[41];
                tmp42[42] = s_statusServiceThread_send_http_ti_000ace5c[42];
                tmp42[43] = s_statusServiceThread_send_http_ti_000ace5c[43];
                tmp42[44] = s_statusServiceThread_send_http_ti_000ace5c[44];
                tmp42[45] = s_statusServiceThread_send_http_ti_000ace5c[45];
                tmp42[46] = s_statusServiceThread_send_http_ti_000ace5c[46];
                tmp42[47] = s_statusServiceThread_send_http_ti_000ace5c[47];
                tmp42[48] = s_statusServiceThread_send_http_ti_000ace5c[48];
                tmp42[49] = s_statusServiceThread_send_http_ti_000ace5c[49];
                tmp42[50] = s_statusServiceThread_send_http_ti_000ace5c[50];
                tmp42[51] = s_statusServiceThread_send_http_ti_000ace5c[51];
                _applog(7,tmp42,false);
              }
              usleep(100000);
            }
            else {
              if (sVar8 < 1) {
                close((int)param);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  tmp42[0] = s_statusServiceThread_send_http_re_000ace90[0];
                  tmp42[1] = s_statusServiceThread_send_http_re_000ace90[1];
                  tmp42[2] = s_statusServiceThread_send_http_re_000ace90[2];
                  tmp42[3] = s_statusServiceThread_send_http_re_000ace90[3];
                  tmp42[4] = s_statusServiceThread_send_http_re_000ace90[4];
                  tmp42[5] = s_statusServiceThread_send_http_re_000ace90[5];
                  tmp42[6] = s_statusServiceThread_send_http_re_000ace90[6];
                  tmp42[7] = s_statusServiceThread_send_http_re_000ace90[7];
                  tmp42[8] = s_statusServiceThread_send_http_re_000ace90[8];
                  tmp42[9] = s_statusServiceThread_send_http_re_000ace90[9];
                  tmp42[10] = s_statusServiceThread_send_http_re_000ace90[10];
                  tmp42[11] = s_statusServiceThread_send_http_re_000ace90[11];
                  tmp42[12] = s_statusServiceThread_send_http_re_000ace90[12];
                  tmp42[13] = s_statusServiceThread_send_http_re_000ace90[13];
                  tmp42[14] = s_statusServiceThread_send_http_re_000ace90[14];
                  tmp42[15] = s_statusServiceThread_send_http_re_000ace90[15];
                  tmp42[16] = s_statusServiceThread_send_http_re_000ace90[16];
                  tmp42[17] = s_statusServiceThread_send_http_re_000ace90[17];
                  tmp42[18] = s_statusServiceThread_send_http_re_000ace90[18];
                  tmp42[19] = s_statusServiceThread_send_http_re_000ace90[19];
                  tmp42[20] = s_statusServiceThread_send_http_re_000ace90[20];
                  tmp42[21] = s_statusServiceThread_send_http_re_000ace90[21];
                  tmp42[22] = s_statusServiceThread_send_http_re_000ace90[22];
                  tmp42[23] = s_statusServiceThread_send_http_re_000ace90[23];
                  tmp42[24] = s_statusServiceThread_send_http_re_000ace90[24];
                  tmp42[25] = s_statusServiceThread_send_http_re_000ace90[25];
                  tmp42[26] = s_statusServiceThread_send_http_re_000ace90[26];
                  tmp42[27] = s_statusServiceThread_send_http_re_000ace90[27];
                  tmp42[28] = s_statusServiceThread_send_http_re_000ace90[28];
                  tmp42[29] = s_statusServiceThread_send_http_re_000ace90[29];
                  tmp42[30] = s_statusServiceThread_send_http_re_000ace90[30];
                  tmp42[31] = s_statusServiceThread_send_http_re_000ace90[31];
                  tmp42[32] = s_statusServiceThread_send_http_re_000ace90[32];
                  tmp42[33] = s_statusServiceThread_send_http_re_000ace90[33];
                  tmp42[34] = s_statusServiceThread_send_http_re_000ace90[34];
                  tmp42[35] = s_statusServiceThread_send_http_re_000ace90[35];
                  tmp42[36] = s_statusServiceThread_send_http_re_000ace90[36];
                  tmp42[37] = s_statusServiceThread_send_http_re_000ace90[37];
                  tmp42[38] = s_statusServiceThread_send_http_re_000ace90[38];
                  tmp42[39] = s_statusServiceThread_send_http_re_000ace90[39];
                  tmp42[40] = s_statusServiceThread_send_http_re_000ace90[40];
                  tmp42[41] = s_statusServiceThread_send_http_re_000ace90[41];
                  tmp42[42] = s_statusServiceThread_send_http_re_000ace90[42];
                  tmp42[43] = s_statusServiceThread_send_http_re_000ace90[43];
                  tmp42[44] = (char)ram0x000acebc;
                  _applog(7,tmp42,false);
                }
                return (void *)0x0;
              }
              sentlen = sentlen + sVar8;
            }
            sVar6 = strlen(strSendbuf);
          } while (((uint)sentlen < sVar6) && (ExitServer != true));
          sVar6 = strlen(strSendbuf);
          if ((sVar6 <= (uint)sentlen) || (ExitServer != false)) break;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_send_http_data____000acec0[0];
          tmp42[1] = s_send_http_data____000acec0[1];
          tmp42[2] = s_send_http_data____000acec0[2];
          tmp42[3] = s_send_http_data____000acec0[3];
          tmp42[4] = s_send_http_data____000acec0[4];
          tmp42[5] = s_send_http_data____000acec0[5];
          tmp42[6] = s_send_http_data____000acec0[6];
          tmp42[7] = s_send_http_data____000acec0[7];
          tmp42[8] = s_send_http_data____000acec0[8];
          tmp42[9] = s_send_http_data____000acec0[9];
          tmp42[10] = s_send_http_data____000acec0[10];
          tmp42[11] = s_send_http_data____000acec0[11];
          tmp42[12] = s_send_http_data____000acec0[12];
          tmp42[13] = s_send_http_data____000acec0[13];
          tmp42[14] = s_send_http_data____000acec0[14];
          tmp42[15] = s_send_http_data____000acec0[15];
          tmp42[16] = (char)(short)ram0x000aced0;
          tmp42[17] = (char)((ushort)(short)ram0x000aced0 >> 8);
          _applog(7,tmp42,false);
        }
        sentlen = 0;
        while( true ) {
          sVar8 = send((int)param,buf + sentlen,sVar3 - sentlen,0);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"send http data ret=%d",sVar8);
            _applog(7,tmp42,false);
          }
          if (sVar8 < 1) break;
          sentlen = sentlen + sVar8;
          if (((int)sVar3 <= sentlen) || (ExitServer == true)) goto LAB_0007aa30;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_statusServiceThread_send_http_da_000aceec[0];
          tmp42[1] = s_statusServiceThread_send_http_da_000aceec[1];
          tmp42[2] = s_statusServiceThread_send_http_da_000aceec[2];
          tmp42[3] = s_statusServiceThread_send_http_da_000aceec[3];
          tmp42[4] = s_statusServiceThread_send_http_da_000aceec[4];
          tmp42[5] = s_statusServiceThread_send_http_da_000aceec[5];
          tmp42[6] = s_statusServiceThread_send_http_da_000aceec[6];
          tmp42[7] = s_statusServiceThread_send_http_da_000aceec[7];
          tmp42[8] = s_statusServiceThread_send_http_da_000aceec[8];
          tmp42[9] = s_statusServiceThread_send_http_da_000aceec[9];
          tmp42[10] = s_statusServiceThread_send_http_da_000aceec[10];
          tmp42[11] = s_statusServiceThread_send_http_da_000aceec[11];
          tmp42[12] = s_statusServiceThread_send_http_da_000aceec[12];
          tmp42[13] = s_statusServiceThread_send_http_da_000aceec[13];
          tmp42[14] = s_statusServiceThread_send_http_da_000aceec[14];
          tmp42[15] = s_statusServiceThread_send_http_da_000aceec[15];
          tmp42[16] = s_statusServiceThread_send_http_da_000aceec[16];
          tmp42[17] = s_statusServiceThread_send_http_da_000aceec[17];
          tmp42[18] = s_statusServiceThread_send_http_da_000aceec[18];
          tmp42[19] = s_statusServiceThread_send_http_da_000aceec[19];
          tmp42[20] = s_statusServiceThread_send_http_da_000aceec[20];
          tmp42[21] = s_statusServiceThread_send_http_da_000aceec[21];
          tmp42[22] = s_statusServiceThread_send_http_da_000aceec[22];
          tmp42[23] = s_statusServiceThread_send_http_da_000aceec[23];
          tmp42[24] = s_statusServiceThread_send_http_da_000aceec[24];
          tmp42[25] = s_statusServiceThread_send_http_da_000aceec[25];
          tmp42[26] = s_statusServiceThread_send_http_da_000aceec[26];
          tmp42[27] = s_statusServiceThread_send_http_da_000aceec[27];
          tmp42[28] = s_statusServiceThread_send_http_da_000aceec[28];
          tmp42[29] = s_statusServiceThread_send_http_da_000aceec[29];
          tmp42[30] = s_statusServiceThread_send_http_da_000aceec[30];
          tmp42[31] = s_statusServiceThread_send_http_da_000aceec[31];
          tmp42[32] = s_statusServiceThread_send_http_da_000aceec[32];
          tmp42[33] = s_statusServiceThread_send_http_da_000aceec[33];
          tmp42[34] = s_statusServiceThread_send_http_da_000aceec[34];
          tmp42[35] = s_statusServiceThread_send_http_da_000aceec[35];
          tmp42[36] = s_statusServiceThread_send_http_da_000aceec[36];
          tmp42[37] = s_statusServiceThread_send_http_da_000aceec[37];
          tmp42[38] = s_statusServiceThread_send_http_da_000aceec[38];
          tmp42[39] = s_statusServiceThread_send_http_da_000aceec[39];
          tmp42[40] = (char)ram0x000acf14;
          _applog(7,tmp42,false);
        }
LAB_0007aa30:
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_one_client_disconnected__000acf18[0];
          tmp42[1] = s_one_client_disconnected__000acf18[1];
          tmp42[2] = s_one_client_disconnected__000acf18[2];
          tmp42[3] = s_one_client_disconnected__000acf18[3];
          tmp42[4] = s_one_client_disconnected__000acf18[4];
          tmp42[5] = s_one_client_disconnected__000acf18[5];
          tmp42[6] = s_one_client_disconnected__000acf18[6];
          tmp42[7] = s_one_client_disconnected__000acf18[7];
          tmp42[8] = s_one_client_disconnected__000acf18[8];
          tmp42[9] = s_one_client_disconnected__000acf18[9];
          tmp42[10] = s_one_client_disconnected__000acf18[10];
          tmp42[11] = s_one_client_disconnected__000acf18[11];
          tmp42[12] = s_one_client_disconnected__000acf18[12];
          tmp42[13] = s_one_client_disconnected__000acf18[13];
          tmp42[14] = s_one_client_disconnected__000acf18[14];
          tmp42[15] = s_one_client_disconnected__000acf18[15];
          tmp42[16] = s_one_client_disconnected__000acf18[16];
          tmp42[17] = s_one_client_disconnected__000acf18[17];
          tmp42[18] = s_one_client_disconnected__000acf18[18];
          tmp42[19] = s_one_client_disconnected__000acf18[19];
          tmp42[20] = s_one_client_disconnected__000acf18[20];
          tmp42[21] = s_one_client_disconnected__000acf18[21];
          tmp42[22] = s_one_client_disconnected__000acf18[22];
          tmp42[23] = s_one_client_disconnected__000acf18[23];
          tmp42[24] = (char)ram0x000acf30;
          _applog(7,tmp42,false);
        }
        close((int)param);
      }
      else {
        close((int)param);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[0];
          tmp42[1] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[1];
          tmp42[2] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[2];
          tmp42[3] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[3];
          tmp42[4] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[4];
          tmp42[5] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[5];
          tmp42[6] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[6];
          tmp42[7] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[7];
          tmp42[8] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[8];
          tmp42[9] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[9];
          tmp42[10] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[10];
          tmp42[11] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[11];
          tmp42[12] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[12];
          tmp42[13] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[13];
          tmp42[14] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[14];
          tmp42[15] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[15];
          tmp42[16] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[16];
          tmp42[17] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[17];
          tmp42[18] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[18];
          tmp42[19] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[19];
          tmp42[20] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[20];
          tmp42[21] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[21];
          tmp42[22] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[22];
          tmp42[23] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[23];
          tmp42[24] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[24];
          tmp42[25] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[25];
          tmp42[26] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[26];
          tmp42[27] = s_setsockopt_SO_RCVTIMEO_failed_000acd44[27];
          tmp42[28] = (char)(short)ram0x000acd60;
          tmp42[29] = (char)((ushort)(short)ram0x000acd60 >> 8);
          _applog(7,tmp42,false);
        }
        sentlen = 0;
      }
    }
    else {
      close((int)param);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[0];
        tmp42[1] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[1];
        tmp42[2] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[2];
        tmp42[3] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[3];
        tmp42[4] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[4];
        tmp42[5] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[5];
        tmp42[6] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[6];
        tmp42[7] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[7];
        tmp42[8] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[8];
        tmp42[9] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[9];
        tmp42[10] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[10];
        tmp42[11] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[11];
        tmp42[12] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[12];
        tmp42[13] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[13];
        tmp42[14] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[14];
        tmp42[15] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[15];
        tmp42[16] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[16];
        tmp42[17] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[17];
        tmp42[18] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[18];
        tmp42[19] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[19];
        tmp42[20] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[20];
        tmp42[21] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[21];
        tmp42[22] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[22];
        tmp42[23] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[23];
        tmp42[24] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[24];
        tmp42[25] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[25];
        tmp42[26] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[26];
        tmp42[27] = s_setsockopt_SO_SNDTIMEO_failed_000acd24[27];
        tmp42[28] = (char)(short)ram0x000acd40;
        tmp42[29] = (char)((ushort)(short)ram0x000acd40 >> 8);
        _applog(7,tmp42,false);
      }
      sentlen = 0;
    }
  }
  else {
    close((int)param);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_statusServiceThread_not_support_h_000acc48[0];
      tmp42[1] = s_statusServiceThread_not_support_h_000acc48[1];
      tmp42[2] = s_statusServiceThread_not_support_h_000acc48[2];
      tmp42[3] = s_statusServiceThread_not_support_h_000acc48[3];
      tmp42[4] = s_statusServiceThread_not_support_h_000acc48[4];
      tmp42[5] = s_statusServiceThread_not_support_h_000acc48[5];
      tmp42[6] = s_statusServiceThread_not_support_h_000acc48[6];
      tmp42[7] = s_statusServiceThread_not_support_h_000acc48[7];
      tmp42[8] = s_statusServiceThread_not_support_h_000acc48[8];
      tmp42[9] = s_statusServiceThread_not_support_h_000acc48[9];
      tmp42[10] = s_statusServiceThread_not_support_h_000acc48[10];
      tmp42[11] = s_statusServiceThread_not_support_h_000acc48[11];
      tmp42[12] = s_statusServiceThread_not_support_h_000acc48[12];
      tmp42[13] = s_statusServiceThread_not_support_h_000acc48[13];
      tmp42[14] = s_statusServiceThread_not_support_h_000acc48[14];
      tmp42[15] = s_statusServiceThread_not_support_h_000acc48[15];
      tmp42[16] = s_statusServiceThread_not_support_h_000acc48[16];
      tmp42[17] = s_statusServiceThread_not_support_h_000acc48[17];
      tmp42[18] = s_statusServiceThread_not_support_h_000acc48[18];
      tmp42[19] = s_statusServiceThread_not_support_h_000acc48[19];
      tmp42[20] = s_statusServiceThread_not_support_h_000acc48[20];
      tmp42[21] = s_statusServiceThread_not_support_h_000acc48[21];
      tmp42[22] = s_statusServiceThread_not_support_h_000acc48[22];
      tmp42[23] = s_statusServiceThread_not_support_h_000acc48[23];
      tmp42[24] = s_statusServiceThread_not_support_h_000acc48[24];
      tmp42[25] = s_statusServiceThread_not_support_h_000acc48[25];
      tmp42[26] = s_statusServiceThread_not_support_h_000acc48[26];
      tmp42[27] = s_statusServiceThread_not_support_h_000acc48[27];
      tmp42[28] = s_statusServiceThread_not_support_h_000acc48[28];
      tmp42[29] = s_statusServiceThread_not_support_h_000acc48[29];
      tmp42[30] = s_statusServiceThread_not_support_h_000acc48[30];
      tmp42[31] = s_statusServiceThread_not_support_h_000acc48[31];
      tmp42[32] = s_statusServiceThread_not_support_h_000acc48[32];
      tmp42[33] = s_statusServiceThread_not_support_h_000acc48[33];
      tmp42[34] = s_statusServiceThread_not_support_h_000acc48[34];
      tmp42[35] = s_statusServiceThread_not_support_h_000acc48[35];
      tmp42[36] = s_statusServiceThread_not_support_h_000acc48[36];
      tmp42[37] = s_statusServiceThread_not_support_h_000acc48[37];
      tmp42[38] = s_statusServiceThread_not_support_h_000acc48[38];
      tmp42[39] = s_statusServiceThread_not_support_h_000acc48[39];
      tmp42[40] = s_statusServiceThread_not_support_h_000acc48[40];
      tmp42[41] = s_statusServiceThread_not_support_h_000acc48[41];
      tmp42[42] = s_statusServiceThread_not_support_h_000acc48[42];
      tmp42[43] = s_statusServiceThread_not_support_h_000acc48[43];
      tmp42[44] = (char)ram0x000acc74;
      _applog(7,tmp42,false);
    }
    sentlen = 0;
  }
  return (void *)sentlen;
}

