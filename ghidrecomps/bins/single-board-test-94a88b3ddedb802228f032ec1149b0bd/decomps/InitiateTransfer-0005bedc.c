
int InitiateTransfer(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *param_1;
  puVar4 = *(undefined4 **)(iVar3 + 0x14c);
  if (*(char *)(param_1 + 100) == '\0') {
    iVar2 = param_1[0x10b];
  }
  else {
    Curl_infof(iVar3,DAT_0005bf80);
    iVar2 = Curl_ssl_connect(param_1,1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = param_1[0x10b];
  }
  if (iVar2 == 0x21) {
    puVar1 = (undefined4 *)*puVar4;
    *puVar1 = 0;
    puVar1[1] = 0;
    Curl_pgrsSetUploadSize
              (iVar3,puVar1,*(undefined4 *)(iVar3 + 0x86b0),*(undefined4 *)(iVar3 + 0x86b4));
    Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,1,*puVar4);
  }
  else {
    Curl_setup_transfer(param_1,1,param_1[0x10c],param_1[0x10d],0,*puVar4,0xffffffff,0);
  }
  param_1[0x10a] = 0;
  *(undefined *)(param_1 + 0xf4) = 1;
  return 0;
}

