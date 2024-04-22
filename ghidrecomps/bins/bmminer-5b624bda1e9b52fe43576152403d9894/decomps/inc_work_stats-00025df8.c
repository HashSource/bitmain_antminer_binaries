
/* WARNING: Unknown calling convention */

void inc_work_stats(thr_info *thr,pool *pool,int diff1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  time_t tVar4;
  pool *ppVar5;
  uint uVar6;
  char *pcVar7;
  int in_r3;
  int iVar8;
  uint uVar9;
  cgpu_info *pcVar10;
  
  pcVar7 = (char *)diff1;
  iVar3 = pthread_mutex_lock(DAT_00025e94);
  if (iVar3 != 0) {
    _mutex_lock(DAT_00025ea0,(char *)0x2212,pcVar7,in_r3);
  }
  puVar2 = DAT_00025e98;
  pcVar10 = thr->cgpu;
  iVar8 = diff1 >> 0x1f;
  uVar9 = *DAT_00025e98;
  puVar1 = DAT_00025e98 + 1;
  uVar6 = *(uint *)&pcVar10->diff1;
  iVar3 = *(int *)((int)&pcVar10->diff1 + 4);
  *DAT_00025e98 = uVar9 + diff1;
  puVar2[1] = *puVar1 + iVar8 + (uint)CARRY4(uVar9,diff1);
  *(uint *)&pcVar10->diff1 = uVar6 + diff1;
  *(uint *)((int)&pcVar10->diff1 + 4) = iVar3 + iVar8 + (uint)CARRY4(uVar6,diff1);
  if (pool == (pool *)0x0) {
    ppVar5 = current_pool();
    pcVar7 = *(char **)&ppVar5->diff1;
    iVar3 = *(int *)((int)&ppVar5->diff1 + 4);
    pcVar10 = thr->cgpu;
    *(char **)&ppVar5->diff1 = pcVar7 + diff1;
    *(uint *)((int)&ppVar5->diff1 + 4) = iVar8 + iVar3 + (uint)CARRY4(diff1,(uint)pcVar7);
  }
  else {
    pcVar7 = *(char **)&pool->diff1;
    iVar3 = *(int *)((int)&pool->diff1 + 4);
    *(char **)&pool->diff1 = pcVar7 + diff1;
    *(uint *)((int)&pool->diff1 + 4) = iVar8 + iVar3 + (uint)CARRY4(diff1,(uint)pcVar7);
  }
  tVar4 = time((time_t *)0x0);
  pcVar10->last_device_valid_work = tVar4;
  iVar8 = pthread_mutex_unlock(DAT_00025e94);
  if (iVar8 != 0) {
    _mutex_unlock_noyield(DAT_00025ea0,(char *)0x2220,pcVar7,iVar3);
  }
  (**DAT_00025e9c)();
  return;
}

