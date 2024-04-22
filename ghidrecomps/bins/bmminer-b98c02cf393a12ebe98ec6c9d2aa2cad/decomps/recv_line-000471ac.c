
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * recv_line(int param_1)

{
  double dVar1;
  char cVar2;
  char *pcVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  ssize_t sVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  char *__s;
  uint uVar11;
  int iVar12;
  timeval local_2838;
  timeval local_2830;
  undefined4 local_2828;
  undefined4 uStack_2824;
  undefined4 uStack_2820;
  undefined4 uStack_281c;
  undefined4 local_2818;
  undefined4 uStack_2814;
  undefined4 uStack_2810;
  undefined4 uStack_280c;
  undefined2 local_2808;
  undefined local_2806;
  undefined4 local_2028;
  undefined4 uStack_2024;
  undefined4 uStack_2020;
  undefined4 uStack_201c;
  undefined4 local_2018;
  undefined4 uStack_2014;
  undefined4 uStack_2010;
  undefined4 uStack_200c;
  undefined4 local_2008;
  undefined4 uStack_2004;
  undefined4 local_2000;
  undefined4 uStack_1ffc;
  undefined4 local_1ff8;
  
  __s = *(char **)(param_1 + 0x250);
  pcVar3 = strchr(__s,10);
  if (pcVar3 == (char *)0x0) {
    gettimeofday(&local_2838,(__timezone_ptr_t)0x0);
    iVar6 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c);
    dVar1 = DAT_00047548;
    if (iVar6 == 0) {
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_2028._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[0];
        local_2028._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[1];
        local_2028._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[2];
        local_2028._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[3];
        uStack_2024._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[4];
        uStack_2024._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[5];
        uStack_2024._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[6];
        uStack_2024._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[7];
        uStack_2020._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[8];
        uStack_2020._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[9];
        uStack_2020._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[10];
        uStack_2020._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[11];
        uStack_201c._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[12];
        uStack_201c._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[13];
        uStack_201c._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[14];
        uStack_201c._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[15];
        local_2018._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[16];
        local_2018._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[17];
        local_2018._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[18];
        local_2018._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[19];
        uStack_2014._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[20];
        uStack_2014._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[21];
        uStack_2014._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[22];
        uStack_2014._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[23];
        uStack_2010._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[24];
        uStack_2010._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[25];
        uStack_2010._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[26];
        uStack_2010._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[27];
        uStack_200c._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[28];
        uStack_200c._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[29];
        uStack_200c._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[30];
        uStack_200c._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[31];
        local_2008._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[32];
        local_2008._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[33];
        local_2008._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[34];
        local_2008._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[35];
        uStack_2004._0_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[36];
        uStack_2004._1_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[37];
        uStack_2004._2_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[38];
        uStack_2004._3_1_ = s_Timed_out_waiting_for_data_on_so_0006727c[39];
        local_2000._0_2_ = (short)ram0x000672a4;
        _applog(7,&local_2028,0);
      }
      goto LAB_00047302;
    }
    while( true ) {
      memset(&local_2028,0,0x2000);
      sVar7 = recv(*(int *)(param_1 + 0x24c),&local_2028,0x1ffc,0);
      if (sVar7 == 0) break;
      gettimeofday(&local_2830,(__timezone_ptr_t)0x0);
      iVar6 = (int)(longlong)
                   ((double)(longlong)(local_2830.tv_usec - local_2838.tv_usec) / dVar1 +
                   (double)(longlong)(local_2830.tv_sec - local_2838.tv_sec));
      if (sVar7 < 0) {
        piVar8 = __errno_location();
        if ((*piVar8 != 0xb) ||
           (iVar9 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c - iVar6), iVar9 == 0))
        {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            local_2828._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[0];
            local_2828._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[1];
            local_2828._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[2];
            local_2828._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[3];
            uStack_2824._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[4];
            uStack_2824._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[5];
            uStack_2824._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[6];
            uStack_2824._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[7];
            uStack_2820._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[8];
            uStack_2820._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[9];
            uStack_2820._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[10];
            uStack_2820._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[11];
            uStack_281c._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[12];
            uStack_281c._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[13];
            uStack_281c._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[14];
            uStack_281c._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[15];
            local_2818._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[16];
            local_2818._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[17];
            local_2818._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[18];
            local_2818._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[19];
            uStack_2814._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[20];
            uStack_2814._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[21];
            uStack_2814._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[22];
            uStack_2814._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[23];
            uStack_2810._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[24];
            uStack_2810._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[25];
            uStack_2810._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[26];
            uStack_2810._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[27];
            uStack_280c._0_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[28];
            uStack_280c._1_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[29];
            uStack_280c._2_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[30];
            uStack_280c._3_1_ = s_Failed_to_recv_sock_in_recv_line_000672cc[31];
            local_2808 = CONCAT11(local_2808._1_1_,(char)ram0x000672ec);
            _applog(7,&local_2828,0);
          }
          goto LAB_0004747e;
        }
      }
      else {
        sVar4 = strlen((char *)&local_2028);
        pcVar3 = *(char **)(param_1 + 0x250);
        sVar5 = strlen(pcVar3);
        uVar10 = sVar4 + sVar5 + 1;
        if (*(uint *)(param_1 + 0x254) <= uVar10) {
          iVar12 = (uVar10 & 0xffffe000) + 0x2000;
          iVar9 = _cgrealloc(pcVar3,iVar12,"util.c",DAT_00047550,0x70b);
          *(int *)(param_1 + 0x250) = iVar9;
          memset((void *)(iVar9 + sVar5),0,iVar12 - sVar5);
          pcVar3 = *(char **)(param_1 + 0x250);
          *(int *)(param_1 + 0x254) = iVar12;
        }
        strcat(pcVar3,(char *)&local_2028);
      }
      __s = *(char **)(param_1 + 0x250);
      if ((0x3b < iVar6) || (pcVar3 = strchr(__s,10), pcVar3 != (char *)0x0)) goto LAB_000471ce;
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_2828._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[0];
      local_2828._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[1];
      local_2828._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[2];
      local_2828._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[3];
      uStack_2824._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[4];
      uStack_2824._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[5];
      uStack_2824._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[6];
      uStack_2824._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[7];
      uStack_2820._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[8];
      uStack_2820._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[9];
      uStack_2820._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[10];
      uStack_2820._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[11];
      uStack_281c._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[12];
      uStack_281c._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[13];
      uStack_281c._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[14];
      uStack_281c._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[15];
      local_2818._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[16];
      local_2818._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[17];
      local_2818._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[18];
      local_2818._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[19];
      uStack_2814._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[20];
      uStack_2814._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[21];
      uStack_2814._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[22];
      uStack_2814._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[23];
      uStack_2810._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[24];
      uStack_2810._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[25];
      uStack_2810._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[26];
      uStack_2810._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[27];
      uStack_280c._0_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[28];
      uStack_280c._1_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[29];
      uStack_280c._2_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[30];
      uStack_280c._3_1_ = s_Socket_closed_waiting_in_recv_li_000672a8[31];
      local_2808 = (undefined2)ram0x000672c8;
      local_2806 = (undefined)((uint)ram0x000672c8 >> 0x10);
      _applog(7,&local_2828,0);
    }
LAB_0004747e:
    suspend_stratum(param_1);
    __s = *(char **)(param_1 + 0x250);
  }
LAB_000471ce:
  sVar4 = strlen(__s);
  pcVar3 = strtok(__s,(char *)&DAT_00065a34);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = (char *)__strdup();
    sVar5 = strlen(pcVar3);
    if ((int)(sVar5 + 1) < (int)sVar4) {
      memmove(*(void **)(param_1 + 0x250),(void *)(sVar5 + 1 + (int)*(void **)(param_1 + 0x250)),
              (sVar4 - sVar5) + 1);
    }
    else {
      **(undefined **)(param_1 + 0x250) = 0;
    }
    cVar2 = opt_protocol;
    uVar11 = *(uint *)(param_1 + 0x208);
    uVar10 = *(uint *)(param_1 + 0x210);
    *(uint *)(param_1 + 0x208) = uVar11 + 1;
    *(uint *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + (uint)(0xfffffffe < uVar11);
    uVar11 = *(uint *)(param_1 + 0x218);
    *(uint *)(param_1 + 0x210) = uVar10 + sVar5;
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + ((int)sVar5 >> 0x1f) + (uint)CARRY4(uVar10,sVar5);
    *(uint *)(param_1 + 0x218) = sVar5 + uVar11;
    *(uint *)(param_1 + 0x21c) =
         ((int)sVar5 >> 0x1f) + *(int *)(param_1 + 0x21c) + (uint)CARRY4(sVar5,uVar11);
    if (cVar2 == '\0') {
      return pcVar3;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 5)) {
      return pcVar3;
    }
    snprintf((char *)&local_2028,0x800,"RECVD: %s",pcVar3);
    _applog(5,&local_2028,0);
    return pcVar3;
  }
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_2028._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[0];
    local_2028._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[1];
    local_2028._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[2];
    local_2028._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[3];
    uStack_2024._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[4];
    uStack_2024._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[5];
    uStack_2024._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[6];
    uStack_2024._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[7];
    uStack_2020._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[8];
    uStack_2020._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[9];
    uStack_2020._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[10];
    uStack_2020._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[11];
    uStack_201c._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[12];
    uStack_201c._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[13];
    uStack_201c._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[14];
    uStack_201c._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[15];
    local_2018._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[16];
    local_2018._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[17];
    local_2018._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[18];
    local_2018._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[19];
    uStack_2014._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[20];
    uStack_2014._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[21];
    uStack_2014._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[22];
    uStack_2014._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[23];
    uStack_2010._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[24];
    uStack_2010._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[25];
    uStack_2010._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[26];
    uStack_2010._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[27];
    uStack_200c._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[28];
    uStack_200c._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[29];
    uStack_200c._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[30];
    uStack_200c._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[31];
    local_2008._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[32];
    local_2008._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[33];
    local_2008._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[34];
    local_2008._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[35];
    uStack_2004._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[36];
    uStack_2004._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[37];
    uStack_2004._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[38];
    uStack_2004._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[39];
    local_2000._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[40];
    local_2000._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[41];
    local_2000._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[42];
    local_2000._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[43];
    uStack_1ffc._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[44];
    uStack_1ffc._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[45];
    uStack_1ffc._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[46];
    uStack_1ffc._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[47];
    local_1ff8._0_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[48];
    local_1ff8._1_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[49];
    local_1ff8._2_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[50];
    local_1ff8._3_1_ = s_Failed_to_parse_a__n_terminated_s_000672f0[51];
    _applog(7,&local_2028,0);
  }
LAB_00047302:
  clear_sock(param_1);
  return (char *)0x0;
}

