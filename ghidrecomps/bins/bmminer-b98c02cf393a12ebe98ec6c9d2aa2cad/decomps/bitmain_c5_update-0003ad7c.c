
void bitmain_c5_update(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  pthread_mutex_t *__mutex;
  undefined4 *puVar4;
  undefined4 local_830;
  void *local_82c;
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  
  __mutex = *(pthread_mutex_t **)(param_1 + 0x14);
  puVar4 = (undefined4 *)**(undefined4 **)(param_1 + 0x98);
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)((int)__mutex + 0x2a4));
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b1fc,0x4236);
    _applog(3,&local_828,1);
    _quit(1);
  }
  *(undefined *)((int)puVar4 + 0x3f) = 0;
  *(undefined *)((int)puVar4 + 0x3e) = 0;
  local_82c = (void *)0x0;
  local_830 = get_work(puVar4,*puVar4);
  _discard_work(&local_830,"driver-btm-c5.c",DAT_0003b0e4,0x423e);
  puVar4 = (undefined4 *)current_pool();
  if (*(char *)(puVar4 + 0xa0) == '\0') {
    local_828._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[0];
    local_828._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[1];
    local_828._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[2];
    local_828._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[3];
    uStack_824._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[4];
    uStack_824._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[5];
    uStack_824._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[6];
    uStack_824._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[7];
    uStack_820._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[8];
    uStack_820._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[9];
    uStack_820._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[10];
    uStack_820._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[11];
    uStack_81c._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[12];
    uStack_81c._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[13];
    uStack_81c._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[14];
    uStack_81c._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[15];
    local_818._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[16];
    local_818._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[17];
    local_818._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[18];
    local_818._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[19];
    uStack_814._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[20];
    uStack_814._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[21];
    uStack_814._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[22];
    uStack_814._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[23];
    uStack_810._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[24];
    uStack_810._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[25];
    uStack_810._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[26];
    uStack_810._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[27];
    uStack_80c._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[28];
    uStack_80c._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[29];
    uStack_80c._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[30];
    uStack_80c._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[31];
    local_808._0_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[32];
    local_808._1_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[33];
    local_808._2_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[34];
    local_808._3_1_ = s_Bitmain_S9_has_to_use_stratum_po_0006445c[35];
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_mutex_lock(__mutex);
  }
  else {
    iVar2 = pthread_mutex_lock(__mutex);
  }
  if (iVar2 == 0) {
    iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b0e4,0x4245);
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  }
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)(puVar4 + 0x35));
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b0e4,0x4245);
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)(puVar4 + 0x35));
  }
  if (iVar2 == 0) {
    iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)(puVar4 + 0x3b));
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b0e4,0x4246);
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)(puVar4 + 0x3b));
  }
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(puVar4 + 0x35));
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b0e4,0x4246);
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(puVar4 + 0x35));
  }
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b0e4,0x4246);
    _applog(3,&local_828,1);
    _quit(1);
  }
  *(undefined4 *)((int)__mutex + 0x2dc) = *puVar4;
  copy_pool_stratum((int)__mutex + 0x1150,(int)__mutex + 0xa18);
  __mutex[0x106].__data.__lock = *(int *)((int)__mutex + 0x188c);
  copy_pool_stratum((int)__mutex + 0xa18,(int)__mutex + 0x2e0);
  *(undefined4 *)((int)__mutex + 0x188c) = *(undefined4 *)((int)__mutex + 0x1888);
  copy_pool_stratum((int)__mutex + 0x2e0,puVar4);
  given_id = given_id + 1;
  *(int *)((int)__mutex + 0x1888) = given_id;
  parse_job_to_c5(&local_82c,puVar4,given_id);
  if (status_error == '\0') {
    pthread_mutex_lock(DAT_0003b0e8);
    send_job(local_82c);
    pthread_mutex_unlock(DAT_0003b0e8);
  }
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(puVar4 + 0x3b));
  uVar1 = DAT_0003b0e4;
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",uVar1,0x4258);
    _applog(3,&local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock(__mutex);
    uVar1 = DAT_0003b1fc;
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",DAT_0003b1fc,0x4259);
    _applog(3,&local_828,1);
    _quit(1);
    iVar2 = pthread_mutex_unlock(__mutex);
    uVar1 = DAT_0003b1fc;
  }
  DAT_0003b1fc = uVar1;
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",uVar1,0x4259);
    _applog(3,&local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  free(local_82c);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)((int)__mutex + 0x2a4));
  uVar1 = DAT_0003b1fc;
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "driver-btm-c5.c",uVar1,0x425b);
    _applog(3,&local_828,1);
    _quit(1);
    (*selective_yield)();
    return;
  }
  (*selective_yield)();
  return;
}

