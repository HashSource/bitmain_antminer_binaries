
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mt_disable(thr_info *mythr,int thr_id,device_drv *drv)

{
  cgpu_info *pcVar1;
  device_drv *drv_local;
  int thr_id_local;
  thr_info *mythr_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being disabled",thr_id);
    _applog(4,tmp42,false);
  }
  pcVar1 = mythr->cgpu;
  *(undefined4 *)&pcVar1->rolling = 0;
  *(undefined4 *)((int)&pcVar1->rolling + 4) = 0;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    tmp42[0] = s_Waiting_on_sem_in_miner_thread_00074270[0];
    tmp42[1] = s_Waiting_on_sem_in_miner_thread_00074270[1];
    tmp42[2] = s_Waiting_on_sem_in_miner_thread_00074270[2];
    tmp42[3] = s_Waiting_on_sem_in_miner_thread_00074270[3];
    tmp42[4] = s_Waiting_on_sem_in_miner_thread_00074270[4];
    tmp42[5] = s_Waiting_on_sem_in_miner_thread_00074270[5];
    tmp42[6] = s_Waiting_on_sem_in_miner_thread_00074270[6];
    tmp42[7] = s_Waiting_on_sem_in_miner_thread_00074270[7];
    tmp42[8] = s_Waiting_on_sem_in_miner_thread_00074270[8];
    tmp42[9] = s_Waiting_on_sem_in_miner_thread_00074270[9];
    tmp42[10] = s_Waiting_on_sem_in_miner_thread_00074270[10];
    tmp42[11] = s_Waiting_on_sem_in_miner_thread_00074270[11];
    tmp42[12] = s_Waiting_on_sem_in_miner_thread_00074270[12];
    tmp42[13] = s_Waiting_on_sem_in_miner_thread_00074270[13];
    tmp42[14] = s_Waiting_on_sem_in_miner_thread_00074270[14];
    tmp42[15] = s_Waiting_on_sem_in_miner_thread_00074270[15];
    tmp42[16] = s_Waiting_on_sem_in_miner_thread_00074270[16];
    tmp42[17] = s_Waiting_on_sem_in_miner_thread_00074270[17];
    tmp42[18] = s_Waiting_on_sem_in_miner_thread_00074270[18];
    tmp42[19] = s_Waiting_on_sem_in_miner_thread_00074270[19];
    tmp42[20] = s_Waiting_on_sem_in_miner_thread_00074270[20];
    tmp42[21] = s_Waiting_on_sem_in_miner_thread_00074270[21];
    tmp42[22] = s_Waiting_on_sem_in_miner_thread_00074270[22];
    tmp42[23] = s_Waiting_on_sem_in_miner_thread_00074270[23];
    tmp42[24] = s_Waiting_on_sem_in_miner_thread_00074270[24];
    tmp42[25] = s_Waiting_on_sem_in_miner_thread_00074270[25];
    tmp42[26] = s_Waiting_on_sem_in_miner_thread_00074270[26];
    tmp42[27] = s_Waiting_on_sem_in_miner_thread_00074270[27];
    tmp42._28_2_ = (undefined2)ram0x0007428c;
    tmp42[30] = (char)((uint)ram0x0007428c >> 0x10);
    _applog(7,tmp42,false);
  }
  _cgsem_wait(&mythr->sem,"cgminer.c","mt_disable",0x233f);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Thread %d being re-enabled",thr_id);
    _applog(4,tmp42,false);
  }
  (*drv->thread_enable)(mythr);
  return;
}

