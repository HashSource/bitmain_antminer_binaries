
void head_join(undefined4 param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  
  if (*param_4 == '\0') {
    if (param_3 != 0) {
      io_add(param_1,&DAT_0005c74c);
      iVar1 = escape_string(param_2,1);
      goto LAB_00015104;
    }
  }
  else {
    if (param_3 != 0) {
      io_add(param_1,&DAT_000634c8);
      *param_4 = '\0';
      iVar1 = escape_string(param_2,1);
LAB_00015104:
      io_add(param_1,&DAT_0005c7f8);
      io_add(param_1,iVar1);
      io_add(param_1,&DAT_000581c4);
      goto LAB_000150b6;
    }
    *param_4 = '\0';
  }
  iVar1 = escape_string(param_2,param_3);
  io_add(param_1,&DAT_00057a20);
  io_add(param_1,iVar1);
  io_add(param_1,&DAT_00057a28);
LAB_000150b6:
  if (param_2 == iVar1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00012060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0007ce68)(iVar1);
  return;
}

