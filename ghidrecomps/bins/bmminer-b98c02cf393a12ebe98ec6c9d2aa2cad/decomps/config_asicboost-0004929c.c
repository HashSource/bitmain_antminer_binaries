
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 config_asicboost(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  void *__ptr;
  int *piVar9;
  int *piVar10;
  undefined4 *__ptr_00;
  char *__s;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 local_2920;
  undefined4 local_291c;
  undefined local_2918;
  undefined4 local_2914 [23];
  undefined auStack_28b8 [160];
  undefined4 local_2818;
  undefined4 uStack_2814;
  undefined4 uStack_2810;
  undefined4 uStack_280c;
  undefined4 local_2808;
  undefined4 uStack_2804;
  undefined4 uStack_2800;
  undefined4 uStack_27fc;
  undefined4 local_27f8;
  undefined4 local_27f4;
  undefined4 uStack_27f0;
  undefined4 uStack_27ec;
  undefined2 uStack_27e8;
  undefined local_27e6;
  char acStack_2018 [8196];
  
  local_291c = 0;
  local_2920 = 0x30;
  local_2918 = 0;
  iVar7 = setup_stratum_socket();
  if (iVar7 == 0) {
    return 0;
  }
  clear_sock(param_1);
  iVar7 = swork_id;
  swork_id = swork_id + 1;
  sprintf(acStack_2018,
          "{\"id\":%d, \"method\":\"mining.configure\", \"params\":[[\"version-rolling\"],{\"version-rolling.mask\":\"ffffffff\",\"version-rolling.min-bit-count\":%d}]}"
          ,iVar7,2);
  sVar8 = strlen(acStack_2018);
  iVar7 = __stratum_send(param_1,acStack_2018,sVar8);
  if (iVar7 != 0) {
    if (opt_debug == '\0') {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return 0;
    }
    local_2818._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[0];
    local_2818._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[1];
    local_2818._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[2];
    local_2818._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[3];
    uStack_2814._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[4];
    uStack_2814._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[5];
    uStack_2814._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[6];
    uStack_2814._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[7];
    uStack_2810._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[8];
    uStack_2810._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[9];
    uStack_2810._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[10];
    uStack_2810._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[11];
    uStack_280c._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[12];
    uStack_280c._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[13];
    uStack_280c._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[14];
    uStack_280c._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[15];
    local_2808._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[16];
    local_2808._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[17];
    local_2808._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[18];
    local_2808._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[19];
    uStack_2804._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[20];
    uStack_2804._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[21];
    uStack_2804._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[22];
    uStack_2804._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[23];
    uStack_2800._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[24];
    uStack_2800._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[25];
    uStack_2800._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[26];
    uStack_2800._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[27];
    uStack_27fc._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[28];
    uStack_27fc._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[29];
    uStack_27fc._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[30];
    uStack_27fc._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[31];
    local_27f8._0_1_ = s_Failed_to_send_s_in_initiate_str_00067988[32];
    local_27f8._1_1_ = s_Failed_to_send_s_in_initiate_str_00067988[33];
    local_27f8._2_1_ = s_Failed_to_send_s_in_initiate_str_00067988[34];
    local_27f8._3_1_ = s_Failed_to_send_s_in_initiate_str_00067988[35];
    local_27f4 = CONCAT31(local_27f4._1_3_,(char)ram0x000679ac);
    _applog(7,&local_2818,0);
    return 0;
  }
  iVar7 = socket_full_isra_2(*(undefined4 *)(param_1 + 0x24c),0x3c);
  if (iVar7 == 0) {
    if (opt_debug == '\0') {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return 0;
    }
    local_2818._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[0];
    local_2818._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[1];
    local_2818._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[2];
    local_2818._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[3];
    uStack_2814._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[4];
    uStack_2814._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[5];
    uStack_2814._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[6];
    uStack_2814._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[7];
    uStack_2810._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[8];
    uStack_2810._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[9];
    uStack_2810._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[10];
    uStack_2810._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[11];
    uStack_280c._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[12];
    uStack_280c._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[13];
    uStack_280c._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[14];
    uStack_280c._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[15];
    local_2808._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[16];
    local_2808._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[17];
    local_2808._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[18];
    local_2808._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[19];
    uStack_2804._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[20];
    uStack_2804._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[21];
    uStack_2804._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[22];
    uStack_2804._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[23];
    uStack_2800._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[24];
    uStack_2800._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[25];
    uStack_2800._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[26];
    uStack_2800._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[27];
    uStack_27fc._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[28];
    uStack_27fc._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[29];
    uStack_27fc._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[30];
    uStack_27fc._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[31];
    local_27f8._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[32];
    local_27f8._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[33];
    local_27f8._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[34];
    local_27f8._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[35];
    local_27f4._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[36];
    local_27f4._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[37];
    local_27f4._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[38];
    local_27f4._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[39];
    uStack_27f0._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[40];
    uStack_27f0._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[41];
    uStack_27f0._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[42];
    uStack_27f0._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[43];
    uStack_27ec._0_1_ = s_Timed_out_waiting_for_response_i_000679b0[44];
    uStack_27ec._1_1_ = s_Timed_out_waiting_for_response_i_000679b0[45];
    uStack_27ec._2_1_ = s_Timed_out_waiting_for_response_i_000679b0[46];
    uStack_27ec._3_1_ = s_Timed_out_waiting_for_response_i_000679b0[47];
    uStack_27e8 = (undefined2)ram0x000679e0;
    local_27e6 = (undefined)((uint)ram0x000679e0 >> 0x10);
    _applog(7,&local_2818,0);
    return 0;
  }
  __ptr = (void *)recv_line(param_1);
  if (__ptr == (void *)0x0) {
    return 0;
  }
  iVar7 = json_loads(__ptr,0,local_2914);
  free(__ptr);
  if (iVar7 == 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return 0;
    }
    snprintf((char *)&local_2818,0x800,"JSON decode failed(%d): %s",local_2914[0],auStack_28b8);
    _applog(6,&local_2818,0);
    return 0;
  }
  piVar9 = (int *)json_object_get(iVar7,"result");
  piVar10 = (int *)json_object_get(iVar7,"error");
  if ((piVar9 == (int *)0x0) || (*piVar9 == 7)) {
    if (piVar10 != (int *)0x0) goto LAB_00049426;
    __ptr_00 = (undefined4 *)malloc(0x11);
    uVar6 = ram0x0005e28c;
    uVar5 = s__unknown_reason__0005e27c._12_4_;
    uVar4 = s__unknown_reason__0005e27c._8_4_;
    uVar15 = s__unknown_reason__0005e27c._4_4_;
    if (__ptr_00 != (undefined4 *)0x0) {
      *__ptr_00 = s__unknown_reason__0005e27c._0_4_;
      __ptr_00[1] = uVar15;
      __ptr_00[2] = uVar4;
      __ptr_00[3] = uVar5;
      *(char *)(__ptr_00 + 4) = (char)uVar6;
    }
  }
  else {
    if ((piVar10 == (int *)0x0) || (*piVar10 == 7)) {
      json_object_get(piVar9,"version-rolling.mask");
      __s = (char *)json_string_value();
      sVar8 = strlen(__s);
      if (0 < (int)sVar8) {
        pcVar11 = (char *)((int)&local_291c + (3 - sVar8));
        pcVar13 = __s + -1;
        do {
          pcVar13 = pcVar13 + 1;
          pcVar11 = pcVar11 + 1;
          *pcVar11 = *pcVar13;
        } while (pcVar13 != __s + (sVar8 - 1));
      }
      uVar16 = 0;
      local_2918 = 0;
      hex2bin(param_1 + 0x28c,&local_2920,4);
      bVar3 = false;
      uVar14 = 0;
      do {
        uVar2 = uVar14 & 0xff;
        uVar1 = uVar14 & 0xff;
        uVar14 = uVar14 + 1;
        if ((*(uint *)(param_1 + 0x28c) >> uVar2 & 1) != 0) {
          uVar16 = uVar16 | 1 << uVar1;
          if (bVar3) break;
          bVar3 = true;
        }
      } while (uVar14 != 0x20);
      uVar15 = 1;
      *(uint *)(param_1 + 0x28c) = uVar16;
      opt_multi_version = 1;
      *(undefined4 *)(param_1 + 0x288) = 4;
      goto LAB_00049494;
    }
LAB_00049426:
    __ptr_00 = (undefined4 *)json_dumps(piVar10,3);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
    snprintf((char *)&local_2818,0x800,"JSON-RPC decode failed: %s",__ptr_00);
    _applog(5,&local_2818,0);
  }
  uVar15 = 0;
  free(__ptr_00);
  opt_multi_version = 1;
  *(undefined4 *)(param_1 + 0x28c) = 0xc000;
  *(undefined4 *)(param_1 + 0x288) = 4;
LAB_00049494:
  if (*(int *)(iVar7 + 4) == -1) {
    return uVar15;
  }
  iVar12 = *(int *)(iVar7 + 4) + -1;
  *(int *)(iVar7 + 4) = iVar12;
  if (iVar12 == 0) {
    json_delete(iVar7);
    return uVar15;
  }
  return uVar15;
}

