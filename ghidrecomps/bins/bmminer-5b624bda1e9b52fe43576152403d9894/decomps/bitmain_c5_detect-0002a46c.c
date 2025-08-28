
/* WARNING: Unknown calling convention */

void bitmain_c5_detect(_Bool hotplug)

{
  _Bool _Var1;
  cgpu_info *cgpu;
  void *pvVar2;
  char tmp42 [2048];
  
  cgpu = (cgpu_info *)calloc(1,0x188);
  if (cgpu == (cgpu_info *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cgpu","driver-btm-c5.c",0x2df4,"bitmain_c5_detect");
  }
  cgpu->deven = DEV_ENABLED;
  cgpu->threads = 1;
  cgpu->drv = &bitmain_c5_drv;
  pvVar2 = calloc(0x1798,1);
  cgpu->device_data = pvVar2;
  if (pvVar2 == (void *)0x0) {
    builtin_strncpy(tmp42,"Failed to calloc cgpu_info data",0x20);
    _applog(3,tmp42,true);
    _quit(1);
    pvVar2 = cgpu->device_data;
  }
  *(undefined4 *)((int)pvVar2 + 0x1788) = 0;
  *(undefined4 *)((int)pvVar2 + 0x178c) = 1;
  *(undefined4 *)((int)pvVar2 + 0x1790) = 2;
  _Var1 = add_cgpu(cgpu);
  if (_Var1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("add_cgpu(cgpu)","driver-btm-c5.c",0x2e00,"bitmain_c5_detect");
}

