
int smtp_doing(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = smtp_multi_statemach();
  if (((iVar1 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
    smtp_dophase_done_isra_3_part_4(param_1);
  }
  return iVar1;
}

