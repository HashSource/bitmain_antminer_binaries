
int OPENSSL_hexchar2int(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 - 0x30U & 0xff;
  if (uVar1 < 0x37) {
    return (int)(char)(&CSWTCH_21)[uVar1];
  }
  return -1;
}

