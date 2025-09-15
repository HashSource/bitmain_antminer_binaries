
void bitmain_c5_detect(void)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  char local_818 [2052];
  
  pvVar1 = calloc(1,0x188);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cgpu","driver-btm-c5.c",0x4124,"bitmain_c5_detect");
  }
  *(undefined1 **)((int)pvVar1 + 4) = &bitmain_c5_drv;
  *(undefined4 *)((int)pvVar1 + 0x20) = 0;
  *(undefined4 *)((int)pvVar1 + 0x94) = 1;
  pvVar2 = calloc(0x1898,1);
  *(void **)((int)pvVar1 + 0x14) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    builtin_strncpy(local_818,"Failed to calloc cgpu_info data",0x20);
    _applog(3,local_818,1);
    _quit(1);
    pvVar2 = *(void **)((int)pvVar1 + 0x14);
  }
  *(undefined4 *)((int)pvVar2 + 0x1888) = 0;
  *(undefined4 *)((int)pvVar2 + 0x188c) = 1;
  *(undefined4 *)((int)pvVar2 + 0x1890) = 2;
  iVar3 = add_cgpu(pvVar1);
  if (iVar3 != 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("add_cgpu(cgpu)","driver-btm-c5.c",0x4130,"bitmain_c5_detect");
}

