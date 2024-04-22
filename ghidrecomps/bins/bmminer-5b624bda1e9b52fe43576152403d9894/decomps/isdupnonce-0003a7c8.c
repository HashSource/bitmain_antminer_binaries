
/* WARNING: Unknown calling convention */

_Bool isdupnonce(cgpu_info *cgpu,work *work,uint nonce)

{
  char *func;
  char *file;
  int iVar1;
  K_ITEM *pKVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  dupdata *dup;
  int *piVar6;
  pthread_mutex_t *ppVar7;
  K_ITEM *item;
  uint *puVar8;
  double dVar9;
  double dVar10;
  timeval now;
  char tmp42 [2048];
  
  piVar6 = (int *)cgpu->dup_data;
  if (piVar6 != (int *)0x0) {
    cgtime(&now);
    uVar4 = piVar6[4];
    ppVar7 = *(pthread_mutex_t **)(piVar6[1] + 8);
    piVar6[4] = uVar4 + 1;
    piVar6[5] = piVar6[5] + (uint)(0xfffffffe < uVar4);
    iVar1 = pthread_mutex_lock(ppVar7);
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      snprintf(tmp42,0x800,DAT_0003aa50,*piVar3,DAT_0003aa3c,DAT_0003aa38,0x46);
      _applog(3,tmp42,true);
      _quit(1);
    }
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ppVar7 + 1));
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      snprintf(tmp42,0x800,DAT_0003aa4c,*piVar3,DAT_0003aa3c,DAT_0003aa38,0x46);
      _applog(3,tmp42,true);
      _quit(1);
    }
    uVar4 = 1;
    iVar1 = *(int *)(piVar6[2] + 0x10);
    while( true ) {
      while( true ) {
        uVar5 = uVar4;
        if (iVar1 == 0) {
          uVar5 = 0;
        }
        if (uVar5 == 0) goto LAB_0003a8a8;
        if ((**(uint **)(iVar1 + 0xc) == work->id) && ((*(uint **)(iVar1 + 0xc))[1] == nonce))
        break;
        iVar1 = *(int *)(iVar1 + 4);
      }
      uVar4 = 0;
      if ((*DAT_0003aa54 != '\0') || ((*DAT_0003aa58 != '\0' || (3 < opt_log_level)))) break;
      uVar4 = 0;
    }
    snprintf(tmp42,0x800,DAT_0003aa34,cgpu->drv->name,cgpu->device_id,nonce);
    _applog(4,tmp42,false);
LAB_0003a8a8:
    if (uVar4 != 0) {
      pKVar2 = _k_unlink_head((K_LIST *)piVar6[1],DAT_0003aa3c,DAT_0003aa38,0x51);
      file = DAT_0003aa3c;
      func = DAT_0003aa38;
      puVar8 = (uint *)pKVar2->data;
      *puVar8 = work->id;
      puVar8[1] = nonce;
      puVar8[2] = now.tv_sec;
      puVar8[3] = now.tv_usec;
      _k_add_head((K_LIST *)piVar6[2],pKVar2,file,func,0x55);
    }
    iVar1 = *(int *)(piVar6[2] + 0x10);
    while (iVar1 != 0) {
      dVar9 = tdiff((timeval *)(*(int *)(iVar1 + 0xc) + 8),&now);
      dVar10 = (double)(longlong)*piVar6;
      if (dVar9 == dVar10 || dVar9 < dVar10 != (NAN(dVar9) || NAN(dVar10))) break;
      pKVar2 = _k_unlink_tail((K_LIST *)piVar6[2],DAT_0003aa3c,DAT_0003aa38,0x59);
      _k_add_head((K_LIST *)piVar6[1],pKVar2,DAT_0003aa3c,DAT_0003aa38,0x5a);
      iVar1 = *(int *)(piVar6[2] + 0x10);
    }
    ppVar7 = *(pthread_mutex_t **)(piVar6[1] + 8);
    iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(ppVar7 + 1));
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      snprintf(tmp42,0x800,DAT_0003aa48,*piVar3,DAT_0003aa3c,DAT_0003aa38,0x5d);
      _applog(3,tmp42,true);
      _quit(1);
    }
    iVar1 = pthread_mutex_unlock(ppVar7);
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      snprintf(tmp42,0x800,DAT_0003aa44,*piVar3,DAT_0003aa3c,DAT_0003aa38,0x5d);
      _applog(3,tmp42,true);
      _quit(1);
    }
    (**DAT_0003aa40)();
    if (uVar4 == 0) {
      uVar5 = piVar6[6];
      piVar6[6] = uVar5 + 1;
      piVar6[7] = piVar6[7] + (uint)(0xfffffffe < uVar5);
    }
    piVar6 = (int *)(uVar4 ^ 1);
  }
  return SUB41(piVar6,0);
}

