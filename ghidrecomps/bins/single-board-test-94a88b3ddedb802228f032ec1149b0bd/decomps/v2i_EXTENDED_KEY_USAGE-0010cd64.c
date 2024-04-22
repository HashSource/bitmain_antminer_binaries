
_STACK * v2i_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  _STACK *st;
  ASN1_OBJECT *data;
  int iVar1;
  undefined4 *puVar2;
  char *s;
  int iVar3;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x67,0x41,DAT_0010cdf8,0x81);
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar1 = sk_num(param_3);
      if (iVar1 <= iVar3) break;
      puVar2 = (undefined4 *)sk_value(param_3,iVar3);
      s = (char *)puVar2[2];
      if (s == (char *)0x0) {
        s = (char *)puVar2[1];
      }
      data = OBJ_txt2obj(s,0);
      if (data == (ASN1_OBJECT *)0x0) {
        sk_pop_free(st,DAT_0010cdfc);
        ERR_put_error(0x22,0x67,0x6e,DAT_0010cdf8,0x8e);
        ERR_add_error_data(6,DAT_0010ce04,*puVar2,DAT_0010ce08,puVar2[1],DAT_0010ce00,puVar2[2]);
        return (_STACK *)0x0;
      }
      sk_push(st,data);
      iVar3 = iVar3 + 1;
    }
  }
  return st;
}

