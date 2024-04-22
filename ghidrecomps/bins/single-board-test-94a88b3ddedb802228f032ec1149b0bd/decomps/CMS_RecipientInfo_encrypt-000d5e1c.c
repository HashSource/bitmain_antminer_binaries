
undefined4 CMS_RecipientInfo_encrypt(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  switch(*param_2) {
  case 0:
    uVar1 = cms_RecipientInfo_ktri_encrypt();
    return uVar1;
  case 1:
    uVar1 = cms_RecipientInfo_kari_encrypt();
    return uVar1;
  case 2:
    uVar1 = cms_RecipientInfo_kekri_encrypt();
    return uVar1;
  case 3:
    uVar1 = cms_RecipientInfo_pwri_crypt(param_1,param_2,1);
    return uVar1;
  default:
    ERR_put_error(0x2e,0xa9,0x9a,DAT_000d5e70,0x34b);
    return 0;
  }
}

