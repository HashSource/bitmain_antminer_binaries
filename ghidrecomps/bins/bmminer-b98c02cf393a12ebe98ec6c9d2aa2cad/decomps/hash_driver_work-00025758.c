
void hash_driver_work(undefined4 *param_1)

{
  undefined *puVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined *puVar7;
  char *__format;
  undefined *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  longlong lVar13;
  undefined4 uVar14;
  int local_838;
  int local_834;
  int iStack_830;
  int iStack_82c;
  char acStack_828 [2052];
  
  iVar9 = param_1[9];
  uVar6 = *param_1;
  lVar3 = 0;
  iVar11 = *(int *)(iVar9 + 4);
  local_838 = 0;
  local_834 = 0;
LAB_00025790:
  cVar2 = *(char *)(iVar9 + 0x16c);
  do {
    if (cVar2 != '\0') {
      *(undefined4 *)(iVar9 + 0x20) = 1;
      return;
    }
    *(undefined *)((int)param_1 + 0x3f) = 0;
    lVar13 = (**(code **)(iVar11 + 0x44))(param_1);
    *(undefined *)((int)param_1 + 0x3e) = 0;
    if ((int)((ulonglong)lVar13 >> 0x20) == -1 && (int)lVar13 == -1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_828,0x800,"%s %d failure, disabling!",*(undefined4 *)(iVar11 + 8),
                 *(undefined4 *)(iVar9 + 8));
        _applog(3,acStack_828,0);
      }
      *(undefined4 *)(iVar9 + 0x20) = 1;
      dev_error(iVar9);
      *(undefined4 *)(iVar9 + 0x20) = 1;
      return;
    }
    lVar3 = lVar13 + lVar3;
    uVar10 = (uint)((ulonglong)lVar3 >> 0x20);
    cgtime(&iStack_830);
    puVar8 = (undefined *)(iStack_82c - local_834);
    puVar7 = (undefined *)(iStack_830 - local_838);
    if ((int)puVar8 < 0) {
      puVar7 = puVar7 + -1;
      puVar8 = &DAT_000f4240 + (int)puVar8;
    }
    if (lVar3 == 0) {
LAB_0002584a:
      if (opt_log_interval <= (int)puVar7) goto LAB_000257e4;
      lVar13 = lVar3;
      if (*(char *)(param_1 + 0xf) == '\0') goto LAB_00025800;
LAB_0002585a:
      mt_disable_isra_16(param_1,uVar6,iVar11 + 0x5c);
    }
    else {
      bVar12 = puVar7 == (undefined *)0x0;
      puVar1 = puVar7;
      if ((int)puVar7 < 1) {
        puVar1 = puVar8 + -200000;
        bVar12 = puVar8 == (undefined *)0x30d40;
      }
      if (bVar12 || (int)puVar1 < 0 != ((int)puVar7 < 1 && SBORROW4((int)puVar8,200000)))
      goto LAB_0002584a;
LAB_000257e4:
      hashmeter(uVar6,(uint)lVar3 | uVar10,(uint)lVar3,uVar10);
      copy_time(&local_838,&iStack_830);
      lVar3 = 0;
      lVar13 = 0;
      if (*(char *)(param_1 + 0xf) != '\0') goto LAB_0002585a;
LAB_00025800:
      lVar3 = lVar13;
      if (*(int *)(iVar9 + 0x20) != 0) goto LAB_0002585a;
    }
    if (*(char *)((int)param_1 + 0x3f) == '\0') goto LAB_00025790;
    iVar4 = pthread_mutex_lock((pthread_mutex_t *)update_job_lock);
    if (iVar4 != 0) {
      piVar5 = __errno_location();
      iVar9 = *piVar5;
      __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar6 = 0x25bc;
      uVar14 = DAT_00025930;
LAB_000258ee:
      snprintf(acStack_828,0x800,__format,iVar9,"cgminer.c",uVar14,uVar6);
      _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
      __quit(1);
    }
    (**(code **)(iVar11 + 0x50))(iVar9);
    iVar4 = pthread_mutex_unlock((pthread_mutex_t *)update_job_lock);
    uVar14 = DAT_00025930;
    if (iVar4 != 0) {
      piVar5 = __errno_location();
      iVar9 = *piVar5;
      __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
      uVar6 = 0x25be;
      goto LAB_000258ee;
    }
    (*selective_yield)();
    cVar2 = *(char *)(iVar9 + 0x16c);
  } while( true );
}

