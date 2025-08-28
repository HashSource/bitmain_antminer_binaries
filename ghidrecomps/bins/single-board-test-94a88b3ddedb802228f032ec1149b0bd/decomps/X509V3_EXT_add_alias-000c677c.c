
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  undefined4 *puVar1;
  int *data;
  _STACK *st;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *local_5c;
  int local_58 [15];
  
  local_5c = local_58;
  if (-1 < nid_from) {
    local_58[0] = nid_from;
    puVar1 = (undefined4 *)OBJ_bsearch_(&local_5c,&standard_exts,0x2a,4,(cmp *)0xc656d);
    if (puVar1 == (undefined4 *)0x0) {
      if ((ext_list == (_STACK *)0x0) || (iVar3 = sk_find(ext_list,local_58), iVar3 == -1))
      goto LAB_000c684c;
      piVar6 = (int *)sk_value(ext_list,iVar3);
    }
    else {
      piVar6 = (int *)*puVar1;
    }
    if (piVar6 != (int *)0x0) {
      data = (int *)CRYPTO_malloc(0x38,"v3_lib.c",0xa7);
      if (data == (int *)0x0) {
        ERR_put_error(0x22,0x6a,0x41,"v3_lib.c",0xa8);
        return 0;
      }
      uVar2 = piVar6[1];
      iVar3 = piVar6[2];
      iVar4 = piVar6[3];
      *data = *piVar6;
      data[1] = uVar2;
      data[2] = iVar3;
      data[3] = iVar4;
      st = ext_list;
      iVar3 = piVar6[5];
      iVar4 = piVar6[6];
      iVar5 = piVar6[7];
      data[4] = piVar6[4];
      data[5] = iVar3;
      data[6] = iVar4;
      data[7] = iVar5;
      iVar3 = piVar6[9];
      iVar4 = piVar6[10];
      iVar5 = piVar6[0xb];
      data[8] = piVar6[8];
      data[9] = iVar3;
      data[10] = iVar4;
      data[0xb] = iVar5;
      iVar3 = piVar6[0xd];
      data[0xc] = piVar6[0xc];
      data[0xd] = iVar3;
      *data = nid_to;
      data[1] = uVar2 | 1;
      if ((st == (_STACK *)0x0) && (st = sk_new((cmp *)0xc6561), ext_list = st, st == (_STACK *)0x0)
         ) {
        ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x4d);
        return 0;
      }
      iVar3 = sk_push(st,data);
      if (iVar3 != 0) {
        return 1;
      }
      ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x51);
      return 0;
    }
  }
LAB_000c684c:
  ERR_put_error(0x22,0x6a,0x66,"v3_lib.c",0xa2);
  return 0;
}

