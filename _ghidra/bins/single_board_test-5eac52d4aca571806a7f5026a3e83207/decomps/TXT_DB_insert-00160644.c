
int TXT_DB_insert(TXT_DB *db,OPENSSL_STRING *value)

{
  OPENSSL_STRING *ppcVar1;
  lhash_st_OPENSSL_STRING *plVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = db->num_fields;
  if (0 < iVar4) {
    iVar6 = 0;
    do {
      plVar2 = db->index[iVar6];
      if (plVar2 != (lhash_st_OPENSSL_STRING *)0x0) {
        if (db->qual[iVar6] == (_func_4786 *)0x0) {
LAB_00160670:
          ppcVar1 = (OPENSSL_STRING *)OPENSSL_LH_retrieve(plVar2,value);
          if (ppcVar1 != (OPENSSL_STRING *)0x0) {
            db->arg_row = ppcVar1;
            db->arg1 = iVar6;
            db->error = 2;
            return 0;
          }
        }
        else {
          iVar4 = (*db->qual[iVar6])(value);
          if (iVar4 != 0) {
            plVar2 = db->index[iVar6];
            goto LAB_00160670;
          }
        }
        iVar4 = db->num_fields;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
    if (0 < iVar4) {
      iVar6 = 0;
      do {
        plVar2 = db->index[iVar6];
        if (plVar2 != (lhash_st_OPENSSL_STRING *)0x0) {
          if (db->qual[iVar6] == (_func_4786 *)0x0) {
LAB_001606a6:
            OPENSSL_LH_insert(plVar2,value);
            iVar4 = OPENSSL_LH_retrieve(db->index[iVar6],value);
            if (iVar4 == 0) goto LAB_001606cc;
          }
          else {
            iVar4 = (*db->qual[iVar6])(value);
            if (iVar4 != 0) {
              plVar2 = db->index[iVar6];
              goto LAB_001606a6;
            }
          }
          iVar4 = db->num_fields;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar4);
      goto LAB_001606c2;
    }
  }
  iVar6 = 0;
LAB_001606c2:
  iVar4 = OPENSSL_sk_push(db->data,value);
  if (iVar4 != 0) {
    return 1;
  }
LAB_001606cc:
  db->error = 1;
  iVar4 = (iVar6 + -1) * 4;
  do {
    if (iVar6 < 1) {
      return 0;
    }
    iVar5 = *(int *)((int)db->index + iVar4);
    if (iVar5 != 0) {
      pcVar3 = *(code **)((int)db->qual + iVar4);
      if (pcVar3 != (code *)0x0) {
        iVar5 = (*pcVar3)(value);
        if (iVar5 == 0) goto LAB_001606f2;
        iVar5 = *(int *)((int)db->index + iVar4);
      }
      OPENSSL_LH_delete(iVar5,value);
    }
LAB_001606f2:
    iVar4 = iVar4 + -4;
    iVar6 = iVar6 + -1;
  } while( true );
}

