
/* WARNING: Unknown calling convention */

_Bool stratum_send(pool *pool,char *s,ssize_t len)

{
  int iVar1;
  int *piVar2;
  char *func;
  char *in_r3;
  send_ret sVar3;
  char cVar4;
  char tmp42 [2048];
  
  func = (char *)len;
  if (((*DAT_000121dc != '\0') && (in_r3 = (char *)(uint)*DAT_000121e0, in_r3 != (char *)0x0)) &&
     ((*DAT_000121e8 != '\0' || ((*DAT_000121ec != '\0' || (in_r3 = *DAT_000121f0, 6 < (int)in_r3)))
      ))) {
    in_r3 = s;
    snprintf(tmp42,0x800,DAT_000121f4);
    func = (char *)0x0;
    _applog(7,tmp42,false);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00012208,(char *)0x698,func,(int)in_r3);
  }
  if (pool->stratum_active == false) {
    sVar3 = SEND_INACTIVE;
    cVar4 = '\0';
  }
  else {
    sVar3 = __stratum_send(pool,s,len);
    cVar4 = '\x01' - (char)sVar3;
    if (SEND_SELECTFAIL < sVar3) {
      cVar4 = '\0';
    }
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_0001220c,*piVar2,DAT_00012204,DAT_00012208,0x69e);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (**DAT_000121e4)();
  if (sVar3 == SEND_SENDFAIL) {
    if ((*DAT_000121e0 != 0) &&
       (((*DAT_000121e8 != '\0' || (*DAT_000121ec != '\0')) || (6 < (int)*DAT_000121f0)))) {
      tmp42._0_4_ = *DAT_00012200;
      tmp42._4_4_ = DAT_00012200[1];
      tmp42._8_4_ = DAT_00012200[2];
      tmp42._12_4_ = DAT_00012200[3];
      tmp42._16_4_ = DAT_00012200[4];
      tmp42._20_4_ = DAT_00012200[5];
      tmp42._24_4_ = DAT_00012200[6];
      tmp42._28_3_ = (undefined3)DAT_00012200[7];
      _applog(7,tmp42,false);
      suspend_stratum(pool);
      return (_Bool)cVar4;
    }
  }
  else {
    if (sVar3 == SEND_INACTIVE) {
      if (*DAT_000121e0 == 0) {
        return (_Bool)cVar4;
      }
      if (((*DAT_000121e8 == '\0') && (*DAT_000121ec == '\0')) && ((int)*DAT_000121f0 < 7)) {
        return (_Bool)cVar4;
      }
      tmp42._0_4_ = *DAT_000121fc;
      tmp42._4_4_ = DAT_000121fc[1];
      tmp42._8_4_ = DAT_000121fc[2];
      tmp42._12_4_ = DAT_000121fc[3];
      tmp42._16_4_ = DAT_000121fc[4];
      tmp42._20_4_ = DAT_000121fc[5];
      tmp42._24_4_ = DAT_000121fc[6];
      tmp42._28_4_ = DAT_000121fc[7];
      tmp42._32_4_ = DAT_000121fc[8];
      tmp42._36_4_ = DAT_000121fc[9];
      tmp42._40_4_ = DAT_000121fc[10];
      tmp42._44_4_ = DAT_000121fc[0xb];
      tmp42._48_2_ = (undefined2)DAT_000121fc[0xc];
      _applog(7,tmp42,false);
      return (_Bool)cVar4;
    }
    if (sVar3 != SEND_SELECTFAIL) {
      return (_Bool)cVar4;
    }
    if ((*DAT_000121e0 != 0) &&
       (((*DAT_000121e8 != '\0' || (*DAT_000121ec != '\0')) || (6 < (int)*DAT_000121f0)))) {
      snprintf(tmp42,0x800,DAT_000121f8,pool->pool_no);
      _applog(7,tmp42,false);
    }
  }
  suspend_stratum(pool);
  return (_Bool)cVar4;
}

