
int EC_KEY_up_ref(EC_KEY *key)

{
  int iVar1;
  
  iVar1 = CRYPTO_add_lock((int *)(key + 0x18),1,0x21,"ec_key.c",0xd9);
  return (uint)(1 < iVar1);
}

