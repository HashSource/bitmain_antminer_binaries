
void aging_get_update_hashrate_info(char *infoStr)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  char *infoStr_local;
  int chain;
  int len;
  
  if (aging_info.aging_24_hour_finished) {
    puVar4 = &DAT_00081b38;
  }
  else {
    puVar4 = &DAT_00081b3c;
  }
  iVar1 = sprintf(infoStr,"aging_24_hour_finished: %s, ",puVar4);
  if (aging_info.is_hash_rate_updated == false) {
    puVar4 = &DAT_00081b3c;
  }
  else {
    puVar4 = &DAT_00081b38;
  }
  iVar2 = sprintf(infoStr + iVar1,"hashrate updated: %s, ",puVar4);
  iVar3 = sprintf(infoStr + iVar1 + iVar2,"fixed %d avg %d, ",aging_info.fixed_hashrate,
                  aging_info.avg_hashrate_24_hour);
  len = iVar1 + iVar2 + iVar3;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = sprintf(infoStr + len,"%d->%d ",aging_info.old_hashrate[chain],
                      aging_info.new_hashrate[chain]);
      len = len + iVar1;
    }
  }
  if (aging_info.aging_24_hour_finished != false) {
    sprintf(infoStr + len,"update time: %s, ",DAT_0001f018);
  }
  return;
}

