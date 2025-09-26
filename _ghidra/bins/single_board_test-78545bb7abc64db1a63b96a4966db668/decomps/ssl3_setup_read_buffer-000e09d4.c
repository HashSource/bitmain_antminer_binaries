
undefined4 ssl3_setup_read_buffer(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  uint num;
  uint uVar4;
  
  num = 0x4550;
  uVar4 = 0x4150;
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8) == 0) {
    num = 0x4548;
    uVar4 = 0x4148;
  }
  if (*(int *)(param_1 + 0x664) == 0) {
    iVar2 = ssl_allow_compression();
    if (iVar2 == 0) {
      num = uVar4;
    }
    if (num < *(uint *)(param_1 + 0x668)) {
      num = *(uint *)(param_1 + 0x668);
    }
    pvVar3 = CRYPTO_malloc(num,"ssl/record/ssl3_buffer.c",0x3f);
    if (pvVar3 == (void *)0x0) {
      ossl_statem_fatal(param_1,0xffffffff,0x9c,0x41,"ssl/record/ssl3_buffer.c",0x46);
      uVar1 = 0;
    }
    else {
      *(void **)(param_1 + 0x664) = pvVar3;
      uVar1 = 1;
      *(uint *)(param_1 + 0x66c) = num;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

