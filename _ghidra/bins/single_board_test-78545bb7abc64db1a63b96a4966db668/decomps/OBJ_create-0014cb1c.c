
int OBJ_create(char *oid,char *sn,char *ln)

{
  int iVar1;
  ASN1_OBJECT *o;
  
  if (((sn == (char *)0x0) || (iVar1 = OBJ_sn2nid(sn), iVar1 == 0)) &&
     ((ln == (char *)0x0 || (iVar1 = OBJ_ln2nid(ln), iVar1 == 0)))) {
    o = OBJ_txt2obj(oid,1);
    if (o != (ASN1_OBJECT *)0x0) {
      iVar1 = OBJ_obj2nid(o);
      if (iVar1 == 0) {
        iVar1 = OBJ_new_nid(1);
        o->sn = sn;
        o->nid = iVar1;
        o->ln = (char **)ln;
        iVar1 = OBJ_add_object(o);
        o->sn = (char *)0x0;
        o->ln = (char **)0x0;
      }
      else {
        iVar1 = 0;
        ERR_put_error(8,100,0x66,"crypto/objects/obj_dat.c",0x2c6);
      }
      ASN1_OBJECT_free(o);
      return iVar1;
    }
    return 0;
  }
  ERR_put_error(8,100,0x66,"crypto/objects/obj_dat.c",699);
  return 0;
}

