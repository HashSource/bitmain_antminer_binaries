
int pkey_hkdf_derive(int param_1,uchar *param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  EVP_MD *md;
  uchar *puVar3;
  uint uVar4;
  int iVar5;
  uint local_6c;
  uint local_68 [17];
  
  piVar1 = *(int **)(param_1 + 0x14);
  md = (EVP_MD *)piVar1[1];
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x34,0x66,0x69,"crypto/kdf/hkdf.c",0xc4);
    iVar2 = 0;
  }
  else {
    puVar3 = (uchar *)piVar1[4];
    if (puVar3 == (uchar *)0x0) {
      ERR_put_error(0x34,0x66,0x68,"crypto/kdf/hkdf.c",200);
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar1;
      if (iVar2 == 1) {
        if (param_2 == (uchar *)0x0) {
          uVar4 = EVP_MD_size(md);
          *param_3 = uVar4;
        }
        else {
          puVar3 = HMAC(md,(void *)piVar1[2],piVar1[3],puVar3,piVar1[5],param_2,local_68);
          if (puVar3 != (uchar *)0x0) {
            *param_3 = local_68[0];
            return 1;
          }
          iVar2 = 0;
        }
      }
      else {
        if (iVar2 == 2) {
          iVar2 = HKDF_Expand(md,puVar3,piVar1[5],piVar1 + 6,piVar1[0x106],param_2,*param_3);
          if (iVar2 != 0) {
            iVar2 = 1;
          }
          return iVar2;
        }
        if (iVar2 == 0) {
          iVar5 = piVar1[0x106];
          uVar4 = *param_3;
          puVar3 = HMAC(md,(void *)piVar1[2],piVar1[3],puVar3,piVar1[5],(uchar *)local_68,&local_6c)
          ;
          if (puVar3 != (uchar *)0x0) {
            iVar2 = HKDF_Expand(md,local_68,local_6c,piVar1 + 6,iVar5,param_2,uVar4);
            if (iVar2 != 0) {
              iVar2 = 1;
            }
            OPENSSL_cleanse(local_68,0x40);
            return iVar2;
          }
        }
        else {
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}

