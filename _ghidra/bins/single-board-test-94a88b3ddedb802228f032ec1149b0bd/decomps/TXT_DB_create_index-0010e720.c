
int TXT_DB_create_index(TXT_DB *db,int field,qual *qual,LHASH_HASH_FN_TYPE hash,
                       LHASH_COMP_FN_TYPE cmp)

{
  _LHASH *lh;
  int iVar1;
  OPENSSL_STRING *data;
  int iVar2;
  void *pvVar3;
  lhash_st_OPENSSL_STRING **pplVar4;
  int iVar5;
  
  if (db->num_fields <= field) {
    db->error = 3;
    return 0;
  }
  lh = lh_new(hash,cmp);
  if (lh == (_LHASH *)0x0) {
    db->error = 1;
    return 0;
  }
  iVar1 = sk_num(&db->data->stack);
  if (0 < iVar1) {
    iVar5 = 0;
    if (qual == (qual *)0x0) {
      iVar5 = 0;
      do {
        pvVar3 = sk_value(&db->data->stack,iVar5);
        pvVar3 = lh_insert(lh,pvVar3);
        if (pvVar3 != (void *)0x0) goto LAB_0010e7ba;
        iVar5 = iVar5 + 1;
      } while (iVar5 != iVar1);
    }
    else {
      do {
        data = (OPENSSL_STRING *)sk_value(&db->data->stack,iVar5);
        iVar2 = (*qual)(data);
        if ((iVar2 != 0) && (pvVar3 = lh_insert(lh,data), pvVar3 != (void *)0x0)) {
LAB_0010e7ba:
          db->error = 2;
          iVar1 = sk_find(&db->data->stack,pvVar3);
          db->arg2 = iVar5;
          db->arg1 = iVar1;
          lh_free(lh);
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != iVar1);
    }
  }
  pplVar4 = db->index;
  if ((_LHASH *)pplVar4[field] != (_LHASH *)0x0) {
    lh_free((_LHASH *)pplVar4[field]);
    pplVar4 = db->index;
  }
  pplVar4[field] = (lhash_st_OPENSSL_STRING *)lh;
  db->qual[field] = (_func_4786 *)qual;
  return 1;
}

