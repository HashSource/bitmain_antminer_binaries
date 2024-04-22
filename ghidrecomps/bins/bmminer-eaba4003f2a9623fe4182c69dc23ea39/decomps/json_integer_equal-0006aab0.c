
int json_integer_equal(json_t *integer1,json_t *integer2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  json_int_t jVar5;
  json_int_t jVar6;
  json_t *integer2_local;
  json_t *integer1_local;
  
  jVar5 = json_integer_value(integer1);
  jVar6 = json_integer_value(integer2);
  iVar3 = (int)((ulonglong)jVar6 >> 0x20);
  bVar4 = (int)((ulonglong)jVar5 >> 0x20) == iVar3;
  bVar1 = (int)jVar5 != (int)jVar6;
  if (!bVar4 || bVar1) {
    iVar3 = 0;
  }
  bVar2 = (byte)iVar3;
  if (bVar4 && !bVar1) {
    bVar2 = 1;
  }
  return (uint)bVar2;
}

