
BIO * BIO_new_NDEF(BIO *out,ASN1_VALUE *val,ASN1_ITEM *it)

{
  BIO *parg;
  BIO_METHOD *type;
  BIO *b;
  BIO *pBVar1;
  int iVar2;
  void *pvVar3;
  BIO_METHOD *local_34 [2];
  BIO *local_2c;
  BIO *local_28;
  int local_24;
  
  pvVar3 = it->funcs;
  local_34[0] = (BIO_METHOD *)val;
  if ((pvVar3 == (void *)0x0) || (*(int *)((int)pvVar3 + 0x10) == 0)) {
    ERR_put_error(0xd,0xd0,0xca,DAT_00127004,0x6a);
    return (BIO *)0x0;
  }
  parg = (BIO *)CRYPTO_malloc(0x18,DAT_00127004,0x6d);
  type = BIO_f_asn1();
  b = BIO_new(type);
  pBVar1 = BIO_push(b,out);
  if (parg == (BIO *)0x0 || b == (BIO *)0x0) {
    if (b == (BIO *)0x0) goto LAB_00126f8c;
  }
  else if (pBVar1 != (BIO *)0x0) {
    BIO_asn1_set_prefix(b,DAT_00127008,DAT_0012700c);
    BIO_asn1_set_suffix(b,DAT_00127010,DAT_00127014);
    local_28 = (BIO *)0x0;
    local_24 = 0;
    local_2c = pBVar1;
    iVar2 = (**(code **)((int)pvVar3 + 0x10))(10,local_34,it,&local_2c);
    if (0 < iVar2) {
      parg->callback = (_func_745 *)it;
      parg->method = local_34[0];
      parg->init = (int)pBVar1;
      parg->shutdown = local_24;
      parg->cb_arg = (char *)local_28;
      BIO_ctrl(b,0x99,0,parg);
      return local_28;
    }
  }
  BIO_free(b);
LAB_00126f8c:
  if (parg != (BIO *)0x0) {
    CRYPTO_free(parg);
    parg = (BIO *)0x0;
  }
  return parg;
}

