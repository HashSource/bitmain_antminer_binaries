
void tls13_generate_handshake_secret(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = ssl_handshake_md();
  tls13_generate_secret(param_1,uVar1,param_1 + 0xcc,param_2,param_3,param_1 + 0x10c);
  return;
}

