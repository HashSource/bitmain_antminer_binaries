
void mcast_init(void)

{
  void *pvVar1;
  int iVar2;
  char local_810 [24];
  undefined4 uStack_7f8;
  undefined2 uStack_7f4;
  undefined1 local_7f2;
  
  pvVar1 = calloc(1,0x40);
  if (pvVar1 == (void *)0x0) {
    builtin_strncpy(local_810,"Failed to calloc mcast t",0x18);
    uStack_7f8 = CONCAT13(uStack_7f8._3_1_,0x7268);
    _applog(3,local_810,1);
    _quit(1);
  }
  iVar2 = thr_info_create(pvVar1,0,0x15a15,pvVar1);
  if (iVar2 != 0) {
    builtin_strncpy(local_810,"API mcast thread create ",0x18);
    uStack_7f8._0_1_ = 'f';
    uStack_7f8._1_1_ = 'a';
    uStack_7f8._2_1_ = 'i';
    uStack_7f8._3_1_ = 'l';
    uStack_7f4 = 0x6465;
    local_7f2 = 0;
    _applog(3,local_810,1);
    _quit(1);
  }
  return;
}

