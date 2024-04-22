
undefined4 Curl_printable_address(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 == 2) {
    iVar2 = *(int *)(param_1 + 0x18) + 4;
  }
  else {
    if (iVar3 != 10) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x18) + 8;
  }
  uVar1 = (*(code *)PTR_inet_ntop_0019413c)(iVar3,iVar2,param_2,param_3);
  return uVar1;
}

