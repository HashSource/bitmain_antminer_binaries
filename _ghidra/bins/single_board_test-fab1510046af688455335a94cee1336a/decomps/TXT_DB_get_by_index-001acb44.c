
OPENSSL_STRING * TXT_DB_get_by_index(TXT_DB *db,int idx,OPENSSL_STRING *value)

{
  OPENSSL_STRING *ppcVar1;
  
  if (db->num_fields <= idx) {
    db->error = 3;
    return (OPENSSL_STRING *)0x0;
  }
  if ((_LHASH *)db->index[idx] != (_LHASH *)0x0) {
    ppcVar1 = (OPENSSL_STRING *)lh_retrieve((_LHASH *)db->index[idx],value);
    db->error = 0;
    return ppcVar1;
  }
  db->error = 4;
  return (OPENSSL_STRING *)0x0;
}

