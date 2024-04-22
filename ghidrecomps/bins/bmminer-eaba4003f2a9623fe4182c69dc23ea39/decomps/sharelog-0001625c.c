
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
        tmp42[0] = s_sharelog_printf_error_00071178[0];
        tmp42[1] = s_sharelog_printf_error_00071178[1];
        tmp42[2] = s_sharelog_printf_error_00071178[2];
        tmp42[3] = s_sharelog_printf_error_00071178[3];
        tmp42[4] = s_sharelog_printf_error_00071178[4];
        tmp42[5] = s_sharelog_printf_error_00071178[5];
        tmp42[6] = s_sharelog_printf_error_00071178[6];
        tmp42[7] = s_sharelog_printf_error_00071178[7];
        tmp42[8] = s_sharelog_printf_error_00071178[8];
        tmp42[9] = s_sharelog_printf_error_00071178[9];
        tmp42[10] = s_sharelog_printf_error_00071178[10];
        tmp42[11] = s_sharelog_printf_error_00071178[11];
        tmp42[12] = s_sharelog_printf_error_00071178[12];
        tmp42[13] = s_sharelog_printf_error_00071178[13];
        tmp42[14] = s_sharelog_printf_error_00071178[14];
        tmp42[15] = s_sharelog_printf_error_00071178[15];
        tmp42[16] = s_sharelog_printf_error_00071178[16];
        tmp42[17] = s_sharelog_printf_error_00071178[17];
        tmp42[18] = s_sharelog_printf_error_00071178[18];
        tmp42[19] = s_sharelog_printf_error_00071178[19];
        tmp42._20_2_ = (undefined2)ram0x0007118c;
        _applog(3,tmp42,false);
        return;
      }
    }
    else {
      s[1023] = '\0';
    }
    _mutex_lock(&sharelog_lock,"cgminer.c","sharelog",0x289);
    sVar2 = fwrite(s,sVar2,1,(FILE *)sharelog_file);
    fflush((FILE *)sharelog_file);
    _mutex_unlock(&sharelog_lock,"cgminer.c","sharelog",0x28c);
    if ((sVar2 != 1) &&
       (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
      tmp42[0] = s_sharelog_fwrite_error_00071190[0];
      tmp42[1] = s_sharelog_fwrite_error_00071190[1];
      tmp42[2] = s_sharelog_fwrite_error_00071190[2];
      tmp42[3] = s_sharelog_fwrite_error_00071190[3];
      tmp42[4] = s_sharelog_fwrite_error_00071190[4];
      tmp42[5] = s_sharelog_fwrite_error_00071190[5];
      tmp42[6] = s_sharelog_fwrite_error_00071190[6];
      tmp42[7] = s_sharelog_fwrite_error_00071190[7];
      tmp42[8] = s_sharelog_fwrite_error_00071190[8];
      tmp42[9] = s_sharelog_fwrite_error_00071190[9];
      tmp42[10] = s_sharelog_fwrite_error_00071190[10];
      tmp42[11] = s_sharelog_fwrite_error_00071190[11];
      tmp42[12] = s_sharelog_fwrite_error_00071190[12];
      tmp42[13] = s_sharelog_fwrite_error_00071190[13];
      tmp42[14] = s_sharelog_fwrite_error_00071190[14];
      tmp42[15] = s_sharelog_fwrite_error_00071190[15];
      tmp42[16] = s_sharelog_fwrite_error_00071190[16];
      tmp42[17] = s_sharelog_fwrite_error_00071190[17];
      tmp42[18] = s_sharelog_fwrite_error_00071190[18];
      tmp42[19] = s_sharelog_fwrite_error_00071190[19];
      tmp42._20_2_ = (undefined2)ram0x000711a4;
      _applog(3,tmp42,false);
    }
  }
  return;
}

