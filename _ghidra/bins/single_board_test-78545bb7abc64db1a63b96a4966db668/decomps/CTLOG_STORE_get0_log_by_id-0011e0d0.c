
int CTLOG_STORE_get0_log_by_id(undefined4 *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = OPENSSL_sk_num(*param_1);
    if (iVar2 <= iVar3) {
      return 0;
    }
    iVar2 = OPENSSL_sk_value(*param_1,iVar3);
    iVar1 = memcmp((void *)(iVar2 + 4),param_2,param_3);
    iVar3 = iVar3 + 1;
  } while (iVar1 != 0);
  return iVar2;
}

