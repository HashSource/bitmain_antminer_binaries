
void timeout_cb(SSL_SESSION *param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  stack_st_void *psVar2;
  int iVar3;
  _func_290 *p_Var4;
  code *pcVar5;
  bool bVar6;
  
  iVar1 = param_2[1];
  iVar3 = param_4;
  if ((iVar1 != 0) && (iVar3 = param_1->timeout + param_1->time, iVar1 <= iVar3)) {
    return;
  }
  OPENSSL_LH_delete(param_2[2],param_1,iVar1,iVar3,param_4);
  p_Var4 = (_func_290 *)(param_1->ex_data).dummy;
  iVar3 = *param_2;
  if ((p_Var4 != (_func_290 *)0x0) &&
     (psVar2 = (param_1->ex_data).sk, psVar2 != (stack_st_void *)0x0)) {
    if (p_Var4 == (_func_290 *)(iVar3 + 0x20)) {
      bVar6 = psVar2 == (stack_st_void *)(iVar3 + 0x1c);
      if (bVar6) {
        p_Var4 = (_func_290 *)0x0;
      }
      if (!bVar6) {
        *(stack_st_void **)(iVar3 + 0x20) = psVar2;
      }
      if (bVar6) {
        *(_func_290 **)(iVar3 + 0x1c) = p_Var4;
      }
      if (bVar6) {
        *(_func_290 **)(iVar3 + 0x20) = p_Var4;
      }
      if (!bVar6) {
        psVar2[0x16].stack.comp = p_Var4;
      }
    }
    else {
      bVar6 = psVar2 == (stack_st_void *)(iVar3 + 0x1c);
      if (!bVar6) {
        *(stack_st_void **)(p_Var4 + 0x1c4) = psVar2;
        psVar2 = (param_1->ex_data).sk;
      }
      if (bVar6) {
        *(_func_290 **)(iVar3 + 0x1c) = p_Var4;
      }
      if (bVar6) {
        *(stack_st_void **)(p_Var4 + 0x1c4) = psVar2;
      }
      if (!bVar6) {
        psVar2[0x16].stack.comp = p_Var4;
      }
    }
    (param_1->ex_data).dummy = 0;
    (param_1->ex_data).sk = (stack_st_void *)0x0;
    iVar3 = *param_2;
  }
  pcVar5 = *(code **)(iVar3 + 0x30);
  param_1->not_resumable = 1;
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(iVar3,param_1);
  }
  SSL_SESSION_free(param_1);
  return;
}

