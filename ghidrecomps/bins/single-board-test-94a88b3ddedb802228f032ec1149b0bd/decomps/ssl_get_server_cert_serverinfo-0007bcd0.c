
bool ssl_get_server_cert_serverinfo(int param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x58);
  iVar4 = *(int *)(param_1 + 0x98);
  *param_3 = 0;
  uVar1 = ssl_cipher_get_cert_index(*(undefined4 *)(iVar2 + 0x344));
  if (uVar1 == 0) {
    uVar1 = (uint)(*(int *)(*(int *)(param_1 + 0x98) + 0x3c) == 0);
  }
  else if (uVar1 == 0xffffffff) {
    ERR_put_error(0x14,0x142,0x44,DAT_0007bd38,0x9d1);
    return false;
  }
  iVar4 = iVar4 + uVar1 * 0x1c;
  iVar2 = *(int *)(iVar4 + 0x4c);
  if (iVar2 != 0) {
    uVar3 = *(undefined4 *)(iVar4 + 0x50);
    *param_2 = iVar2;
    *param_3 = uVar3;
  }
  return iVar2 != 0;
}

