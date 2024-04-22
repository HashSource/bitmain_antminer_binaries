
int asn1_do_lock(ASN1_VALUE **pval,int op,ASN1_ITEM *it)

{
  int iVar1;
  void *pvVar2;
  
  if (it->itype == '\x06' || it->itype == '\x01') {
    pvVar2 = it->funcs;
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
    }
    else if ((*(uint *)((int)pvVar2 + 4) & 1) == 0) {
      iVar1 = 0;
    }
    else if (op == 0) {
      iVar1 = 1;
      *(undefined4 *)(*pval + *(int *)((int)pvVar2 + 8)) = 1;
    }
    else {
      iVar1 = CRYPTO_add_lock((int *)(*pval + *(int *)((int)pvVar2 + 8)),op,
                              *(int *)((int)pvVar2 + 0xc),DAT_000bb96c,0x76);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

