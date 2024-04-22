
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mt_disable_isra_16(int param_1,undefined4 param_2,code **param_3)

{
  char cVar1;
  int iVar2;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined2 uStack_804;
  undefined local_802;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf((char *)&local_820,0x800,"Thread %d being disabled",param_2);
    _applog(4,&local_820,0);
  }
  cVar1 = opt_debug;
  iVar2 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(iVar2 + 0x30) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  if ((cVar1 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    local_820._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[0];
    local_820._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[1];
    local_820._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[2];
    local_820._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[3];
    uStack_81c._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[4];
    uStack_81c._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[5];
    uStack_81c._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[6];
    uStack_81c._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[7];
    uStack_818._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[8];
    uStack_818._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[9];
    uStack_818._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[10];
    uStack_818._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[11];
    uStack_814._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[12];
    uStack_814._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[13];
    uStack_814._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[14];
    uStack_814._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[15];
    local_810._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[16];
    local_810._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[17];
    local_810._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[18];
    local_810._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[19];
    uStack_80c._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[20];
    uStack_80c._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[21];
    uStack_80c._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[22];
    uStack_80c._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[23];
    uStack_808._0_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[24];
    uStack_808._1_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[25];
    uStack_808._2_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[26];
    uStack_808._3_1_ = s_Waiting_on_sem_in_miner_thread_0005c34c[27];
    uStack_804 = (undefined2)ram0x0005c368;
    local_802 = (undefined)((uint)ram0x0005c368 >> 0x10);
    _applog(7,&local_820,0);
  }
  _cgsem_wait(param_1 + 0x10,"cgminer.c",DAT_0001c158,0x2359);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf((char *)&local_820,0x800,"Thread %d being re-enabled",param_2);
    _applog(4,&local_820,0);
  }
  (**param_3)(param_1);
  return;
}

