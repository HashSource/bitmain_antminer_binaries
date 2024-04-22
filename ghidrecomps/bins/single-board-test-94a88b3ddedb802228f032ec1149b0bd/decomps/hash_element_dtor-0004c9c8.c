
void hash_element_dtor(int param_1,int *param_2)

{
  code **ppcVar1;
  code *pcVar2;
  
  ppcVar1 = DAT_0004c9f0;
  (**DAT_0004c9f0)(param_2[1]);
  param_2[1] = 0;
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0xc))();
    *param_2 = 0;
  }
  pcVar2 = *ppcVar1;
  param_2[2] = 0;
  (*pcVar2)(param_2);
  return;
}

