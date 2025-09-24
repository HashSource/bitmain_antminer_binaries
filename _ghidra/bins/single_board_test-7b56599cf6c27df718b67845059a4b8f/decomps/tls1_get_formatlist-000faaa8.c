
void tls1_get_formatlist(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x564) == 0) {
    *param_2 = (int)&ecformats_default;
    if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) == 0) {
      uVar1 = 3;
    }
    else {
      uVar1 = 2;
    }
    *param_3 = uVar1;
    return;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x560);
  *param_2 = *(int *)(param_1 + 0x564);
  *param_3 = uVar1;
  return;
}

