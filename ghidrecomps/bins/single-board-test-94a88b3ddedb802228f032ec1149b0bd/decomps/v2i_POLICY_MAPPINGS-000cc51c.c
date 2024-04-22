
_STACK * v2i_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  _STACK *st;
  undefined4 *puVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_OBJECT **data;
  int iVar4;
  int iVar5;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x91,0x41,DAT_000cc608,0x7b);
  }
  else {
    iVar5 = 0;
    while( true ) {
      iVar4 = sk_num(param_3);
      if (iVar4 <= iVar5) break;
      puVar1 = (undefined4 *)sk_value(param_3,iVar5);
      if ((puVar1[2] == 0) || ((char *)puVar1[1] == (char *)0x0)) {
        sk_pop_free(st,DAT_000cc604);
        iVar5 = 0x84;
LAB_000cc59c:
        ERR_put_error(0x22,0x91,0x6e,DAT_000cc608,iVar5);
        ERR_add_error_data(6,DAT_000cc610,*puVar1,DAT_000cc614,puVar1[1],DAT_000cc60c,puVar1[2]);
        return (_STACK *)0x0;
      }
      pAVar2 = OBJ_txt2obj((char *)puVar1[1],0);
      pAVar3 = OBJ_txt2obj((char *)puVar1[2],0);
      if (pAVar2 == (ASN1_OBJECT *)0x0 || pAVar3 == (ASN1_OBJECT *)0x0) {
        sk_pop_free(st,DAT_000cc604);
        iVar5 = 0x8d;
        goto LAB_000cc59c;
      }
      data = (ASN1_OBJECT **)ASN1_item_new(DAT_000cc600);
      if (data == (ASN1_OBJECT **)0x0) {
        sk_pop_free(st,DAT_000cc604);
        ERR_put_error(0x22,0x91,0x41,DAT_000cc608,0x94);
        return (_STACK *)0x0;
      }
      *data = pAVar2;
      data[1] = pAVar3;
      sk_push(st,data);
      iVar5 = iVar5 + 1;
    }
  }
  return st;
}

