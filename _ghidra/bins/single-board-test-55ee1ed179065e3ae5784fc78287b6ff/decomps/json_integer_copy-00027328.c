
undefined4 json_integer_copy(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = json_integer_value(param_1);
  uVar1 = json_integer((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  return uVar1;
}

