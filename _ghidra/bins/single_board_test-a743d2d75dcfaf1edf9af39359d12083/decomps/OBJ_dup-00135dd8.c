
ASN1_OBJECT * OBJ_dup(ASN1_OBJECT *o)

{
  ASN1_OBJECT *ptr;
  uchar *__dest;
  char **ppcVar1;
  size_t sVar2;
  char *__dest_00;
  int iVar3;
  int iVar4;
  
  if (o == (ASN1_OBJECT *)0x0) {
    return (ASN1_OBJECT *)0x0;
  }
  if (-1 < o->flags << 0x1f) {
    return o;
  }
  ptr = ASN1_OBJECT_new();
  if (ptr == (ASN1_OBJECT *)0x0) {
    ERR_put_error(8,0x65,0xd,"obj_lib.c",0x50);
    return (ASN1_OBJECT *)0x0;
  }
  __dest = (uchar *)CRYPTO_malloc(o->length,"obj_lib.c",0x53);
  if (__dest == (uchar *)0x0) {
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
    goto LAB_00135e92;
  }
  if (o->data != (uchar *)0x0) {
    memcpy(__dest,o->data,o->length);
  }
  iVar4 = o->length;
  ptr->ln = (char **)0x0;
  iVar3 = o->nid;
  ppcVar1 = o->ln;
  ptr->data = __dest;
  ptr->sn = (char *)0x0;
  ptr->length = iVar4;
  ptr->nid = iVar3;
  if (ppcVar1 == (char **)0x0) {
    ppcVar1 = (char **)0x0;
LAB_00135e4a:
    if (o->sn == (char *)0x0) {
LAB_00135e70:
      ptr->flags = o->flags | 0xd;
      return ptr;
    }
    sVar2 = strlen(o->sn);
    __dest_00 = (char *)CRYPTO_malloc(sVar2 + 1,"obj_lib.c",0x68);
    if (__dest_00 != (char *)0x0) {
      memcpy(__dest_00,o->sn,sVar2 + 1);
      ptr->sn = __dest_00;
      goto LAB_00135e70;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
    if (ppcVar1 != (char **)0x0) {
      CRYPTO_free(ppcVar1);
    }
  }
  else {
    sVar2 = strlen((char *)ppcVar1);
    ppcVar1 = (char **)CRYPTO_malloc(sVar2 + 1,"obj_lib.c",0x5f);
    if (ppcVar1 != (char **)0x0) {
      memcpy(ppcVar1,o->ln,sVar2 + 1);
      ptr->ln = ppcVar1;
      goto LAB_00135e4a;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
  }
  CRYPTO_free(__dest);
LAB_00135e92:
  CRYPTO_free(ptr);
  return (ASN1_OBJECT *)0x0;
}

