
int Curl_open(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = (**DAT_00043d4c)(1,0x87a0,param_3,*DAT_00043d4c,param_4);
  ppcVar1 = DAT_00043d50;
  if (iVar2 == 0) {
    return 0x1b;
  }
  *(undefined4 *)(iVar2 + 0x879c) = 0xc0dedbad;
  iVar3 = (**ppcVar1)(0x100);
  *(int *)(iVar2 + 0x594) = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0x1b;
    uVar4 = 0;
  }
  else {
    iVar3 = Curl_init_userdefined(iVar2 + 0x150);
    *(uint *)(iVar2 + 0x4a8) = *(uint *)(iVar2 + 0x4a8) | 0x10;
    *(undefined4 *)(iVar2 + 0x598) = 0x100;
    *(undefined4 *)(iVar2 + 0x590) = 0;
    *(undefined4 *)(iVar2 + 0x420) = 0;
    *(undefined4 *)(iVar2 + 0x86d8) = 0;
    *(undefined4 *)(iVar2 + 0x86e4) = 0;
    *(undefined4 *)(iVar2 + 0x85a0) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x85a4) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x438) = 5;
    if (iVar3 == 0) {
      *param_1 = iVar2;
      return 0;
    }
    uVar4 = *(undefined4 *)(iVar2 + 0x594);
  }
  ppcVar1 = DAT_00043d54;
  (**DAT_00043d54)(uVar4);
  Curl_freeset(iVar2);
  (**ppcVar1)(iVar2);
  return iVar3;
}

