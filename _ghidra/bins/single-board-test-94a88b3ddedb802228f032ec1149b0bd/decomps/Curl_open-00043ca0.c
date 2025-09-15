
int Curl_open(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*Curl_ccalloc)(1,0x87a0,param_3,Curl_ccalloc,param_4);
  if (iVar1 == 0) {
    return 0x1b;
  }
  *(undefined4 *)(iVar1 + 0x879c) = 0xc0dedbad;
  iVar2 = (*Curl_cmalloc)(0x100);
  *(int *)(iVar1 + 0x594) = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0x1b;
    uVar3 = 0;
  }
  else {
    iVar2 = Curl_init_userdefined(iVar1 + 0x150);
    *(uint *)(iVar1 + 0x4a8) = *(uint *)(iVar1 + 0x4a8) | 0x10;
    *(undefined4 *)(iVar1 + 0x598) = 0x100;
    *(undefined4 *)(iVar1 + 0x590) = 0;
    *(undefined4 *)(iVar1 + 0x420) = 0;
    *(undefined4 *)(iVar1 + 0x86d8) = 0;
    *(undefined4 *)(iVar1 + 0x86e4) = 0;
    *(undefined4 *)(iVar1 + 0x85a0) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x85a4) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x438) = 5;
    if (iVar2 == 0) {
      *param_1 = iVar1;
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar1 + 0x594);
  }
  (*Curl_cfree)(uVar3);
  Curl_freeset(iVar1);
  (*Curl_cfree)(iVar1);
  return iVar2;
}

