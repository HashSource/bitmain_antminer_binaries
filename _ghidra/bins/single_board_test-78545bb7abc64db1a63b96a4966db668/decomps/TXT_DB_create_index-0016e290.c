
int TXT_DB_create_index(TXT_DB *db,int field,qual *qual,LHASH_HASH_FN_TYPE hash,
                       LHASH_COMP_FN_TYPE cmp)

{
  lhash_st_OPENSSL_STRING *plVar1;
  int iVar2;
  OPENSSL_STRING *ppcVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  int iVar7;
  
  if (db->num_fields <= field) {
    db->error = 3;
    return 0;
  }
  plVar1 = (lhash_st_OPENSSL_STRING *)OPENSSL_LH_new(hash,cmp);
  if (plVar1 == (lhash_st_OPENSSL_STRING *)0x0) {
    db->error = 1;
    return 0;
  }
  iVar2 = OPENSSL_sk_num(db->data);
  if (0 < iVar2) {
    iVar7 = 0;
    if (qual == (qual *)0x0) {
      iVar7 = 0;
      do {
        uVar5 = OPENSSL_sk_value(db->data,iVar7);
        iVar4 = OPENSSL_LH_insert(plVar1,uVar5);
        if (iVar4 != 0) goto LAB_0016e342;
        iVar7 = iVar7 + 1;
        iVar4 = OPENSSL_LH_retrieve(plVar1,uVar5);
        if (iVar4 == 0) goto LAB_0016e35e;
      } while (iVar2 != iVar7);
    }
    else {
      do {
        ppcVar3 = (OPENSSL_STRING *)OPENSSL_sk_value(db->data,iVar7);
        iVar4 = (*qual)(ppcVar3);
        if (iVar4 != 0) {
          iVar4 = OPENSSL_LH_insert(plVar1,ppcVar3);
          if (iVar4 != 0) {
LAB_0016e342:
            db->error = 2;
            lVar6 = OPENSSL_sk_find(db->data,iVar4);
            db->arg2 = iVar7;
            db->arg1 = lVar6;
            OPENSSL_LH_free(plVar1);
            return 0;
          }
          iVar4 = OPENSSL_LH_retrieve(plVar1,ppcVar3);
          if (iVar4 == 0) {
LAB_0016e35e:
            db->error = 1;
            OPENSSL_LH_free(plVar1);
            return 0;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != iVar2);
    }
  }
  OPENSSL_LH_free(db->index[field]);
  db->index[field] = plVar1;
  db->qual[field] = (_func_4786 *)qual;
  return 1;
}

