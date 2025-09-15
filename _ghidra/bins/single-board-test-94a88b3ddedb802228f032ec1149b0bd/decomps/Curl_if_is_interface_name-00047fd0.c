
undefined4 Curl_if_is_interface_name(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *local_14 [2];
  
  iVar1 = getifaddrs(local_14);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    piVar3 = local_14[0];
    if (local_14[0] == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      do {
        iVar1 = curl_strequal(piVar3[1],param_1);
        if (iVar1 != 0) {
          uVar2 = 1;
          goto LAB_00047ffe;
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)0x0);
      uVar2 = 0;
    }
LAB_00047ffe:
    freeifaddrs(local_14[0]);
  }
  return uVar2;
}

