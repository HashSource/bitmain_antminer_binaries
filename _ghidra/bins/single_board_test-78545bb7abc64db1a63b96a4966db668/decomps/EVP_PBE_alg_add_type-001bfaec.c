
int EVP_PBE_alg_add_type(int pbe_type,int pbe_nid,int cipher_nid,int md_nid,undefined1 *keygen)

{
  int *ptr;
  int iVar1;
  
  if (((pbe_algs != 0) || (pbe_algs = OPENSSL_sk_new(0x1bfac1), pbe_algs != 0)) &&
     (ptr = (int *)CRYPTO_malloc(0x14,"crypto/evp/evp_pbe.c",0xab), ptr != (int *)0x0)) {
    *ptr = pbe_type;
    ptr[1] = pbe_nid;
    ptr[2] = cipher_nid;
    ptr[3] = md_nid;
    ptr[4] = (int)keygen;
    iVar1 = OPENSSL_sk_push(pbe_algs,ptr);
    if (iVar1 != 0) {
      return 1;
    }
    CRYPTO_free(ptr);
  }
  ERR_put_error(6,0xa0,0x41,"crypto/evp/evp_pbe.c",0xbb);
  return 0;
}

