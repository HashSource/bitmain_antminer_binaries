
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * miner_thread(void *userdata)

{
  _Bool _Var1;
  time_t tVar2;
  cgpu_info *dev;
  device_drv *pdVar3;
  void *userdata_local;
  char tmp42 [2048];
  char threadname [16];
  device_drv *drv;
  cgpu_info *cgpu;
  int thr_id;
  thr_info *mythr;
  
                    /* WARNING: Load size is inaccurate */
  dev = *(cgpu_info **)((int)userdata + 0x24);
  pdVar3 = dev->drv;
  snprintf(threadname,0x10,"%d/Miner",*userdata);
  RenameThread(threadname);
  thread_reportout((thr_info *)userdata);
  _Var1 = (*pdVar3->thread_init)((thr_info *)userdata);
  if (_Var1) {
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
    _cgsem_wait((cgsem_t *)((int)userdata + 0x10),"cgminer.c","miner_thread",0x25bf);
    tVar2 = time((time_t *)0x0);
    dev->last_device_valid_work = tVar2;
    (*pdVar3->hash_work)((thr_info *)userdata);
    (*pdVar3->thread_shutdown)((thr_info *)userdata);
  }
  else {
    dev_error(dev,REASON_THREAD_FAIL_INIT);
  }
  return (void *)0x0;
}

