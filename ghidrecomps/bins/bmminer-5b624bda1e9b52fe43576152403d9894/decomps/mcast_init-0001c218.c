
/* WARNING: Unknown calling convention */

void mcast_init(void)

{
  thr_info *thr_00;
  thr_info *thr;
  int iVar1;
  char tmp42 [2048];
  
  thr_00 = (thr_info *)calloc(1,0x40);
  if (thr_00 == (thr_info *)0x0) {
    tmp42._0_4_ = *DAT_0001c294;
    tmp42._4_4_ = DAT_0001c294[1];
    tmp42._8_4_ = DAT_0001c294[2];
    tmp42._12_4_ = DAT_0001c294[3];
    tmp42._16_4_ = DAT_0001c294[4];
    tmp42._20_4_ = DAT_0001c294[5];
    tmp42._24_3_ = (undefined3)DAT_0001c294[6];
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = thr_info_create(thr_00,(pthread_attr_t *)0x0,DAT_0001c28c,thr_00);
  if (iVar1 != 0) {
    tmp42._0_4_ = *DAT_0001c290;
    tmp42._4_4_ = DAT_0001c290[1];
    tmp42._8_4_ = DAT_0001c290[2];
    tmp42._12_4_ = DAT_0001c290[3];
    tmp42._16_4_ = DAT_0001c290[4];
    tmp42._20_4_ = DAT_0001c290[5];
    tmp42._24_4_ = DAT_0001c290[6];
    tmp42._28_2_ = (undefined2)DAT_0001c290[7];
    tmp42[30] = (char)((uint)DAT_0001c290[7] >> 0x10);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

