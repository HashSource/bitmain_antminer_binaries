
void TXT_DB_free(TXT_DB *db)

{
  void *pvVar1;
  lhash_st_OPENSSL_STRING **ptr;
  void *ptr_00;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  
  if (db != (TXT_DB *)0x0) {
    ptr = db->index;
    if (ptr != (lhash_st_OPENSSL_STRING **)0x0) {
      iVar2 = db->num_fields + -1;
      if (-1 < iVar2) {
        iVar4 = iVar2 * 4;
        do {
          puVar5 = (undefined4 *)((int)ptr + iVar4);
          iVar2 = iVar2 + -1;
          iVar4 = iVar4 + -4;
          if ((_LHASH *)*puVar5 != (_LHASH *)0x0) {
            lh_free((_LHASH *)*puVar5);
            ptr = db->index;
          }
        } while (iVar2 != -1);
      }
      CRYPTO_free(ptr);
    }
    if (db->qual != (_func_4786 **)0x0) {
      CRYPTO_free(db->qual);
    }
    if (&db->data->stack != (_STACK *)0x0) {
      iVar2 = sk_num(&db->data->stack);
      iVar2 = iVar2 + -1;
      if (-1 < iVar2) {
        do {
          pvVar1 = sk_value(&db->data->stack,iVar2);
          iVar4 = db->num_fields;
          pvVar6 = *(void **)((int)pvVar1 + iVar4 * 4);
          if (pvVar6 == (void *)0x0) {
            if (0 < iVar4) {
              puVar5 = (undefined4 *)((int)pvVar1 + -4);
              iVar3 = 0;
              do {
                puVar5 = puVar5 + 1;
                iVar3 = iVar3 + 1;
                if ((void *)*puVar5 != (void *)0x0) {
                  CRYPTO_free((void *)*puVar5);
                  iVar4 = db->num_fields;
                }
              } while (iVar3 < iVar4);
            }
          }
          else if (0 < iVar4) {
            puVar5 = (undefined4 *)((int)pvVar1 + -4);
            iVar3 = 0;
            do {
              puVar5 = puVar5 + 1;
              ptr_00 = (void *)*puVar5;
              iVar3 = iVar3 + 1;
              if (((ptr_00 < pvVar1) || (pvVar6 < ptr_00)) && (ptr_00 != (void *)0x0)) {
                CRYPTO_free(ptr_00);
                iVar4 = db->num_fields;
              }
            } while (iVar3 < iVar4);
          }
          pvVar1 = sk_value(&db->data->stack,iVar2);
          iVar2 = iVar2 + -1;
          CRYPTO_free(pvVar1);
        } while (iVar2 != -1);
      }
      sk_free(&db->data->stack);
    }
    CRYPTO_free(db);
    return;
  }
  return;
}

