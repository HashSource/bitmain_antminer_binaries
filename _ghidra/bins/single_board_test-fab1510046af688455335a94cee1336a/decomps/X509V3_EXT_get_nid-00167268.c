
X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  undefined4 *puVar1;
  int iVar2;
  X509V3_EXT_METHOD *pXVar3;
  int *local_4c;
  int local_48 [14];
  
  if (-1 < nid) {
    local_4c = local_48;
    local_48[0] = nid;
    puVar1 = (undefined4 *)OBJ_bsearch_(&local_4c,&standard_exts,0x2a,4,(cmp *)0x1671fd);
    if (puVar1 != (undefined4 *)0x0) {
      return (X509V3_EXT_METHOD *)*puVar1;
    }
    if ((ext_list != (_STACK *)0x0) && (iVar2 = sk_find(ext_list,local_48), iVar2 != -1)) {
      pXVar3 = (X509V3_EXT_METHOD *)sk_value(ext_list,iVar2);
      return pXVar3;
    }
  }
  return (X509V3_EXT_METHOD *)0x0;
}

