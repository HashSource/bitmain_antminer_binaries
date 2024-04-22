
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined2 local_7fc;
  undefined local_7fa;
  
  if (param_2[0xa8] == 0) {
    return;
  }
  iVar10 = param_2[0x1ab];
  __nmemb = param_2[0x189];
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c",DAT_0002e144,0x40b4);
    _applog(3,&local_828,1);
    _quit(1);
  }
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_1 + 0x3b));
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c",DAT_0002e144,0x40b4);
    _applog(3,&local_828,1);
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
    local_828._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[0];
    local_828._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[1];
    local_828._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[2];
    local_828._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[3];
    uStack_824._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[4];
    uStack_824._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[5];
    uStack_824._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[6];
    uStack_824._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[7];
    uStack_820._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[8];
    uStack_820._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[9];
    uStack_820._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[10];
    uStack_820._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[11];
    uStack_81c._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[12];
    uStack_81c._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[13];
    uStack_81c._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[14];
    uStack_81c._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[15];
    local_818._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[16];
    local_818._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[17];
    local_818._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[18];
    local_818._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[19];
    uStack_814._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[20];
    uStack_814._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[21];
    uStack_814._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[22];
    uStack_814._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[23];
    uStack_810._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[24];
    uStack_810._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[25];
    uStack_810._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[26];
    uStack_810._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[27];
    uStack_80c._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[28];
    uStack_80c._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[29];
    uStack_80c._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[30];
    uStack_80c._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[31];
    local_808._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[32];
    local_808._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[33];
    local_808._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[34];
    local_808._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[35];
    uStack_804._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[36];
    uStack_804._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[37];
    uStack_804._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[38];
    uStack_804._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[39];
    uStack_800._0_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[40];
    uStack_800._1_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[41];
    uStack_800._2_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[42];
    uStack_800._3_1_ = s_Failed_to_calloc_pool_stratum_co_000621d0[43];
    local_7fc = CONCAT11(local_7fc._1_1_,(char)ram0x000621fc);
    _applog(3,&local_828,1);
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
          local_828._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[0];
          local_828._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[1];
          local_828._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[2];
          local_828._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[3];
          uStack_824._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[4];
          uStack_824._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[5];
          uStack_824._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[6];
          uStack_824._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[7];
          uStack_820._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[8];
          uStack_820._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[9];
          uStack_820._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[10];
          uStack_820._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[11];
          uStack_81c._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[12];
          uStack_81c._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[13];
          uStack_81c._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[14];
          uStack_81c._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[15];
          local_818._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[16];
          local_818._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[17];
          local_818._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[18];
          local_818._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[19];
          uStack_814._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[20];
          uStack_814._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[21];
          uStack_814._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[22];
          uStack_814._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[23];
          uStack_810._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[24];
          uStack_810._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[25];
          uStack_810._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[26];
          uStack_810._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[27];
          uStack_80c._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[28];
          uStack_80c._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[29];
          uStack_80c._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[30];
          uStack_80c._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[31];
          local_808._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[32];
          local_808._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[33];
          local_808._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[34];
          local_808._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[35];
          uStack_804._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[36];
          uStack_804._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[37];
          uStack_804._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[38];
          uStack_804._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[39];
          uStack_800._0_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[40];
          uStack_800._1_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[41];
          uStack_800._2_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[42];
          uStack_800._3_1_ = s_Failed_to_malloc_pool_stratum_sw_00062200[43];
          local_7fc = (undefined2)ram0x0006222c;
          local_7fa = (undefined)((uint)ram0x0006222c >> 0x10);
          _applog(3,&local_828,1);
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
  uVar3 = DAT_0002e144;
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c",uVar3,0x40da);
    _applog(3,&local_828,1);
    _quit(1);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
  uVar3 = DAT_0002e144;
  if (iVar1 != 0) {
    piVar5 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar5,
             "driver-btm-c5.c",uVar3,0x40da);
    _applog(3,&local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  return;
}

