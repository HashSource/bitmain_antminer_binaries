
undefined4 dtls_construct_change_cipher_spec(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0x100) {
    iVar2 = param_1[0x20];
    iVar1 = *(ushort *)(iVar2 + 0x10a) + 1;
    *(short *)(iVar2 + 0x10a) = (short)iVar1;
    iVar1 = WPACKET_put_bytes__(param_2,iVar1,*(undefined2 *)(iVar2 + 0x108),0,2);
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0x173,0x44,"ssl/statem/statem_dtls.c",0x396);
      return 0;
    }
  }
  return 1;
}

