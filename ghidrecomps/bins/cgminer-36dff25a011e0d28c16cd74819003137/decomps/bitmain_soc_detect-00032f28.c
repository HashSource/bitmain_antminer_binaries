
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
    __assert_fail("cgpu","driver-btm-soc.c",0x20d8,"bitmain_soc_detect");
  }
  cgpu_00->drv = &bitmain_soc_drv;
  cgpu_00->deven = DEV_ENABLED;
  cgpu_00->threads = 1;
  pvVar2 = calloc(0x1898,1);
  cgpu_00->device_data = pvVar2;
  if (cgpu_00->device_data == (void *)0x0) {
    tmp42[0] = s_Failed_to_calloc_cgpu_info_data_0009d620[0];
    tmp42[1] = s_Failed_to_calloc_cgpu_info_data_0009d620[1];
    tmp42[2] = s_Failed_to_calloc_cgpu_info_data_0009d620[2];
    tmp42[3] = s_Failed_to_calloc_cgpu_info_data_0009d620[3];
    tmp42[4] = s_Failed_to_calloc_cgpu_info_data_0009d620[4];
    tmp42[5] = s_Failed_to_calloc_cgpu_info_data_0009d620[5];
    tmp42[6] = s_Failed_to_calloc_cgpu_info_data_0009d620[6];
    tmp42[7] = s_Failed_to_calloc_cgpu_info_data_0009d620[7];
    tmp42[8] = s_Failed_to_calloc_cgpu_info_data_0009d620[8];
    tmp42[9] = s_Failed_to_calloc_cgpu_info_data_0009d620[9];
    tmp42[10] = s_Failed_to_calloc_cgpu_info_data_0009d620[10];
    tmp42[11] = s_Failed_to_calloc_cgpu_info_data_0009d620[11];
    tmp42[12] = s_Failed_to_calloc_cgpu_info_data_0009d620[12];
    tmp42[13] = s_Failed_to_calloc_cgpu_info_data_0009d620[13];
    tmp42[14] = s_Failed_to_calloc_cgpu_info_data_0009d620[14];
    tmp42[15] = s_Failed_to_calloc_cgpu_info_data_0009d620[15];
    tmp42[16] = s_Failed_to_calloc_cgpu_info_data_0009d620[16];
    tmp42[17] = s_Failed_to_calloc_cgpu_info_data_0009d620[17];
    tmp42[18] = s_Failed_to_calloc_cgpu_info_data_0009d620[18];
    tmp42[19] = s_Failed_to_calloc_cgpu_info_data_0009d620[19];
    tmp42[20] = s_Failed_to_calloc_cgpu_info_data_0009d620[20];
    tmp42[21] = s_Failed_to_calloc_cgpu_info_data_0009d620[21];
    tmp42[22] = s_Failed_to_calloc_cgpu_info_data_0009d620[22];
    tmp42[23] = s_Failed_to_calloc_cgpu_info_data_0009d620[23];
    tmp42[24] = s_Failed_to_calloc_cgpu_info_data_0009d620[24];
    tmp42[25] = s_Failed_to_calloc_cgpu_info_data_0009d620[25];
    tmp42[26] = s_Failed_to_calloc_cgpu_info_data_0009d620[26];
    tmp42[27] = s_Failed_to_calloc_cgpu_info_data_0009d620[27];
    tmp42[28] = s_Failed_to_calloc_cgpu_info_data_0009d620[28];
    tmp42[29] = s_Failed_to_calloc_cgpu_info_data_0009d620[29];
    tmp42[30] = s_Failed_to_calloc_cgpu_info_data_0009d620[30];
    tmp42[31] = s_Failed_to_calloc_cgpu_info_data_0009d620[31];
    _applog(3,tmp42,true);
    _quit(1);
  }
  pvVar2 = cgpu_00->device_data;
  *(undefined4 *)((int)pvVar2 + 0x1888) = 0;
  *(undefined4 *)((int)pvVar2 + 0x188c) = 1;
  *(undefined4 *)((int)pvVar2 + 0x1890) = 2;
  _Var1 = add_cgpu(cgpu_00);
  if (!_Var1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("add_cgpu(cgpu)","driver-btm-soc.c",0x20e4,"bitmain_soc_detect");
  }
  return;
}

