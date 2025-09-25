
int OBJ_add_object(ASN1_OBJECT *obj)

{
  void **ppvVar1;
  ASN1_OBJECT *a;
  void *ptr;
  int *piVar2;
  int iVar3;
  void *local_28 [4];
  
  local_28[1] = (void *)0x0;
  local_28[0] = (void *)0x0;
  local_28[2] = (void *)0x0;
  local_28[3] = (void *)0x0;
  if ((added == 0) && (added = OPENSSL_LH_new(0x13e39d,0x13e2fd), added == 0)) {
    return 0;
  }
  a = OBJ_dup(obj);
  if (a == (ASN1_OBJECT *)0x0) goto LAB_0013e594;
  local_28[3] = CRYPTO_malloc(8,"crypto/objects/obj_dat.c",0xb9);
  if (local_28[3] != (void *)0x0) {
    if ((a->length != 0) && (obj->data != (uchar *)0x0)) {
      local_28[0] = CRYPTO_malloc(8,"crypto/objects/obj_dat.c",0xbc);
      if (local_28[0] == (void *)0x0) goto LAB_0013e582;
    }
    if (a->sn != (char *)0x0) {
      local_28[1] = CRYPTO_malloc(8,"crypto/objects/obj_dat.c",0xbf);
      if (local_28[1] == (void *)0x0) goto LAB_0013e582;
    }
    if (a->ln == (char **)0x0) {
LAB_0013e544:
      iVar3 = 0;
      do {
        piVar2 = (int *)local_28[iVar3];
        if (piVar2 != (int *)0x0) {
          *piVar2 = iVar3;
          piVar2[1] = (int)a;
          ptr = (void *)OPENSSL_LH_insert(added,piVar2);
          CRYPTO_free(ptr);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
      a->flags = a->flags & 0xfffffff2;
      return a->nid;
    }
    local_28[2] = CRYPTO_malloc(8,"crypto/objects/obj_dat.c",0xc2);
    if (local_28[2] != (void *)0x0) goto LAB_0013e544;
  }
LAB_0013e582:
  ERR_put_error(8,0x69,0x41,"crypto/objects/obj_dat.c",0xd4);
LAB_0013e594:
  iVar3 = 0;
  do {
    ppvVar1 = local_28 + iVar3;
    iVar3 = iVar3 + 1;
    CRYPTO_free(*ppvVar1);
  } while (iVar3 != 4);
  ASN1_OBJECT_free(a);
  return 0;
}

