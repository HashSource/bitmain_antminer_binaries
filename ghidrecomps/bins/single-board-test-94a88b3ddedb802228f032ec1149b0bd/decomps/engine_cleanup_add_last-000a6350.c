
void engine_cleanup_add_last(undefined4 param_1)

{
  _STACK **pp_Var1;
  undefined4 *data;
  _STACK *p_Var2;
  
  pp_Var1 = DAT_000a6384;
  if (*DAT_000a6384 == (_STACK *)0x0) {
    p_Var2 = sk_new_null();
    *pp_Var1 = p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      return;
    }
  }
  data = (undefined4 *)CRYPTO_malloc(4,DAT_000a6388,0xa8);
  if (data != (undefined4 *)0x0) {
    *data = param_1;
    sk_push(*pp_Var1,data);
    return;
  }
  return;
}

