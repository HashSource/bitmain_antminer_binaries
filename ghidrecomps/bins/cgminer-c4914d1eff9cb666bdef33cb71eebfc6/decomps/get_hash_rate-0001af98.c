
/* WARNING: Unknown calling convention */

void * get_hash_rate(void)

{
  uint32_t uVar1;
  uint uVar2;
  int iVar3;
  double dVar4;
  undefined8 uVar5;
  int index [16];
  double each_chain_h [16] [10];
  timeval diff;
  timeval new_h;
  timeval old_h;
  char *hash_log;
  uint32_t counter;
  double each_chain_h_all;
  uint32_t i;
  uint32_t which_chain;
  
  memset(each_chain_h,0,0x500);
  memset(index,0,0x40);
  cgtime(&old_h);
  cgtime(&new_h);
  do {
    cgtime(&new_h);
    diff.tv_sec = new_h.tv_sec - old_h.tv_sec;
    diff.tv_usec = new_h.tv_usec - old_h.tv_usec;
    if (diff.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
      diff.tv_usec = diff.tv_usec + 1000000;
    }
    each_chain_h_all = 0.0;
    for (which_chain = 0; uVar1 = which_chain, which_chain < 0x10; which_chain = which_chain + 1) {
      if (dev->chain_exist[which_chain] != 0) {
        uVar2 = *(uint *)(h_each_chain + which_chain);
        iVar3 = index[which_chain];
        uVar5 = __floatundidf(-uVar2,((uVar2 & 0xfffffffe) -
                                     *(int *)((int)h_each_chain + which_chain * 8 + 4)) +
                                     (uint)(uVar2 * -0x80000000 < uVar2) * -2 +
                                     (uint)CARRY4(uVar2 * 0x7fffffff,uVar2 * 0x7fffffff) +
                                     (uint)CARRY4(uVar2 * -2,uVar2));
        *(int *)(each_chain_h[which_chain] + iVar3) = (int)uVar5;
        *(int *)((int)each_chain_h[uVar1] + iVar3 * 8 + 4) = (int)((ulonglong)uVar5 >> 0x20);
        *(undefined4 *)(h_each_chain + which_chain) = 0;
        *(undefined4 *)((int)h_each_chain + which_chain * 8 + 4) = 0;
        each_chain_h[which_chain][index[which_chain]] =
             each_chain_h[which_chain][index[which_chain]] /
             ((double)(longlong)diff.tv_sec + (double)(longlong)(diff.tv_usec + 1) / DAT_0001b318);
        *(undefined4 *)(each_chain_h_avg + which_chain) = 0;
        *(undefined4 *)((int)each_chain_h_avg + which_chain * 8 + 4) = 0;
        for (i = 0; i < 10; i = i + 1) {
          each_chain_h_avg[which_chain] =
               each_chain_h_avg[which_chain] + each_chain_h[which_chain][i];
        }
        dVar4 = (each_chain_h_avg[which_chain] / DAT_0001b320) / 10.0;
        sprintf(displayed_rate[which_chain],"%.2f",SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
        each_chain_h_all = each_chain_h_all + (each_chain_h_avg[which_chain] / DAT_0001b320) / 10.0;
        index[which_chain] = index[which_chain] + 1;
        if (9 < index[which_chain]) {
          index[which_chain] = 0;
        }
      }
    }
    sprintf(displayed_hash_rate,"%.2f",each_chain_h_all._0_4_,each_chain_h_all._4_4_);
    geach_chain_h_all._0_4_ = each_chain_h_all._0_4_;
    geach_chain_h_all._4_4_ = each_chain_h_all._4_4_;
    copy_time(&old_h,&new_h);
    sleep(5);
  } while( true );
}

