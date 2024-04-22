
/* WARNING: Unknown calling convention */

int bitmain_axi_close(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = munmap(*(void **)(DAT_0002d848 + 0x8d4),0x160);
  if (((iVar1 < 0) && (*DAT_0002d858 != '\0')) &&
     ((*DAT_0002d85c != '\0' || ((*DAT_0002d860 != '\0' || (6 < *DAT_0002d864)))))) {
    tmp42._0_4_ = *DAT_0002d868;
    tmp42._4_4_ = DAT_0002d868[1];
    tmp42._8_4_ = DAT_0002d868[2];
    tmp42._12_4_ = DAT_0002d868[3];
    _applog(7,tmp42,false);
  }
  iVar1 = munmap(*(void **)(DAT_0002d84c + 0x200),0x1000000);
  if (((iVar1 < 0) && (*DAT_0002d858 != '\0')) &&
     ((*DAT_0002d85c != '\0' || ((*DAT_0002d860 != '\0' || (6 < *DAT_0002d864)))))) {
    tmp42._0_4_ = *DAT_0002d868;
    tmp42._4_4_ = DAT_0002d868[1];
    tmp42._8_4_ = DAT_0002d868[2];
    tmp42._12_4_ = DAT_0002d868[3];
    _applog(7,tmp42,false);
  }
  close(*DAT_0002d850);
  iVar1 = close(*DAT_0002d854);
  return iVar1;
}

