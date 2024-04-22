
/* WARNING: Unknown calling convention */

work * make_work(void)

{
  work *pwVar1;
  work *work;
  uint uVar2;
  char tmp42 [2048];
  
  pwVar1 = (work *)_cgcalloc(1,0x1c0,DAT_00021dcc,DAT_00021dd0,0x88f);
  if (pwVar1 == (work *)0x0) {
    tmp42._0_4_ = *DAT_00021dd4;
    tmp42._4_4_ = DAT_00021dd4[1];
    tmp42._8_4_ = DAT_00021dd4[2];
    tmp42._12_4_ = DAT_00021dd4[3];
    tmp42._16_4_ = DAT_00021dd4[4];
    tmp42._20_4_ = DAT_00021dd4[5];
    tmp42._24_4_ = DAT_00021dd4[6];
    tmp42._28_4_ = DAT_00021dd4[7];
    tmp42._32_2_ = (undefined2)DAT_00021dd4[8];
    tmp42[34] = (char)((uint)DAT_00021dd4[8] >> 0x10);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar2 = total_work_inc();
  pwVar1->id = uVar2;
  return pwVar1;
}

