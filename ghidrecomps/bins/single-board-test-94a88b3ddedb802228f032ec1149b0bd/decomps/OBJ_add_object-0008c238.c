
int OBJ_add_object(ASN1_OBJECT *obj)

{
  int iVar1;
  ASN1_OBJECT *ptr;
  _LHASH *p_Var2;
  void *pvVar3;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  iVar1 = DAT_0008c36c;
  local_20 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  if (*(int *)(DAT_0008c36c + 4) == 0) {
    p_Var2 = lh_new(DAT_0008c374,DAT_0008c378);
    *(_LHASH **)(iVar1 + 4) = p_Var2;
    if (p_Var2 == (_LHASH *)0x0) {
      return 0;
    }
  }
  ptr = OBJ_dup(obj);
  if (ptr != (ASN1_OBJECT *)0x0) {
    local_14 = (undefined4 *)CRYPTO_malloc(8,DAT_0008c370,0x10e);
    if ((((local_14 != (undefined4 *)0x0) &&
         (((ptr->length == 0 || (obj->data == (uchar *)0x0)) ||
          (local_20 = (undefined4 *)CRYPTO_malloc(8,DAT_0008c370,0x112),
          local_20 != (undefined4 *)0x0)))) &&
        ((ptr->sn == (char *)0x0 ||
         (local_1c = (undefined4 *)CRYPTO_malloc(8,DAT_0008c370,0x117),
         local_1c != (undefined4 *)0x0)))) &&
       ((ptr->ln == (char **)0x0 ||
        (local_18 = (undefined4 *)CRYPTO_malloc(8,DAT_0008c370,0x11c), local_18 != (undefined4 *)0x0
        )))) {
      if (local_20 != (undefined4 *)0x0) {
        p_Var2 = *(_LHASH **)(iVar1 + 4);
        *local_20 = 0;
        local_20[1] = ptr;
        pvVar3 = lh_insert(p_Var2,local_20);
        if (pvVar3 != (void *)0x0) {
          CRYPTO_free(pvVar3);
        }
      }
      if (local_1c != (undefined4 *)0x0) {
        p_Var2 = *(_LHASH **)(iVar1 + 4);
        *local_1c = 1;
        local_1c[1] = ptr;
        pvVar3 = lh_insert(p_Var2,local_1c);
        if (pvVar3 != (void *)0x0) {
          CRYPTO_free(pvVar3);
        }
      }
      if (local_18 != (undefined4 *)0x0) {
        p_Var2 = *(_LHASH **)(iVar1 + 4);
        *local_18 = 2;
        local_18[1] = ptr;
        pvVar3 = lh_insert(p_Var2,local_18);
        if (pvVar3 != (void *)0x0) {
          CRYPTO_free(pvVar3);
        }
      }
      if (local_14 != (undefined4 *)0x0) {
        local_14[1] = ptr;
        p_Var2 = *(_LHASH **)(iVar1 + 4);
        *local_14 = 3;
        pvVar3 = lh_insert(p_Var2,local_14);
        if (pvVar3 != (void *)0x0) {
          CRYPTO_free(pvVar3);
        }
      }
      ptr->flags = ptr->flags & 0xfffffff2;
      return ptr->nid;
    }
    ERR_put_error(8,0x69,0x41,DAT_0008c370,0x12f);
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
  return 0;
}

