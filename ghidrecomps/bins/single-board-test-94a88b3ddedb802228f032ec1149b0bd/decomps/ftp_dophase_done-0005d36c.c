
int ftp_dophase_done(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined auStack_14 [4];
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  if (param_2 == 0) {
    if (*(int *)(iVar2 + 0xc) == 0) {
      *(undefined *)((int)param_1 + 0x1f5) = 1;
      goto LAB_0005d384;
    }
  }
  else {
    iVar1 = ftp_do_more(param_1,auStack_14);
    if (iVar1 != 0) {
      close_secondarysocket(param_1);
      return iVar1;
    }
    if (*(int *)(iVar2 + 0xc) == 0) goto LAB_0005d384;
  }
  Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
LAB_0005d384:
  *(undefined *)((int)param_1 + 0x40d) = 1;
  return 0;
}

