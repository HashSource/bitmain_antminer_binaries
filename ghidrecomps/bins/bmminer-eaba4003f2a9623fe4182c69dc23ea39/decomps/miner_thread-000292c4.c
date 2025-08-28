
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
      builtin_strncpy(tmp42,"Waiting on sem in miner thre",0x1c);
      tmp42[0x1c] = 'a';
      tmp42[0x1d] = 'd';
      tmp42[0x1e] = '\0';
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

