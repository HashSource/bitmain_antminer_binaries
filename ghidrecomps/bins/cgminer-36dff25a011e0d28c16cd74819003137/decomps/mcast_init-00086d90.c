
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void mcast_init(void)

{
  thr_info *thr_00;
  int iVar1;
  char tmp42 [2048];
  thr_info *thr;
  
  thr_00 = (thr_info *)_cgcalloc(1,0x40,"api-btm.c","mcast_init",0x1473);
  iVar1 = thr_info_create(thr_00,(pthread_attr_t *)0x0,mcast_thread,thr_00);
  if (iVar1 != 0) {
    tmp42[0] = s_API_mcast_thread_create_failed_000aeaa8[0];
    tmp42[1] = s_API_mcast_thread_create_failed_000aeaa8[1];
    tmp42[2] = s_API_mcast_thread_create_failed_000aeaa8[2];
    tmp42[3] = s_API_mcast_thread_create_failed_000aeaa8[3];
    tmp42[4] = s_API_mcast_thread_create_failed_000aeaa8[4];
    tmp42[5] = s_API_mcast_thread_create_failed_000aeaa8[5];
    tmp42[6] = s_API_mcast_thread_create_failed_000aeaa8[6];
    tmp42[7] = s_API_mcast_thread_create_failed_000aeaa8[7];
    tmp42[8] = s_API_mcast_thread_create_failed_000aeaa8[8];
    tmp42[9] = s_API_mcast_thread_create_failed_000aeaa8[9];
    tmp42[10] = s_API_mcast_thread_create_failed_000aeaa8[10];
    tmp42[11] = s_API_mcast_thread_create_failed_000aeaa8[11];
    tmp42[12] = s_API_mcast_thread_create_failed_000aeaa8[12];
    tmp42[13] = s_API_mcast_thread_create_failed_000aeaa8[13];
    tmp42[14] = s_API_mcast_thread_create_failed_000aeaa8[14];
    tmp42[15] = s_API_mcast_thread_create_failed_000aeaa8[15];
    tmp42[16] = s_API_mcast_thread_create_failed_000aeaa8[16];
    tmp42[17] = s_API_mcast_thread_create_failed_000aeaa8[17];
    tmp42[18] = s_API_mcast_thread_create_failed_000aeaa8[18];
    tmp42[19] = s_API_mcast_thread_create_failed_000aeaa8[19];
    tmp42[20] = s_API_mcast_thread_create_failed_000aeaa8[20];
    tmp42[21] = s_API_mcast_thread_create_failed_000aeaa8[21];
    tmp42[22] = s_API_mcast_thread_create_failed_000aeaa8[22];
    tmp42[23] = s_API_mcast_thread_create_failed_000aeaa8[23];
    tmp42[24] = s_API_mcast_thread_create_failed_000aeaa8[24];
    tmp42[25] = s_API_mcast_thread_create_failed_000aeaa8[25];
    tmp42[26] = s_API_mcast_thread_create_failed_000aeaa8[26];
    tmp42[27] = s_API_mcast_thread_create_failed_000aeaa8[27];
    tmp42._28_2_ = (undefined2)ram0x000aeac4;
    tmp42[30] = (char)((uint)ram0x000aeac4 >> 0x10);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

