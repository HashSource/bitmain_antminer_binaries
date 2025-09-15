
undefined4 restart_stratum(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x281) != '\0') {
    suspend_stratum();
  }
  iVar1 = initiate_stratum(param_1);
  if ((iVar1 != 0) &&
     (((*(char *)(param_1 + 0x244) == '\0' || (iVar1 = subscribe_extranonce(param_1), iVar1 != 0))
      && (iVar1 = auth_stratum(param_1), iVar1 != 0)))) {
    stratum_resumed(param_1);
    return 1;
  }
  pool_died(param_1);
  return 0;
}

