
int CRYPTO_ocb128_finish(undefined4 *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  if (param_3 - 1 < 0x10) {
    local_30 = param_1[0x24] ^ param_1[0x20] ^ param_1[0xe];
    uStack_2c = param_1[0x25] ^ param_1[0x21] ^ param_1[0xf];
    local_38 = param_1[0x22] ^ param_1[0x1e] ^ param_1[0xc];
    uStack_34 = param_1[0x23] ^ param_1[0x1f] ^ param_1[0xd];
    (*(code *)*param_1)(&local_38,&local_38,param_1[2]);
    local_38 = param_1[0x1a] ^ local_38;
    uStack_34 = param_1[0x1b] ^ uStack_34;
    local_30 = local_30 ^ param_1[0x1c];
    uStack_2c = uStack_2c ^ param_1[0x1d];
    iVar1 = CRYPTO_memcmp(&local_38,param_2,param_3);
    return iVar1;
  }
  return -1;
}

