
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  int iVar1;
  
  if (ext_list == (_STACK *)0x0) {
    ext_list = sk_new((cmp *)0x1671f1);
    iVar1 = 0x4d;
    if (ext_list == (_STACK *)0x0) goto LAB_00167232;
  }
  iVar1 = sk_push(ext_list,ext);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = 0x51;
LAB_00167232:
  ERR_put_error(0x22,0x68,0x41,"v3_lib.c",iVar1);
  return 0;
}

