
int EVP_PBE_alg_add_type(int pbe_type,int pbe_nid,int cipher_nid,int md_nid,undefined1 *keygen)

{
  int *data;
  
  if (pbe_algs == (_STACK *)0x0) {
    pbe_algs = sk_new((cmp *)0x153a19);
  }
  data = (int *)CRYPTO_malloc(0x14,"evp_pbe.c",0xe9);
  if (data == (int *)0x0) {
    ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xea);
  }
  else {
    *data = pbe_type;
    data[1] = pbe_nid;
    data[2] = cipher_nid;
    data[3] = md_nid;
    data[4] = (int)keygen;
    sk_push(pbe_algs,data);
  }
  return (uint)(data != (int *)0x0);
}

