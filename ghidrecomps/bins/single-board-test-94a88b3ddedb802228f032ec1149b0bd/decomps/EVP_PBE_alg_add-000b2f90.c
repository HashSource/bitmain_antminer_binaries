
int EVP_PBE_alg_add(int nid,EVP_CIPHER *cipher,EVP_MD *md,undefined1 *keygen)

{
  _STACK **pp_Var1;
  undefined4 *data;
  _STACK *p_Var2;
  int iVar3;
  int iVar4;
  
  iVar4 = -1;
  if (cipher != (EVP_CIPHER *)0x0) {
    iVar4 = EVP_CIPHER_nid(cipher);
  }
  iVar3 = -1;
  if (md != (EVP_MD *)0x0) {
    iVar3 = EVP_MD_type(md);
  }
  pp_Var1 = DAT_000b300c;
  if (*DAT_000b300c == (_STACK *)0x0) {
    p_Var2 = sk_new(DAT_000b3014);
    *pp_Var1 = p_Var2;
  }
  data = (undefined4 *)CRYPTO_malloc(0x14,DAT_000b3010,0xe9);
  if (data == (undefined4 *)0x0) {
    ERR_put_error(6,0xa0,0x41,DAT_000b3010,0xea);
  }
  else {
    data[1] = nid;
    data[2] = iVar4;
    data[3] = iVar3;
    data[4] = keygen;
    *data = 0;
    sk_push(*pp_Var1,data);
  }
  return (uint)(data != (undefined4 *)0x0);
}

