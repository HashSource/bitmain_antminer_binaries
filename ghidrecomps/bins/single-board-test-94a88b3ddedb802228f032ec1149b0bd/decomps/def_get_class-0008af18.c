
undefined4 * def_get_class(undefined4 param_1)

{
  _LHASH **pp_Var1;
  undefined4 *puVar2;
  undefined4 *ptr;
  _STACK *p_Var3;
  _LHASH *p_Var4;
  undefined4 local_24 [4];
  
  pp_Var1 = DAT_0008afec;
  if (*DAT_0008afec == (_LHASH *)0x0) {
    CRYPTO_lock(9,2,DAT_0008aff0,0x116);
    if (*pp_Var1 == (_LHASH *)0x0) {
      p_Var4 = lh_new(DAT_0008aff4,DAT_0008aff8);
      *pp_Var1 = p_Var4;
      if (p_Var4 == (_LHASH *)0x0) {
        CRYPTO_lock(10,2,DAT_0008aff0,0x119);
        return (undefined4 *)0x0;
      }
    }
    CRYPTO_lock(10,2,DAT_0008aff0,0x119);
  }
  local_24[0] = param_1;
  CRYPTO_lock(9,2,DAT_0008aff0,0x13e);
  puVar2 = (undefined4 *)lh_retrieve(*pp_Var1,local_24);
  pp_Var1 = DAT_0008afec;
  ptr = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    ptr = (undefined4 *)CRYPTO_malloc(0xc,DAT_0008aff0,0x141);
    if (ptr != (undefined4 *)0x0) {
      *ptr = param_1;
      ptr[2] = 0;
      p_Var3 = sk_new_null();
      ptr[1] = p_Var3;
      if (p_Var3 != (_STACK *)0x0) {
        lh_insert(*pp_Var1,ptr);
        goto LAB_0008af46;
      }
      CRYPTO_free(ptr);
    }
    CRYPTO_lock(10,2,DAT_0008aff0,0x152);
    ERR_put_error(0xf,0x69,0x41,DAT_0008aff0,0x154);
  }
  else {
LAB_0008af46:
    CRYPTO_lock(10,2,DAT_0008aff0,0x152);
    puVar2 = ptr;
  }
  return puVar2;
}

