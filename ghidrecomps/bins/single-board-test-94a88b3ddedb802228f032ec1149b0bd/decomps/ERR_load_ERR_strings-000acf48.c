
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  undefined **ppuVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  puVar4 = ERR_str_libraries;
  iVar2 = ERR_str_libraries._0_4_;
  while (iVar2 != 0) {
    (*(code *)err_fns[3])(puVar4);
    puVar4 = (undefined1 *)((int)puVar4 + 8);
    iVar2 = *(int *)puVar4;
  }
  puVar4 = ERR_str_reasons;
  iVar2 = ERR_str_reasons._0_4_;
  while (iVar2 != 0) {
    (*(code *)err_fns[3])(puVar4);
    puVar4 = (undefined1 *)((int)puVar4 + 8);
    iVar2 = *(int *)puVar4;
  }
  puVar4 = ERR_str_functs;
  ppuVar1 = err_fns;
  uVar3 = ERR_str_functs._0_4_;
  while (err_fns = ppuVar1, uVar3 != 0) {
    *(uint *)puVar4 = uVar3 | 0x2000000;
    (*(code *)ppuVar1[3])(puVar4);
    puVar4 = (undefined1 *)((int)puVar4 + 8);
    ppuVar1 = err_fns;
    uVar3 = *(uint *)puVar4;
  }
  build_SYS_str_reasons();
  if (SYS_str_reasons._0_4_ == 0) {
    return;
  }
  puVar4 = SYS_str_reasons;
  uVar3 = SYS_str_reasons._0_4_;
  do {
    ppuVar1 = err_fns;
    *(uint *)puVar4 = uVar3 | 0x2000000;
    (*(code *)ppuVar1[3])(puVar4);
    puVar4 = (undefined1 *)((int)puVar4 + 8);
    uVar3 = *(uint *)puVar4;
  } while (uVar3 != 0);
  return;
}

