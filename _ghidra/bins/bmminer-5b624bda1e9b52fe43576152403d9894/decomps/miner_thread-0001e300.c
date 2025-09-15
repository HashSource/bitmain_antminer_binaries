
/* WARNING: Unknown calling convention */

void * miner_thread(void *userdata)

{
  _Bool _Var1;
  time_t tVar2;
  _func_void_thr_info_ptr *p_Var3;
  device_drv *drv;
  device_drv *pdVar4;
  cgpu_info *cgpu;
  cgpu_info *dev;
  char threadname [16];
  char tmp42 [2048];
  
  dev = *(cgpu_info **)((int)userdata + 0x24);
                    /* WARNING: Load size is inaccurate */
  pdVar4 = dev->drv;
  snprintf(threadname,0x10,"%d/Miner",*userdata);
  RenameThread(threadname);
  thread_reportout((thr_info *)userdata);
  _Var1 = (*pdVar4->thread_init)((thr_info *)userdata);
  if (_Var1) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Waiting on sem in miner thre",0x1c);
      tmp42[0x1c] = 'a';
      tmp42[0x1d] = 'd';
      tmp42[0x1e] = '\0';
      _applog(7,tmp42,false);
    }
    _cgsem_wait((cgsem_t *)((int)userdata + 0x10),"cgminer.c","miner_thread",0x25b8);
    tVar2 = time((time_t *)0x0);
    p_Var3 = pdVar4->hash_work;
    dev->last_device_valid_work = tVar2;
    (*p_Var3)((thr_info *)userdata);
    (*pdVar4->thread_shutdown)((thr_info *)userdata);
  }
  else {
    dev_error(dev,REASON_THREAD_FAIL_INIT);
  }
  return (void *)0x0;
}

