
byte twoc2hex(undefined param_1,undefined param_2)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = c2hex(param_1);
  bVar2 = c2hex(param_2);
  return bVar2 ^ cVar1 << 4;
}

