
void Curl_ossl_version(undefined4 param_1,undefined4 param_2)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char local_1c;
  char local_1b;
  undefined local_1a;
  
  uVar5 = 0;
  local_1a = 0;
  local_1b = '\0';
  uVar1 = SSLeay();
  if (uVar1 < 0x906000) {
    local_1c = '\0';
    uVar4 = 2;
    uVar2 = 1;
  }
  else if ((uVar1 & 0xff0) == 0) {
    uVar2 = uVar1 >> 0x1c;
    uVar5 = (uVar1 << 4) >> 0x18;
    uVar4 = (uVar1 << 0xc) >> 0x18;
    local_1c = '\0';
  }
  else {
    uVar5 = uVar1 >> 4 & 0xff;
    if (uVar5 < 0x1b) {
      local_1c = (char)(uVar1 >> 4) + '`';
      uVar2 = uVar1 >> 0x1c;
      uVar5 = (uVar1 << 4) >> 0x18;
      uVar4 = (uVar1 << 0xc) >> 0x18;
    }
    else {
      iVar3 = uVar5 - 1;
      uVar2 = uVar1 >> 0x1c;
      local_1c = 'z';
      uVar5 = (uVar1 << 4) >> 0x18;
      uVar4 = (uVar1 << 0xc) >> 0x18;
      local_1b = (char)iVar3 + (char)(iVar3 / 0x1a) * -0x1a + 'b';
    }
  }
  curl_msnprintf(param_1,param_2,DAT_00059c80,DAT_00059c84,uVar2,uVar5,uVar4,&local_1c);
  return;
}

