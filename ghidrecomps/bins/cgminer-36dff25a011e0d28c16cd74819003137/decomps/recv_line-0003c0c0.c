
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * recv_line(pool *pool)

{
  _Bool _Var1;
  char *pcVar2;
  ssize_t sVar3;
  size_t sVar4;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  double dVar8;
  pool *pool_local;
  char tmp42_1 [2048];
  char tmp42 [2048];
  timeval now;
  timeval rstart;
  ssize_t len;
  char *tok;
  ssize_t buflen;
  size_t slen;
  ssize_t n;
  int waited;
  char *sret;
  
  sret = (char *)0x0;
  pcVar2 = strchr(pool->sockbuf,10);
  if (pcVar2 == (char *)0x0) {
    cgtime(&rstart);
    _Var1 = socket_full(pool,0x3c);
    if (_Var1) {
      do {
        memset(tmp42,0,0x2000);
        sVar3 = recv(pool->sock,tmp42,0x1ffc,0);
        if (sVar3 == 0) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42_1[0] = s_Socket_closed_waiting_in_recv_li_0009f2c0[0];
            tmp42_1[1] = s_Socket_closed_waiting_in_recv_li_0009f2c0[1];
            tmp42_1[2] = s_Socket_closed_waiting_in_recv_li_0009f2c0[2];
            tmp42_1[3] = s_Socket_closed_waiting_in_recv_li_0009f2c0[3];
            tmp42_1[4] = s_Socket_closed_waiting_in_recv_li_0009f2c0[4];
            tmp42_1[5] = s_Socket_closed_waiting_in_recv_li_0009f2c0[5];
            tmp42_1[6] = s_Socket_closed_waiting_in_recv_li_0009f2c0[6];
            tmp42_1[7] = s_Socket_closed_waiting_in_recv_li_0009f2c0[7];
            tmp42_1[8] = s_Socket_closed_waiting_in_recv_li_0009f2c0[8];
            tmp42_1[9] = s_Socket_closed_waiting_in_recv_li_0009f2c0[9];
            tmp42_1[10] = s_Socket_closed_waiting_in_recv_li_0009f2c0[10];
            tmp42_1[11] = s_Socket_closed_waiting_in_recv_li_0009f2c0[11];
            tmp42_1[12] = s_Socket_closed_waiting_in_recv_li_0009f2c0[12];
            tmp42_1[13] = s_Socket_closed_waiting_in_recv_li_0009f2c0[13];
            tmp42_1[14] = s_Socket_closed_waiting_in_recv_li_0009f2c0[14];
            tmp42_1[15] = s_Socket_closed_waiting_in_recv_li_0009f2c0[15];
            tmp42_1[16] = s_Socket_closed_waiting_in_recv_li_0009f2c0[16];
            tmp42_1[17] = s_Socket_closed_waiting_in_recv_li_0009f2c0[17];
            tmp42_1[18] = s_Socket_closed_waiting_in_recv_li_0009f2c0[18];
            tmp42_1[19] = s_Socket_closed_waiting_in_recv_li_0009f2c0[19];
            tmp42_1[20] = s_Socket_closed_waiting_in_recv_li_0009f2c0[20];
            tmp42_1[21] = s_Socket_closed_waiting_in_recv_li_0009f2c0[21];
            tmp42_1[22] = s_Socket_closed_waiting_in_recv_li_0009f2c0[22];
            tmp42_1[23] = s_Socket_closed_waiting_in_recv_li_0009f2c0[23];
            tmp42_1[24] = s_Socket_closed_waiting_in_recv_li_0009f2c0[24];
            tmp42_1[25] = s_Socket_closed_waiting_in_recv_li_0009f2c0[25];
            tmp42_1[26] = s_Socket_closed_waiting_in_recv_li_0009f2c0[26];
            tmp42_1[27] = s_Socket_closed_waiting_in_recv_li_0009f2c0[27];
            tmp42_1[28] = s_Socket_closed_waiting_in_recv_li_0009f2c0[28];
            tmp42_1[29] = s_Socket_closed_waiting_in_recv_li_0009f2c0[29];
            tmp42_1[30] = s_Socket_closed_waiting_in_recv_li_0009f2c0[30];
            tmp42_1[31] = s_Socket_closed_waiting_in_recv_li_0009f2c0[31];
            tmp42_1._32_2_ = (undefined2)ram0x0009f2e0;
            tmp42_1[34] = (char)((uint)ram0x0009f2e0 >> 0x10);
            _applog(7,tmp42_1,false);
          }
          suspend_stratum(pool);
          goto LAB_0003c4c8;
        }
        cgtime(&now);
        dVar8 = tdiff(&now,&rstart);
        if (sVar3 < 0) {
          _Var1 = sock_blocks();
          if ((!_Var1) || (_Var1 = socket_full(pool,0x3c - (int)(longlong)dVar8), !_Var1)) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42_1[0] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[0];
              tmp42_1[1] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[1];
              tmp42_1[2] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[2];
              tmp42_1[3] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[3];
              tmp42_1[4] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[4];
              tmp42_1[5] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[5];
              tmp42_1[6] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[6];
              tmp42_1[7] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[7];
              tmp42_1[8] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[8];
              tmp42_1[9] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[9];
              tmp42_1[10] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[10];
              tmp42_1[11] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[11];
              tmp42_1[12] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[12];
              tmp42_1[13] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[13];
              tmp42_1[14] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[14];
              tmp42_1[15] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[15];
              tmp42_1[16] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[16];
              tmp42_1[17] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[17];
              tmp42_1[18] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[18];
              tmp42_1[19] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[19];
              tmp42_1[20] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[20];
              tmp42_1[21] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[21];
              tmp42_1[22] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[22];
              tmp42_1[23] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[23];
              tmp42_1[24] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[24];
              tmp42_1[25] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[25];
              tmp42_1[26] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[26];
              tmp42_1[27] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[27];
              tmp42_1[28] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[28];
              tmp42_1[29] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[29];
              tmp42_1[30] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[30];
              tmp42_1[31] = s_Failed_to_recv_sock_in_recv_line_0009f2e4[31];
              tmp42_1[32] = (char)ram0x0009f304;
              _applog(7,tmp42_1,false);
            }
            suspend_stratum(pool);
            goto LAB_0003c4c8;
          }
        }
        else {
          sVar4 = strlen(tmp42);
          recalloc_sock(pool,sVar4);
          strcat(pool->sockbuf,tmp42);
        }
        if ((0x3b < (int)(longlong)dVar8) ||
           (pcVar2 = strchr(pool->sockbuf,10), pcVar2 != (char *)0x0)) goto LAB_0003c4c8;
      } while( true );
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Timed_out_waiting_for_data_on_so_0009f294[0];
      tmp42[1] = s_Timed_out_waiting_for_data_on_so_0009f294[1];
      tmp42[2] = s_Timed_out_waiting_for_data_on_so_0009f294[2];
      tmp42[3] = s_Timed_out_waiting_for_data_on_so_0009f294[3];
      tmp42[4] = s_Timed_out_waiting_for_data_on_so_0009f294[4];
      tmp42[5] = s_Timed_out_waiting_for_data_on_so_0009f294[5];
      tmp42[6] = s_Timed_out_waiting_for_data_on_so_0009f294[6];
      tmp42[7] = s_Timed_out_waiting_for_data_on_so_0009f294[7];
      tmp42[8] = s_Timed_out_waiting_for_data_on_so_0009f294[8];
      tmp42[9] = s_Timed_out_waiting_for_data_on_so_0009f294[9];
      tmp42[10] = s_Timed_out_waiting_for_data_on_so_0009f294[10];
      tmp42[11] = s_Timed_out_waiting_for_data_on_so_0009f294[11];
      tmp42[12] = s_Timed_out_waiting_for_data_on_so_0009f294[12];
      tmp42[13] = s_Timed_out_waiting_for_data_on_so_0009f294[13];
      tmp42[14] = s_Timed_out_waiting_for_data_on_so_0009f294[14];
      tmp42[15] = s_Timed_out_waiting_for_data_on_so_0009f294[15];
      tmp42[16] = s_Timed_out_waiting_for_data_on_so_0009f294[16];
      tmp42[17] = s_Timed_out_waiting_for_data_on_so_0009f294[17];
      tmp42[18] = s_Timed_out_waiting_for_data_on_so_0009f294[18];
      tmp42[19] = s_Timed_out_waiting_for_data_on_so_0009f294[19];
      tmp42[20] = s_Timed_out_waiting_for_data_on_so_0009f294[20];
      tmp42[21] = s_Timed_out_waiting_for_data_on_so_0009f294[21];
      tmp42[22] = s_Timed_out_waiting_for_data_on_so_0009f294[22];
      tmp42[23] = s_Timed_out_waiting_for_data_on_so_0009f294[23];
      tmp42[24] = s_Timed_out_waiting_for_data_on_so_0009f294[24];
      tmp42[25] = s_Timed_out_waiting_for_data_on_so_0009f294[25];
      tmp42[26] = s_Timed_out_waiting_for_data_on_so_0009f294[26];
      tmp42[27] = s_Timed_out_waiting_for_data_on_so_0009f294[27];
      tmp42[28] = s_Timed_out_waiting_for_data_on_so_0009f294[28];
      tmp42[29] = s_Timed_out_waiting_for_data_on_so_0009f294[29];
      tmp42[30] = s_Timed_out_waiting_for_data_on_so_0009f294[30];
      tmp42[31] = s_Timed_out_waiting_for_data_on_so_0009f294[31];
      tmp42[32] = s_Timed_out_waiting_for_data_on_so_0009f294[32];
      tmp42[33] = s_Timed_out_waiting_for_data_on_so_0009f294[33];
      tmp42[34] = s_Timed_out_waiting_for_data_on_so_0009f294[34];
      tmp42[35] = s_Timed_out_waiting_for_data_on_so_0009f294[35];
      tmp42[36] = s_Timed_out_waiting_for_data_on_so_0009f294[36];
      tmp42[37] = s_Timed_out_waiting_for_data_on_so_0009f294[37];
      tmp42[38] = s_Timed_out_waiting_for_data_on_so_0009f294[38];
      tmp42[39] = s_Timed_out_waiting_for_data_on_so_0009f294[39];
      tmp42[40] = (char)(short)ram0x0009f2bc;
      tmp42[41] = (char)((ushort)(short)ram0x0009f2bc >> 8);
      _applog(7,tmp42,false);
    }
  }
  else {
LAB_0003c4c8:
    sVar4 = strlen(pool->sockbuf);
    pcVar2 = strtok(pool->sockbuf,(char *)&DAT_0009f218);
    if (pcVar2 == (char *)0x0) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_parse_a__n_terminated_s_0009f308[0];
        tmp42[1] = s_Failed_to_parse_a__n_terminated_s_0009f308[1];
        tmp42[2] = s_Failed_to_parse_a__n_terminated_s_0009f308[2];
        tmp42[3] = s_Failed_to_parse_a__n_terminated_s_0009f308[3];
        tmp42[4] = s_Failed_to_parse_a__n_terminated_s_0009f308[4];
        tmp42[5] = s_Failed_to_parse_a__n_terminated_s_0009f308[5];
        tmp42[6] = s_Failed_to_parse_a__n_terminated_s_0009f308[6];
        tmp42[7] = s_Failed_to_parse_a__n_terminated_s_0009f308[7];
        tmp42[8] = s_Failed_to_parse_a__n_terminated_s_0009f308[8];
        tmp42[9] = s_Failed_to_parse_a__n_terminated_s_0009f308[9];
        tmp42[10] = s_Failed_to_parse_a__n_terminated_s_0009f308[10];
        tmp42[11] = s_Failed_to_parse_a__n_terminated_s_0009f308[11];
        tmp42[12] = s_Failed_to_parse_a__n_terminated_s_0009f308[12];
        tmp42[13] = s_Failed_to_parse_a__n_terminated_s_0009f308[13];
        tmp42[14] = s_Failed_to_parse_a__n_terminated_s_0009f308[14];
        tmp42[15] = s_Failed_to_parse_a__n_terminated_s_0009f308[15];
        tmp42[16] = s_Failed_to_parse_a__n_terminated_s_0009f308[16];
        tmp42[17] = s_Failed_to_parse_a__n_terminated_s_0009f308[17];
        tmp42[18] = s_Failed_to_parse_a__n_terminated_s_0009f308[18];
        tmp42[19] = s_Failed_to_parse_a__n_terminated_s_0009f308[19];
        tmp42[20] = s_Failed_to_parse_a__n_terminated_s_0009f308[20];
        tmp42[21] = s_Failed_to_parse_a__n_terminated_s_0009f308[21];
        tmp42[22] = s_Failed_to_parse_a__n_terminated_s_0009f308[22];
        tmp42[23] = s_Failed_to_parse_a__n_terminated_s_0009f308[23];
        tmp42[24] = s_Failed_to_parse_a__n_terminated_s_0009f308[24];
        tmp42[25] = s_Failed_to_parse_a__n_terminated_s_0009f308[25];
        tmp42[26] = s_Failed_to_parse_a__n_terminated_s_0009f308[26];
        tmp42[27] = s_Failed_to_parse_a__n_terminated_s_0009f308[27];
        tmp42[28] = s_Failed_to_parse_a__n_terminated_s_0009f308[28];
        tmp42[29] = s_Failed_to_parse_a__n_terminated_s_0009f308[29];
        tmp42[30] = s_Failed_to_parse_a__n_terminated_s_0009f308[30];
        tmp42[31] = s_Failed_to_parse_a__n_terminated_s_0009f308[31];
        tmp42[32] = s_Failed_to_parse_a__n_terminated_s_0009f308[32];
        tmp42[33] = s_Failed_to_parse_a__n_terminated_s_0009f308[33];
        tmp42[34] = s_Failed_to_parse_a__n_terminated_s_0009f308[34];
        tmp42[35] = s_Failed_to_parse_a__n_terminated_s_0009f308[35];
        tmp42[36] = s_Failed_to_parse_a__n_terminated_s_0009f308[36];
        tmp42[37] = s_Failed_to_parse_a__n_terminated_s_0009f308[37];
        tmp42[38] = s_Failed_to_parse_a__n_terminated_s_0009f308[38];
        tmp42[39] = s_Failed_to_parse_a__n_terminated_s_0009f308[39];
        tmp42[40] = s_Failed_to_parse_a__n_terminated_s_0009f308[40];
        tmp42[41] = s_Failed_to_parse_a__n_terminated_s_0009f308[41];
        tmp42[42] = s_Failed_to_parse_a__n_terminated_s_0009f308[42];
        tmp42[43] = s_Failed_to_parse_a__n_terminated_s_0009f308[43];
        tmp42[44] = s_Failed_to_parse_a__n_terminated_s_0009f308[44];
        tmp42[45] = s_Failed_to_parse_a__n_terminated_s_0009f308[45];
        tmp42[46] = s_Failed_to_parse_a__n_terminated_s_0009f308[46];
        tmp42[47] = s_Failed_to_parse_a__n_terminated_s_0009f308[47];
        tmp42[48] = s_Failed_to_parse_a__n_terminated_s_0009f308[48];
        tmp42[49] = s_Failed_to_parse_a__n_terminated_s_0009f308[49];
        tmp42[50] = s_Failed_to_parse_a__n_terminated_s_0009f308[50];
        tmp42[51] = s_Failed_to_parse_a__n_terminated_s_0009f308[51];
        _applog(7,tmp42,false);
      }
    }
    else {
      sret = strdup(pcVar2);
      sVar5 = strlen(sret);
      if ((int)(sVar5 + 1) < (int)sVar4) {
        memmove(pool->sockbuf,pool->sockbuf + sVar5 + 1,(sVar4 - sVar5) + 1);
      }
      else {
        *pool->sockbuf = '\0';
      }
      uVar6 = *(uint *)&(pool->cgminer_pool_stats).times_received;
      iVar7 = *(int *)((int)&(pool->cgminer_pool_stats).times_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).times_received = uVar6 + 1;
      *(uint *)((int)&(pool->cgminer_pool_stats).times_received + 4) =
           iVar7 + (uint)(0xfffffffe < uVar6);
      uVar6 = *(uint *)&(pool->cgminer_pool_stats).bytes_received;
      iVar7 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).bytes_received = uVar6 + sVar5;
      *(uint *)((int)&(pool->cgminer_pool_stats).bytes_received + 4) =
           iVar7 + ((int)sVar5 >> 0x1f) + (uint)CARRY4(uVar6,sVar5);
      uVar6 = *(uint *)&(pool->cgminer_pool_stats).net_bytes_received;
      iVar7 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4);
      *(uint *)&(pool->cgminer_pool_stats).net_bytes_received = uVar6 + sVar5;
      *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_received + 4) =
           iVar7 + ((int)sVar5 >> 0x1f) + (uint)CARRY4(uVar6,sVar5);
    }
  }
  if (sret == (char *)0x0) {
    clear_sock(pool);
  }
  else if (((opt_protocol != false) && (opt_debug != false)) &&
          ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"RECVD: %s",sret);
    _applog(7,tmp42,false);
  }
  return sret;
}

