
int RSA_up_ref(RSA *r)

{
  int iVar1;
  
  iVar1 = CRYPTO_add_lock(&r->references,1,9,"rsa_lib.c",0x108);
  return (uint)(1 < iVar1);
}

