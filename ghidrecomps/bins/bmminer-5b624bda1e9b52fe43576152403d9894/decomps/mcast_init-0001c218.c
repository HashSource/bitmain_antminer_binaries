
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mcast_init(void)

{
  undefined4 uVar1;
  thr_info *thr;
  int iVar2;
  char tmp42 [2048];
  
  thr = (thr_info *)calloc(1,0x40);
  uVar1 = tmp42._24_4_;
  if (thr == (thr_info *)0x0) {
    builtin_strncpy(tmp42,"Failed to calloc mcast thr",0x1b);
    tmp42[0x1b] = SUB41(uVar1,3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar2 = thr_info_create(thr,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x1911d,thr);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"API mcast thread create fail",0x1c);
    tmp42[0x1c] = 'e';
    tmp42[0x1d] = 'd';
    tmp42[0x1e] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

