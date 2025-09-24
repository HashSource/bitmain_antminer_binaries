
undefined4 pkey_scrypt_derive(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  if (*piVar2 == 0) {
    ERR_put_error(0x34,0x6d,0x6e,"crypto/kdf/scrypt.c",0xde);
    uVar1 = 0;
  }
  else if (piVar2[2] == 0) {
    ERR_put_error(0x34,0x6d,0x6f,"crypto/kdf/scrypt.c",0xe3);
    uVar1 = 0;
  }
  else {
    uVar1 = EVP_PBE_scrypt(*piVar2,piVar2[1],piVar2[2],piVar2[3],piVar2[4],piVar2[5],piVar2[6],
                           piVar2[7],piVar2[8],piVar2[9],piVar2[10],piVar2[0xb],param_2,*param_3);
  }
  return uVar1;
}

