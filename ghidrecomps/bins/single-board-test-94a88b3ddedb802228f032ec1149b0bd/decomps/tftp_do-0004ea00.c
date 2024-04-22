
int tftp_do(int param_1,undefined *param_2)

{
  int iVar1;
  int *piVar2;
  
  *param_2 = 0;
  piVar2 = *(int **)(param_1 + 0x3c0);
  if (piVar2 == (int *)0x0) {
    iVar1 = tftp_connect();
    if (iVar1 != 0) {
      return iVar1;
    }
    piVar2 = *(int **)(param_1 + 0x3c0);
    if (piVar2 == (int *)0x0) {
      return 0x2c;
    }
  }
  *param_2 = 0;
  iVar1 = tftp_state_machine(piVar2);
  if (*piVar2 == 3) {
    if (iVar1 == 0) goto LAB_0004ea28;
  }
  else if (iVar1 == 0) {
    tftp_multi_statemach(param_1,param_2);
LAB_0004ea28:
    iVar1 = tftp_translate_code(piVar2[2]);
    return iVar1;
  }
  return iVar1;
}

