
int OBJ_add_object(ASN1_OBJECT *obj)

{
  _LHASH *p_Var1;
  ASN1_OBJECT *ptr;
  void *pvVar2;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  local_20 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  if ((added != (_LHASH *)0x0) ||
     (added = lh_new((LHASH_HASH_FN_TYPE)0x134f59,(LHASH_COMP_FN_TYPE)0x134efd),
     added != (_LHASH *)0x0)) {
    ptr = OBJ_dup(obj);
    if (ptr != (ASN1_OBJECT *)0x0) {
      local_14 = (undefined4 *)CRYPTO_malloc(8,"obj_dat.c",0x10e);
      if ((((local_14 != (undefined4 *)0x0) &&
           (((ptr->length == 0 || (obj->data == (uchar *)0x0)) ||
            (local_20 = (undefined4 *)CRYPTO_malloc(8,"obj_dat.c",0x112),
            local_20 != (undefined4 *)0x0)))) &&
          ((ptr->sn == (char *)0x0 ||
           (local_1c = (undefined4 *)CRYPTO_malloc(8,"obj_dat.c",0x117),
           local_1c != (undefined4 *)0x0)))) &&
         ((ptr->ln == (char **)0x0 ||
          (local_18 = (undefined4 *)CRYPTO_malloc(8,"obj_dat.c",0x11c),
          local_18 != (undefined4 *)0x0)))) {
        p_Var1 = added;
        if (local_20 != (undefined4 *)0x0) {
          *local_20 = 0;
          local_20[1] = ptr;
          pvVar2 = lh_insert(p_Var1,local_20);
          if (pvVar2 != (void *)0x0) {
            CRYPTO_free(pvVar2);
          }
        }
        p_Var1 = added;
        if (local_1c != (undefined4 *)0x0) {
          *local_1c = 1;
          local_1c[1] = ptr;
          pvVar2 = lh_insert(p_Var1,local_1c);
          if (pvVar2 != (void *)0x0) {
            CRYPTO_free(pvVar2);
          }
        }
        p_Var1 = added;
        if (local_18 != (undefined4 *)0x0) {
          *local_18 = 2;
          local_18[1] = ptr;
          pvVar2 = lh_insert(p_Var1,local_18);
          if (pvVar2 != (void *)0x0) {
            CRYPTO_free(pvVar2);
          }
        }
        if (local_14 != (undefined4 *)0x0) {
          local_14[1] = ptr;
          p_Var1 = added;
          *local_14 = 3;
          pvVar2 = lh_insert(p_Var1,local_14);
          if (pvVar2 != (void *)0x0) {
            CRYPTO_free(pvVar2);
          }
        }
        ptr->flags = ptr->flags & 0xfffffff2;
        return ptr->nid;
      }
      ERR_put_error(8,0x69,0x41,"obj_dat.c",0x12f);
    }
    if (local_20 != (undefined4 *)0x0) {
      CRYPTO_free(local_20);
    }
    if (local_1c != (undefined4 *)0x0) {
      CRYPTO_free(local_1c);
    }
    if (local_18 != (undefined4 *)0x0) {
      CRYPTO_free(local_18);
    }
    if (local_14 != (undefined4 *)0x0) {
      CRYPTO_free(local_14);
    }
    if (ptr != (ASN1_OBJECT *)0x0) {
      CRYPTO_free(ptr);
    }
  }
  return 0;
}

