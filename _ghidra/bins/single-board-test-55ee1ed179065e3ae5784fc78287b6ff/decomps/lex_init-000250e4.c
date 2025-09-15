
undefined4 lex_init(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  stream_init(param_1,param_2,param_3);
  iVar1 = strbuffer_init(param_1 + 0x28);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

