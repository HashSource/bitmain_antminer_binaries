
undefined4 ssl_allow_compression(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x4ec) & 0x20000) != 0) {
    return 0;
  }
  uVar1 = ssl_security(param_1,0xf,0,0,0);
  return uVar1;
}

