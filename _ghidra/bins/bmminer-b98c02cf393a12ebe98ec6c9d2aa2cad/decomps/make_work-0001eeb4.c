
int make_work(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_810 [32];
  undefined2 uStack_7f0;
  undefined1 local_7ee;
  
  iVar1 = _cgcalloc(1,0x1c0,"cgminer.c","make_work",0x8a6);
  if (iVar1 != 0) {
    uVar2 = total_work_inc();
    *(undefined4 *)(iVar1 + 0x154) = uVar2;
    return iVar1;
  }
  builtin_strncpy(local_810,"Failed to calloc work in make_wo",0x20);
  uStack_7f0 = 0x6b72;
  local_7ee = 0;
  _applog(3,local_810,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

