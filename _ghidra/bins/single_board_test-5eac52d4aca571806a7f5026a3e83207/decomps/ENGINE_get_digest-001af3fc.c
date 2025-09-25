
EVP_MD * ENGINE_get_digest(ENGINE *e,int nid)

{
  ENGINE_DIGESTS_PTR pEVar1;
  int iVar2;
  EVP_MD *local_14;
  
  pEVar1 = ENGINE_get_digests(e);
  if ((pEVar1 != (ENGINE_DIGESTS_PTR)0x0) &&
     (iVar2 = (*pEVar1)(e,&local_14,(int **)0x0,nid), iVar2 != 0)) {
    return local_14;
  }
  ERR_put_error(0x26,0xba,0x93,"crypto/engine/tb_digest.c",0x4a);
  return (EVP_MD *)0x0;
}

