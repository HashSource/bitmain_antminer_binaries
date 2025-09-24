
int obj_name_cmp(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 - *param_2 != 0) {
    return *param_1 - *param_2;
  }
  if ((name_funcs_stack != 0) && (iVar1 = OPENSSL_sk_num(), *param_1 < iVar1)) {
    iVar1 = OPENSSL_sk_value(name_funcs_stack);
                    /* WARNING: Could not recover jumptable at 0x00142098. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(iVar1 + 4))(param_1[2],param_2[2]);
    return iVar1;
  }
  iVar1 = strcasecmp((char *)param_1[2],(char *)param_2[2]);
  return iVar1;
}

