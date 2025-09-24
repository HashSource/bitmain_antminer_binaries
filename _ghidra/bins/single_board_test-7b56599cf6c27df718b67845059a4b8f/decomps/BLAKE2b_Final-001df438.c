
undefined4 BLAKE2b_Final(undefined4 *param_1,void *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)((int)param_2 + 0x50) = 0xffffffff;
  *(undefined4 *)((int)param_2 + 0x54) = 0xffffffff;
  memset((void *)((int)param_2 + 0x60 + *(int *)((int)param_2 + 0xe0)),0,
         0x80 - *(int *)((int)param_2 + 0xe0));
  blake2b_compress(param_2,(int)param_2 + 0x60,*(undefined4 *)((int)param_2 + 0xe0));
  puVar3 = (undefined4 *)((int)param_2 + -8);
  do {
    puVar1 = puVar3 + 2;
    uVar2 = puVar3[3];
    *param_1 = *puVar1;
    param_1[1] = uVar2;
    param_1 = param_1 + 2;
    puVar3 = puVar1;
  } while (puVar1 != (undefined4 *)((int)param_2 + 0x38));
  OPENSSL_cleanse(param_2,0xe8);
  return 1;
}

