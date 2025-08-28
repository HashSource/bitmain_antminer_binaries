
/* WARNING: Unknown calling convention */

work * make_work(void)

{
  work *pwVar1;
  uint uVar2;
  char tmp42 [2048];
  work *work;
  
  pwVar1 = (work *)_cgcalloc(1,0x1c0,"cgminer.c","make_work",0x896);
  if (pwVar1 == (work *)0x0) {
    builtin_strncpy(tmp42,"Failed to calloc work in make_wo",0x20);
    tmp42[0x20] = 'r';
    tmp42[0x21] = 'k';
    tmp42[0x22] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar2 = total_work_inc();
  pwVar1->id = uVar2;
  return pwVar1;
}

