
void roll_work(work *work)

{
  uint __bsx;
  uint uVar1;
  work *work_local;
  char tmp42 [2048];
  uint ntime;
  uint *work_ntime;
  
  uVar1 = *(uint *)(work->data + 0x44);
  uVar1 = (uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8) + 1;
  *(uint *)(work->data + 0x44) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 * 0x1000000;
  local_work = local_work + 1;
  work->rolls = work->rolls + 1;
  work->nonce = 0;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Successfully rolled work",0x18);
    tmp42[0x18] = '\0';
    _applog(7,tmp42,false);
  }
  if (work->ntime != (char *)0x0) {
    modify_ntime(work->ntime,1);
  }
  uVar1 = total_work_inc();
  work->id = uVar1;
  return;
}

