
_STACK * v2i_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  _STACK *st;
  undefined4 *puVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_VALUE *data;
  int iVar4;
  int iVar5;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x91,0x41,"v3_pmaps.c",0x7b);
  }
  else {
    iVar5 = 0;
    while( true ) {
      iVar4 = sk_num(param_3);
      if (iVar4 <= iVar5) break;
      puVar1 = (undefined4 *)sk_value(param_3,iVar5);
      if ((puVar1[2] == 0) || ((char *)puVar1[1] == (char *)0x0)) {
        sk_pop_free(st,(func *)0x16ce11);
        iVar5 = 0x84;
LAB_0016ce9c:
        ERR_put_error(0x22,0x91,0x6e,"v3_pmaps.c",iVar5);
        ERR_add_error_data(6,"section:",*puVar1,",name:",puVar1[1],",value:",puVar1[2]);
        return (_STACK *)0x0;
      }
      pAVar2 = OBJ_txt2obj((char *)puVar1[1],0);
      pAVar3 = OBJ_txt2obj((char *)puVar1[2],0);
      if (pAVar2 == (ASN1_OBJECT *)0x0 || pAVar3 == (ASN1_OBJECT *)0x0) {
        sk_pop_free(st,(func *)0x16ce11);
        iVar5 = 0x8d;
        goto LAB_0016ce9c;
      }
      data = ASN1_item_new((ASN1_ITEM *)&POLICY_MAPPING_it);
      if (data == (ASN1_VALUE *)0x0) {
        sk_pop_free(st,(func *)0x16ce11);
        ERR_put_error(0x22,0x91,0x41,"v3_pmaps.c",0x94);
        return (_STACK *)0x0;
      }
      *(ASN1_OBJECT **)data = pAVar2;
      *(ASN1_OBJECT **)(data + 4) = pAVar3;
      sk_push(st,data);
      iVar5 = iVar5 + 1;
    }
  }
  return st;
}

