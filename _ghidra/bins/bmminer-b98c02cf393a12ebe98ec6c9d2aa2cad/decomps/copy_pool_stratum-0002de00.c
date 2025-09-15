
void copy_pool_stratum(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  size_t __nmemb;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  char local_828 [44];
  ushort local_7fc;
  undefined1 local_7fa;
  
  if (param_2[0xa8] == 0) {
    return;
  }
  iVar10 = param_2[0x1ab];
  __nmemb = param_2[0x189];
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","copy_pool_stratum",0x40b4);
    _applog(3,local_828,1);
    _quit(1);
  }
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf(local_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","copy_pool_stratum",0x40b4);
    _applog(3,local_828,1);
    _quit(1);
  }
  free((void *)param_1[0xa8]);
  free((void *)param_1[0x99]);
  free((void *)param_1[0x188]);
  if ((__nmemb & 3) != 0) {
    __nmemb = (__nmemb & 0xfffffffc) + 4;
  }
  pvVar2 = calloc(__nmemb,1);
  param_1[0x188] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    builtin_strncpy(local_828,"Failed to calloc pool_stratum coinbase in c5",0x2c);
    local_7fc = local_7fc & 0xff00;
    _applog(3,local_828,1);
    _quit(1);
    pvVar2 = (void *)param_1[0x188];
  }
  memcpy(pvVar2,(void *)param_2[0x188],__nmemb);
  if (0 < (int)param_1[0x1ab]) {
    iVar1 = 0;
    do {
      iVar12 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      free(*(void **)(param_1[0xa9] + iVar12));
    } while (iVar1 < (int)param_1[0x1ab]);
  }
  if (iVar10 != 0) {
    pvVar2 = realloc((void *)param_1[0xa9],iVar10 * 4 + 1);
    param_1[0xa9] = pvVar2;
    if (0 < iVar10) {
      iVar1 = 0;
      while( true ) {
        iVar12 = iVar1 * 4;
        pvVar4 = malloc(0x20);
        *(void **)((int)pvVar2 + iVar1 * 4) = pvVar4;
        puVar9 = *(undefined4 **)(param_1[0xa9] + iVar1 * 4);
        if (puVar9 == (undefined4 *)0x0) {
          builtin_strncpy(local_828,"Failed to malloc pool_stratum swork merkle_b",0x2c);
          local_7fc = 0x6e69;
          local_7fa = 0;
          _applog(3,local_828,1);
          _quit(1);
          puVar9 = *(undefined4 **)(param_1[0xa9] + iVar1 * 4);
        }
        iVar1 = iVar1 + 1;
        puVar8 = *(undefined4 **)(param_2[0xa9] + iVar12);
        uVar7 = puVar8[1];
        uVar3 = puVar8[2];
        uVar6 = puVar8[3];
        *puVar9 = *puVar8;
        puVar9[1] = uVar7;
        puVar9[2] = uVar3;
        puVar9[3] = uVar6;
        uVar7 = puVar8[5];
        uVar3 = puVar8[6];
        uVar6 = puVar8[7];
        puVar9[4] = puVar8[4];
        puVar9[5] = uVar7;
        puVar9[6] = uVar3;
        puVar9[7] = uVar6;
        if (iVar10 == iVar1) break;
        pvVar2 = (void *)param_1[0xa9];
      }
    }
  }
  uVar11 = param_2[0x1c8];
  uVar13 = param_2[0x1c9];
  uVar3 = param_2[0x189];
  uVar6 = param_2[0x18a];
  *param_1 = *param_2;
  uVar7 = param_2[0x9e];
  param_1[0x1c8] = uVar11;
  param_1[0x1c9] = uVar13;
  uVar11 = param_2[0x1ab];
  param_1[0x18a] = uVar6;
  param_1[0x9e] = uVar7;
  param_1[0x1ab] = uVar11;
  param_1[0x189] = uVar3;
  uVar3 = __strdup(param_2[0xa8]);
  param_1[0xa8] = uVar3;
  uVar3 = __strdup(param_2[0x99]);
  param_1[0x99] = uVar3;
  uVar3 = param_2[0x1c4];
  uVar6 = param_2[0x1c5];
  param_1[0x1c3] = param_2[0x1c3];
  param_1[0x1c4] = uVar3;
  param_1[0x1c5] = uVar6;
  memcpy(param_1 + 0x18b,param_2 + 0x18b,0x80);
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf(local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","copy_pool_stratum",0x40da);
    _applog(3,local_828,1);
    _quit(1);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c","copy_pool_stratum",0x40da);
    _applog(3,local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  return;
}

