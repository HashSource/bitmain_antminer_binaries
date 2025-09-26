
EVP_CIPHER * ENGINE_get_cipher(ENGINE *e,int nid)

{
  ENGINE_CIPHERS_PTR pEVar1;
  int iVar2;
  EVP_CIPHER *local_14;
  
  pEVar1 = ENGINE_get_ciphers(e);
  if ((pEVar1 != (ENGINE_CIPHERS_PTR)0x0) &&
     (iVar2 = (*pEVar1)(e,&local_14,(int **)0x0,nid), iVar2 != 0)) {
    return local_14;
  }
  ERR_put_error(0x26,0xb9,0x92,"crypto/engine/tb_cipher.c",0x4a);
  return (EVP_CIPHER *)0x0;
}

