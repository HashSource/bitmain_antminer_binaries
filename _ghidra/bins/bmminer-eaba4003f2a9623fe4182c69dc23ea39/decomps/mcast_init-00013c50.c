
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mcast_init(void)

{
  thr_info *thr_00;
  int iVar1;
  char tmp42 [2048];
  thr_info *thr;
  
  thr_00 = (thr_info *)_cgcalloc(1,0x40,"api-btm.c","mcast_init",0x1465);
  iVar1 = thr_info_create(thr_00,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x13c0d,thr_00);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"API mcast thread create fail",0x1c);
    tmp42[0x1c] = 'e';
    tmp42[0x1d] = 'd';
    tmp42[0x1e] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

