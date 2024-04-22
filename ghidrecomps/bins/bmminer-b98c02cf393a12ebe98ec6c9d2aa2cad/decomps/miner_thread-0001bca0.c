
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 miner_thread(undefined4 *param_1)

{
  int iVar1;
  time_t tVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char acStack_828 [16];
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined2 uStack_7fc;
  undefined local_7fa;
  
  iVar5 = param_1[9];
  iVar4 = *(int *)(iVar5 + 4);
  snprintf(acStack_828,0x10,"%d/Miner",*param_1);
  RenameThread(acStack_828);
  thread_reportout(param_1);
  iVar1 = (**(code **)(iVar4 + 0x34))(param_1);
  if (iVar1 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_818._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[0];
      local_818._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[1];
      local_818._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[2];
      local_818._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[3];
      uStack_814._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[4];
      uStack_814._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[5];
      uStack_814._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[6];
      uStack_814._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[7];
      uStack_810._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[8];
      uStack_810._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[9];
      uStack_810._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[10];
      uStack_810._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[11];
      uStack_80c._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[12];
      uStack_80c._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[13];
      uStack_80c._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[14];
      uStack_80c._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[15];
      local_808._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[16];
      local_808._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[17];
      local_808._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[18];
      local_808._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[19];
      uStack_804._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[20];
      uStack_804._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[21];
      uStack_804._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[22];
      uStack_804._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[23];
      uStack_800._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[24];
      uStack_800._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[25];
      uStack_800._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[26];
      uStack_800._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[27];
      uStack_7fc = (undefined2)ram0x0005c368;
      local_7fa = (undefined)((uint)ram0x0005c368 >> 0x10);
      _applog(7,&local_818,0);
    }
    _cgsem_wait(param_1 + 4,"cgminer.c",DAT_0001bd80,0x25d9);
    tVar2 = time((time_t *)0x0);
    pcVar3 = *(code **)(iVar4 + 0x3c);
    *(time_t *)(iVar5 + 0xe8) = tVar2;
    (*pcVar3)(param_1);
    (**(code **)(iVar4 + 0x58))(param_1);
    return 0;
  }
  dev_error(iVar5,0);
  return 0;
}

