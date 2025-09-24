
int ECDSA_do_verify(uchar *dgst,int dgst_len,ECDSA_SIG *sig,EC_KEY *eckey)

{
  int iVar1;
  
  if (*(code **)(*(int *)eckey + 0x38) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012176a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)eckey + 0x38))(dgst);
    return iVar1;
  }
  ERR_put_error(0x10,0xfc,0x98,"crypto/ec/ecdsa_vrf.c",0x19);
  return -1;
}

