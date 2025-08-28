
void bitmain_soc_detect(_Bool hotplug)

{
  _Bool _Var1;
  cgpu_info *cgpu_00;
  void *pvVar2;
  _Bool hotplug_local;
  char tmp42 [2048];
  bitmain_soc_info *a;
  device_drv *drv;
  cgpu_info *cgpu;
  
  cgpu_00 = (cgpu_info *)calloc(1,0x188);
  if (cgpu_00 == (cgpu_info *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("cgpu","driver-btm-soc.c",0x2e13,"bitmain_soc_detect");
  }
  cgpu_00->drv = &bitmain_soc_drv;
  cgpu_00->deven = DEV_ENABLED;
  cgpu_00->threads = 1;
  pvVar2 = calloc(0x18b0,1);
  cgpu_00->device_data = pvVar2;
  if (cgpu_00->device_data == (void *)0x0) {
    builtin_strncpy(tmp42,"Failed to calloc cgpu_info data",0x20);
    _applog(3,tmp42,true);
    _quit(1);
  }
  pvVar2 = cgpu_00->device_data;
  *(undefined4 *)((int)pvVar2 + 0x18a0) = 0;
  *(undefined4 *)((int)pvVar2 + 0x18a4) = 1;
  *(undefined4 *)((int)pvVar2 + 0x18a8) = 2;
  _Var1 = add_cgpu(cgpu_00);
  if (!_Var1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("add_cgpu(cgpu)","driver-btm-soc.c",0x2e1f,"bitmain_soc_detect");
  }
  return;
}

