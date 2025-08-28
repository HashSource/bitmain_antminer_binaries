
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aging_save_info(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  char logstr [2048];
  FILE *fd;
  int chain;
  int len;
  int i;
  
  memset(logstr,0,0x800);
  pFVar1 = fopen(aging_file,"wb");
  if (pFVar1 != (FILE *)0x0) {
    fwrite(&aging_info,1,0x99c0,pFVar1);
    fclose(pFVar1);
  }
  pFVar1 = fopen(aging_debug,"w");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  pFVar1 = fopen(aging_debug,"a+");
  if (pFVar1 != (FILE *)0x0) {
    if (aging_info.is_aging_finished == false) {
      puVar6 = &DAT_00081b3c;
    }
    else {
      puVar6 = &DAT_00081b38;
    }
    iVar2 = sprintf(logstr,"is aging finished : %s\n",puVar6);
    if (aging_info.is_bad_machine == false) {
      puVar6 = &DAT_00081b3c;
    }
    else {
      puVar6 = &DAT_00081b38;
    }
    iVar3 = sprintf(logstr + iVar2,"is bad machine    : %s\n",puVar6);
    iVar4 = sprintf(logstr + iVar2 + iVar3,"total aging time  : %d seconds\n",
                    aging_info.aging_seconds);
    iVar4 = iVar2 + iVar3 + iVar4;
    iVar2 = sprintf(logstr + iVar4,"sweep temperature : %d\n",aging_info.sweep_temp);
    iVar7 = iVar4 + iVar2;
    iVar3 = sprintf(logstr + iVar7,"last inbalance at : %d second\n",aging_info.last_inbalance_time)
    ;
    iVar5 = sprintf(logstr + iVar7 + iVar3,"start time        : %s",0x23456c);
    iVar8 = iVar7 + iVar3 + iVar5;
    if (aging_info.finish_time[0] == '\0') {
      builtin_strncpy(logstr + iVar4 + iVar2 + iVar3 + iVar5,"fini",4);
      builtin_strncpy(logstr + iVar7 + iVar3 + iVar5 + 4,"sh time       : \n",0x12);
      len = iVar8 + 0x15;
    }
    else {
      iVar2 = sprintf(logstr + iVar8,"finish time       : %s",0x2345ac);
      len = iVar8 + iVar2;
    }
    iVar2 = sprintf(logstr + len,"start time value  : %lu\n",aging_info.tv_start_time.tv_sec);
    iVar3 = sprintf(logstr + len + iVar2,"finish time value : %lu\n",
                    aging_info.tv_finish_time.tv_sec);
    iVar3 = len + iVar2 + iVar3;
    iVar2 = sprintf(logstr + iVar3,"average hashrate  : %.2f\n",
                    aging_info.avg_hashrate_when_finish._0_4_,
                    aging_info.avg_hashrate_when_finish._4_4_);
    fwrite(logstr,1,iVar3 + iVar2,pFVar1);
    len = 0;
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        iVar2 = sprintf(logstr + len,"\nchain %d inbalance %d times:\n",chain,
                        aging_info.inbalance_times[chain]);
        len = len + iVar2;
        for (i = 0; (uint)i < aging_info.inbalance_times[chain]; i = i + 1) {
          iVar2 = sprintf(logstr + len,"%d. %s",i + 1,(i + chain * 0x20) * 0x40 + 0x235e50);
          iVar3 = len + iVar2 + -1;
          uVar9 = *(undefined4 *)(aging_info.inbalance_voltage[chain] + i);
          iVar2 = sprintf(logstr + iVar3,", time %4ds, voltage %.2f\n",
                          aging_info.inbalance_detected_time[chain][i],uVar9,uVar9,
                          *(undefined4 *)((int)aging_info.inbalance_voltage[chain] + i * 8 + 4));
          len = iVar3 + iVar2;
          if (0x400 < len) {
            fwrite(logstr,1,len,pFVar1);
            len = 0;
          }
        }
      }
    }
    fwrite(logstr,1,len,pFVar1);
    if (aging_info.aging_24_hour_finished == false) {
      puVar6 = &DAT_00081b3c;
    }
    else {
      puVar6 = &DAT_00081b38;
    }
    iVar2 = sprintf(logstr,"\naging_24_hour_finished  : %s\n",puVar6);
    if (aging_info.is_hash_rate_updated == false) {
      puVar6 = &DAT_00081b3c;
    }
    else {
      puVar6 = &DAT_00081b38;
    }
    iVar3 = sprintf(logstr + iVar2,"is_hash_rate_updated    : %s\n",puVar6);
    iVar4 = sprintf(logstr + iVar2 + iVar3,"org_ideal_fixed_hashrate: %d\n",
                    aging_info.fixed_hashrate);
    iVar4 = iVar2 + iVar3 + iVar4;
    iVar2 = sprintf(logstr + iVar4,"avg_hashrate_24_hour    : %d\n",aging_info.avg_hashrate_24_hour)
    ;
    len = iVar4 + iVar2;
    if (aging_info.aging_24_hour_finished != false) {
      iVar2 = sprintf(logstr + len,"update time: %s",0x23dedc);
      len = len + iVar2;
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        iVar2 = sprintf(logstr + len,"chain %d old_hashrate %d new_hashrate %d\n",chain,
                        aging_info.old_hashrate[chain],aging_info.new_hashrate[chain]);
        len = len + iVar2;
      }
    }
    fwrite(logstr,1,len,pFVar1);
    fclose(pFVar1);
  }
  return;
}

