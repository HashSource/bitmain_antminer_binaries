
ASN1_OBJECT * OBJ_dup(ASN1_OBJECT *o)

{
  ASN1_OBJECT *a;
  uchar *puVar1;
  char **ppcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  if ((o == (ASN1_OBJECT *)0x0) || (-1 < o->flags << 0x1f)) {
    return o;
  }
  a = ASN1_OBJECT_new();
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(8,0x65,0xd,"crypto/objects/obj_lib.c",0x1c);
    return (ASN1_OBJECT *)0x0;
  }
  iVar4 = o->length;
  a->flags = o->flags | 0xd;
  if (0 < iVar4) {
    puVar1 = (uchar *)CRYPTO_memdup(o->data,iVar4,"crypto/objects/obj_lib.c",0x26);
    a->data = puVar1;
    if (puVar1 == (uchar *)0x0) goto LAB_0014ccf2;
    iVar4 = o->length;
  }
  ppcVar2 = o->ln;
  iVar5 = o->nid;
  a->length = iVar4;
  a->nid = iVar5;
  if (ppcVar2 != (char **)0x0) {
    ppcVar2 = (char **)CRYPTO_strdup((char *)ppcVar2,"crypto/objects/obj_lib.c",0x2c);
    a->ln = ppcVar2;
    if (ppcVar2 == (char **)0x0) goto LAB_0014ccf2;
  }
  if (o->sn == (char *)0x0) {
    return a;
  }
  pcVar3 = CRYPTO_strdup(o->sn,"crypto/objects/obj_lib.c",0x2f);
  a->sn = pcVar3;
  if (pcVar3 != (char *)0x0) {
    return a;
  }
LAB_0014ccf2:
  ASN1_OBJECT_free(a);
  ERR_put_error(8,0x65,0x41,"crypto/objects/obj_lib.c",0x35);
  return (ASN1_OBJECT *)0x0;
}

