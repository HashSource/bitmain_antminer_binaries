
void zcashPerson(void *param_1,undefined4 param_2,undefined4 param_3)

{
  memcpy(param_1,"ZcashPoW",8);
  *(undefined4 *)((int)param_1 + 8) = param_2;
  *(undefined4 *)((int)param_1 + 0xc) = param_3;
  return;
}

