
void * ASN1_d2i_bio(xnew *xnew,undefined1 *d2i,BIO *in,void **x)

{
  int iVar1;
  void *pvVar2;
  BUF_MEM *local_18;
  char *local_14;
  
  pvVar2 = (void *)0x0;
  local_18 = (BUF_MEM *)0x0;
  iVar1 = asn1_d2i_read_bio(in,&local_18);
  if (-1 < iVar1) {
    local_14 = local_18->data;
    pvVar2 = (void *)(*(code *)d2i)(x,&local_14);
  }
  BUF_MEM_free(local_18);
  return pvVar2;
}

