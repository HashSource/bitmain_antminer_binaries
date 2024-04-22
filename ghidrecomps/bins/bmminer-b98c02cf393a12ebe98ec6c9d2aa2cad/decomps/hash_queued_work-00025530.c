
void hash_queued_work(undefined4 *param_1)

{
  undefined *puVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *__format;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  pthread_rwlock_t *__rwlock;
  uint uVar12;
  bool bVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined4 local_83c;
  int local_838;
  int local_834;
  int iStack_830;
  int iStack_82c;
  char acStack_828 [2052];
  
  iVar10 = param_1[9];
  uVar7 = *param_1;
  lVar3 = 0;
  iVar11 = *(int *)(iVar10 + 4);
  local_838 = 0;
  local_834 = 0;
LAB_00025558:
  cVar2 = *(char *)(iVar10 + 0x16c);
  do {
    if (cVar2 != '\0') {
      *(undefined4 *)(iVar10 + 0x20) = 1;
      return;
    }
    *(undefined *)((int)param_1 + 0x3f) = 0;
    do {
      if (*(int *)(iVar10 + 0x164) != 0) goto LAB_00025574;
      __rwlock = (pthread_rwlock_t *)(iVar10 + 0x140);
      local_83c = get_work(param_1,uVar7);
      iVar4 = pthread_rwlock_wrlock(__rwlock);
      if (iVar4 != 0) {
        piVar5 = __errno_location();
        iVar10 = *piVar5;
        __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
        uVar15 = 0x2438;
        uVar7 = DAT_00025754;
        goto LAB_000256f6;
      }
      if (*(int *)(iVar10 + 0x164) == 0) {
        *(undefined4 *)(iVar10 + 0x164) = local_83c;
        iVar4 = pthread_rwlock_unlock(__rwlock);
        if (iVar4 != 0) {
LAB_0002572e:
          uVar7 = DAT_00025754;
          piVar5 = __errno_location();
          iVar10 = *piVar5;
          __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
          uVar15 = 0x2443;
LAB_000256f6:
          snprintf(acStack_828,0x800,__format,iVar10,"cgminer.c",uVar7,uVar15);
          _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
          __quit(1);
        }
        (*selective_yield)();
      }
      else {
        iVar4 = pthread_rwlock_unlock(__rwlock);
        if (iVar4 != 0) goto LAB_0002572e;
        (*selective_yield)();
        _discard_work(&local_83c,"cgminer.c",DAT_00025754,0x2447);
      }
LAB_00025574:
      iVar4 = (**(code **)(iVar11 + 0x48))(iVar10);
    } while (iVar4 == 0);
    lVar14 = (**(code **)(iVar11 + 0x44))(param_1);
    *(undefined *)((int)param_1 + 0x3e) = 0;
    if ((int)((ulonglong)lVar14 >> 0x20) == -1 && (int)lVar14 == -1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_828,0x800,"%s %d failure, disabling!",*(undefined4 *)(iVar11 + 8),
                 *(undefined4 *)(iVar10 + 8));
        _applog(3,acStack_828,0);
      }
      *(undefined4 *)(iVar10 + 0x20) = 1;
      dev_error(iVar10);
      *(undefined4 *)(iVar10 + 0x20) = 1;
      return;
    }
    lVar3 = lVar14 + lVar3;
    uVar12 = (uint)((ulonglong)lVar3 >> 0x20);
    cgtime(&iStack_830);
    puVar9 = (undefined *)(iStack_82c - local_834);
    puVar8 = (undefined *)(iStack_830 - local_838);
    if ((int)puVar9 < 0) {
      puVar8 = puVar8 + -1;
      puVar9 = &DAT_000f4240 + (int)puVar9;
    }
    uVar6 = (uint)lVar3 | uVar12;
    if (lVar3 == 0) {
LAB_00025616:
      if (opt_log_interval <= (int)puVar8) goto LAB_000255d0;
      lVar14 = lVar3;
      if (*(char *)(param_1 + 0xf) == '\0') goto LAB_000255f0;
LAB_0002562e:
      mt_disable_isra_16(param_1,uVar7,iVar11 + 0x5c);
    }
    else {
      uVar6 = 200000;
      bVar13 = puVar8 == (undefined *)0x0;
      puVar1 = puVar8;
      if ((int)puVar8 < 1) {
        puVar1 = puVar9 + -200000;
        bVar13 = puVar9 == (undefined *)0x30d40;
      }
      if (bVar13 || (int)puVar1 < 0 != ((int)puVar8 < 1 && SBORROW4((int)puVar9,200000)))
      goto LAB_00025616;
LAB_000255d0:
      hashmeter(uVar7,uVar6,(uint)lVar3,uVar12);
      copy_time(&local_838,&iStack_830);
      lVar3 = 0;
      lVar14 = 0;
      if (*(char *)(param_1 + 0xf) != '\0') goto LAB_0002562e;
LAB_000255f0:
      lVar3 = lVar14;
      if (*(int *)(iVar10 + 0x20) != 0) goto LAB_0002562e;
    }
    if (*(char *)((int)param_1 + 0x3f) == '\0') goto LAB_00025558;
    (**(code **)(iVar11 + 0x50))(iVar10);
    cVar2 = *(char *)(iVar10 + 0x16c);
  } while( true );
}

