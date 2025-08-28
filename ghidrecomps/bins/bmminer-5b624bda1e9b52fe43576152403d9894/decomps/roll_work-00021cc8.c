
/* WARNING: Unknown calling convention */

void roll_work(work *work)

{
  _Bool _Var1;
  uint uVar2;
  int iVar3;
  char *hexstr;
  char tmp42 [2048];
  
  _Var1 = opt_debug;
  uVar2 = *(uint *)(work->data + 0x44);
  iVar3 = work->rolls;
  uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
          ) + 1;
  local_work = local_work + 1;
  *(uint *)(work->data + 0x44) =
       uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
  ;
  work->rolls = iVar3 + 1;
  work->nonce = 0;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Successfully rolled work",0x18);
    tmp42[0x18] = '\0';
    _applog(7,tmp42,false);
  }
  hexstr = work->ntime;
  if (hexstr != (char *)0x0) {
    hex2bin((uchar *)tmp42,hexstr,4);
    uVar2 = (tmp42._0_4_ << 0x18 | ((uint)tmp42._0_4_ >> 8 & 0xff) << 0x10 |
             ((uint)tmp42._0_4_ >> 0x10 & 0xff) << 8 | (uint)tmp42._0_4_ >> 0x18) + 1;
    tmp42._0_4_ = uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                  uVar2 >> 0x18;
    __bin2hex(hexstr,(uchar *)tmp42,4);
  }
  uVar2 = total_work_inc();
  work->id = uVar2;
  return;
}

