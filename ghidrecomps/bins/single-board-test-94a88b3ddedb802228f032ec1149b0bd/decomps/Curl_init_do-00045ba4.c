
undefined4 Curl_init_do(int param_1,int param_2)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar1;
  bool bVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  
  if (param_2 != 0) {
    *(undefined *)(param_2 + 0x1f5) = 0;
  }
  *(undefined *)(param_1 + 0x86bc) = 0;
  *(undefined *)(param_1 + 0x867c) = 0;
  if (*(char *)(param_1 + 0x307) == '\0') {
    iVar1 = *(int *)(param_1 + 0x278);
    bVar2 = iVar1 == 5;
    if (bVar2) {
      iVar1 = 1;
    }
    if (bVar2) {
      *(int *)(param_1 + 0x278) = iVar1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x278) = 5;
  }
  curlx_tvnow(&local_28);
  *(undefined4 *)(param_1 + 0x88) = local_28;
  *(undefined4 *)(param_1 + 0x8c) = uStack_24;
  *(int *)(param_1 + 0x128) = param_1 + 0x459d;
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x594);
  *(int *)(param_1 + 0x124) = param_1 + 0x59c;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined *)(param_1 + 0x135) = 0;
  Curl_speedinit(param_1);
  Curl_pgrsSetUploadCounter(param_1,extraout_r1,0,0);
  Curl_pgrsSetDownloadCounter(param_1,extraout_r1_00,0,0);
  return 0;
}

