
void TXT_DB_free(TXT_DB *db)

{
  lhash_st_OPENSSL_STRING **ptr;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *puVar6;
  void *ptr_00;
  
  if (db == (TXT_DB *)0x0) {
    return;
  }
  ptr = db->index;
  if (ptr != (lhash_st_OPENSSL_STRING **)0x0) {
    iVar2 = db->num_fields + -1;
    if (-1 < iVar2) {
      iVar4 = iVar2 * 4;
      do {
        iVar2 = iVar2 + -1;
        OPENSSL_LH_free(*(undefined4 *)((int)ptr + iVar4));
        iVar4 = iVar4 + -4;
        ptr = db->index;
      } while (iVar2 != -1);
    }
    CRYPTO_free(ptr);
  }
  CRYPTO_free(db->qual);
  if (db->data != (stack_st_OPENSSL_PSTRING *)0x0) {
    iVar2 = OPENSSL_sk_num();
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        pvVar1 = (void *)OPENSSL_sk_value(db->data,iVar2);
        iVar4 = db->num_fields;
        pvVar5 = *(void **)((int)pvVar1 + iVar4 * 4);
        if (pvVar5 == (void *)0x0) {
          if (0 < iVar4) {
            puVar6 = (undefined4 *)((int)pvVar1 - 4);
            iVar4 = 0;
            do {
              puVar6 = puVar6 + 1;
              iVar4 = iVar4 + 1;
              CRYPTO_free((void *)*puVar6);
            } while (iVar4 < db->num_fields);
          }
        }
        else if (0 < iVar4) {
          iVar3 = 0;
          do {
            ptr_00 = *(void **)((int)pvVar1 + iVar3 * 4);
            iVar3 = iVar3 + 1;
            if (pvVar5 < ptr_00 || ptr_00 < pvVar1) {
              CRYPTO_free(ptr_00);
              iVar4 = db->num_fields;
            }
          } while (iVar3 < iVar4);
        }
        pvVar1 = (void *)OPENSSL_sk_value(db->data,iVar2);
        iVar2 = iVar2 + -1;
        CRYPTO_free(pvVar1);
      } while (iVar2 != -1);
    }
    OPENSSL_sk_free(db->data);
  }
  CRYPTO_free(db);
  return;
}

