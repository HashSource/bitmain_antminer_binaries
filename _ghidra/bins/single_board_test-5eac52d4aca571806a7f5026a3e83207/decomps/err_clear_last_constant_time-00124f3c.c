
void err_clear_last_constant_time(uint param_1)

{
  ERR_STATE *pEVar1;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    pEVar1->err_flags[pEVar1->err_line[0xe] + -2] =
         ~((int)(param_1 - 1 & ~param_1) >> 0x1f) & 2U |
         pEVar1->err_flags[pEVar1->err_line[0xe] + -2];
  }
  return;
}

