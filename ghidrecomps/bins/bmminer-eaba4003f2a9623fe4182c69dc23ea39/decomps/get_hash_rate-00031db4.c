
/* WARNING: Unknown calling convention */

void * get_hash_rate(void)

{
  uint uVar1;
  int iVar2;
  double dVar3;
  undefined8 uVar4;
  int index [16];
  double each_chain_h [16] [10];
  timeval diff;
  timeval new_h;
  timeval old_h;
  double each_chain_h_all;
  uint i;
  uint which_chain;
  
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
        iVar2 = index[which_chain];
        uVar4 = __aeabi_ul2d((int)((ulonglong)*(uint *)(h_each_chain + which_chain) * 0xffffffff),
                             (int)((ulonglong)*(uint *)(h_each_chain + which_chain) * 0xffffffff >>
                                  0x20) - *(int *)((int)h_each_chain + which_chain * 8 + 4));
        *(int *)(each_chain_h[which_chain] + iVar2) = (int)uVar4;
        *(int *)((int)each_chain_h[uVar1] + iVar2 * 8 + 4) = (int)((ulonglong)uVar4 >> 0x20);
        *(undefined4 *)(h_each_chain + which_chain) = 0;
        *(undefined4 *)((int)h_each_chain + which_chain * 8 + 4) = 0;
        each_chain_h[which_chain][index[which_chain]] =
             each_chain_h[which_chain][index[which_chain]] /
             ((double)(longlong)diff.tv_sec + (double)(longlong)(diff.tv_usec + 1) / DAT_00032100);
        *(undefined4 *)(each_chain_h_avg + which_chain) = 0;
        *(undefined4 *)((int)each_chain_h_avg + which_chain * 8 + 4) = 0;
        for (i = 0; i < 10; i = i + 1) {
          each_chain_h_avg[which_chain] =
               each_chain_h_avg[which_chain] + each_chain_h[which_chain][i];
        }
        dVar3 = (each_chain_h_avg[which_chain] / DAT_00032108) / 10.0;
        sprintf(displayed_rate[which_chain],"%.2f",SUB84(dVar3,0),(int)((ulonglong)dVar3 >> 0x20));
        each_chain_h_all = each_chain_h_all + (each_chain_h_avg[which_chain] / DAT_00032108) / 10.0;
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

