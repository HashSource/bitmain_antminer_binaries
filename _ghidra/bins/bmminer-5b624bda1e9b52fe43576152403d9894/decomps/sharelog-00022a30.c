
/* WARNING: Unknown calling convention */

void sharelog(char *disposition,work *work)

{
  thr_info *ptVar1;
  char *pcVar2;
  char *__ptr;
  char *__ptr_00;
  size_t sVar3;
  pool *ppVar4;
  char *func;
  char *func_00;
  __time_t _Var5;
  int line;
  int line_00;
  int iVar6;
  cgpu_info *cgpu;
  cgpu_info *pcVar7;
  char s [1024];
  char tmp42 [2048];
  
  if (sharelog_file == (FILE *)0x0) {
    return;
  }
  iVar6 = work->thr_id;
  ptVar1 = get_thread(iVar6);
  ppVar4 = work->pool;
  _Var5 = (work->tv_work_found).tv_sec;
  pcVar7 = ptVar1->cgpu;
  pcVar2 = bin2hex(work->target,0x20);
  __ptr = bin2hex(work->hash,0x20);
  __ptr_00 = bin2hex(work->data,0x80);
  sVar3 = snprintf(s,0x400,"%lu,%s,%s,%s,%s%u,%u,%s,%s\n",_Var5,disposition,pcVar2,ppVar4->rpc_url,
                   pcVar7->drv->name,pcVar7->device_id,iVar6,__ptr,__ptr_00);
  free(pcVar2);
  free(__ptr);
  free(__ptr_00);
  if ((int)sVar3 < 0x400) {
    if ((int)sVar3 < 0) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
        return;
      }
      pcVar2 = "sharelog printf error";
      goto LAB_00022b1c;
    }
  }
  else {
    s[0x3ff] = '\0';
  }
  iVar6 = pthread_mutex_lock((pthread_mutex_t *)&sharelog_lock);
  if (iVar6 != 0) {
    _mutex_lock((pthread_mutex_t *)"sharelog",(char *)0x282,func,line);
  }
  sVar3 = fwrite(s,sVar3,1,(FILE *)sharelog_file);
  fflush((FILE *)sharelog_file);
  iVar6 = pthread_mutex_unlock((pthread_mutex_t *)&sharelog_lock);
  if (iVar6 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"sharelog",(char *)0x285,func_00,line_00);
  }
  (*selective_yield)();
  if (sVar3 == 1) {
    return;
  }
  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
    return;
  }
  pcVar2 = "sharelog fwrite error";
LAB_00022b1c:
  tmp42._0_4_ = *(undefined4 *)pcVar2;
  tmp42._4_4_ = *(undefined4 *)(pcVar2 + 4);
  tmp42._8_4_ = *(undefined4 *)(pcVar2 + 8);
  tmp42._12_4_ = *(undefined4 *)(pcVar2 + 0xc);
  tmp42._16_4_ = *(undefined4 *)(pcVar2 + 0x10);
  tmp42._20_2_ = (undefined2)*(undefined4 *)(pcVar2 + 0x14);
  _applog(3,tmp42,false);
  return;
}

