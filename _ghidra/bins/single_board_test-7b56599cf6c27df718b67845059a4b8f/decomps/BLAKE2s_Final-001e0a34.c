
undefined4 BLAKE2s_Final(undefined4 *param_1,void *param_2)

{
  undefined4 *puVar1;
  
  *(undefined4 *)((int)param_2 + 0x28) = 0xffffffff;
  memset((void *)((int)param_2 + 0x30 + *(int *)((int)param_2 + 0x70)),0,
         0x40 - *(int *)((int)param_2 + 0x70));
  blake2s_compress(param_2,(int)param_2 + 0x30,*(undefined4 *)((int)param_2 + 0x70));
  puVar1 = (undefined4 *)((int)param_2 + -4);
  do {
    puVar1 = puVar1 + 1;
    *param_1 = *puVar1;
    param_1 = param_1 + 1;
  } while (puVar1 != (undefined4 *)((int)param_2 + 0x1c));
  OPENSSL_cleanse(param_2,0x74);
  return 1;
}

