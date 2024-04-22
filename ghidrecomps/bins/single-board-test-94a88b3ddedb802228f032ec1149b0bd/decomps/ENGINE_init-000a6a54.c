
int ENGINE_init(ENGINE *e)

{
  int iVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x77,0x43,DAT_000a6ab4,0x83);
    return 0;
  }
  CRYPTO_lock(9,0x1e,DAT_000a6ab4,0x86);
  iVar1 = *(int *)(e + 0x5c);
  if ((iVar1 == 0) && (*(code **)(e + 0x38) != (code *)0x0)) {
    iVar2 = (**(code **)(e + 0x38))(e);
    if (iVar2 == 0) goto LAB_000a6a7a;
    iVar1 = *(int *)(e + 0x5c);
  }
  else {
    iVar2 = 1;
  }
  *(int *)(e + 0x5c) = iVar1 + 1;
  *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
LAB_000a6a7a:
  CRYPTO_lock(10,0x1e,DAT_000a6ab4,0x88);
  return iVar2;
}

