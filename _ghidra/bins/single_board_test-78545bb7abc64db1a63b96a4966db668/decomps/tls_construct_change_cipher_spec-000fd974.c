
bool tls_construct_change_cipher_spec(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = WPACKET_put_bytes__(param_2,param_2,1,0,1);
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x50,0x1ab,0x44,"ssl/statem/statem_lib.c",0x36a);
  }
  return iVar1 != 0;
}

