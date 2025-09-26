
void * ASN1_d2i_bio(xnew *xnew,undefined1 *d2i,BIO *in,void **x)

{
  int iVar1;
  void *pvVar2;
  BUF_MEM *local_20;
  char *local_1c [2];
  
  pvVar2 = (void *)0x0;
  local_20 = (BUF_MEM *)0x0;
  iVar1 = asn1_d2i_read_bio(in,&local_20);
  if (-1 < iVar1) {
    local_1c[0] = local_20->data;
    pvVar2 = (void *)(*(code *)d2i)(x,local_1c);
  }
  if (local_20 != (BUF_MEM *)0x0) {
    BUF_MEM_free(local_20);
  }
  return pvVar2;
}

