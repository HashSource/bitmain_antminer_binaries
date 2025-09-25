
bool ec_missing_parameters(int param_1)

{
  EC_GROUP *pEVar1;
  
  if (*(EC_KEY **)(param_1 + 0x18) != (EC_KEY *)0x0) {
    pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x18));
    return pEVar1 == (EC_GROUP *)0x0;
  }
  return true;
}

