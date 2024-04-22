
undefined4 curl_share_cleanup(int param_1)

{
  int iVar1;
  int iVar2;
  code **ppcVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return 3;
  }
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(0,1,2,*(undefined4 *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 4) == 0) {
    Curl_hash_destroy(param_1 + 0x14);
    Curl_cookie_cleanup(*(undefined4 *)(param_1 + 0x2c));
    iVar1 = *(int *)(param_1 + 0x30);
    ppcVar3 = DAT_0004d3b8;
    if (iVar1 != 0) {
      if (*(int *)(param_1 + 0x34) != 0) {
        iVar2 = 0;
        uVar4 = 0;
        do {
          uVar4 = uVar4 + 1;
          Curl_ssl_kill_session(iVar1 + iVar2);
          iVar2 = iVar2 + 0x58;
          iVar1 = *(int *)(param_1 + 0x30);
        } while (uVar4 < *(uint *)(param_1 + 0x34));
      }
      ppcVar3 = DAT_0004d3b8;
      (**DAT_0004d3b8)();
    }
    if (*(code **)(param_1 + 0xc) != (code *)0x0) {
      (**(code **)(param_1 + 0xc))(0,1,*(undefined4 *)(param_1 + 0x10));
    }
    (**ppcVar3)(param_1);
    return 0;
  }
  if (*(code **)(param_1 + 0xc) == (code *)0x0) {
    return 2;
  }
  (**(code **)(param_1 + 0xc))(0,1,*(undefined4 *)(param_1 + 0x10));
  return 2;
}

