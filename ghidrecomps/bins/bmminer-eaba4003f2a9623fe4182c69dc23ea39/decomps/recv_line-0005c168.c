
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
            tmp42_1[0] = s_Socket_closed_waiting_in_recv_li_0007b1d0[0];
            tmp42_1[1] = s_Socket_closed_waiting_in_recv_li_0007b1d0[1];
            tmp42_1[2] = s_Socket_closed_waiting_in_recv_li_0007b1d0[2];
            tmp42_1[3] = s_Socket_closed_waiting_in_recv_li_0007b1d0[3];
            tmp42_1[4] = s_Socket_closed_waiting_in_recv_li_0007b1d0[4];
            tmp42_1[5] = s_Socket_closed_waiting_in_recv_li_0007b1d0[5];
            tmp42_1[6] = s_Socket_closed_waiting_in_recv_li_0007b1d0[6];
            tmp42_1[7] = s_Socket_closed_waiting_in_recv_li_0007b1d0[7];
            tmp42_1[8] = s_Socket_closed_waiting_in_recv_li_0007b1d0[8];
            tmp42_1[9] = s_Socket_closed_waiting_in_recv_li_0007b1d0[9];
            tmp42_1[10] = s_Socket_closed_waiting_in_recv_li_0007b1d0[10];
            tmp42_1[11] = s_Socket_closed_waiting_in_recv_li_0007b1d0[11];
            tmp42_1[12] = s_Socket_closed_waiting_in_recv_li_0007b1d0[12];
            tmp42_1[13] = s_Socket_closed_waiting_in_recv_li_0007b1d0[13];
            tmp42_1[14] = s_Socket_closed_waiting_in_recv_li_0007b1d0[14];
            tmp42_1[15] = s_Socket_closed_waiting_in_recv_li_0007b1d0[15];
            tmp42_1[16] = s_Socket_closed_waiting_in_recv_li_0007b1d0[16];
            tmp42_1[17] = s_Socket_closed_waiting_in_recv_li_0007b1d0[17];
            tmp42_1[18] = s_Socket_closed_waiting_in_recv_li_0007b1d0[18];
            tmp42_1[19] = s_Socket_closed_waiting_in_recv_li_0007b1d0[19];
            tmp42_1[20] = s_Socket_closed_waiting_in_recv_li_0007b1d0[20];
            tmp42_1[21] = s_Socket_closed_waiting_in_recv_li_0007b1d0[21];
            tmp42_1[22] = s_Socket_closed_waiting_in_recv_li_0007b1d0[22];
            tmp42_1[23] = s_Socket_closed_waiting_in_recv_li_0007b1d0[23];
            tmp42_1[24] = s_Socket_closed_waiting_in_recv_li_0007b1d0[24];
            tmp42_1[25] = s_Socket_closed_waiting_in_recv_li_0007b1d0[25];
            tmp42_1[26] = s_Socket_closed_waiting_in_recv_li_0007b1d0[26];
            tmp42_1[27] = s_Socket_closed_waiting_in_recv_li_0007b1d0[27];
            tmp42_1[28] = s_Socket_closed_waiting_in_recv_li_0007b1d0[28];
            tmp42_1[29] = s_Socket_closed_waiting_in_recv_li_0007b1d0[29];
            tmp42_1[30] = s_Socket_closed_waiting_in_recv_li_0007b1d0[30];
            tmp42_1[31] = s_Socket_closed_waiting_in_recv_li_0007b1d0[31];
            tmp42_1._32_2_ = (undefined2)ram0x0007b1f0;
            tmp42_1[34] = (char)((uint)ram0x0007b1f0 >> 0x10);
            _applog(7,tmp42_1,false);
          }
          suspend_stratum(pool);
          goto LAB_0005c474;
        }
        cgtime(&now);
        dVar8 = tdiff(&now,&rstart);
        if (sVar3 < 0) {
          _Var1 = sock_blocks();
          if ((!_Var1) || (_Var1 = socket_full(pool,0x3c - (int)(longlong)dVar8), !_Var1)) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42_1[0] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[0];
              tmp42_1[1] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[1];
              tmp42_1[2] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[2];
              tmp42_1[3] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[3];
              tmp42_1[4] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[4];
              tmp42_1[5] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[5];
              tmp42_1[6] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[6];
              tmp42_1[7] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[7];
              tmp42_1[8] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[8];
              tmp42_1[9] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[9];
              tmp42_1[10] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[10];
              tmp42_1[11] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[11];
              tmp42_1[12] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[12];
              tmp42_1[13] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[13];
              tmp42_1[14] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[14];
              tmp42_1[15] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[15];
              tmp42_1[16] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[16];
              tmp42_1[17] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[17];
              tmp42_1[18] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[18];
              tmp42_1[19] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[19];
              tmp42_1[20] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[20];
              tmp42_1[21] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[21];
              tmp42_1[22] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[22];
              tmp42_1[23] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[23];
              tmp42_1[24] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[24];
              tmp42_1[25] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[25];
              tmp42_1[26] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[26];
              tmp42_1[27] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[27];
              tmp42_1[28] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[28];
              tmp42_1[29] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[29];
              tmp42_1[30] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[30];
              tmp42_1[31] = s_Failed_to_recv_sock_in_recv_line_0007b1f4[31];
              tmp42_1[32] = (char)ram0x0007b214;
              _applog(7,tmp42_1,false);
            }
            suspend_stratum(pool);
            goto LAB_0005c474;
          }
        }
        else {
          sVar4 = strlen(tmp42);
          recalloc_sock(pool,sVar4);
          strcat(pool->sockbuf,tmp42);
        }
        if ((0x3b < (int)(longlong)dVar8) ||
           (pcVar2 = strchr(pool->sockbuf,10), pcVar2 != (char *)0x0)) goto LAB_0005c474;
      } while( true );
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Timed_out_waiting_for_data_on_so_0007b1a4[0];
      tmp42[1] = s_Timed_out_waiting_for_data_on_so_0007b1a4[1];
      tmp42[2] = s_Timed_out_waiting_for_data_on_so_0007b1a4[2];
      tmp42[3] = s_Timed_out_waiting_for_data_on_so_0007b1a4[3];
      tmp42[4] = s_Timed_out_waiting_for_data_on_so_0007b1a4[4];
      tmp42[5] = s_Timed_out_waiting_for_data_on_so_0007b1a4[5];
      tmp42[6] = s_Timed_out_waiting_for_data_on_so_0007b1a4[6];
      tmp42[7] = s_Timed_out_waiting_for_data_on_so_0007b1a4[7];
      tmp42[8] = s_Timed_out_waiting_for_data_on_so_0007b1a4[8];
      tmp42[9] = s_Timed_out_waiting_for_data_on_so_0007b1a4[9];
      tmp42[10] = s_Timed_out_waiting_for_data_on_so_0007b1a4[10];
      tmp42[11] = s_Timed_out_waiting_for_data_on_so_0007b1a4[11];
      tmp42[12] = s_Timed_out_waiting_for_data_on_so_0007b1a4[12];
      tmp42[13] = s_Timed_out_waiting_for_data_on_so_0007b1a4[13];
      tmp42[14] = s_Timed_out_waiting_for_data_on_so_0007b1a4[14];
      tmp42[15] = s_Timed_out_waiting_for_data_on_so_0007b1a4[15];
      tmp42[16] = s_Timed_out_waiting_for_data_on_so_0007b1a4[16];
      tmp42[17] = s_Timed_out_waiting_for_data_on_so_0007b1a4[17];
      tmp42[18] = s_Timed_out_waiting_for_data_on_so_0007b1a4[18];
      tmp42[19] = s_Timed_out_waiting_for_data_on_so_0007b1a4[19];
      tmp42[20] = s_Timed_out_waiting_for_data_on_so_0007b1a4[20];
      tmp42[21] = s_Timed_out_waiting_for_data_on_so_0007b1a4[21];
      tmp42[22] = s_Timed_out_waiting_for_data_on_so_0007b1a4[22];
      tmp42[23] = s_Timed_out_waiting_for_data_on_so_0007b1a4[23];
      tmp42[24] = s_Timed_out_waiting_for_data_on_so_0007b1a4[24];
      tmp42[25] = s_Timed_out_waiting_for_data_on_so_0007b1a4[25];
      tmp42[26] = s_Timed_out_waiting_for_data_on_so_0007b1a4[26];
      tmp42[27] = s_Timed_out_waiting_for_data_on_so_0007b1a4[27];
      tmp42[28] = s_Timed_out_waiting_for_data_on_so_0007b1a4[28];
      tmp42[29] = s_Timed_out_waiting_for_data_on_so_0007b1a4[29];
      tmp42[30] = s_Timed_out_waiting_for_data_on_so_0007b1a4[30];
      tmp42[31] = s_Timed_out_waiting_for_data_on_so_0007b1a4[31];
      tmp42[32] = s_Timed_out_waiting_for_data_on_so_0007b1a4[32];
      tmp42[33] = s_Timed_out_waiting_for_data_on_so_0007b1a4[33];
      tmp42[34] = s_Timed_out_waiting_for_data_on_so_0007b1a4[34];
      tmp42[35] = s_Timed_out_waiting_for_data_on_so_0007b1a4[35];
      tmp42[36] = s_Timed_out_waiting_for_data_on_so_0007b1a4[36];
      tmp42[37] = s_Timed_out_waiting_for_data_on_so_0007b1a4[37];
      tmp42[38] = s_Timed_out_waiting_for_data_on_so_0007b1a4[38];
      tmp42[39] = s_Timed_out_waiting_for_data_on_so_0007b1a4[39];
      tmp42[40] = (char)(short)ram0x0007b1cc;
      tmp42[41] = (char)((ushort)(short)ram0x0007b1cc >> 8);
      _applog(7,tmp42,false);
    }
  }
  else {
LAB_0005c474:
    sVar4 = strlen(pool->sockbuf);
    pcVar2 = strtok(pool->sockbuf,(char *)&DAT_0007b128);
    if (pcVar2 == (char *)0x0) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Failed_to_parse_a__n_terminated_s_0007b218[0];
        tmp42[1] = s_Failed_to_parse_a__n_terminated_s_0007b218[1];
        tmp42[2] = s_Failed_to_parse_a__n_terminated_s_0007b218[2];
        tmp42[3] = s_Failed_to_parse_a__n_terminated_s_0007b218[3];
        tmp42[4] = s_Failed_to_parse_a__n_terminated_s_0007b218[4];
        tmp42[5] = s_Failed_to_parse_a__n_terminated_s_0007b218[5];
        tmp42[6] = s_Failed_to_parse_a__n_terminated_s_0007b218[6];
        tmp42[7] = s_Failed_to_parse_a__n_terminated_s_0007b218[7];
        tmp42[8] = s_Failed_to_parse_a__n_terminated_s_0007b218[8];
        tmp42[9] = s_Failed_to_parse_a__n_terminated_s_0007b218[9];
        tmp42[10] = s_Failed_to_parse_a__n_terminated_s_0007b218[10];
        tmp42[11] = s_Failed_to_parse_a__n_terminated_s_0007b218[11];
        tmp42[12] = s_Failed_to_parse_a__n_terminated_s_0007b218[12];
        tmp42[13] = s_Failed_to_parse_a__n_terminated_s_0007b218[13];
        tmp42[14] = s_Failed_to_parse_a__n_terminated_s_0007b218[14];
        tmp42[15] = s_Failed_to_parse_a__n_terminated_s_0007b218[15];
        tmp42[16] = s_Failed_to_parse_a__n_terminated_s_0007b218[16];
        tmp42[17] = s_Failed_to_parse_a__n_terminated_s_0007b218[17];
        tmp42[18] = s_Failed_to_parse_a__n_terminated_s_0007b218[18];
        tmp42[19] = s_Failed_to_parse_a__n_terminated_s_0007b218[19];
        tmp42[20] = s_Failed_to_parse_a__n_terminated_s_0007b218[20];
        tmp42[21] = s_Failed_to_parse_a__n_terminated_s_0007b218[21];
        tmp42[22] = s_Failed_to_parse_a__n_terminated_s_0007b218[22];
        tmp42[23] = s_Failed_to_parse_a__n_terminated_s_0007b218[23];
        tmp42[24] = s_Failed_to_parse_a__n_terminated_s_0007b218[24];
        tmp42[25] = s_Failed_to_parse_a__n_terminated_s_0007b218[25];
        tmp42[26] = s_Failed_to_parse_a__n_terminated_s_0007b218[26];
        tmp42[27] = s_Failed_to_parse_a__n_terminated_s_0007b218[27];
        tmp42[28] = s_Failed_to_parse_a__n_terminated_s_0007b218[28];
        tmp42[29] = s_Failed_to_parse_a__n_terminated_s_0007b218[29];
        tmp42[30] = s_Failed_to_parse_a__n_terminated_s_0007b218[30];
        tmp42[31] = s_Failed_to_parse_a__n_terminated_s_0007b218[31];
        tmp42[32] = s_Failed_to_parse_a__n_terminated_s_0007b218[32];
        tmp42[33] = s_Failed_to_parse_a__n_terminated_s_0007b218[33];
        tmp42[34] = s_Failed_to_parse_a__n_terminated_s_0007b218[34];
        tmp42[35] = s_Failed_to_parse_a__n_terminated_s_0007b218[35];
        tmp42[36] = s_Failed_to_parse_a__n_terminated_s_0007b218[36];
        tmp42[37] = s_Failed_to_parse_a__n_terminated_s_0007b218[37];
        tmp42[38] = s_Failed_to_parse_a__n_terminated_s_0007b218[38];
        tmp42[39] = s_Failed_to_parse_a__n_terminated_s_0007b218[39];
        tmp42[40] = s_Failed_to_parse_a__n_terminated_s_0007b218[40];
        tmp42[41] = s_Failed_to_parse_a__n_terminated_s_0007b218[41];
        tmp42[42] = s_Failed_to_parse_a__n_terminated_s_0007b218[42];
        tmp42[43] = s_Failed_to_parse_a__n_terminated_s_0007b218[43];
        tmp42[44] = s_Failed_to_parse_a__n_terminated_s_0007b218[44];
        tmp42[45] = s_Failed_to_parse_a__n_terminated_s_0007b218[45];
        tmp42[46] = s_Failed_to_parse_a__n_terminated_s_0007b218[46];
        tmp42[47] = s_Failed_to_parse_a__n_terminated_s_0007b218[47];
        tmp42[48] = s_Failed_to_parse_a__n_terminated_s_0007b218[48];
        tmp42[49] = s_Failed_to_parse_a__n_terminated_s_0007b218[49];
        tmp42[50] = s_Failed_to_parse_a__n_terminated_s_0007b218[50];
        tmp42[51] = s_Failed_to_parse_a__n_terminated_s_0007b218[51];
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

