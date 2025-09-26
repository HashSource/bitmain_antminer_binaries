
int DSA_up_ref(DSA *r)

{
  int iVar1;
  
  iVar1 = CRYPTO_add_lock(&r->references,1,8,"dsa_lib.c",0xed);
  return (uint)(1 < iVar1);
}

