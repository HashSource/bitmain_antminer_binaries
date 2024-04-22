
/* WARNING: Unknown calling convention */

void restart_threads(void)

{
  char tmp42 [2048];
  
  tmp42._0_4_ = *DAT_0000a958;
  tmp42._4_4_ = DAT_0000a958[1];
  tmp42._8_4_ = DAT_0000a958[2];
  tmp42._12_4_ = DAT_0000a958[3];
  tmp42._16_4_ = DAT_0000a958[4];
  tmp42._20_4_ = DAT_0000a958[5];
  tmp42._24_4_ = DAT_0000a958[6];
  tmp42._28_4_ = DAT_0000a958[7];
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

