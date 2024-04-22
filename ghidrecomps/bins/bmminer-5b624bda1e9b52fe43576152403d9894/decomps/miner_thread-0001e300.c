
/* WARNING: Unknown calling convention */

void * miner_thread(void *userdata)

{
  _Bool _Var1;
  thr_info *mythr;
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
  snprintf(threadname,0x10,DAT_0001e3ac,*userdata);
  RenameThread(threadname);
  thread_reportout((thr_info *)userdata);
  _Var1 = (*pdVar4->thread_init)((thr_info *)userdata);
  if (_Var1 == false) {
    dev_error(dev,REASON_THREAD_FAIL_INIT);
  }
  else {
    if ((*DAT_0001e3b0 != '\0') &&
       (((*DAT_0001e3b4 != '\0' || (*DAT_0001e3b8 != '\0')) || (6 < *DAT_0001e3c8)))) {
      tmp42._0_4_ = *DAT_0001e3bc;
      tmp42._4_4_ = DAT_0001e3bc[1];
      tmp42._8_4_ = DAT_0001e3bc[2];
      tmp42._12_4_ = DAT_0001e3bc[3];
      tmp42._16_4_ = DAT_0001e3bc[4];
      tmp42._20_4_ = DAT_0001e3bc[5];
      tmp42._24_4_ = DAT_0001e3bc[6];
      tmp42._28_2_ = (undefined2)DAT_0001e3bc[7];
      tmp42[30] = (char)((uint)DAT_0001e3bc[7] >> 0x10);
      _applog(7,tmp42,false);
    }
    _cgsem_wait((cgsem_t *)((int)userdata + 0x10),DAT_0001e3c0,DAT_0001e3c4,0x25b8);
    tVar2 = time((time_t *)0x0);
    p_Var3 = pdVar4->hash_work;
    dev->last_device_valid_work = tVar2;
    (*p_Var3)((thr_info *)userdata);
    (*pdVar4->thread_shutdown)((thr_info *)userdata);
  }
  return (void *)0x0;
}

