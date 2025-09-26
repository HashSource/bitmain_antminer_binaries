
undefined4 BIO_ADDR_sockaddr_size(short *param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  sVar1 = *param_1;
  if (sVar1 == 2) {
    return 0x10;
  }
  if (sVar1 == 10) {
    return 0x1c;
  }
  if (sVar1 == 1) {
    uVar2 = 0x6e;
  }
  else {
    uVar2 = 0x70;
  }
  return uVar2;
}

