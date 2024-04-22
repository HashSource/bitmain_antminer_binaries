
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flush_queue(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined2 uStack_7f8;
  undefined local_7f6;
  
  local_814 = 0;
  if (param_1 != 0) {
    iVar2 = pthread_rwlock_trywrlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar2 == 0) {
      local_814 = *(int *)(param_1 + 0x164);
      *(undefined4 *)(param_1 + 0x164) = 0;
      iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
      uVar1 = DAT_00021558;
      if (iVar2 != 0) {
        piVar3 = __errno_location();
        snprintf((char *)&local_810,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                 *piVar3,"cgminer.c",uVar1,0x2541);
        _applog(3,&local_810,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      (*selective_yield)();
      if (((local_814 != 0) &&
          (_free_work(&local_814,"cgminer.c",DAT_00021558,0x2545), opt_debug != '\0')) &&
         ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
        local_810._0_1_ = s_Discarded_queued_work_item_0005d590[0];
        local_810._1_1_ = s_Discarded_queued_work_item_0005d590[1];
        local_810._2_1_ = s_Discarded_queued_work_item_0005d590[2];
        local_810._3_1_ = s_Discarded_queued_work_item_0005d590[3];
        uStack_80c._0_1_ = s_Discarded_queued_work_item_0005d590[4];
        uStack_80c._1_1_ = s_Discarded_queued_work_item_0005d590[5];
        uStack_80c._2_1_ = s_Discarded_queued_work_item_0005d590[6];
        uStack_80c._3_1_ = s_Discarded_queued_work_item_0005d590[7];
        uStack_808._0_1_ = s_Discarded_queued_work_item_0005d590[8];
        uStack_808._1_1_ = s_Discarded_queued_work_item_0005d590[9];
        uStack_808._2_1_ = s_Discarded_queued_work_item_0005d590[10];
        uStack_808._3_1_ = s_Discarded_queued_work_item_0005d590[11];
        uStack_804._0_1_ = s_Discarded_queued_work_item_0005d590[12];
        uStack_804._1_1_ = s_Discarded_queued_work_item_0005d590[13];
        uStack_804._2_1_ = s_Discarded_queued_work_item_0005d590[14];
        uStack_804._3_1_ = s_Discarded_queued_work_item_0005d590[15];
        local_800._0_1_ = s_Discarded_queued_work_item_0005d590[16];
        local_800._1_1_ = s_Discarded_queued_work_item_0005d590[17];
        local_800._2_1_ = s_Discarded_queued_work_item_0005d590[18];
        local_800._3_1_ = s_Discarded_queued_work_item_0005d590[19];
        uStack_7fc._0_1_ = s_Discarded_queued_work_item_0005d590[20];
        uStack_7fc._1_1_ = s_Discarded_queued_work_item_0005d590[21];
        uStack_7fc._2_1_ = s_Discarded_queued_work_item_0005d590[22];
        uStack_7fc._3_1_ = s_Discarded_queued_work_item_0005d590[23];
        uStack_7f8 = (undefined2)ram0x0005d5a8;
        local_7f6 = (undefined)((uint)ram0x0005d5a8 >> 0x10);
        _applog(7,&local_810,0);
      }
    }
  }
  return;
}

