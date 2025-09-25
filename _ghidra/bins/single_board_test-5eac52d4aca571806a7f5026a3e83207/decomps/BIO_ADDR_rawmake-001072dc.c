
undefined4
BIO_ADDR_rawmake(undefined2 *param_1,int param_2,char *param_3,int param_4,undefined2 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 == 1) {
    if (param_4 + 1U < 0x6d) {
      memset(param_1,0,0x6e);
      *param_1 = (short)param_2;
      strncpy((char *)(param_1 + 1),param_3,0x6b);
      return 1;
    }
  }
  else if (param_2 == 2) {
    if (param_4 == 4) {
      *param_1 = (short)param_2;
      *(undefined4 *)(param_1 + 2) = 0;
      param_1[1] = param_5;
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 6) = 0;
      *(undefined4 *)(param_1 + 2) = *(undefined4 *)param_3;
      return 1;
    }
  }
  else if (param_2 == 10 && param_4 == 0x10) {
    *(undefined4 *)(param_1 + 2) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 10) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    param_1[1] = param_5;
    *param_1 = 10;
    uVar1 = *(undefined4 *)(param_3 + 4);
    uVar2 = *(undefined4 *)(param_3 + 8);
    uVar3 = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)param_3;
    *(undefined4 *)(param_1 + 6) = uVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 10) = uVar3;
    return 1;
  }
  return 0;
}

