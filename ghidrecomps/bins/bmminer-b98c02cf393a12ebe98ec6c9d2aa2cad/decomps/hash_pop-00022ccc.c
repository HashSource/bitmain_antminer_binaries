
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hash_pop(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  char *__format;
  void **ppvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  timespec local_828;
  int local_820;
  int local_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined4 local_7f4;
  undefined4 uStack_7f0;
  undefined local_7ec;
  
  iVar1 = pthread_mutex_lock(stgd_lock);
  if (iVar1 != 0) {
    piVar4 = __errno_location();
    iVar1 = *piVar4;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar10 = 0x1f95;
    uVar9 = DAT_00023010;
    goto LAB_00022fb0;
  }
  if ((staged_work == 0) || (*(int *)(*(int *)(staged_work + 0x158) + 0xc) == 0)) {
    if (param_1 != 0) {
      do {
        cgtime(&local_820);
        local_828.tv_nsec = local_81c * 1000;
        local_828.tv_sec = local_820 + 10;
        pthread_cond_signal((pthread_cond_t *)gws_cond);
        iVar1 = pthread_cond_timedwait((pthread_cond_t *)(getq + 0x28),stgd_lock,&local_828);
        if (((iVar1 != 0) && (no_work == '\0')) &&
           ((no_work = '\x01', use_syslog != '\0' ||
            ((opt_log_output != '\0' || (3 < opt_log_level)))))) {
          local_818._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[0];
          local_818._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[1];
          local_818._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[2];
          local_818._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[3];
          uStack_814._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[4];
          uStack_814._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[5];
          uStack_814._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[6];
          uStack_814._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[7];
          uStack_810._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[8];
          uStack_810._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[9];
          uStack_810._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[10];
          uStack_810._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[11];
          uStack_80c._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[12];
          uStack_80c._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[13];
          uStack_80c._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[14];
          uStack_80c._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[15];
          local_808._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[16];
          local_808._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[17];
          local_808._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[18];
          local_808._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[19];
          uStack_804._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[20];
          uStack_804._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[21];
          uStack_804._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[22];
          uStack_804._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[23];
          uStack_800._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[24];
          uStack_800._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[25];
          uStack_800._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[26];
          uStack_800._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[27];
          uStack_7fc._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[28];
          uStack_7fc._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[29];
          uStack_7fc._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[30];
          uStack_7fc._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[31];
          local_7f8._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[32];
          local_7f8._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[33];
          local_7f8._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[34];
          local_7f8._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[35];
          local_7f4._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[36];
          local_7f4._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[37];
          local_7f4._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[38];
          local_7f4._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[39];
          uStack_7f0._0_1_ = s_Waiting_for_work_to_be_available_0005d7d4[40];
          uStack_7f0._1_1_ = s_Waiting_for_work_to_be_available_0005d7d4[41];
          uStack_7f0._2_1_ = s_Waiting_for_work_to_be_available_0005d7d4[42];
          uStack_7f0._3_1_ = s_Waiting_for_work_to_be_available_0005d7d4[43];
          local_7ec = (undefined)ram0x0005d800;
          _applog(4,&local_818,0);
        }
      } while ((staged_work == 0) || (*(int *)(*(int *)(staged_work + 0x158) + 0xc) == 0));
      goto LAB_00022db8;
    }
  }
  else {
LAB_00022db8:
    if (no_work == '\0') {
LAB_00022dc4:
      ppvVar5 = *(void ***)(staged_work + 0x158);
      param_1 = staged_work;
      if ((int)ppvVar5[3] <= staged_rollable) {
        iVar1 = *(int *)(staged_work + 0x160);
        goto LAB_00022ddc;
      }
      iVar1 = *(int *)(staged_work + 0x160);
      if ((*(char *)(staged_work + 0x111) == '\0') && (*(int *)(staged_work + 0x114) != 0)) {
        do {
          param_1 = iVar1;
          if (param_1 == 0) goto LAB_00022f44;
          iVar1 = *(int *)(param_1 + 0x160);
        } while ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0));
        goto LAB_00022ddc;
      }
      iVar6 = *(int *)(staged_work + 0x15c);
      if (iVar6 == 0) goto LAB_00022f5a;
LAB_00022de6:
      iVar2 = param_1 + 0x158;
      pvVar3 = (void *)((int)ppvVar5[5] + iVar6);
      if (param_1 == (int)ppvVar5[4] - (int)ppvVar5[5]) {
        ppvVar5[4] = pvVar3;
      }
      *(int *)((int)pvVar3 + 8) = iVar1;
      iVar1 = *(int *)(param_1 + 0x160);
      iVar7 = staged_work;
      if (iVar1 != 0) {
LAB_00022e04:
        iVar7 = staged_work;
        *(int *)(iVar1 + *(int *)(*(int *)(staged_work + 0x158) + 0x14) + 4) = iVar6;
      }
      piVar4 = *(int **)(iVar7 + 0x158);
      iVar7 = *piVar4;
      iVar6 = (*(uint *)(param_1 + 0x174) & piVar4[1] - 1U) * 0xc;
      iVar8 = *(int *)(iVar7 + iVar6);
      *(int *)(iVar7 + iVar6 + 4) = *(int *)(iVar7 + iVar6 + 4) + -1;
      iVar1 = *(int *)(param_1 + 0x168);
      if (iVar8 == iVar2) {
        *(int *)(iVar7 + iVar6) = iVar1;
      }
      iVar6 = *(int *)(param_1 + 0x164);
      if (iVar6 != 0) {
        *(int *)(iVar6 + 0x10) = iVar1;
        iVar1 = *(int *)(param_1 + 0x168);
      }
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0xc) = iVar6;
      }
      piVar4[3] = piVar4[3] + -1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        local_818._0_1_ = s_Work_available_from_pools__resum_0005d804[0];
        local_818._1_1_ = s_Work_available_from_pools__resum_0005d804[1];
        local_818._2_1_ = s_Work_available_from_pools__resum_0005d804[2];
        local_818._3_1_ = s_Work_available_from_pools__resum_0005d804[3];
        uStack_814._0_1_ = s_Work_available_from_pools__resum_0005d804[4];
        uStack_814._1_1_ = s_Work_available_from_pools__resum_0005d804[5];
        uStack_814._2_1_ = s_Work_available_from_pools__resum_0005d804[6];
        uStack_814._3_1_ = s_Work_available_from_pools__resum_0005d804[7];
        uStack_810._0_1_ = s_Work_available_from_pools__resum_0005d804[8];
        uStack_810._1_1_ = s_Work_available_from_pools__resum_0005d804[9];
        uStack_810._2_1_ = s_Work_available_from_pools__resum_0005d804[10];
        uStack_810._3_1_ = s_Work_available_from_pools__resum_0005d804[11];
        uStack_80c._0_1_ = s_Work_available_from_pools__resum_0005d804[12];
        uStack_80c._1_1_ = s_Work_available_from_pools__resum_0005d804[13];
        uStack_80c._2_1_ = s_Work_available_from_pools__resum_0005d804[14];
        uStack_80c._3_1_ = s_Work_available_from_pools__resum_0005d804[15];
        local_808._0_1_ = s_Work_available_from_pools__resum_0005d804[16];
        local_808._1_1_ = s_Work_available_from_pools__resum_0005d804[17];
        local_808._2_1_ = s_Work_available_from_pools__resum_0005d804[18];
        local_808._3_1_ = s_Work_available_from_pools__resum_0005d804[19];
        uStack_804._0_1_ = s_Work_available_from_pools__resum_0005d804[20];
        uStack_804._1_1_ = s_Work_available_from_pools__resum_0005d804[21];
        uStack_804._2_1_ = s_Work_available_from_pools__resum_0005d804[22];
        uStack_804._3_1_ = s_Work_available_from_pools__resum_0005d804[23];
        uStack_800._0_1_ = s_Work_available_from_pools__resum_0005d804[24];
        uStack_800._1_1_ = s_Work_available_from_pools__resum_0005d804[25];
        uStack_800._2_1_ = s_Work_available_from_pools__resum_0005d804[26];
        uStack_800._3_1_ = s_Work_available_from_pools__resum_0005d804[27];
        uStack_7fc._0_1_ = s_Work_available_from_pools__resum_0005d804[28];
        uStack_7fc._1_1_ = s_Work_available_from_pools__resum_0005d804[29];
        uStack_7fc._2_1_ = s_Work_available_from_pools__resum_0005d804[30];
        uStack_7fc._3_1_ = s_Work_available_from_pools__resum_0005d804[31];
        local_7f8._0_1_ = s_Work_available_from_pools__resum_0005d804[32];
        local_7f8._1_1_ = s_Work_available_from_pools__resum_0005d804[33];
        local_7f8._2_1_ = s_Work_available_from_pools__resum_0005d804[34];
        local_7f8._3_1_ = s_Work_available_from_pools__resum_0005d804[35];
        local_7f4._0_1_ = (char)ram0x0005d828;
        _applog(4,&local_818,0);
      }
      no_work = '\0';
      if (staged_work != 0) goto LAB_00022dc4;
      iVar1 = iRam00000160;
      ppvVar5 = ppvRam00000158;
      param_1 = staged_work;
      if (staged_rollable < 0) {
LAB_00022f44:
                    /* WARNING: Treating indirect jump as call */
        UNRECOVERED_JUMPTABLE = (code *)software_udf(0xff,0x22f4a);
        iVar1 = (*UNRECOVERED_JUMPTABLE)();
        return iVar1;
      }
LAB_00022ddc:
      iVar6 = *(int *)(param_1 + 0x15c);
      if (iVar6 != 0) goto LAB_00022de6;
LAB_00022f5a:
      if (iVar1 != 0) {
        iVar2 = param_1 + 0x158;
        staged_work = iVar1;
        if (param_1 == (int)ppvVar5[4] - (int)ppvVar5[5]) {
          ppvVar5[4] = ppvVar5[5];
        }
        goto LAB_00022e04;
      }
      free(*ppvVar5);
      free(*(void **)(staged_work + 0x158));
      staged_work = iVar1;
    }
    if ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0)) {
      staged_rollable = staged_rollable + -1;
    }
    pthread_cond_signal((pthread_cond_t *)gws_cond);
    pthread_cond_signal((pthread_cond_t *)(getq + 0x28));
    last_getwork = time((time_t *)0x0);
  }
  iVar1 = pthread_mutex_unlock(stgd_lock);
  uVar9 = DAT_00023010;
  if (iVar1 == 0) {
    (*selective_yield)();
    return param_1;
  }
  piVar4 = __errno_location();
  iVar1 = *piVar4;
  __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  uVar10 = 0x1fdd;
LAB_00022fb0:
  snprintf((char *)&local_818,0x800,__format,iVar1,"cgminer.c",uVar9,uVar10);
  _applog(3,&local_818,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

