
undefined4 Curl_wait_ms(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else if (param_1 < 0) {
    piVar2 = __errno_location();
    uVar3 = 0xffffffff;
    *piVar2 = 0x16;
  }
  else {
    curlx_tvnow(&local_28);
    iVar1 = param_1;
    do {
      iVar1 = poll((pollfd *)0x0,0,iVar1);
      if (iVar1 != -1) {
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        break;
      }
      piVar2 = __errno_location();
      if (*piVar2 != 0) {
        if (Curl_ack_eintr != 0) {
          return 0xffffffff;
        }
        if (*piVar2 != 4) {
          return 0xffffffff;
        }
      }
      curlx_tvnow(&local_20);
      iVar1 = curlx_tvdiff(local_20,uStack_1c,local_28,uStack_24);
      iVar1 = param_1 - iVar1;
    } while (0 < iVar1);
    uVar3 = 0;
  }
  return uVar3;
}

