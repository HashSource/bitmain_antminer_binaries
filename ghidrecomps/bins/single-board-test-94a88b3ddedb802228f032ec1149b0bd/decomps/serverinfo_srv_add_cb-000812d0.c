
undefined4 serverinfo_srv_add_cb(undefined4 param_1,int param_2,byte **param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *local_28;
  uint local_24;
  
  local_28 = (byte *)0x0;
  local_24 = 0;
  iVar1 = ssl_get_server_cert_serverinfo(param_1,&local_28,&local_24);
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *param_3 = (byte *)0x0;
  *param_4 = 0;
  if (local_28 != (byte *)0x0 && local_24 != 0) {
    if (local_24 < 2) {
      return 0;
    }
    iVar1 = (uint)local_28[1] + (uint)*local_28 * 0x100;
    if (local_24 - 2 < 2) {
      return 0;
    }
    local_24 = local_24 - 4;
    uVar2 = (uint)local_28[3] + (uint)local_28[2] * 0x100;
    if (local_24 < uVar2) {
      return 0;
    }
    do {
      if (param_2 == iVar1) {
        *param_3 = local_28 + 4;
        *param_4 = uVar2;
        return 1;
      }
      local_28 = local_28 + 4 + uVar2;
      iVar3 = local_24 - uVar2;
      local_24 = iVar3 - 4;
      if (iVar3 == 0) {
        return 0xffffffff;
      }
    } while (((iVar3 != 1) && (iVar1 = (uint)local_28[1] + (uint)*local_28 * 0x100, 1 < iVar3 - 2U))
            && (uVar2 = (uint)local_28[3] + (uint)local_28[2] * 0x100, uVar2 <= local_24));
  }
  return 0;
}

