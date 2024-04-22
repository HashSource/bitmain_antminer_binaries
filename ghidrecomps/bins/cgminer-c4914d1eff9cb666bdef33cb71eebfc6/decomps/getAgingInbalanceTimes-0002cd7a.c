
void getAgingInbalanceTimes(char *infoStr)

{
  int iVar1;
  char *infoStr_local;
  
  iVar1 = aging_get_total_inbalance_times();
  sprintf(infoStr,"aging reopen time=%d",iVar1);
  return;
}

