
undefined4 tls_construct_key_update(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = WPACKET_put_bytes__(param_2,param_2,*(int *)(param_1 + 0x5f0),
                              *(int *)(param_1 + 0x5f0) >> 0x1f,1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x5f0) = 0xffffffff;
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x205,0x44,"ssl/statem/statem_lib.c",0x267);
  return 0;
}

