
int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  uchar *out;
  int nid;
  ASN1_OBJECT *obj;
  
  iVar1 = a2d_ASN1_OBJECT((uchar *)0x0,0,oid,-1);
  if (iVar1 < 1) {
    return 0;
  }
  out = (uchar *)CRYPTO_malloc(iVar1,DAT_0008cdc0,0x312);
  if (out == (uchar *)0x0) {
    ERR_put_error(8,100,0x41,DAT_0008cdc0,0x313);
    return 0;
  }
  iVar1 = a2d_ASN1_OBJECT(out,iVar1,oid,-1);
  if (iVar1 != 0) {
    nid = *DAT_0008cdc4;
    *DAT_0008cdc4 = nid + 1;
    obj = ASN1_OBJECT_create(nid,out,iVar1,sn,ln);
    if (obj != (ASN1_OBJECT *)0x0) {
      iVar1 = OBJ_add_object(obj);
      goto LAB_0008cd70;
    }
  }
  obj = (ASN1_OBJECT *)0x0;
  iVar1 = 0;
LAB_0008cd70:
  ASN1_OBJECT_free(obj);
  CRYPTO_free(out);
  return iVar1;
}

