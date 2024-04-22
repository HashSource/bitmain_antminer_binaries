
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mcast_init(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined4 uStack_7f8;
  undefined2 uStack_7f4;
  undefined local_7f2;
  
  pvVar1 = calloc(1,0x40);
  if (pvVar1 == (void *)0x0) {
    local_810._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[0];
    local_810._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[1];
    local_810._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[2];
    local_810._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[3];
    uStack_80c._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[4];
    uStack_80c._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[5];
    uStack_80c._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[6];
    uStack_80c._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[7];
    uStack_808._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[8];
    uStack_808._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[9];
    uStack_808._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[10];
    uStack_808._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[11];
    uStack_804._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[12];
    uStack_804._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[13];
    uStack_804._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[14];
    uStack_804._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[15];
    local_800._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[16];
    local_800._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[17];
    local_800._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[18];
    local_800._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[19];
    uStack_7fc._0_1_ = s_Failed_to_calloc_mcast_thr_0005872c[20];
    uStack_7fc._1_1_ = s_Failed_to_calloc_mcast_thr_0005872c[21];
    uStack_7fc._2_1_ = s_Failed_to_calloc_mcast_thr_0005872c[22];
    uStack_7fc._3_1_ = s_Failed_to_calloc_mcast_thr_0005872c[23];
    _applog(3,&local_810,1);
    _quit(1);
  }
  iVar2 = thr_info_create(pvVar1,0,0x15a15,pvVar1);
  if (iVar2 != 0) {
    local_810._0_1_ = s_API_mcast_thread_create_failed_00058748[0];
    local_810._1_1_ = s_API_mcast_thread_create_failed_00058748[1];
    local_810._2_1_ = s_API_mcast_thread_create_failed_00058748[2];
    local_810._3_1_ = s_API_mcast_thread_create_failed_00058748[3];
    uStack_80c._0_1_ = s_API_mcast_thread_create_failed_00058748[4];
    uStack_80c._1_1_ = s_API_mcast_thread_create_failed_00058748[5];
    uStack_80c._2_1_ = s_API_mcast_thread_create_failed_00058748[6];
    uStack_80c._3_1_ = s_API_mcast_thread_create_failed_00058748[7];
    uStack_808._0_1_ = s_API_mcast_thread_create_failed_00058748[8];
    uStack_808._1_1_ = s_API_mcast_thread_create_failed_00058748[9];
    uStack_808._2_1_ = s_API_mcast_thread_create_failed_00058748[10];
    uStack_808._3_1_ = s_API_mcast_thread_create_failed_00058748[11];
    uStack_804._0_1_ = s_API_mcast_thread_create_failed_00058748[12];
    uStack_804._1_1_ = s_API_mcast_thread_create_failed_00058748[13];
    uStack_804._2_1_ = s_API_mcast_thread_create_failed_00058748[14];
    uStack_804._3_1_ = s_API_mcast_thread_create_failed_00058748[15];
    local_800._0_1_ = s_API_mcast_thread_create_failed_00058748[16];
    local_800._1_1_ = s_API_mcast_thread_create_failed_00058748[17];
    local_800._2_1_ = s_API_mcast_thread_create_failed_00058748[18];
    local_800._3_1_ = s_API_mcast_thread_create_failed_00058748[19];
    uStack_7fc._0_1_ = s_API_mcast_thread_create_failed_00058748[20];
    uStack_7fc._1_1_ = s_API_mcast_thread_create_failed_00058748[21];
    uStack_7fc._2_1_ = s_API_mcast_thread_create_failed_00058748[22];
    uStack_7fc._3_1_ = s_API_mcast_thread_create_failed_00058748[23];
    uStack_7f8._0_1_ = s_API_mcast_thread_create_failed_00058748[24];
    uStack_7f8._1_1_ = s_API_mcast_thread_create_failed_00058748[25];
    uStack_7f8._2_1_ = s_API_mcast_thread_create_failed_00058748[26];
    uStack_7f8._3_1_ = s_API_mcast_thread_create_failed_00058748[27];
    uStack_7f4 = (undefined2)ram0x00058764;
    local_7f2 = (undefined)((uint)ram0x00058764 >> 0x10);
    _applog(3,&local_810,1);
    _quit(1);
  }
  return;
}

