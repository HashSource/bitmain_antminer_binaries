
/* WARNING: Unknown calling convention */

float _get_higher_voltage(void)

{
  _Bool _Var1;
  double dVar2;
  float fVar3;
  float volt;
  int _chain;
  
  volt = 0.0;
  _Var1 = is_T11();
  if (_Var1) {
    for (_chain = 0; _chain < 0x10; _chain = _chain + 1) {
      if (dev->chain_exist[_chain] != 0) {
        dVar2 = get_higher_voltage_by_chain((uint8_t)_chain);
        volt = (float)(dVar2 + (double)volt);
      }
    }
    fVar3 = volt / (float)(longlong)_chain;
  }
  else {
    dVar2 = get_higher_voltage();
    fVar3 = (float)dVar2;
  }
  return fVar3;
}

