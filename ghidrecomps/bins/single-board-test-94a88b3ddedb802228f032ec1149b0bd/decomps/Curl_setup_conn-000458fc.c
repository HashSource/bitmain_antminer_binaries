
int Curl_setup_conn(int *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  int local_28;
  int iStack_24;
  
  iVar2 = *param_1;
  Curl_pgrsTime(iVar2,3);
  if ((*(uint *)(param_1[0x86] + 0x40) & 0x10) == 0) {
    iVar1 = *(int *)(iVar2 + 0x3a8);
    *param_2 = 0;
    *(undefined *)((int)param_1 + 0x202) = 0;
    if (iVar1 != 0) {
      (**DAT_000459d8)(param_1[0x8c]);
      param_1[0x8c] = 0;
      iVar1 = curl_maprintf(DAT_000459dc,*(undefined4 *)(iVar2 + 0x3a8));
      param_1[0x8c] = iVar1;
      if (iVar1 == 0) {
        return 0x1b;
      }
    }
    *(undefined4 *)(iVar2 + 0x8680) = 0;
    *(undefined4 *)(iVar2 + 0x8684) = 0;
    *(undefined4 *)(iVar2 + 0x80) = 0;
    curlx_tvnow(&local_28);
    param_1[0x51] = local_28;
    param_1[0x52] = iStack_24;
    if (param_1[0x55] == -1) {
      *(undefined *)((int)param_1 + 0x1f6) = 0;
      iVar2 = Curl_connecthost(param_1,param_1[0x12]);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      Curl_pgrsTime(iVar2,4);
      Curl_pgrsTime(iVar2,5);
      *(undefined *)((int)param_1 + 0x1f6) = 1;
      iVar2 = param_1[0x55];
      *param_2 = 1;
      Curl_updateconninfo(param_1,iVar2);
      Curl_verboseconnect(param_1);
    }
    curlx_tvnow(&local_28);
    param_1[0x51] = local_28;
    param_1[0x52] = iStack_24;
  }
  else {
    *param_2 = 1;
  }
  return 0;
}

