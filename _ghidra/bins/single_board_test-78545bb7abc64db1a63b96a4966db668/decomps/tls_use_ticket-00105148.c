
undefined4 tls_use_ticket(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x4ec) & 0x4000) != 0) {
    return 0;
  }
  uVar1 = ssl_security(param_1,10,0,0,0);
  return uVar1;
}

