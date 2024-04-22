
void bitmain_c5_detect(void)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  
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
    local_818._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[0];
    local_818._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[1];
    local_818._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[2];
    local_818._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[3];
    uStack_814._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[4];
    uStack_814._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[5];
    uStack_814._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[6];
    uStack_814._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[7];
    uStack_810._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[8];
    uStack_810._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[9];
    uStack_810._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[10];
    uStack_810._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[11];
    uStack_80c._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[12];
    uStack_80c._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[13];
    uStack_80c._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[14];
    uStack_80c._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[15];
    local_808._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[16];
    local_808._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[17];
    local_808._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[18];
    local_808._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[19];
    uStack_804._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[20];
    uStack_804._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[21];
    uStack_804._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[22];
    uStack_804._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[23];
    uStack_800._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[24];
    uStack_800._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[25];
    uStack_800._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[26];
    uStack_800._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[27];
    uStack_7fc._0_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[28];
    uStack_7fc._1_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[29];
    uStack_7fc._2_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[30];
    uStack_7fc._3_1_ = s_Failed_to_calloc_cgpu_info_data_00061f38[31];
    _applog(3,&local_818,1);
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

