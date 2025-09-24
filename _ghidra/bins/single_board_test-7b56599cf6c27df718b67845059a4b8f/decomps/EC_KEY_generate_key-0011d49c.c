
int EC_KEY_generate_key(EC_KEY *key)

{
  int iVar1;
  
  if ((key != (EC_KEY *)0x0) && (*(int *)(key + 0xc) != 0)) {
    if (*(code **)(*(int *)key + 0x20) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011d4b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(*(int *)key + 0x20))();
      return iVar1;
    }
    ERR_put_error(0x10,0xb3,0x98,"crypto/ec/ec_key.c",0xbe);
    return 0;
  }
  ERR_put_error(0x10,0xb3,0x43,"crypto/ec/ec_key.c",0xb9);
  return 0;
}

