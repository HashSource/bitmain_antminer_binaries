
int OBJ_add_sigid(int signid,int dig_id,int pkey_id)

{
  _STACK **pp_Var1;
  _STACK **pp_Var2;
  _STACK **pp_Var3;
  int *data;
  int iVar4;
  _STACK *p_Var5;
  
  pp_Var1 = DAT_0008d174;
  if (*DAT_0008d174 == (_STACK *)0x0) {
    p_Var5 = sk_new(DAT_0008d180);
    *pp_Var1 = p_Var5;
    if (p_Var5 == (_STACK *)0x0) {
      return 0;
    }
  }
  pp_Var2 = DAT_0008d178;
  if (*DAT_0008d178 == (_STACK *)0x0) {
    p_Var5 = sk_new(DAT_0008d184);
    *pp_Var2 = p_Var5;
    if (p_Var5 == (_STACK *)0x0) {
      return 0;
    }
  }
  data = (int *)CRYPTO_malloc(0xc,DAT_0008d17c,0x9f);
  if (data != (int *)0x0) {
    data[2] = pkey_id;
    *data = signid;
    data[1] = dig_id;
    iVar4 = sk_push(*pp_Var1,data);
    pp_Var3 = DAT_0008d178;
    pp_Var1 = DAT_0008d174;
    if (iVar4 == 0) {
      CRYPTO_free(data);
      return 0;
    }
    iVar4 = sk_push(*pp_Var2,data);
    if (iVar4 != 0) {
      sk_sort(*pp_Var1);
      sk_sort(*pp_Var3);
      return 1;
    }
  }
  return 0;
}

