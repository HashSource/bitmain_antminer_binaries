
void load_builtin_compressions(void)

{
  _STACK **pp_Var1;
  _STACK *p_Var2;
  undefined4 *ptr;
  COMP_METHOD *pCVar3;
  char *pcVar4;
  
  pp_Var1 = DAT_0007f938;
  CRYPTO_lock(5,0x10,DAT_0007f93c,0x1d9);
  if (*pp_Var1 != (_STACK *)0x0) {
    CRYPTO_lock(6,0x10,DAT_0007f93c,0x1f9);
    return;
  }
  CRYPTO_lock(6,0x10,DAT_0007f93c,0x1db);
  CRYPTO_lock(9,0x10,DAT_0007f93c,0x1dc);
  if (*pp_Var1 == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    p_Var2 = sk_new(DAT_0007f940);
    *pp_Var1 = p_Var2;
    if (p_Var2 != (_STACK *)0x0) {
      ptr = (undefined4 *)CRYPTO_malloc(0xc,DAT_0007f93c,0x1e5);
      if (ptr != (undefined4 *)0x0) {
        pCVar3 = COMP_zlib();
        ptr[2] = pCVar3;
        if ((pCVar3 == (COMP_METHOD *)0x0) || (pCVar3->type != 0)) {
          pcVar4 = pCVar3->name;
          *ptr = 1;
          p_Var2 = *pp_Var1;
          ptr[1] = pcVar4;
          sk_push(p_Var2,ptr);
        }
        else {
          CRYPTO_free(ptr);
        }
      }
      sk_sort(*pp_Var1);
    }
    CRYPTO_mem_ctrl(2);
  }
  CRYPTO_lock(10,0x10,DAT_0007f93c,0x1f7);
  return;
}

