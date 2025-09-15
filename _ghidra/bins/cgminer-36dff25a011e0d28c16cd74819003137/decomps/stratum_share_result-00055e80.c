
void stratum_share_result(json_t *val,json_t *res_val,json_t *err_val,stratum_share *sshare)

{
  time_t tVar1;
  work *work_00;
  int iVar2;
  stratum_share *sshare_local;
  json_t *err_val_local;
  json_t *res_val_local;
  json_t *val_local;
  char tmp42 [2048];
  char hashshow [64];
  int srdiff;
  time_t now_t;
  work *work;
  
  work_00 = sshare->work;
  tVar1 = time((time_t *)0x0);
  iVar2 = tVar1 - sshare->sshare_sent;
  if (((opt_debug != false) || (0 < iVar2)) &&
     ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"Pool %d stratum share result lag time %d seconds",work_00->pool->pool_no,
             iVar2);
    _applog(6,tmp42,false);
  }
  show_hash(work_00,hashshow);
  share_result(val,res_val,err_val,work_00,hashshow,false,"");
  return;
}

