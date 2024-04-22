
int pop3_done(int *param_1,int param_2)

{
  code **ppcVar1;
  code *pcVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(*param_1 + 0x14c);
  if (puVar3 != (undefined4 *)0x0) {
    if (param_2 != 0) {
      *(undefined *)((int)param_1 + 0x1ed) = 1;
    }
    ppcVar1 = DAT_00050f70;
    (**DAT_00050f70)(puVar3[1]);
    pcVar2 = *ppcVar1;
    puVar3[1] = 0;
    (*pcVar2)(puVar3[2]);
    puVar3[2] = 0;
    *puVar3 = 0;
    return param_2;
  }
  return 0;
}

