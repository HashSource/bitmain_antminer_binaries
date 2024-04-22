
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  _STACK **pp_Var1;
  int **ppiVar2;
  int *data;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  _STACK *st;
  int *local_5c;
  int local_58 [15];
  
  local_5c = local_58;
  if (-1 < nid_from) {
    local_58[0] = nid_from;
    ppiVar2 = (int **)OBJ_bsearch_(&local_5c,DAT_000c6878,0x2a,4,DAT_000c6874);
    pp_Var1 = DAT_000c6880;
    if (ppiVar2 == (int **)0x0) {
      if ((*DAT_000c6880 == (_STACK *)0x0) || (iVar4 = sk_find(*DAT_000c6880,local_58), iVar4 == -1)
         ) goto LAB_000c684c;
      piVar7 = (int *)sk_value(*pp_Var1,iVar4);
    }
    else {
      piVar7 = *ppiVar2;
    }
    if (piVar7 != (int *)0x0) {
      data = (int *)CRYPTO_malloc(0x38,DAT_000c687c,0xa7);
      pp_Var1 = DAT_000c6880;
      if (data == (int *)0x0) {
        ERR_put_error(0x22,0x6a,0x41,DAT_000c687c,0xa8);
        return 0;
      }
      uVar3 = piVar7[1];
      iVar4 = piVar7[2];
      iVar5 = piVar7[3];
      *data = *piVar7;
      data[1] = uVar3;
      data[2] = iVar4;
      data[3] = iVar5;
      st = *pp_Var1;
      iVar4 = piVar7[5];
      iVar5 = piVar7[6];
      iVar6 = piVar7[7];
      data[4] = piVar7[4];
      data[5] = iVar4;
      data[6] = iVar5;
      data[7] = iVar6;
      iVar4 = piVar7[9];
      iVar5 = piVar7[10];
      iVar6 = piVar7[0xb];
      data[8] = piVar7[8];
      data[9] = iVar4;
      data[10] = iVar5;
      data[0xb] = iVar6;
      iVar4 = piVar7[0xd];
      data[0xc] = piVar7[0xc];
      data[0xd] = iVar4;
      *data = nid_to;
      data[1] = uVar3 | 1;
      if (st == (_STACK *)0x0) {
        st = sk_new(DAT_000c6884);
        *pp_Var1 = st;
        if (st == (_STACK *)0x0) {
          ERR_put_error(0x22,0x68,0x41,DAT_000c687c,0x4d);
          return 0;
        }
      }
      iVar4 = sk_push(st,data);
      if (iVar4 != 0) {
        return 1;
      }
      ERR_put_error(0x22,0x68,0x41,DAT_000c687c,0x51);
      return 0;
    }
  }
LAB_000c684c:
  ERR_put_error(0x22,0x6a,0x66,DAT_000c687c,0xa2);
  return 0;
}

