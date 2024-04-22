
/* WARNING: Unknown calling convention */

char * set_extranonce_subscribe(char *arg)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  pool *pool;
  char tmp42 [2048];
  
  iVar1 = DAT_00021750;
  iVar2 = *DAT_00021754;
  iVar3 = *(int *)(DAT_00021750 + 0x494) + 1;
  *(int *)(DAT_00021750 + 0x494) = iVar3;
  if (iVar2 < iVar3) {
    add_pool();
    iVar3 = *(int *)(iVar1 + 0x494);
  }
  puVar4 = *(undefined4 **)(*DAT_00021758 + (iVar3 + -1) * 4);
  if ((*DAT_0002175c != '\0') &&
     (((*DAT_00021760 != '\0' || (*DAT_00021764 != '\0')) || (6 < *DAT_00021768)))) {
    snprintf(tmp42,0x800,DAT_0002176c,*puVar4);
    _applog(7,tmp42,false);
  }
  opt_set_bool((_Bool *)(puVar4 + 0x91));
  return (char *)0x0;
}

