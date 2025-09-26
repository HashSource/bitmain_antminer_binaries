
void trans_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar2;
  
  iVar1 = BN_GENCB_get_arg(param_3);
  puVar2 = *(undefined4 **)(iVar1 + 0x20);
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x1c);
  *puVar2 = param_1;
  puVar2[1] = param_2;
                    /* WARNING: Could not recover jumptable at 0x0013c8fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

