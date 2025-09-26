
/* WARNING: Unknown calling convention */

int get_margin(void)

{
  int iVar1;
  _Bool _Var2;
  char *pcVar3;
  double dVar4;
  int freq;
  int margin;
  
  dVar4 = ceil((0.992 / (double)g_rt.nonce_rate - 1.0) *
               (double)(longlong)
                       (int)(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].
                            Frequence);
  iVar1 = (int)(longlong)dVar4;
  pcVar3 = strstr((Local_Config_Information->Hash_Board).Board_Name,"70502");
  if ((pcVar3 == (char *)0x0) || (_Var2 = is_ft("F1V02B4C1-3"), !_Var2)) {
    if (iVar1 < 1) {
      margin = 3;
    }
    else {
      margin = iVar1 + 3;
    }
  }
  else if (iVar1 < 1) {
    margin = 5;
  }
  else {
    margin = iVar1 + 5;
  }
  return margin;
}

