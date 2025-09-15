
int hash_pop(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *__format;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  timespec local_828;
  int local_820;
  int local_81c;
  char local_818 [36];
  uint local_7f4;
  char acStack_7f0 [2008];
  
  iVar2 = pthread_mutex_lock(stgd_lock);
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar9 = 0x1f95;
    goto LAB_00022fb0;
  }
  if ((staged_work == 0) || (*(int *)(*(int *)(staged_work + 0x158) + 0xc) == 0)) {
    if (param_1 != 0) {
      do {
        cgtime(&local_820);
        local_828.tv_nsec = local_81c * 1000;
        local_828.tv_sec = local_820 + 10;
        pthread_cond_signal((pthread_cond_t *)gws_cond);
        iVar2 = pthread_cond_timedwait((pthread_cond_t *)(getq + 0x28),stgd_lock,&local_828);
        if (((iVar2 != 0) && (no_work == '\0')) &&
           ((no_work = '\x01', use_syslog != '\0' ||
            ((opt_log_output != '\0' || (3 < opt_log_level)))))) {
          builtin_strncpy(local_818,"Waiting for work to be available fro",0x24);
          local_7f4._0_1_ = 'm';
          local_7f4._1_1_ = ' ';
          local_7f4._2_1_ = 'p';
          local_7f4._3_1_ = 'o';
          builtin_strncpy(acStack_7f0,"ols.",4);
          acStack_7f0[4] = 0;
          _applog(4,local_818,0);
        }
      } while ((staged_work == 0) || (*(int *)(*(int *)(staged_work + 0x158) + 0xc) == 0));
      goto LAB_00022db8;
    }
  }
  else {
LAB_00022db8:
    if (no_work == '\0') {
LAB_00022dc4:
      puVar6 = *(undefined4 **)(staged_work + 0x158);
      param_1 = staged_work;
      if ((int)puVar6[3] <= staged_rollable) {
        iVar2 = *(int *)(staged_work + 0x160);
        goto LAB_00022ddc;
      }
      iVar2 = *(int *)(staged_work + 0x160);
      if ((*(char *)(staged_work + 0x111) == '\0') && (*(int *)(staged_work + 0x114) != 0)) {
        do {
          param_1 = iVar2;
          if (param_1 == 0) goto LAB_00022f44;
          iVar2 = *(int *)(param_1 + 0x160);
        } while ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0));
        goto LAB_00022ddc;
      }
      iVar7 = *(int *)(staged_work + 0x15c);
      if (iVar7 == 0) goto LAB_00022f5a;
LAB_00022de6:
      iVar3 = param_1 + 0x158;
      iVar4 = puVar6[5] + iVar7;
      if (param_1 == puVar6[4] - puVar6[5]) {
        puVar6[4] = iVar4;
      }
      *(int *)(iVar4 + 8) = iVar2;
      iVar2 = *(int *)(param_1 + 0x160);
      iVar4 = staged_work;
      if (iVar2 != 0) {
LAB_00022e04:
        iVar4 = staged_work;
        *(int *)(iVar2 + *(int *)(*(int *)(staged_work + 0x158) + 0x14) + 4) = iVar7;
      }
      piVar5 = *(int **)(iVar4 + 0x158);
      iVar4 = *piVar5;
      iVar7 = (*(uint *)(param_1 + 0x174) & piVar5[1] - 1U) * 0xc;
      iVar8 = *(int *)(iVar4 + iVar7);
      *(int *)(iVar4 + iVar7 + 4) = *(int *)(iVar4 + iVar7 + 4) + -1;
      iVar2 = *(int *)(param_1 + 0x168);
      if (iVar8 == iVar3) {
        *(int *)(iVar4 + iVar7) = iVar2;
      }
      iVar7 = *(int *)(param_1 + 0x164);
      if (iVar7 != 0) {
        *(int *)(iVar7 + 0x10) = iVar2;
        iVar2 = *(int *)(param_1 + 0x168);
      }
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0xc) = iVar7;
      }
      piVar5[3] = piVar5[3] + -1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        builtin_strncpy(local_818,"Work available from pools, resuming.",0x24);
        local_7f4 = local_7f4 & 0xffffff00;
        _applog(4,local_818,0);
      }
      no_work = '\0';
      if (staged_work != 0) goto LAB_00022dc4;
      iVar2 = iRam00000160;
      puVar6 = puRam00000158;
      param_1 = staged_work;
      if (staged_rollable < 0) {
LAB_00022f44:
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0x22f4a);
        (*pcVar1)();
      }
LAB_00022ddc:
      iVar7 = *(int *)(param_1 + 0x15c);
      if (iVar7 != 0) goto LAB_00022de6;
LAB_00022f5a:
      if (iVar2 != 0) {
        iVar3 = param_1 + 0x158;
        staged_work = iVar2;
        if (param_1 == puVar6[4] - puVar6[5]) {
          puVar6[4] = puVar6[5];
        }
        goto LAB_00022e04;
      }
      free((void *)*puVar6);
      free(*(void **)(staged_work + 0x158));
      staged_work = iVar2;
    }
    if ((*(char *)(param_1 + 0x111) == '\0') && (*(int *)(param_1 + 0x114) != 0)) {
      staged_rollable = staged_rollable + -1;
    }
    pthread_cond_signal((pthread_cond_t *)gws_cond);
    pthread_cond_signal((pthread_cond_t *)(getq + 0x28));
    last_getwork = time((time_t *)0x0);
  }
  iVar2 = pthread_mutex_unlock(stgd_lock);
  if (iVar2 == 0) {
    (*selective_yield)();
    return param_1;
  }
  piVar5 = __errno_location();
  iVar2 = *piVar5;
  __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  uVar9 = 0x1fdd;
LAB_00022fb0:
  snprintf(local_818,0x800,__format,iVar2,"cgminer.c","hash_pop",uVar9);
  _applog(3,local_818,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

