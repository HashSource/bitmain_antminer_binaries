
uint multi_getsock_constprop_6(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if ((*(char *)(param_1 + 0x867d) == '\0') &&
     (piVar4 = *(int **)(param_1 + 8), piVar4 != (int *)0x0)) {
    iVar3 = *(int *)(param_1 + 0xc);
    if (iVar3 - 3U < 0xe) {
      *piVar4 = param_1;
    }
    switch(iVar3) {
    case 4:
      uVar2 = piVar4[0x57] + 1;
      bVar5 = uVar2 != 0;
      if (bVar5) {
        *param_2 = piVar4[0x57];
      }
      else {
        uVar2 = 0;
      }
      uVar1 = uVar2;
      if (bVar5) {
        uVar2 = 1;
        uVar1 = 0x10000;
      }
      if (piVar4[0x58] == -1) {
        return uVar1;
      }
      param_2[uVar2] = piVar4[0x58];
      return uVar1 | 1 << (uVar2 + 0x10 & 0xff);
    case 5:
      if (piVar4[0x11a] == 1) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0x10000;
      }
      *param_2 = piVar4[0x55];
      return uVar2;
    case 6:
    case 7:
      uVar2 = Curl_protocol_getsock(piVar4,param_2,5,param_4);
      return uVar2;
    case 9:
    case 10:
      uVar2 = Curl_doing_getsock(piVar4,param_2,5,param_4);
      return uVar2;
    case 0xb:
      if (*(code **)(piVar4[0x86] + 0x28) != (code *)0x0) {
        uVar2 = (**(code **)(piVar4[0x86] + 0x28))(piVar4,param_2,5);
        return uVar2;
      }
      break;
    case 0xc:
    case 0xd:
    case 0xe:
      uVar2 = Curl_single_getsock(piVar4,param_2,5,param_4);
      return uVar2;
    }
  }
  return 0;
}

