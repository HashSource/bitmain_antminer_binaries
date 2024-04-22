
undefined4
tls1_generate_master_secret(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined auStack_50 [52];
  
  uVar1 = ssl_get_algorithm2();
  tls1_PRF_constprop_0
            (uVar1,"master secret",0xd,*(int *)(param_1 + 0x58) + 0xc0,0x20,0,0,
             *(int *)(param_1 + 0x58) + 0xa0,0x20,param_3,param_4,*(int *)(param_1 + 0xc0) + 0x14,
             auStack_50,0x30);
  OPENSSL_cleanse(auStack_50,0x30);
  return 0x30;
}

