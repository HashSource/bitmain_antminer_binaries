
/* WARNING: Unknown calling convention */

_Bool new_nonce(thr_info *thr,uint nonce)

{
  undefined1 uVar1;
  cgpu_info *pcVar2;
  bool bVar3;
  char tmp42 [2048];
  
  pcVar2 = thr->cgpu;
  bVar3 = pcVar2->last_nonce == nonce;
  if (!bVar3) {
    pcVar2->last_nonce = nonce;
    thr = (thr_info *)0x1;
  }
  uVar1 = SUB41(thr,0);
  if ((bVar3) &&
     (((use_syslog != false || (opt_log_output != false)) || (uVar1 = 0, 5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s %d duplicate share detected as HW error",pcVar2->drv->name,
             pcVar2->device_id);
    _applog(6,tmp42,false);
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

