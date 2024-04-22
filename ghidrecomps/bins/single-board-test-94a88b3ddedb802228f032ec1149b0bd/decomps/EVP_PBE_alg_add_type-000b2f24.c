
int EVP_PBE_alg_add_type(int pbe_type,int pbe_nid,int cipher_nid,int md_nid,undefined1 *keygen)

{
  _STACK **pp_Var1;
  int *data;
  _STACK *p_Var2;
  
  pp_Var1 = DAT_000b2f84;
  if (*DAT_000b2f84 == (_STACK *)0x0) {
    p_Var2 = sk_new(DAT_000b2f8c);
    *pp_Var1 = p_Var2;
  }
  data = (int *)CRYPTO_malloc(0x14,DAT_000b2f88,0xe9);
  if (data == (int *)0x0) {
    ERR_put_error(6,0xa0,0x41,DAT_000b2f88,0xea);
  }
  else {
    *data = pbe_type;
    data[1] = pbe_nid;
    data[2] = cipher_nid;
    data[3] = md_nid;
    data[4] = (int)keygen;
    sk_push(*pp_Var1,data);
  }
  return (uint)(data != (int *)0x0);
}

