
int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  uchar *out;
  int len;
  ASN1_OBJECT *obj;
  
  iVar1 = a2d_ASN1_OBJECT((uchar *)0x0,0,oid,-1);
  if (iVar1 < 1) {
    return 0;
  }
  out = (uchar *)CRYPTO_malloc(iVar1,"obj_dat.c",0x312);
  if (out == (uchar *)0x0) {
    ERR_put_error(8,100,0x41,"obj_dat.c",0x313);
    return 0;
  }
  len = a2d_ASN1_OBJECT(out,iVar1,oid,-1);
  iVar1 = new_nid;
  if (len != 0) {
    new_nid = new_nid + 1;
    obj = ASN1_OBJECT_create(iVar1,out,len,sn,ln);
    if (obj != (ASN1_OBJECT *)0x0) {
      iVar1 = OBJ_add_object(obj);
      goto LAB_00135c88;
    }
  }
  obj = (ASN1_OBJECT *)0x0;
  iVar1 = 0;
LAB_00135c88:
  ASN1_OBJECT_free(obj);
  CRYPTO_free(out);
  return iVar1;
}

