
X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  X509V3_EXT_METHOD *pXVar3;
  int *local_4c;
  int local_48 [14];
  
  if (-1 < nid) {
    local_4c = local_48;
    local_48[0] = nid;
    puVar1 = (undefined4 *)OBJ_bsearch_(&local_4c,&standard_exts,0x2f,4,(cmp *)0x171a0d);
    if (puVar1 != (undefined4 *)0x0) {
      return (X509V3_EXT_METHOD *)*puVar1;
    }
    if (ext_list != 0) {
      uVar2 = OPENSSL_sk_find(ext_list,local_48);
      pXVar3 = (X509V3_EXT_METHOD *)OPENSSL_sk_value(ext_list,uVar2);
      return pXVar3;
    }
  }
  return (X509V3_EXT_METHOD *)0x0;
}

