
/* WARNING: Removing unreachable block (ram,0x000ab006) */
/* WARNING: Removing unreachable block (ram,0x000ab00c) */
/* WARNING: Removing unreachable block (ram,0x000aa9a8) */
/* WARNING: Removing unreachable block (ram,0x000aa9b2) */
/* WARNING: Removing unreachable block (ram,0x000ab150) */

void _dopr(undefined4 *param_1,void **param_2,int *param_3,int *param_4,undefined4 *param_5,
          char *param_6)

{
  void *pvVar1;
  int iVar2;
  int local_54;
  
  if ((*param_6 != '\0') && ((param_2 != (void **)0x0 || (*param_3 != 0)))) {
                    /* WARNING: Could not recover jumptable at 0x000aa828. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&switchD_000aa828::switchdataD_000aa82c + switchD_000aa828::switchdataD_000aa82c))();
    return;
  }
  *param_5 = 0;
  iVar2 = *param_3;
  local_54 = 0;
  if ((param_2 != (void **)0x0) && (iVar2 == 0)) {
    pvVar1 = *param_2;
    *param_3 = 0x400;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = CRYPTO_malloc(0x400,DAT_000ab178,0x2c9);
      *param_2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_000aa9d8;
      iVar2 = *param_3;
      *param_1 = 0;
    }
    else {
      pvVar1 = CRYPTO_realloc(pvVar1,0x400,DAT_000aad00,0x2d4);
      *param_2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_000aa9d8;
      iVar2 = *param_3;
    }
  }
  if (iVar2 != 0) {
    if ((undefined *)*param_1 == (undefined *)0x0) {
      *(undefined *)*param_2 = 0;
      local_54 = 1;
    }
    else {
      *(undefined *)*param_1 = 0;
      local_54 = 1;
    }
  }
LAB_000aa9d8:
  *param_4 = local_54 + -1;
  return;
}

