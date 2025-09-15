
int DH_up_ref(DH *dh)

{
  int iVar1;
  
  iVar1 = CRYPTO_add_lock(&dh->references,1,0x1a,"dh_lib.c",0xe6);
  return (uint)(1 < iVar1);
}

