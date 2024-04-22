
/* WARNING: Unknown calling convention */

void bitmain_c5_detect(_Bool hotplug)

{
  device_drv *pdVar1;
  _Bool _Var2;
  cgpu_info *cgpu_00;
  cgpu_info *cgpu;
  bitmain_c5_info *a;
  char tmp42 [2048];
  
  cgpu_00 = (cgpu_info *)calloc(1,0x188);
  pdVar1 = DAT_0002a4fc;
  if (cgpu_00 == (cgpu_info *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail(DAT_0002a500,DAT_0002a504,0x2df4,DAT_0002a508);
  }
  cgpu_00->deven = DEV_ENABLED;
  cgpu_00->threads = 1;
  cgpu_00->drv = pdVar1;
  a = (bitmain_c5_info *)calloc(0x1798,1);
  cgpu_00->device_data = a;
  if (a == (bitmain_c5_info *)0x0) {
    tmp42._0_4_ = *DAT_0002a510;
    tmp42._4_4_ = DAT_0002a510[1];
    tmp42._8_4_ = DAT_0002a510[2];
    tmp42._12_4_ = DAT_0002a510[3];
    tmp42._16_4_ = DAT_0002a510[4];
    tmp42._20_4_ = DAT_0002a510[5];
    tmp42._24_4_ = DAT_0002a510[6];
    tmp42._28_4_ = DAT_0002a510[7];
    _applog(3,tmp42,true);
    _quit(1);
    a = (bitmain_c5_info *)cgpu_00->device_data;
  }
  a->pool0_given_id = 0;
  a->pool1_given_id = 1;
  a->pool2_given_id = 2;
  _Var2 = add_cgpu(cgpu_00);
  if (_Var2) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail(DAT_0002a50c,DAT_0002a504,0x2e00,DAT_0002a508);
}

