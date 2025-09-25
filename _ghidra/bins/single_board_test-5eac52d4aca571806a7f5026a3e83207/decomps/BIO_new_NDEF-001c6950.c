
BIO * BIO_new_NDEF(BIO *out,ASN1_VALUE *val,ASN1_ITEM *it)

{
  undefined4 *ptr;
  BIO_METHOD *type;
  BIO *b;
  BIO *pBVar1;
  int iVar2;
  void *pvVar3;
  ASN1_VALUE *local_34 [2];
  BIO *local_2c;
  BIO *local_28;
  undefined4 local_24;
  
  pvVar3 = it->funcs;
  local_34[0] = val;
  if ((pvVar3 != (void *)0x0) && (*(int *)((int)pvVar3 + 0x10) != 0)) {
    ptr = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/asn1/bio_ndef.c",0x3f);
    type = BIO_f_asn1();
    b = BIO_new(type);
    if ((b != (BIO *)0x0 && ptr != (undefined4 *)0x0) &&
       (pBVar1 = BIO_push(b,out), pBVar1 != (BIO *)0x0)) {
      BIO_asn1_set_prefix(b,(undefined1 *)0x1c68d9,(undefined1 *)0x1c67b9);
      BIO_asn1_set_suffix(b,(undefined1 *)0x1c67e9,(undefined1 *)0x1c688d);
      local_28 = (BIO *)0x0;
      local_24 = 0;
      local_2c = pBVar1;
      iVar2 = (**(code **)((int)pvVar3 + 0x10))(10,local_34,it,&local_2c);
      if (0 < iVar2) {
        ptr[3] = pBVar1;
        ptr[1] = it;
        ptr[2] = local_28;
        *ptr = local_34[0];
        ptr[4] = local_24;
        BIO_ctrl(b,0x99,0,ptr);
        return local_28;
      }
    }
    BIO_free(b);
    CRYPTO_free(ptr);
    return (BIO *)0x0;
  }
  ERR_put_error(0xd,0xd0,0xca,"crypto/asn1/bio_ndef.c",0x3c);
  return (BIO *)0x0;
}

