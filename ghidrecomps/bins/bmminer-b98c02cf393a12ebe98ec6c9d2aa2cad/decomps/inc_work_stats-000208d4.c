
void inc_work_stats(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  time_t tVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_00020974,0x2233);
  }
  iVar5 = *(int *)(param_1 + 0x24);
  iVar1 = (int)param_3 >> 0x1f;
  uVar2 = *(uint *)(iVar5 + 0xc0);
  bVar6 = CARRY4((uint)total_diff1,param_3);
  total_diff1._0_4_ = (uint)total_diff1 + param_3;
  total_diff1._4_4_ = total_diff1._4_4_ + iVar1 + (uint)bVar6;
  *(uint *)(iVar5 + 0xc0) = uVar2 + param_3;
  *(uint *)(iVar5 + 0xc4) = *(int *)(iVar5 + 0xc4) + iVar1 + (uint)CARRY4(uVar2,param_3);
  if (param_2 == 0) {
    iVar4 = current_pool();
    uVar2 = *(uint *)(iVar4 + 0x28);
    iVar5 = *(int *)(param_1 + 0x24);
    *(uint *)(iVar4 + 0x28) = param_3 + uVar2;
    *(uint *)(iVar4 + 0x2c) = iVar1 + *(int *)(iVar4 + 0x2c) + (uint)CARRY4(param_3,uVar2);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x28);
    *(uint *)(param_2 + 0x28) = uVar2 + param_3;
    *(uint *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + iVar1 + (uint)CARRY4(uVar2,param_3);
  }
  tVar3 = time((time_t *)0x0);
  *(time_t *)(iVar5 + 0xe8) = tVar3;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0002094a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*selective_yield)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _mutex_unlock_noyield_part_48_constprop_77(DAT_00020974,0x2241);
}

