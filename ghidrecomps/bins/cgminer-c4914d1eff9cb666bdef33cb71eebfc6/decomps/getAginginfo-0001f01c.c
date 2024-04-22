
void getAginginfo(char *infoStr)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  char *infoStr_local;
  int len;
  
  if (aging_info.is_aging_finished) {
    puVar3 = &DAT_00081b38;
  }
  else {
    puVar3 = &DAT_00081b3c;
  }
  if (aging_info.is_bad_machine) {
    puVar4 = &DAT_00081b38;
  }
  else {
    puVar4 = &DAT_00081b3c;
  }
  iVar1 = sprintf(infoStr,"finished: %s bad: %s from %s",puVar3,puVar4,DAT_0001f0f4);
  iVar2 = sprintf(infoStr + iVar1 + -1," to %s",DAT_0001f0f8);
  sprintf(infoStr + iVar1 + -1 + iVar2," inbalance_times %d %d %d",aging_info.inbalance_times[0],
          aging_info.inbalance_times[1],aging_info.inbalance_times[2]);
  return;
}

