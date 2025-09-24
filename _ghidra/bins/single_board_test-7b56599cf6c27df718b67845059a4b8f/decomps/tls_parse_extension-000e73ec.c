
undefined4
tls_parse_extension(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
                   undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar3 = param_4 + param_2 * 0x18;
  if ((*(int *)(iVar3 + 8) == 0) || (*(int *)(iVar3 + 0xc) != 0)) {
    return 1;
  }
  *(undefined4 *)(iVar3 + 0xc) = 1;
  if (param_2 < 0x1a) {
    iVar1 = extension_is_relevant(param_1,(&DAT_00270134)[param_2 * 8]);
    if (iVar1 == 0) {
      return 1;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00270140 + param_2 * 0x20);
    if (*(int *)(param_1 + 0x1c) != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(&DAT_0027013c + param_2 * 0x20);
    }
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000e7458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1,iVar3,param_3,param_5);
      return uVar2;
    }
  }
  uVar2 = custom_ext_parse(param_1,param_3,*(undefined4 *)(iVar3 + 0x10),
                           *(undefined4 *)(param_4 + param_2 * 0x18),*(undefined4 *)(iVar3 + 4),
                           param_5,param_6);
  return uVar2;
}

