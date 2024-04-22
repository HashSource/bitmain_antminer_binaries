
/* WARNING: Unknown calling convention */

void aging_save_info(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
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
  pFVar1 = fopen(aging_debug,(char *)&DAT_00081b34);
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
  }
  fd = (FILE *)fopen(aging_debug,"a+");
  if (fd != (FILE *)0x0) {
    if (aging_info.is_aging_finished == false) {
      puVar5 = &DAT_00081b3c;
    }
    else {
      puVar5 = &DAT_00081b38;
    }
    iVar2 = sprintf(logstr,"is aging finished : %s\n",puVar5);
    if (aging_info.is_bad_machine == false) {
      puVar5 = &DAT_00081b3c;
    }
    else {
      puVar5 = &DAT_00081b38;
    }
    iVar3 = sprintf(logstr + iVar2,"is bad machine    : %s\n",puVar5);
    iVar4 = sprintf(logstr + iVar2 + iVar3,"total aging time  : %d seconds\n",
                    aging_info.aging_seconds);
    iVar4 = iVar2 + iVar3 + iVar4;
    iVar2 = sprintf(logstr + iVar4,"sweep temperature : %d\n",aging_info.sweep_temp);
    iVar4 = iVar4 + iVar2;
    iVar2 = sprintf(logstr + iVar4,"last inbalance at : %d second\n",aging_info.last_inbalance_time)
    ;
    iVar4 = iVar4 + iVar2;
    iVar2 = sprintf(logstr + iVar4,"start time        : %s",DAT_0001ea9c);
    iVar4 = iVar4 + iVar2;
    if (aging_info.finish_time[0] == '\0') {
      len = iVar4;
      *(undefined4 *)(logstr + iVar4) = s_finish_time___00081be0._0_4_;
      *(undefined4 *)(logstr + iVar4 + 4) = s_finish_time___00081be0._4_4_;
      *(undefined4 *)(logstr + iVar4 + 8) = s_finish_time___00081be0._8_4_;
      *(undefined4 *)(logstr + iVar4 + 0xc) = s_finish_time___00081be0._12_4_;
      *(undefined4 *)(logstr + iVar4 + 0x10) = s_finish_time___00081be0._16_4_;
      *(undefined2 *)(logstr + iVar4 + 0x14) = s_finish_time___00081be0._20_2_;
      len = len + 0x15;
    }
    else {
      iVar2 = sprintf(logstr + iVar4,"finish time       : %s",DAT_0001eaa0);
      len = iVar4 + iVar2;
    }
    iVar2 = sprintf(logstr + len,"start time value  : %lu\n",aging_info.tv_start_time.tv_sec);
    iVar3 = sprintf(logstr + len + iVar2,"finish time value : %lu\n",
                    aging_info.tv_finish_time.tv_sec);
    iVar3 = len + iVar2 + iVar3;
    iVar2 = sprintf(logstr + iVar3,"average hashrate  : %.2f\n",
                    aging_info.avg_hashrate_when_finish._0_4_,
                    aging_info.avg_hashrate_when_finish._4_4_);
    fwrite(logstr,1,iVar3 + iVar2,(FILE *)fd);
    len = 0;
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        iVar2 = sprintf(logstr + len,"\nchain %d inbalance %d times:\n",chain,
                        aging_info.inbalance_times[chain]);
        len = len + iVar2;
        for (i = 0; (uint)i < aging_info.inbalance_times[chain]; i = i + 1) {
          iVar2 = sprintf(logstr + len,"%d. %s",i + 1,(i + chain * 0x20) * 0x40 + 0x235e50);
          iVar3 = len + iVar2 + -1;
          uVar6 = *(undefined4 *)(aging_info.inbalance_voltage[chain] + i);
          iVar2 = sprintf(logstr + iVar3,", time %4ds, voltage %.2f\n",
                          aging_info.inbalance_detected_time[chain][i],uVar6,uVar6,
                          *(undefined4 *)((int)aging_info.inbalance_voltage[chain] + i * 8 + 4));
          len = iVar3 + iVar2;
          if (0x400 < len) {
            fwrite(logstr,1,len,(FILE *)fd);
            len = 0;
          }
        }
      }
    }
    fwrite(logstr,1,len,(FILE *)fd);
    if (aging_info.aging_24_hour_finished == false) {
      puVar5 = &DAT_00081b3c;
    }
    else {
      puVar5 = &DAT_00081b38;
    }
    iVar2 = sprintf(logstr,"\naging_24_hour_finished  : %s\n",puVar5);
    if (aging_info.is_hash_rate_updated == false) {
      puVar5 = &DAT_00081b3c;
    }
    else {
      puVar5 = &DAT_00081b38;
    }
    iVar3 = sprintf(logstr + iVar2,"is_hash_rate_updated    : %s\n",puVar5);
    iVar4 = sprintf(logstr + iVar2 + iVar3,"org_ideal_fixed_hashrate: %d\n",
                    aging_info.fixed_hashrate);
    iVar4 = iVar2 + iVar3 + iVar4;
    iVar2 = sprintf(logstr + iVar4,"avg_hashrate_24_hour    : %d\n",aging_info.avg_hashrate_24_hour)
    ;
    len = iVar4 + iVar2;
    if (aging_info.aging_24_hour_finished != false) {
      iVar2 = sprintf(logstr + len,"update time: %s",DAT_0001ec14);
      len = len + iVar2;
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        iVar2 = sprintf(logstr + len,"chain %d old_hashrate %d new_hashrate %d\n",chain,
                        aging_info.old_hashrate[chain],aging_info.new_hashrate[chain]);
        len = len + iVar2;
      }
    }
    fwrite(logstr,1,len,(FILE *)fd);
    fclose((FILE *)fd);
  }
  return;
}

