
int Curl_pgrsDone(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x470) = 0;
  iVar1 = Curl_pgrsUpdate();
  if (iVar1 == 0) {
    if ((-1 < *(int *)(iVar2 + 0x4a8) << 0x1b) && (*(char *)(iVar2 + 0x4a0) == '\0')) {
      curl_mfprintf(*(undefined4 *)(iVar2 + 0x150),DAT_0003e6fc,param_3,0,param_4);
    }
    *(undefined4 *)(iVar2 + 0x578) = 0;
  }
  return iVar1;
}

