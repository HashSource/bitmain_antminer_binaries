
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  int iVar1;
  
  if (*(code **)(*(int *)eckey + 0x34) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012b378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)eckey + 0x34))(type);
    return iVar1;
  }
  ERR_put_error(0x10,0xfd,0x98,"crypto/ec/ecdsa_vrf.c",0x29);
  return -1;
}

