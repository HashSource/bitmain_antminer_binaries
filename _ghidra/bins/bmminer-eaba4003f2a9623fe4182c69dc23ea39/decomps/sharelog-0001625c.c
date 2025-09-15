
void sharelog(char *disposition,work *work)

{
  cgpu_info *pcVar1;
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  size_t sVar2;
  int thr_id_00;
  pool *ppVar3;
  __time_t _Var4;
  work *work_local;
  char *disposition_local;
  char tmp42 [2048];
  char s [1024];
  size_t ret;
  int rv;
  char *data;
  char *hash;
  char *target;
  ulong t;
  pool *pool;
  cgpu_info *cgpu;
  int thr_id;
  
  if (sharelog_file != (FILE *)0x0) {
    thr_id_00 = work->thr_id;
    pcVar1 = get_thr_cgpu(thr_id_00);
    ppVar3 = work->pool;
    _Var4 = (work->tv_work_found).tv_sec;
    __ptr = bin2hex(work->target,0x20);
    __ptr_00 = bin2hex(work->hash,0x20);
    __ptr_01 = bin2hex(work->data,0x80);
    sVar2 = snprintf(s,0x400,"%lu,%s,%s,%s,%s%u,%u,%s,%s\n",_Var4,disposition,__ptr,ppVar3->rpc_url,
                     pcVar1->drv->name,pcVar1->device_id,thr_id_00,__ptr_00,__ptr_01);
    free(__ptr);
    free(__ptr_00);
    free(__ptr_01);
    if ((int)sVar2 < 0x400) {
      if ((int)sVar2 < 0) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
          return;
        }
        builtin_strncpy(tmp42,"sharelog printf erro",0x14);
        tmp42[0x14] = 'r';
        tmp42[0x15] = '\0';
        _applog(3,tmp42,false);
        return;
      }
    }
    else {
      s[0x3ff] = '\0';
    }
    _mutex_lock(&sharelog_lock,"cgminer.c","sharelog",0x289);
    sVar2 = fwrite(s,sVar2,1,(FILE *)sharelog_file);
    fflush((FILE *)sharelog_file);
    _mutex_unlock(&sharelog_lock,"cgminer.c","sharelog",0x28c);
    if ((sVar2 != 1) &&
       (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
      builtin_strncpy(tmp42,"sharelog fwrite erro",0x14);
      tmp42[0x14] = 'r';
      tmp42[0x15] = '\0';
      _applog(3,tmp42,false);
    }
  }
  return;
}

